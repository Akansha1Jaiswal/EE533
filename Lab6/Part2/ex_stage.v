`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    20:38:04 02/20/2026 
// Design Name: 
// Module Name:    ex_stage 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
// Responsibilities:
//  - Compute ALU result
//  - Generate flags (N Z C V)
//  - Evaluate condition field
//  - Update CPSR if needed
//  - Decide branch
//  - Compute branch target (word-addressed PC)
//  - Gate control signals based on condition
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
`timescale 1ns / 1ps
module ex_stage(
    input  wire        clk,
    input  wire        reset,

    // From ID/EX
    input  wire [31:0] rs_data,
    input  wire [31:0] rt_data,
    input  wire [3:0]  cond,
    input  wire [3:0]  alu_opcode,   // pipelined clean opcode from control unit
    input  wire        ALUSrc,       // choose immediate/offset vs register
    input  wire        S_bit,
    input  wire        is_dp,
    input  wire        is_ldr,
    input  wire        is_str,
    input  wire        is_branch,
    input  wire        is_bx,
    input  wire [31:0] branch_offset,
    input  wire [31:0] pc_plus1,
    input  wire [4:0]  shamt,
    input  wire        I,
    input  wire [31:0] imm32,

    // CPSR flags input (current flags)
    input  wire        N_in,
    input  wire        Z_in,
    input  wire        C_in,
    input  wire        V_in,

    input  wire [3:0]  Rn,
    input  wire [3:0]  Rm,

    input  wire [11:0] offset12,
    input  wire        U,             // optional, kept for clarity

    // forwarding controls & forwarded values
    input  wire [1:0] forwardA,
    input  wire [1:0] forwardB,
    input  wire [31:0] EX_MEM_alu_in,    // alu result from EX/MEM
    input  wire [31:0] MEM_WB_data_in,   // value being written back (write_data_WB)

    output wire [31:0] alu_result,
    output wire        branch_taken,
    output wire [31:0] branch_target,
    output wire [31:0] store_data_out,
    output wire        N_out,
    output wire        Z_out,
    output wire        C_out,
    output wire        V_out,
    output wire        update_flags
    );

    // ---------- forwarding & operands ----------
    wire [31:0] alu_A_raw = (forwardA == 2'b01) ? EX_MEM_alu_in :
                            (forwardA == 2'b10) ? MEM_WB_data_in :
                                                  rs_data;

    // ARM PC read = PC_word + 2 (you use word addressing)
    wire [31:0] pc_word_plus2 = pc_plus1 + 32'd1;

    wire [31:0] alu_A = (Rn == 4'd15) ? pc_word_plus2 : alu_A_raw;

    wire [31:0] rt_fwd = (forwardB == 2'b01) ? EX_MEM_alu_in :
                         (forwardB == 2'b10) ? MEM_WB_data_in :
                                               rt_data;

    assign store_data_out = rt_fwd;

    // ---------- operand2 selection ----------
    wire [31:0] offset_ext = {20'b0, offset12}; // zero-extend offset12 (plain LDR/STR offset)
    wire [31:0] alu_B;

    // If ALUSrc==1 prefer DP-immediate when is_dp & I, otherwise use offset_ext (for mem/branch)
    assign alu_B = (ALUSrc) ? ((is_dp & I) ? imm32 : offset_ext) : rt_fwd;

    // ---------- ALU ----------
    wire [3:0] effective_opcode = alu_opcode; // just pass-through

    alu32 ALU(
        .A(alu_A),
        .B(alu_B),
        .opcode(effective_opcode),
        .shamt(shamt),
        .result(alu_result),
        .zero_flag(Z_out),
        .Cout(C_out),
        .overflow_flag(V_out),
        .neg_flag(N_out)
    );

    // ---------- condition evaluation ----------
    wire cond_ok;
    cond_eval COND(
        .cond(cond),
        .N(N_in),
        .Z(Z_in),
        .C(C_in),
        .V(V_in),
        .cond_true(cond_ok)
    );

    // ---------- branch logic ----------
    wire [31:0] branch_target_calc = pc_plus1 + 32'd1 + branch_offset;
    wire [31:0] bx_target = (Rm == 4'd15) ? pc_word_plus2 : alu_A_raw;

    assign branch_taken = cond_ok & (is_branch | is_bx);
    assign branch_target = is_bx ? bx_target : branch_target_calc;

    // ---------- flags update control ----------
    assign update_flags = cond_ok & (is_dp & S_bit);
// ================= EX DEBUG =================
always @(posedge clk) begin
    $display("------------------------------------------------");
    $display("[EX] t=%0t", $time);

    $display("  cond=%b  cond_ok=%b  is_dp=%b  is_ldr=%b  is_str=%b  is_branch=%b  is_bx=%b",
             cond, cond_ok, is_dp, is_ldr, is_str, is_branch, is_bx);

    $display("  alu_opcode=%b  ALUSrc=%b  S_bit=%b",
             alu_opcode, ALUSrc, S_bit);

    $display("  Rn=%0d  Rm=%0d  I=%b  imm32=%h  offset12=%h  U=%b",
             Rn, Rm, I, imm32, offset12, U);

    $display("  forwardA=%b  forwardB=%b",
             forwardA, forwardB);

    $display("  rs_data=%h  rt_data=%h",
             rs_data, rt_data);

    $display("  EX_MEM_alu_in=%h  MEM_WB_data_in=%h",
             EX_MEM_alu_in, MEM_WB_data_in);

    $display("  alu_A=%h  alu_B=%h",
             alu_A, alu_B);

    $display("  alu_result=%h",
             alu_result);

    $display("  store_data_out=%h",
             store_data_out);

    $display("  N=%b Z=%b C=%b V=%b",
             N_out, Z_out, C_out, V_out);
end
// ============================================
 
endmodule