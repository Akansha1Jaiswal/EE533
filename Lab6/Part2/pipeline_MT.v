`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Module: pipeline_top_4thread
// Description: 4-Thread Interleaved Multi-Threaded ARM-like Processor
//
// Architecture:
//   - 4 hardware threads (contexts), each with its own PC and CPSR
//   - Thread ID cycles: 0->1->2->3->0->... every clock
//   - Single pipeline: IF, ID, EX, MEM, WB ? each stage tagged with thread_id
//   - Register file: BRAM-based, 6-bit address = {thread_id[1:0], reg[3:0]}
//     (64 registers total: 16 per thread)
//   - Because threads are interleaved, a given thread sees a new instruction
//     only every 4 cycles, so RAW hazards within one thread are naturally 
//     resolved by the inter-thread gap (4 cycles between same-thread instr.)
//   - The hazard detection unit only needs to stall for load-use if the
//     same thread appears back-to-back across 4 pipeline stages
//   - Each thread gets its own CPSR flags register
//   - Instruction memory is shared (threads use same IMem, different PCs)
//   - Data memory is shared (BRAM)
//////////////////////////////////////////////////////////////////////////////////

module pipeline_top_4thread(
    input wire clk,
    input wire reset
);

// ====================================================================
// Thread scheduling: round-robin 0->1->2->3->0...
// ====================================================================
reg [1:0] current_thread;  // IF stage thread ID

always @(posedge clk or posedge reset) begin
    if (reset) current_thread <= 2'd0;
    else       current_thread <= current_thread + 2'd1;
end

// ====================================================================
// Per-thread Program Counters (4 PCs)
// ====================================================================
reg [31:0] pc [0:3];

wire [31:0] pc_out      = pc[current_thread];
wire [31:0] pc_plus1    = pc_out + 32'd1;

// branch_taken and branch_target come from EX stage (tagged with thread)
wire        branch_taken;
wire [31:0] branch_target;
wire [1:0]  branch_thread_id;   // which thread is branching (from EX/MEM stage)

// pc_write from hazard unit (for current thread in IF)
wire pc_write;

integer t;
always @(posedge clk or posedge reset) begin
    if (reset) begin
        pc[0] <= 32'd0;
        pc[1] <= 32'd64;
        pc[2] <= 32'd128;
        pc[3] <= 32'd192;
    end else begin
        // 1) Handle branch for its own thread
        if (branch_taken)
            pc[branch_thread_id] <= branch_target;

        // 2) Increment the currently scheduled thread
        if (pc_write && (!branch_taken || branch_thread_id != current_thread))
            pc[current_thread] <= pc[current_thread] + 32'd1;
    end
end

// ====================================================================
// Instruction Memory (shared, indexed by PC)
// ====================================================================

//Added for BRAM extra latency 
reg [1:0]  fetch_thread_reg;  // thread that sent address to BRAM last cycle
reg [31:0] fetch_pc_plus1_reg; // PC+1 for that fetch

always @(posedge clk or posedge reset) begin
    if (reset) begin
        fetch_thread_reg <= 2'd0;
		  fetch_pc_plus1_reg <= 32'd1;  // PC 0 + 1
	 end	  
    else begin
        fetch_thread_reg <= current_thread;  // register the PC one cycle ahead
		  fetch_pc_plus1_reg <= pc_plus1;
		  end
end

// END




wire [31:0] instruction_IF;

imem imem (
    .addr(pc_out[8:0]),
    .clk(clk),
    .din(32'b0),
    .dout(instruction_IF),
    .we(1'b0)
);

// ====================================================================
// IF/ID Pipeline Register  (carries thread_id through pipeline)
// ====================================================================
wire [31:0] instruction_ID;
wire [31:0] pc_plus1_ID;
wire [1:0]  thread_id_ID;
wire        IF_ID_write;
wire        IF_ID_flush;

IF_ID_mt if_id (
    .clk(clk),
    .reset(reset),
    .write_enable(IF_ID_write),
    .flush(IF_ID_flush),
    .instruction_in(instruction_IF),
    .pc_plus1_in(fetch_pc_plus1_reg),
    .thread_id_in(fetch_thread_reg),
    .instruction_out(instruction_ID),
    .pc_plus1_out(pc_plus1_ID),
    .thread_id_out(thread_id_ID)
);

// ====================================================================
// ID Stage: Decode + Control
// ====================================================================
wire [3:0]  cond_ID, Rn_ID, Rd_ID, Rm_ID;
wire [4:0]  shamt_ID;
wire        is_dp_ID, is_ldr_ID, is_str_ID, is_branch_ID, is_bx_ID;
wire [3:0]  dp_opcode_ID;
wire        S_ID, I_ID, U_ID;
wire signed [31:0] branch_offset_ID;
wire [11:0] offset12_ID;
wire [31:0] imm32_ID;

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

wire [3:0] alu_opcode_ID;
wire       ALUSrc_ID, MemRead_ID, MemWrite_ID, RegWrite_ID, MemToReg_ID;

control_unit CU (
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

// ====================================================================
// Register File ? BRAM-based, 64 entries: {thread_id[1:0], reg[3:0]}
// ====================================================================
// WB signals (declared forward)
wire [31:0] write_data_WB;
wire [3:0]  Rd_WB;
wire        WRegEn_WB;
wire [1:0]  thread_id_WB;

wire [3:0] reg_read_addr1 = is_bx_ID ? Rm_ID : Rn_ID;
wire [3:0] reg_read_addr2 = (is_ldr_ID | is_str_ID) ? Rd_ID : Rm_ID;

// 6-bit addresses: {thread_id, reg_addr}
wire [5:0] rf_rd_addr1 = {thread_id_ID, reg_read_addr1};
wire [5:0] rf_rd_addr2 = {thread_id_ID, reg_read_addr2};
wire [5:0] rf_wr_addr  = {thread_id_WB, Rd_WB};

wire [31:0] rs_data_ID, rt_data_ID;

// Double-clocked BRAM register file
// Read on posedge, write on negedge (or use registered output)
regfile_bram_mt regfile (
    .clk(clk),
    .reset(reset),
    .we(WRegEn_WB),
    .wr_addr(rf_wr_addr),
    .wr_data(write_data_WB),
    .rd_addr1(rf_rd_addr1),
    .rd_addr2(rf_rd_addr2),
    .rd_data1(rs_data_ID),
    .rd_data2(rt_data_ID)
);

// ====================================================================
// Hazard Detection Unit
// (In 4-thread interleaving, same thread reappears every 4 cycles.
//  With a 5-stage pipeline, a load in EX won't complete before the
//  same thread arrives at ID again ? so load-use stall still needed.)
// ====================================================================
wire [1:0] ID_EX_thread;
wire       ID_EX_MemRead;
wire [3:0] ID_EX_Rd;

wire HDU_PC_write, HDU_IF_ID_write, HDU_ID_EX_flush;

hdu_mt hazard (
    .ID_EX_MemRead(ID_EX_MemRead),
    .ID_EX_Rd(ID_EX_Rd),
    .ID_EX_thread(ID_EX_thread),
    .IF_ID_thread(thread_id_ID),
    .IF_ID_Rs(Rn_ID),
    .IF_ID_Rt(Rm_ID),
    .PC_write(HDU_PC_write),
    .IF_ID_write(HDU_IF_ID_write),
    .ID_EX_flush(HDU_ID_EX_flush)
);

assign IF_ID_write = HDU_IF_ID_write;
assign pc_write    = HDU_PC_write;
assign IF_ID_flush = branch_taken;

// ====================================================================
// ID/EX Pipeline Register
// ====================================================================
wire [31:0] rs_data_EX, rt_data_EX, pc_plus1_EX;
wire [3:0]  cond_EX, dp_opcode_EX, Rd_EX, Rn_EX, Rm_EX;
wire [4:0]  shamt_EX;
wire        S_EX, is_dp_EX, is_ldr_EX, is_str_EX, is_branch_EX, is_bx_EX;
wire        I_EX, U_EX;
wire signed [31:0] branch_offset_EX;
wire [11:0] offset12_EX;
wire [31:0] imm32_EX;
wire [3:0]  alu_opcode_EX;
wire        ALUSrc_EX;
wire [1:0]  thread_id_EX;

wire ID_EX_flush_final = HDU_ID_EX_flush | branch_taken;

ID_EX_mt id_ex (
    .clk(clk),
    .reset(reset),
    .flush(ID_EX_flush_final),
    .rs_data_in(rs_data_ID),
    .rt_data_in(rt_data_ID),
    .pc_plus1_in(pc_plus1_ID),
    .alu_opcode_in(alu_opcode_ID),
    .ALUSrc_in(ALUSrc_ID),
    .cond_in(cond_ID),
    .dp_opcode_in(dp_opcode_ID),
    .S_in(S_ID),
    .is_dp_in(is_dp_ID),
    .is_ldr_in(is_ldr_ID),
    .is_str_in(is_str_ID),
    .is_branch_in(is_branch_ID),
    .is_bx_in(is_bx_ID),
    .branch_offset_in(branch_offset_ID),
    .Rd_in(Rd_ID),
    .shamt_in(shamt_ID),
    .offset12_in(offset12_ID),
    .U_in(U_ID),
    .Rn_in(Rn_ID),
    .Rm_in(Rm_ID),
    .I_in(I_ID),
    .imm32_in(imm32_ID),
    .thread_id_in(thread_id_ID),
    // outputs
    .rs_data_out(rs_data_EX),
    .rt_data_out(rt_data_EX),
    .pc_plus1_out(pc_plus1_EX),
    .alu_opcode_out(alu_opcode_EX),
    .ALUSrc_out(ALUSrc_EX),
    .cond_out(cond_EX),
    .dp_opcode_out(dp_opcode_EX),
    .S_out(S_EX),
    .is_dp_out(is_dp_EX),
    .is_ldr_out(is_ldr_EX),
    .is_str_out(is_str_EX),
    .is_branch_out(is_branch_EX),
    .is_bx_out(is_bx_EX),
    .branch_offset_out(branch_offset_EX),
    .Rd_out(Rd_EX),
    .shamt_out(shamt_EX),
    .offset12_out(offset12_EX),
    .U_out(U_EX),
    .Rn_out(Rn_EX),
    .Rm_out(Rm_EX),
    .I_out(I_EX),
    .imm32_out(imm32_EX),
    .thread_id_out(thread_id_EX)
);

assign ID_EX_MemRead = is_ldr_EX;
assign ID_EX_Rd      = Rd_EX;
assign ID_EX_thread  = thread_id_EX;

// ====================================================================
// Per-Thread CPSR Registers (4 sets of N/Z/C/V flags)
// ====================================================================
wire N_EX, Z_EX, C_EX, V_EX;
wire update_flags;

wire cpsr_N, cpsr_Z, cpsr_C, cpsr_V;

// 4 CPSR registers, indexed by thread_id_EX
reg [3:0] cpsr_N_r, cpsr_Z_r, cpsr_C_r, cpsr_V_r;

always @(posedge clk or posedge reset) begin
    if (reset) begin
        cpsr_N_r <= 4'b0; cpsr_Z_r <= 4'b0;
        cpsr_C_r <= 4'b0; cpsr_V_r <= 4'b0;
    end else if (update_flags) begin
        cpsr_N_r[thread_id_EX] <= N_EX;
        cpsr_Z_r[thread_id_EX] <= Z_EX;
        cpsr_C_r[thread_id_EX] <= C_EX;
        cpsr_V_r[thread_id_EX] <= V_EX;
    end
end

// Read CPSR for the thread currently in EX
assign cpsr_N = cpsr_N_r[thread_id_EX];
assign cpsr_Z = cpsr_Z_r[thread_id_EX];
assign cpsr_C = cpsr_C_r[thread_id_EX];
assign cpsr_V = cpsr_V_r[thread_id_EX];

// ====================================================================
// Forwarding Unit (same thread only)
// With 4-thread interleaving the forwarding unit must compare thread IDs
// to avoid forwarding from one thread to another.
// ====================================================================
wire [31:0] exmem_alu;
wire [31:0] exmem_rt;
wire [3:0]  exmem_rd;
wire        exmem_WRegEn, exmem_WMemEn, exmem_MemToReg;
wire [1:0]  exmem_thread;

wire [31:0] alu_result_WB;
wire [31:0] mem_data_WB;
wire [3:0]  Rd_WB_internal;
wire        WRegEn_WB_internal;
wire        MemToReg_WB;
wire [1:0]  thread_id_WB_internal;

assign write_data_WB = MemToReg_WB ? mem_data_WB : alu_result_WB;
assign Rd_WB         = Rd_WB_internal;
assign WRegEn_WB     = WRegEn_WB_internal;
assign thread_id_WB  = thread_id_WB_internal;

wire [1:0] forwardA, forwardB;

forwarding_unit_mt fwd (
    .ID_EX_Rs(Rn_EX),
    .ID_EX_Rt(Rm_EX),
    .ID_EX_thread(thread_id_EX),
    .EX_MEM_Rd(exmem_rd),
    .EX_MEM_RegWrite(exmem_WRegEn),
    .EX_MEM_thread(exmem_thread),
    .MEM_WB_Rd(Rd_WB_internal),
    .MEM_WB_RegWrite(WRegEn_WB_internal),
    .MEM_WB_thread(thread_id_WB_internal),
    .forwardA(forwardA),
    .forwardB(forwardB)
);

// ====================================================================
// EX Stage
// ====================================================================
wire [31:0] alu_result_EX;
wire [31:0] store_data_out;

ex_stage ex (
    .clk(clk),
    .reset(reset),
    .rs_data(rs_data_EX),
    .rt_data(rt_data_EX),
    .cond(cond_EX),
    .alu_opcode(alu_opcode_EX),
    .ALUSrc(ALUSrc_EX),
    .S_bit(S_EX),
    .is_dp(is_dp_EX),
    .is_ldr(is_ldr_EX),
    .is_str(is_str_EX),
    .is_branch(is_branch_EX),
    .is_bx(is_bx_EX),
    .branch_offset(branch_offset_EX),
    .pc_plus1(pc_plus1_EX),
    .shamt(shamt_EX),
    .store_data_out(store_data_out),
    .forwardA(forwardA),
    .forwardB(forwardB),
    .EX_MEM_alu_in(exmem_alu),
    .MEM_WB_data_in(write_data_WB),
    .I(I_EX),
    .imm32(imm32_EX),
    .offset12(offset12_EX),
    .N_in(cpsr_N),
    .Z_in(cpsr_Z),
    .C_in(cpsr_C),
    .V_in(cpsr_V),
    .Rn(Rn_EX),
    .Rm(Rm_EX),
    .alu_result(alu_result_EX),
    .branch_taken(branch_taken),
    .branch_target(branch_target),
    .N_out(N_EX),
    .Z_out(Z_EX),
    .C_out(C_EX),
    .V_out(V_EX),
    .update_flags(update_flags)
);

// Branch thread ID is captured from EX stage thread
assign branch_thread_id = thread_id_EX;

// ====================================================================
// EX/MEM Pipeline Register
// ====================================================================
EX_MEM_mt ex_mem (
    .clk(clk),
    .reset(reset),
    .alu_result_in(alu_result_EX),
    .rt_data_in(store_data_out),
    .rd_in(Rd_EX),
    .WRegEn_in(is_dp_EX | is_ldr_EX),
    .WMemEn_in(is_str_EX),
    .MemToReg_in(is_ldr_EX),
    .branch_taken_in(branch_taken),
    .branch_target_in(branch_target),
    .thread_id_in(thread_id_EX),
    .alu_result_out(exmem_alu),
    .rt_data_out(exmem_rt),
    .rd_out(exmem_rd),
    .WRegEn_out(exmem_WRegEn),
    .WMemEn_out(exmem_WMemEn),
    .MemToReg_out(exmem_MemToReg),
    .thread_id_out(exmem_thread),
    .mem_addr_out(),
    .branch_taken_out(),
    .branch_target_out()
);

// ====================================================================
// Data Memory (shared BRAM)
// ====================================================================
wire [7:0]  bram_addr   = exmem_alu[10:3];
wire        word_select  = exmem_alu[2];
wire        bram_we      = exmem_WMemEn;

wire [63:0] bram_dout;
reg  [63:0] bram_dout_reg;
reg  [63:0] bram_din;

always @(posedge clk)
    bram_dout_reg <= bram_dout;

always @(*) begin
    if (word_select == 1'b0)
        bram_din = { bram_dout_reg[63:32], exmem_rt };
    else
        bram_din = { exmem_rt, bram_dout_reg[31:0] };
end

DMem dmem (
    .clka(clk),
    .addra(bram_addr),
    .dina(bram_din),
    .douta(bram_dout),
    .wea(bram_we),
    .clkb(1'b0),
    .addrb(8'b0),
    .dinb(64'b0),
    .doutb(),
    .web(1'b0)
);

reg [31:0] mem_rdata_reg;
always @(posedge clk) begin
    if (word_select == 1'b0)
        mem_rdata_reg <= bram_dout_reg[31:0];
    else
        mem_rdata_reg <= bram_dout_reg[63:32];
end

// ====================================================================
// MEM/WB Pipeline Register
// ====================================================================
MEM_WB_mt mem_wb (
    .clk(clk),
    .reset(reset),
    .alu_result_in(exmem_alu),
    .mem_data_in(mem_rdata_reg),
    .rd_in(exmem_rd),
    .WRegEn_in(exmem_WRegEn),
    .MemToReg_in(exmem_MemToReg),
    .thread_id_in(exmem_thread),
    .alu_result_out(alu_result_WB),
    .mem_data_out(mem_data_WB),
    .rd_out(Rd_WB_internal),
    .WRegEn_out(WRegEn_WB_internal),
    .MemToReg_out(MemToReg_WB),
    .thread_id_out(thread_id_WB_internal)
);

// ====================================================================
// Debug monitors
// ====================================================================
always @(posedge clk) begin
    $display("[T%0d] PC=%0d | IF instr=%h | EX alu=%0d | WB rd=%0d data=%0d",
        current_thread, pc_out, instruction_IF,
        alu_result_EX, Rd_WB_internal, write_data_WB);
end

endmodule


//======================================================================
// Module: regfile_bram_mt
// 64-entry x 32-bit BRAM register file for 4 threads
// Address: {thread_id[1:0], reg_num[3:0]} = 6-bit address
// Reads are synchronous (output registered), writes on posedge clk
// To support 2 reads + 1 write in the same cycle, we use:
//   - Port A: Read1 (registered output)
//   - Port B: Read2 (registered output)
//   - Write: on posedge clk (to Port A when not reading on Port A)
// Since reads and write may conflict, we double-clock: 
//   write on negedge, read on posedge
//======================================================================
module regfile_bram_mt (
    input  wire        clk,
    input  wire        reset,
    input  wire        we,
    input  wire [5:0]  wr_addr,
    input  wire [31:0] wr_data,
    input  wire [5:0]  rd_addr1,
    input  wire [5:0]  rd_addr2,
    output reg  [31:0] rd_data1,
    output reg  [31:0] rd_data2
);
    // 64 x 32-bit register file
    reg [31:0] mem [0:63];
    integer i;

    // Initialize to 0
    initial begin
        for (i = 0; i < 64; i = i+1)
            mem[i] = 32'd0;
    end

    // Write on negedge (double-clocking: write in off-phase)
    always @(negedge clk) begin
        if (we)
            mem[wr_addr] <= wr_data;
    end

    // Read on posedge (registered outputs)
    always @(posedge clk) begin
        rd_data1 <= mem[rd_addr1];
        rd_data2 <= mem[rd_addr2];
    end
endmodule


//======================================================================
// Module: IF_ID_mt  (adds thread_id tracking)
//======================================================================
module IF_ID_mt (
    input  wire        clk,
    input  wire        reset,
    input  wire        write_enable,
    input  wire        flush,
    input  wire [31:0] instruction_in,
    input  wire [31:0] pc_plus1_in,
    input  wire [1:0]  thread_id_in,
    output reg  [31:0] instruction_out,
    output reg  [31:0] pc_plus1_out,
    output reg  [1:0]  thread_id_out
);
    always @(posedge clk or posedge reset) begin
        if (reset || flush) begin
            instruction_out <= 32'b0;
            pc_plus1_out    <= 32'b0;
            thread_id_out   <= 2'b0;
        end else if (write_enable) begin
            instruction_out <= instruction_in;
            pc_plus1_out    <= pc_plus1_in;
            thread_id_out   <= thread_id_in;
        end
    end
endmodule


//======================================================================
// Module: ID_EX_mt  (adds thread_id field)
//======================================================================
module ID_EX_mt (
    input  wire        clk,
    input  wire        reset,
    input  wire        flush,
    input  wire [31:0] rs_data_in, rt_data_in, pc_plus1_in,
    input  wire [3:0]  alu_opcode_in,
    input  wire        ALUSrc_in,
    input  wire [3:0]  cond_in, dp_opcode_in, Rd_in, Rn_in, Rm_in,
    input  wire [4:0]  shamt_in,
    input  wire        S_in, is_dp_in, is_ldr_in, is_str_in,
    input  wire        is_branch_in, is_bx_in,
    input  wire signed [31:0] branch_offset_in,
    input  wire [11:0] offset12_in,
    input  wire        U_in, I_in,
    input  wire [31:0] imm32_in,
    input  wire [1:0]  thread_id_in,

    output reg  [31:0] rs_data_out, rt_data_out, pc_plus1_out,
    output reg  [3:0]  alu_opcode_out,
    output reg         ALUSrc_out,
    output reg  [3:0]  cond_out, dp_opcode_out, Rd_out, Rn_out, Rm_out,
    output reg  [4:0]  shamt_out,
    output reg         S_out, is_dp_out, is_ldr_out, is_str_out,
    output reg         is_branch_out, is_bx_out,
    output reg  signed [31:0] branch_offset_out,
    output reg  [11:0] offset12_out,
    output reg         U_out, I_out,
    output reg  [31:0] imm32_out,
    output reg  [1:0]  thread_id_out
);
    always @(posedge clk or posedge reset) begin
        if (reset || flush) begin
            rs_data_out <= 0; rt_data_out <= 0; pc_plus1_out <= 0;
            alu_opcode_out <= 0; ALUSrc_out <= 0;
            cond_out <= 0; dp_opcode_out <= 0; Rd_out <= 0;
            Rn_out <= 0; Rm_out <= 0; shamt_out <= 0;
            S_out <= 0; is_dp_out <= 0; is_ldr_out <= 0;
            is_str_out <= 0; is_branch_out <= 0; is_bx_out <= 0;
            branch_offset_out <= 0; offset12_out <= 0;
            U_out <= 0; I_out <= 0; imm32_out <= 0;
            thread_id_out <= 0;
        end else begin
            rs_data_out <= rs_data_in; rt_data_out <= rt_data_in;
            pc_plus1_out <= pc_plus1_in;
            alu_opcode_out <= alu_opcode_in; ALUSrc_out <= ALUSrc_in;
            cond_out <= cond_in; dp_opcode_out <= dp_opcode_in;
            Rd_out <= Rd_in; Rn_out <= Rn_in; Rm_out <= Rm_in;
            shamt_out <= shamt_in; S_out <= S_in;
            is_dp_out <= is_dp_in; is_ldr_out <= is_ldr_in;
            is_str_out <= is_str_in; is_branch_out <= is_branch_in;
            is_bx_out <= is_bx_in; branch_offset_out <= branch_offset_in;
            offset12_out <= offset12_in; U_out <= U_in;
            I_out <= I_in; imm32_out <= imm32_in;
            thread_id_out <= thread_id_in;
        end
    end
endmodule


//======================================================================
// Module: EX_MEM_mt  (adds thread_id field)
//======================================================================
module EX_MEM_mt (
    input  wire        clk,
    input  wire        reset,
    input  wire [31:0] alu_result_in,
    input  wire [31:0] rt_data_in,
    input  wire [3:0]  rd_in,
    input  wire        WRegEn_in, WMemEn_in, MemToReg_in,
    input  wire        branch_taken_in,
    input  wire [31:0] branch_target_in,
    input  wire [1:0]  thread_id_in,

    output reg  [31:0] alu_result_out,
    output reg  [31:0] rt_data_out,
    output reg  [3:0]  rd_out,
    output reg         WRegEn_out, WMemEn_out, MemToReg_out,
    output reg  [1:0]  thread_id_out,
    output reg  [31:0] mem_addr_out,
    output reg         branch_taken_out,
    output reg  [31:0] branch_target_out
);
    always @(posedge clk or posedge reset) begin
        if (reset) begin
            alu_result_out <= 0; rt_data_out <= 0; rd_out <= 0;
            WRegEn_out <= 0; WMemEn_out <= 0; MemToReg_out <= 0;
            mem_addr_out <= 0; branch_taken_out <= 0;
            branch_target_out <= 0; thread_id_out <= 0;
        end else begin
            alu_result_out <= alu_result_in;
            rt_data_out    <= rt_data_in;
            rd_out         <= rd_in;
            WRegEn_out     <= WRegEn_in;
            WMemEn_out     <= WMemEn_in;
            MemToReg_out   <= MemToReg_in;
            mem_addr_out   <= alu_result_in;
            branch_taken_out  <= branch_taken_in;
            branch_target_out <= branch_target_in;
            thread_id_out  <= thread_id_in;
        end
    end
endmodule


//======================================================================
// Module: MEM_WB_mt  (adds thread_id field)
//======================================================================
module MEM_WB_mt (
    input  wire        clk,
    input  wire        reset,
    input  wire [31:0] alu_result_in,
    input  wire [31:0] mem_data_in,
    input  wire [3:0]  rd_in,
    input  wire        WRegEn_in, MemToReg_in,
    input  wire [1:0]  thread_id_in,

    output reg  [31:0] alu_result_out,
    output reg  [31:0] mem_data_out,
    output reg  [3:0]  rd_out,
    output reg         WRegEn_out, MemToReg_out,
    output reg  [1:0]  thread_id_out
);
    always @(posedge clk or posedge reset) begin
        if (reset) begin
            alu_result_out <= 0; mem_data_out <= 0;
            rd_out <= 0; WRegEn_out <= 0; MemToReg_out <= 0;
            thread_id_out <= 0;
        end else begin
            alu_result_out <= alu_result_in;
            mem_data_out   <= mem_data_in;
            rd_out         <= rd_in;
            WRegEn_out     <= WRegEn_in;
            MemToReg_out   <= MemToReg_in;
            thread_id_out  <= thread_id_in;
        end
    end
endmodule


//======================================================================
// Module: hdu_mt ? Multi-Thread Hazard Detection Unit
// In 4-thread interleaving, RAW hazards for the same thread across
// adjacent pipeline stages only occur when a LOAD result is needed
// by the immediately following instruction of the SAME thread.
// Since same-thread instructions are 4 cycles apart and the pipeline
// is 5 stages, only load-use on consecutive same-thread instructions
// requires a stall (1 stall cycle).
//======================================================================
module hdu_mt (
    input  wire        ID_EX_MemRead,
    input  wire [3:0]  ID_EX_Rd,
    input  wire [1:0]  ID_EX_thread,
    input  wire [1:0]  IF_ID_thread,
    input  wire [3:0]  IF_ID_Rs,
    input  wire [3:0]  IF_ID_Rt,
    output wire        PC_write,
    output wire        IF_ID_write,
    output wire        ID_EX_flush
);
    // Stall only if: same thread, load in EX, and destination matches source
    wire same_thread = (ID_EX_thread == IF_ID_thread);
    wire load_use    = ID_EX_MemRead && same_thread &&
                       ((ID_EX_Rd == IF_ID_Rs) || (ID_EX_Rd == IF_ID_Rt));

    assign PC_write    = ~load_use;
    assign IF_ID_write = ~load_use;
    assign ID_EX_flush =  load_use;
endmodule


//======================================================================
// Module: forwarding_unit_mt ? Multi-Thread Forwarding Unit
// Only forward from same thread (compare thread_id tags)
//======================================================================
module forwarding_unit_mt (
    input  wire [3:0]  ID_EX_Rs,
    input  wire [3:0]  ID_EX_Rt,
    input  wire [1:0]  ID_EX_thread,
    input  wire [3:0]  EX_MEM_Rd,
    input  wire        EX_MEM_RegWrite,
    input  wire [1:0]  EX_MEM_thread,
    input  wire [3:0]  MEM_WB_Rd,
    input  wire        MEM_WB_RegWrite,
    input  wire [1:0]  MEM_WB_thread,
    output reg  [1:0]  forwardA,
    output reg  [1:0]  forwardB
);
    wire exmem_same = (EX_MEM_thread == ID_EX_thread);
    wire memwb_same = (MEM_WB_thread == ID_EX_thread);

    always @(*) begin
        // forwardA: source is Rs (Rn)
        if (EX_MEM_RegWrite && exmem_same && (EX_MEM_Rd != 4'b0) && (EX_MEM_Rd == ID_EX_Rs))
            forwardA = 2'b10;  // from EX/MEM
        else if (MEM_WB_RegWrite && memwb_same && (MEM_WB_Rd != 4'b0) && (MEM_WB_Rd == ID_EX_Rs))
            forwardA = 2'b01;  // from MEM/WB
        else
            forwardA = 2'b00;  // no forwarding

        // forwardB: source is Rt (Rm)
        if (EX_MEM_RegWrite && exmem_same && (EX_MEM_Rd != 4'b0) && (EX_MEM_Rd == ID_EX_Rt))
            forwardB = 2'b10;
        else if (MEM_WB_RegWrite && memwb_same && (MEM_WB_Rd != 4'b0) && (MEM_WB_Rd == ID_EX_Rt))
            forwardB = 2'b01;
        else
            forwardB = 2'b00;
    end
endmodule


