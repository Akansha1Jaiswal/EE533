`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    20:51:53 02/20/2026 
// Design Name: 
// Module Name:    branch_unit 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
// Branch decision + target calculation unit
//
// Inputs:
//   cond           -> instruction condition field
//   N,Z,C,V        -> CPSR flags
//   is_branch      -> B / BLE / BGE
//   is_bx          -> BX instruction
//   branch_offset  -> signed word offset (already sign-extended)
//   pc_plus1       -> PC+1 (word addressed)
//   bx_reg_value   -> register value for BX
//
// Outputs:
//   branch_taken
//   branch_target
//
// Notes:
//   - Word-addressed PC design (no <<2 shift)
//   - Branch target = pc_plus1 + offset
//   - BX target = register value
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module branch_unit(
    input  wire [3:0]  cond,
    input  wire        N,
    input  wire        Z,
    input  wire        C,
    input  wire        V,
    input  wire        is_branch,
    input  wire        is_bx,
    input  wire signed [31:0] branch_offset,
    input  wire [31:0] pc_plus1,
    input  wire [31:0] bx_reg_value,

    output wire        branch_taken,
    output wire [31:0] branch_target
    );

    // Condition Evaluation
    wire cond_ok;

    cond_eval COND(
        .cond(cond),
        .N(N),
        .Z(Z),
        .C(C),
        .V(V),
        .cond_true(cond_ok)
    );

    // Target Calculation
    wire [31:0] branch_target_calc;
    assign branch_target_calc = pc_plus1 + branch_offset;

    // Branch Decision
    assign branch_taken = cond_ok & (is_branch | is_bx);
    assign branch_target = is_bx ? bx_reg_value : branch_target_calc;

endmodule


