module simple_gpu (
    input  clk,
    input  reset,
    //output [63:0] debug_r3
    input  cpu_enable, // gated run/stop from wrapper



// IMEM external programming interface 
//
	input imem_we_ext,
	input  [8:0]  imem_addr_ext,
	input  [31:0] imem_data_ext,

// DMEM external programming / read interface

	input  dmem_we_ext,
	input  [7:0] dmem_addr_ext,
	input  [63:0] dmem_data_ext,
	input dmem_re_ext,
	output [63:0] dmem_rdata_ext,
	 //RegFile external read 
	 input regfile_re_ext,
  	 input [3:0] regfile_addr_ext,
	 output [63:0] regfile_rdata_ext
);

// ============================================================
// PC
// ============================================================
wire hazard_stall;
wire tensor_stall;
wire stall;
wire [8:0] pc;

gpu_pc PC (
    .clk   (clk),
    .reset (reset),
    .en    (~stall),
    .pc    (pc)
);

// ============================================================
// INSTRUCTION MEMORY
// ============================================================
wire [31:0] instruction;
wire [5:0]  imem_addr_mux = imem_we_ext ? imem_addr_ext[5:0] : pc[5:0];
wire [31:0] imem_din_mux  = imem_we_ext ? imem_data_ext      : 32'b0;
wire        imem_we_mux   = imem_we_ext;
/*
instruction_memory IM (
    .addr        (pc[5:0]),
    .clk         (clk),
	 .din			(32'b0),
    .dout (instruction),
	 .we (1'b0)
);
*/

instruction_memory IM (
    .addr (imem_addr_mux),
    .clk  (clk),
    .din  (imem_din_mux),
    .dout (instruction),
    .we   (imem_we_mux)
);

// ============================================================
// IF/ID PIPELINE REGISTER
// ============================================================
reg [31:0] IF_ID_instr;

always @(posedge clk) begin
    if (reset)       IF_ID_instr <= 32'd0;
    else if (!stall) IF_ID_instr <= instruction;
end

// ============================================================
// DECODE
// ============================================================
wire [4:0]  opcode_isa;
wire        DT;
wire [3:0]  rD_addr, rA_addr, rB_addr, rC_addr;
wire [15:0] imm16;
wire        is_rtype, is_itype, is_mtype, is_wtype;

isa_decoder DEC (
    .instruction (IF_ID_instr),
    .opcode_isa  (opcode_isa),
    .DT          (DT),
    .rd          (rD_addr),
    .ra          (rA_addr),
    .rb          (rB_addr),
    .rc          (rC_addr),
    .imm16       (imm16),
    .is_rtype    (is_rtype),
    .is_itype    (is_itype),
    .is_mtype    (is_mtype),
    .is_wtype    (is_wtype)
);

// ============================================================
// NOP GATE
// ============================================================
wire is_nop     = (IF_ID_instr == 32'd0);
wire is_rtype_g = is_rtype & ~is_nop;
wire is_itype_g = is_itype & ~is_nop;
wire is_mtype_g = is_mtype & ~is_nop;
wire is_wtype_g = is_wtype & ~is_nop;

// ============================================================
// STORE GUARD ? STORE must not write back to register file
// ============================================================
wire is_store_op = is_mtype_g && (opcode_isa == 5'b00001);  // STORE opcode

// ============================================================
// CONTROL
// ============================================================
wire reg_write, mem_read, mem_write;
wire alu_enable, tensor_enable;
wire use_immediate, data_type_bf16;
wire [4:0] alu_op;

gpu_control_unit CTRL (
    .opcode           (opcode_isa),
    .DT               (DT),
    .is_rtype_control (is_rtype_g),
    .is_itype_control (is_itype_g),
    .is_mtype_control (is_mtype_g),
    .is_wtype_control (is_wtype_g),
    .alu_enable       (alu_enable),
    .tensor_enable    (tensor_enable),
    .mem_read         (mem_read),
    .mem_write        (mem_write),
    .reg_write        (reg_write),
    .use_immediate    (use_immediate),
    .data_type_bf16   (data_type_bf16),
    .alu_op           (alu_op)
);

// ============================================================
// REGISTER FILE
// ============================================================
wire [63:0] imm_ext  = {4{imm16}};
wire [63:0] rsA_data, rsB_data, rsC_data;

reg [63:0] MEM_WB_result;
reg [3:0]  MEM_WB_rd;
reg        MEM_WB_reg_write;
reg        MEM_WB_valid;

register_file RF (
    .clk        (clk),
    .reset      (reset),
    .rs1        (rA_addr),
    .rs2        (rB_addr),
    .rs3        (rC_addr),
    .rd         (MEM_WB_rd),
    .write_data (MEM_WB_result),
    .we         (MEM_WB_valid & MEM_WB_reg_write),
    .read_data1 (rsA_data),
    .read_data2 (rsB_data),
    .read_data3 (rsC_data)
);

//assign debug_r3 = RF.reg_array[3];

// ============================================================
// HAZARD DETECTION ? 6 slots A..F, all checked
// Slot A = EX1 (1 cycle after ID issue)
// Slot B = EX2_d1
// Slot C = EX2_MEM
// Slot D = EX2 result reg
// Slot E = BYPASS / MEM_WB_rd_Pass
// Slot F = MEM_WB write (RF write fires this cycle)
// Stall through F; consumer reads RF on the NEXT cycle (clean)
// ============================================================
reg [3:0] haz_dest_A, haz_dest_B, haz_dest_C;
reg [3:0] haz_dest_D, haz_dest_E, haz_dest_F;
reg       haz_we_A,   haz_we_B,   haz_we_C;
reg       haz_we_D,   haz_we_E,   haz_we_F;

wire src_uses_rA = is_rtype_g | is_itype_g | is_mtype_g | is_wtype_g;
wire src_uses_rB = is_rtype_g | is_wtype_g;
wire src_uses_rC = is_wtype_g;

wire haz_A = haz_we_A && (haz_dest_A != 4'd0) && (
    (src_uses_rA && (haz_dest_A == rA_addr)) ||
    (src_uses_rB && (haz_dest_A == rB_addr)) ||
    (src_uses_rC && (haz_dest_A == rC_addr)) );

wire haz_B = haz_we_B && (haz_dest_B != 4'd0) && (
    (src_uses_rA && (haz_dest_B == rA_addr)) ||
    (src_uses_rB && (haz_dest_B == rB_addr)) ||
    (src_uses_rC && (haz_dest_B == rC_addr)) );

wire haz_C = haz_we_C && (haz_dest_C != 4'd0) && (
    (src_uses_rA && (haz_dest_C == rA_addr)) ||
    (src_uses_rB && (haz_dest_C == rB_addr)) ||
    (src_uses_rC && (haz_dest_C == rC_addr)) );

wire haz_D = haz_we_D && (haz_dest_D != 4'd0) && (
    (src_uses_rA && (haz_dest_D == rA_addr)) ||
    (src_uses_rB && (haz_dest_D == rB_addr)) ||
    (src_uses_rC && (haz_dest_D == rC_addr)) );

wire haz_E = haz_we_E && (haz_dest_E != 4'd0) && (
    (src_uses_rA && (haz_dest_E == rA_addr)) ||
    (src_uses_rB && (haz_dest_E == rB_addr)) ||
    (src_uses_rC && (haz_dest_E == rC_addr)) );

wire haz_F = haz_we_F && (haz_dest_F != 4'd0) && (
    (src_uses_rA && (haz_dest_F == rA_addr)) ||
    (src_uses_rB && (haz_dest_F == rB_addr)) ||
    (src_uses_rC && (haz_dest_F == rC_addr)) );

assign hazard_stall = haz_A | haz_B | haz_C | haz_D | haz_E | haz_F;
assign stall        = hazard_stall | tensor_stall | ~cpu_enable;

// Shift register ? advances every cycle unconditionally
always @(posedge clk) begin
    if (reset) begin
        haz_dest_B <= 4'd0; haz_we_B <= 1'b0; 
        haz_dest_C <= 4'd0; haz_we_C <= 1'b0;
        haz_dest_D <= 4'd0; haz_we_D <= 1'b0;
        haz_dest_E <= 4'd0; haz_we_E <= 1'b0;
        haz_dest_F <= 4'd0; haz_we_F <= 1'b0;
    end
    else begin
        haz_dest_B <= haz_dest_A; haz_we_B <= haz_we_A;
        haz_dest_C <= haz_dest_B; haz_we_C <= haz_we_B;
        haz_dest_D <= haz_dest_C; haz_we_D <= haz_we_C;
        haz_dest_E <= haz_dest_D; haz_we_E <= haz_we_D;
        haz_dest_F <= haz_dest_E; haz_we_F <= haz_we_E;
    end
end

// ============================================================
// ID?EX1 PIPELINE REGISTER
// ============================================================
reg [63:0] EX1_opA, EX1_opB, EX1_opC, EX1_store_data;
reg [4:0]  EX1_alu_op;
reg        EX1_alu_enable, EX1_tensor_enable;
reg        EX1_mem_read, EX1_mem_write, EX1_reg_write;
reg        EX1_data_type_bf16;
reg [3:0]  EX1_rd;

always @(posedge clk) begin
    if (reset) begin
        EX1_opA            <= 64'd0;
        EX1_opB            <= 64'd0;
        EX1_opC            <= 64'd0;
        EX1_store_data     <= 64'd0;
        EX1_alu_op         <= 5'd0;
        EX1_alu_enable     <= 1'b0;
        EX1_tensor_enable  <= 1'b0;
        EX1_mem_read       <= 1'b0;
        EX1_mem_write      <= 1'b0;
        EX1_reg_write      <= 1'b0;
        EX1_data_type_bf16 <= 1'b0;
        EX1_rd             <= 4'd0;
        haz_dest_A         <= 4'd0;
        haz_we_A           <= 1'b0;
    end
    else if (!stall) begin
        EX1_opA        <= rsA_data;
        EX1_opB        <= is_mtype_g ? 64'd0 :(use_immediate ? imm_ext : rsB_data);
        EX1_opC        <= rsC_data;
        EX1_store_data <= rsB_data;
        EX1_alu_op         <= alu_op;
        EX1_alu_enable     <= alu_enable;
        EX1_tensor_enable  <= tensor_enable;
        EX1_mem_read       <= mem_read;
        EX1_mem_write      <= mem_write;
        EX1_reg_write      <= reg_write & ~is_store_op;
        EX1_data_type_bf16 <= data_type_bf16;
        EX1_rd             <= rD_addr;
        haz_dest_A         <= rD_addr;
        haz_we_A           <= reg_write & ~is_nop & ~is_store_op;
    end
    else begin
        EX1_alu_enable    <= 1'b0;
        EX1_tensor_enable <= 1'b0;
        EX1_mem_read      <= 1'b0;
        EX1_mem_write     <= 1'b0;
        EX1_reg_write     <= 1'b0;
        haz_we_A          <= 1'b0;
    end
end

wire [3:0] shift_amount = EX1_opB[3:0];

// ============================================================
// SIMD ALU ? stage 1
// ============================================================
wire [15:0] r0_s1_EX1, r1_s1_EX1, r2_s1_EX1, r3_s1_EX1;
wire        alu_valid_EX1;

simd_alu1 ALU1 (
    .enable    (EX1_alu_enable),
    .srcA      (EX1_opA),
    .srcB      (EX1_opB),
    .srcC      (EX1_opC),
    .opcode    (EX1_alu_op),
    .shift     (shift_amount),
    .bf16_mode (EX1_data_type_bf16),
    .r0_s1     (r0_s1_EX1),
    .r1_s1     (r1_s1_EX1),
    .r2_s1     (r2_s1_EX1),
    .r3_s1     (r3_s1_EX1),
    .valid_out (alu_valid_EX1)
);

// ============================================================
// TENSOR CORE
// ============================================================
wire [63:0] tensor_result1;
wire        tensor_valid_Final;

tensor_core TC1 (
    .clk       (clk),
    .reset     (reset),
    .enable    (EX1_tensor_enable),
    .srcA      (EX1_opA),
    .srcB      (EX1_opB),
    .srcC      (EX1_opC),
    .result    (tensor_result1),
    .valid_out (tensor_valid_Final),
    .stall     (tensor_stall)
);

reg        tensor_pending;
reg [3:0]  tensor_rd_hold;
reg        tensor_regwrite_hold;

always @(posedge clk) begin
    if (reset) begin
        tensor_pending       <= 1'b0;
        tensor_rd_hold       <= 4'd0;
        tensor_regwrite_hold <= 1'b0;
    end
    else begin
        if (EX1_tensor_enable) begin
            tensor_pending       <= 1'b1;
            tensor_rd_hold       <= EX1_rd;
            tensor_regwrite_hold <= EX1_reg_write;
        end
        if (tensor_valid_Final)
            tensor_pending <= 1'b0;
    end
end

// ============================================================
// EX1?EX2 PIPELINE REGISTER
// ============================================================
reg [15:0] EX2_AluRes0, EX2_AluRes1, EX2_AluRes2, EX2_AluRes3;
reg [63:0] EX2_TensorRes;
reg        EX2_ALU_valid, EX2_Tensor_Valid;
reg [3:0]  EX2_d1_rd;
reg        EX2_d1_mem_read, EX2_d1_mem_write, EX2_d1_reg_write;
reg [63:0] EX2_d1_store_data;

always @(posedge clk) begin
    if (reset) begin
        EX2_AluRes0       <= 16'd0;
        EX2_AluRes1       <= 16'd0;
        EX2_AluRes2       <= 16'd0;
        EX2_AluRes3       <= 16'd0;
        EX2_ALU_valid     <= 1'b0;
        EX2_TensorRes     <= 64'd0;
        EX2_Tensor_Valid  <= 1'b0;
        EX2_d1_rd         <= 4'd0;
        EX2_d1_mem_read   <= 1'b0;
        EX2_d1_mem_write  <= 1'b0;
        EX2_d1_reg_write  <= 1'b0;
        EX2_d1_store_data <= 64'd0;
    end
    else if (tensor_valid_Final) begin
        tensor_pending    <= 1'b0;
        EX2_TensorRes     <= tensor_result1;
        EX2_Tensor_Valid  <= 1'b1;
        EX2_ALU_valid     <= 1'b0;
        EX2_d1_rd         <= tensor_rd_hold;
        EX2_d1_reg_write  <= tensor_regwrite_hold;
        EX2_d1_mem_read   <= EX1_mem_read;
        EX2_d1_mem_write  <= EX1_mem_write;
        EX2_d1_store_data <= EX1_store_data;
    end
    else begin
        EX2_AluRes0       <= r0_s1_EX1;
        EX2_AluRes1       <= r1_s1_EX1;
        EX2_AluRes2       <= r2_s1_EX1;
        EX2_AluRes3       <= r3_s1_EX1;
        EX2_ALU_valid     <= alu_valid_EX1;
        EX2_Tensor_Valid  <= 1'b0;
        EX2_d1_rd         <= EX1_rd;
        EX2_d1_reg_write  <= EX1_reg_write;
        EX2_d1_mem_read   <= EX1_mem_read;
        EX2_d1_mem_write  <= EX1_mem_write;
        EX2_d1_store_data <= EX1_store_data;
    end
end

// ============================================================
// SIMD ALU ? stage 2
// ============================================================
wire        alu_valid_final;
wire [63:0] ALU_result_Final;

simd_alu2 ALU2 (
    .enable    (EX2_ALU_valid),
    .r0_s1     (EX2_AluRes0),
    .r1_s1     (EX2_AluRes1),
    .r2_s1     (EX2_AluRes2),
    .r3_s1     (EX2_AluRes3),
    .valid_out (alu_valid_final),
    .result    (ALU_result_Final)
);

// ============================================================
// EX2?MEM PIPELINE REGISTER
// ============================================================
reg [3:0]  EX2_MEM_rd;
reg        EX2_MEM_mem_read, EX2_MEM_mem_write, EX2_MEM_reg_write;
reg        EX2_Mem_ALU_valid, EX2_Mem_Tensor_Valid;
reg [63:0] EX2_MEM_store_data;
reg [63:0] EX2_result;
reg [63:0] EX2_Mem_ALU;
reg [63:0] EX2_Mem_Tensor;
reg        EX2_valid;
reg        EX2_MEM_mem_write_dly;
reg [63:0] EX2_MEM_store_data_dly;
reg [63:0] EX2_MEM_ALU_dly;

always @(posedge clk) begin
    if (reset) begin
        EX2_MEM_rd             <= 4'd0;
        EX2_MEM_mem_read       <= 1'b0;
        EX2_MEM_mem_write      <= 1'b0;
        EX2_MEM_reg_write      <= 1'b0;
        EX2_MEM_store_data     <= 64'b0;
        EX2_Mem_ALU            <= 64'd0;
        EX2_Mem_Tensor         <= 64'd0;
        EX2_Mem_ALU_valid      <= 1'b0;
        EX2_valid              <= 1'b0;
        EX2_Mem_Tensor_Valid   <= 1'b0;
        EX2_MEM_mem_write_dly  <= 1'b0;
        EX2_MEM_store_data_dly <= 64'd0;
        EX2_result             <= 64'd0;
    end
    else begin
        EX2_MEM_mem_read       <= EX2_d1_mem_read;
        EX2_MEM_mem_write      <= EX2_d1_mem_write;
        EX2_MEM_store_data     <= EX2_d1_store_data;
        EX2_MEM_rd             <= EX2_d1_rd;
        EX2_Mem_ALU            <= ALU_result_Final;
        EX2_Mem_ALU_valid      <= alu_valid_final;
        EX2_Mem_Tensor         <= EX2_TensorRes;
        EX2_Mem_Tensor_Valid   <= EX2_Tensor_Valid;
        EX2_MEM_reg_write      <= EX2_d1_reg_write;
        EX2_MEM_mem_write_dly  <= EX2_MEM_mem_write;
        EX2_MEM_store_data_dly <= EX2_MEM_store_data;
        EX2_MEM_ALU_dly        <= EX2_Mem_ALU;
        EX2_valid              <= EX2_Mem_Tensor_Valid || EX2_Mem_ALU_valid;
        EX2_result             <= EX2_Mem_Tensor_Valid ? EX2_Mem_Tensor
                                                       : EX2_Mem_ALU;
    end
end

// ============================================================
// DATA MEMORY
// ============================================================
wire [63:0] mem_data;

// Address mux: host external read/write takes priority over pipeline
// When dmem_re_ext=1: port A reads host address -> drives dmem_rdata_ext
// When dmem_we_ext=1: port B writes host data to host address
// Otherwise: pipeline controls both ports normally
wire [7:0]  dmem_addra = dmem_re_ext  ? dmem_addr_ext         : EX2_MEM_ALU_dly[7:0];
wire [7:0]  dmem_addrb = dmem_we_ext  ? dmem_addr_ext         : EX2_MEM_ALU_dly[7:0];
wire [63:0] dmem_dinb  = dmem_we_ext  ? dmem_data_ext         : EX2_MEM_store_data_dly;
wire        dmem_web   = dmem_we_ext  | EX2_MEM_mem_write_dly;
wire [63:0] dmem_douta;

assign mem_data       = dmem_douta;  // pipeline LOAD result
assign dmem_rdata_ext = dmem_douta;  // external host read result

data_Rmemory DM (
    // PORT A -- pipeline read OR external host read (address muxed)
    .clka   (clk),
    .addra  (dmem_addra),
    .dina   (64'b0),
    .douta  (dmem_douta),
    .wea    (1'b0),

    // PORT B -- pipeline write OR external host write (address/data muxed)
    .clkb   (clk),
    .addrb  (dmem_addrb),
    .dinb   (dmem_dinb),
    .doutb  (),
    .web    (dmem_web)
);

// ============================================================
// BYPASS PASS REGISTERS
// ============================================================
reg [3:0] EX2_MEM_rd_Pass;
reg       EX2_MEM_reg_write_Pass;
reg       EX2_MEM_mem_read_Pass;

always @(posedge clk) begin
    if (reset) begin
        EX2_MEM_rd_Pass        <= 4'd0;
        EX2_MEM_reg_write_Pass <= 1'b0;
        EX2_MEM_mem_read_Pass  <= 1'b0;
    end
    else begin
        EX2_MEM_rd_Pass        <= EX2_MEM_rd;
        EX2_MEM_reg_write_Pass <= EX2_MEM_reg_write;
        EX2_MEM_mem_read_Pass  <= EX2_MEM_mem_read;
    end
end

// ============================================================
// MEM/WB PIPELINE REGISTER
// ============================================================
always @(posedge clk) begin
    if (reset) begin
        MEM_WB_result    <= 64'd0;
        MEM_WB_rd        <= 4'd0;
        MEM_WB_reg_write <= 1'b0;
        MEM_WB_valid     <= 1'b0;
    end
    else begin
        if (EX2_valid) begin
            MEM_WB_result    <= EX2_MEM_mem_read_Pass ? mem_data : EX2_result;
            MEM_WB_rd        <= EX2_MEM_rd_Pass;
            MEM_WB_reg_write <= EX2_MEM_reg_write_Pass && (EX2_MEM_rd_Pass != 4'd0);
            MEM_WB_valid     <= 1'b1;
        end
        else begin
            MEM_WB_valid     <= 1'b0;
            MEM_WB_reg_write <= 1'b0;
        end
    end
end


// ============================================================
// REGFILE SHADOW -- external read interface for NetFPGA host
//
// Mirrors every MEM/WB writeback into a 16x64 shadow array.
// Host reads via regfile_re_ext + regfile_addr_ext -> regfile_rdata_ext
// Wrapper (GPU_top_integrate.v) latches rdata_ext into
// regfile_upper_read / regfile_lower_read on the next posedge.
//
// Why shadow and not direct RF read:
// register_file has 3 read ports (rs1,rs2,rs3) already consumed
// by the pipeline. Shadow avoids adding a 4th port.
// ============================================================
reg [63:0] regfile_shadow [0:15];
integer    __shadow_i;

always @(posedge clk) begin
    if (reset) begin
        for (__shadow_i = 0; __shadow_i < 16; __shadow_i = __shadow_i + 1)
            regfile_shadow[__shadow_i] <= 64'd0;
    end
    else begin
        // Update shadow on every successful writeback
        if (MEM_WB_valid && MEM_WB_reg_write && (MEM_WB_rd != 4'd0))
            regfile_shadow[MEM_WB_rd] <= MEM_WB_result;
    end
end

// Combinational output -- valid same cycle as regfile_re_ext
// Wrapper latches it on the next rising edge into hardware registers
assign regfile_rdata_ext = regfile_re_ext ? regfile_shadow[regfile_addr_ext] : 64'd0;

endmodule
