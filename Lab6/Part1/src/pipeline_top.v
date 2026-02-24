`timescale 1ns / 1ps

module pipeline_top(
    input  wire clk,
    input  wire reset,

    // -------- IMEM external programming --------
    input        imem_we_ext,
    input [8:0]  imem_addr_ext,
    input [31:0] imem_data_ext,

    // -------- DMEM external programming --------
    input        dmem_we_ext,
    input [7:0]  dmem_addr_ext,
    input [31:0] dmem_data_ext,

    input        dmem_re_ext,
    output [31:0] dmem_rdata_ext,

    // -------- REGFILE external read --------
    input  [3:0] regfile_addr_ext,
    input        regfile_re_ext,
    output [31:0] regfile_rdata_ext
);

// ==========================================================
// ===================== IF STAGE ===========================
// ==========================================================

wire [31:0] pc_out;
wire [31:0] pc_plus1;
wire [31:0] pc_next;

assign pc_plus1 = pc_out + 32'd4;

wire branch_taken;
wire [31:0] branch_target;
assign pc_next = branch_taken ? branch_target : pc_plus1;

wire pc_write;

PC pc (
    .clk(clk),
    .reset(reset),
    .pc_write(pc_write),
    .pc_next(pc_next),
    .pc_out(pc_out)
);

// ---------------- IMEM (external programmable) ----------------

wire [31:0] instruction_IF;

wire [8:0] imem_addr_mux =
        imem_we_ext ? imem_addr_ext : pc_out[10:2];

wire [31:0] imem_din_mux =
        imem_we_ext ? imem_data_ext : 32'b0;

wire imem_we_mux = imem_we_ext;

IMem imem (
    .addr(imem_addr_mux),
    .clk(clk),
    .din(imem_din_mux),
    .dout(instruction_IF),
    .we(imem_we_mux)
);

// ==========================================================
// ===================== IF/ID ==============================
// ==========================================================

wire [31:0] instruction_ID;
wire [31:0] pc_plus1_ID;
wire IF_ID_write;
wire IF_ID_flush;

IF_ID if_id (
    .clk(clk),
    .reset(reset),
    .write_enable(IF_ID_write),
    .flush(IF_ID_flush),
    .instruction_in(instruction_IF),
    .pc_plus1_in(pc_plus1),
    .instruction_out(instruction_ID),
    .pc_plus1_out(pc_plus1_ID)
);

// ==========================================================
// ===================== ID STAGE ===========================
// ==========================================================

wire [3:0] cond_ID;
wire [3:0] Rn_ID, Rd_ID, Rm_ID;
wire [4:0] shamt_ID;
wire is_dp_ID, is_ldr_ID, is_str_ID, is_branch_ID, is_bx_ID;
wire [3:0] dp_opcode_ID;
wire S_ID;
wire signed [31:0] branch_offset_ID;
wire U_ID;
wire [11:0] offset12_ID;

wire I_ID;
wire [31:0] imm32_ID;
wire [3:0] alu_opcode_ID;
wire ALUSrc_ID;
wire MemRead_ID, MemWrite_ID, RegWrite_ID, MemToReg_ID;

instruction_decoder decoder (
    .instr(instruction_ID),
    .cond(cond_ID),
    .Rn(Rn_ID),
    .Rd(Rd_ID),
    .Rm(Rm_ID),
    .shamt(shamt_ID),
    .is_dp(is_dp_ID),
    .dp_opcode(dp_opcode_ID),
    .S(S_ID),
    .I(I_ID),
    .imm32(imm32_ID),
    .is_ldr(is_ldr_ID),
    .is_str(is_str_ID),
    .is_branch(is_branch_ID),
    .branch_offset(branch_offset_ID),
    .offset12(offset12_ID),
    .U(U_ID),
    .is_bx(is_bx_ID)
);

control_unit CU(
    .is_dp(is_dp_ID),
    .is_ldr(is_ldr_ID),
    .is_str(is_str_ID),
    .is_branch(is_branch_ID),
    .dp_opcode(dp_opcode_ID),
    .I(I_ID),
    .U(U_ID),
    .alu_opcode(alu_opcode_ID),
    .ALUSrc(ALUSrc_ID),
    .MemRead(MemRead_ID),
    .MemWrite(MemWrite_ID),
    .RegWrite(RegWrite_ID),
    .MemToReg(MemToReg_ID)
);

// ---------------- REGFILE (external readable) ----------------

wire [31:0] rs_data_ID;
wire [31:0] rt_data_ID;

wire [31:0] write_data_WB;
wire [3:0]  Rd_WB;
wire        WRegEn_WB;

wire [3:0] reg_read_addr1 = is_bx_ID ? Rm_ID : Rn_ID;
wire [3:0] reg_read_addr2 = is_str_ID ? Rd_ID : Rm_ID;

wire [3:0] regfile_addr_mux =
        regfile_re_ext ? regfile_addr_ext : reg_read_addr1;

wire [31:0] rs_data_mux;

regfile16_32bit regfile (
    .clk(clk),
    .reset(reset),
    .we(WRegEn_WB),
    .wr_addr(Rd_WB),
    .wr_data(write_data_WB),
    .rd_addr1(regfile_addr_mux),
    .rd_addr2(reg_read_addr2),
    .rd_data1(rs_data_mux),
    .rd_data2(rt_data_ID)
);

assign regfile_rdata_ext = rs_data_mux;
assign rs_data_ID = rs_data_mux;

// ==========================================================
// ===================== HAZARD =============================
// ==========================================================

wire ID_EX_MemRead;
wire [3:0] ID_EX_Rd;
wire HDU_PC_write, HDU_IF_ID_write, HDU_ID_EX_flush;

hdu hazard (
    .ID_EX_MemRead(ID_EX_MemRead),
    .ID_EX_Rd(ID_EX_Rd),
    .IF_ID_Rs(Rn_ID),
    .IF_ID_Rt(Rm_ID),
    .PC_write(HDU_PC_write),
    .IF_ID_write(HDU_IF_ID_write),
    .ID_EX_flush(HDU_ID_EX_flush)
);

assign IF_ID_write = HDU_IF_ID_write;
assign pc_write    = HDU_PC_write;
assign IF_ID_flush = branch_taken;

// ==========================================================
// ===================== EX/MEM/WB ==========================
// ==========================================================
// (UNCHANGED pipeline logic — same as your original)
// ==========================================================

// ---------------- DMEM (external programmable) ----------------
// ---------- EX/MEM wires ----------
wire [31:0] exmem_alu;
wire [31:0] exmem_rt;
wire [3:0]  exmem_rd;
wire        exmem_WRegEn;
wire        exmem_WMemEn;
wire        exmem_MemToReg;
wire [7:0]  dmem_addr_cpu = exmem_alu[9:2];
wire [7:0]  dmem_addr_mux =
        (dmem_we_ext || dmem_re_ext) ? dmem_addr_ext : dmem_addr_cpu;

wire [31:0] dmem_din_mux =
        dmem_we_ext ? dmem_data_ext : exmem_rt;

wire        dmem_we_mux =
        dmem_we_ext | exmem_WMemEn;

wire [31:0] dmem_out;

DMem32 dmem (
    .clka(clk),
    .clkb(clk),
    .addra(dmem_addr_cpu),
    .addrb(dmem_addr_mux),
    .dina(exmem_rt),
    .dinb(dmem_din_mux),
    .douta(dmem_out),
    .doutb(dmem_rdata_ext),
    .wea(exmem_WMemEn),
    .web(dmem_we_mux)
);

reg [31:0] mem_rdata_reg;

always @(posedge clk) begin
    if (dmem_re_ext)
        mem_rdata_reg <= dmem_rdata_ext;
    else
        mem_rdata_reg <= dmem_out;
end

// ==========================================================
// ===================== MEM/WB =============================
// ==========================================================

MEM_WB mem_wb (
    .clk(clk),
    .reset(reset),
    .alu_result_in(exmem_alu),
    .mem_data_in(mem_rdata_reg),
    .rd_in(exmem_rd),
    .WRegEn_in(exmem_WRegEn),
    .MemToReg_in(exmem_MemToReg),
    .alu_result_out(alu_result_WB),
    .mem_data_out(mem_data_WB),
    .rd_out(Rd_WB_internal),
    .WRegEn_out(WRegEn_WB_internal),
    .MemToReg_out(MemToReg_WB)
);

assign write_data_WB =
        MemToReg_WB ? mem_data_WB : alu_result_WB;

assign Rd_WB = Rd_WB_internal;
assign WRegEn_WB = WRegEn_WB_internal;

endmodule