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
module ex_stage(
    input  wire        clk,
    input  wire        reset,

    // From ID/EX
    input  wire [31:0] rs_data,
    input  wire [31:0] rt_data,
    input  wire [3:0]  cond,
    input  wire [3:0]  alu_opcode,
    input  wire        ALUSrc,
    input  wire        S_bit,
    input  wire        is_dp,
    input  wire        is_ldr,
    input  wire        is_str,
    input  wire        is_branch,
    input  wire        is_bx,
    input  wire signed [31:0] branch_offset,
    input  wire [31:0] pc_plus1,   // = PC + 4 (byte-addressed)
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
    input  wire        U,

    // forwarding controls & forwarded values
    input  wire [1:0] forwardA,
    input  wire [1:0] forwardB,
    input  wire [31:0] EX_MEM_alu_in,
    input  wire [31:0] MEM_WB_data_in,

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

    // rt forwarded value (used both for ALU B and as Rm fallback for BX)
    wire [31:0] rt_fwd = (forwardB == 2'b01) ? EX_MEM_alu_in :
                         (forwardB == 2'b10) ? MEM_WB_data_in :
                                               rt_data;

    assign store_data_out = rt_fwd;

    // ---------- PC-as-operand (byte-addressed convention) ----------
    // pc_plus1 is PC + 4 (byte-addressed). ARM gives PC-as-operand = PC + 8.
    wire [31:0] pc_as_operand = pc_plus1 + 32'd4;

    // If Rn==15 use PC+8, else forwarded/reg value.
    wire [31:0] alu_A = (Rn === 4'd15) ? pc_as_operand : alu_A_raw;

    // ---------- operand2 selection ----------
    wire [31:0] offset_ext = {20'b0, offset12};

    wire use_imm32 = (ALUSrc === 1'b1) && (is_dp === 1'b1) && (I === 1'b1);
    wire use_offset = (ALUSrc === 1'b1) && !(use_imm32);

    wire [31:0] alu_B = use_imm32 ? imm32 :
                        use_offset ? offset_ext :
                                     rt_fwd;

    // ---------- ALU ----------
    wire [3:0] effective_opcode = alu_opcode;

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

    // ---------- branch logic (byte-addressed PC) ----------
    // branch_target = PC + 8 + (branch_offset << 2)
    // pc_plus1 = PC + 4  =>  PC + 8 = pc_plus1 + 4
    wire signed [31:0] branch_target_calc_signed = $signed(pc_plus1) + 32'sd4 + ($signed(branch_offset));
    wire [31:0] branch_target_calc = branch_target_calc_signed;

    // BX target uses forwarded rt (rt_fwd). If Rm==15 use PC+8.
    wire [31:0] rm_raw = rt_fwd;
    wire [31:0] bx_target = (Rm === 4'd15) ? pc_as_operand : rm_raw;

    assign branch_taken = (cond_ok === 1'b1) && (is_branch || is_bx);
    assign branch_target = (is_bx) ? bx_target : branch_target_calc;

    // ---------- flags update control ----------
    assign update_flags = (cond_ok === 1'b1) && (is_dp && S_bit);

endmodule