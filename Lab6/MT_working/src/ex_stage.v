`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    01:28:01 02/26/2026 
// Design Name: 
// Module Name:    ex_stage 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module ex_stage (
    // ID/EX inputs 
    input  wire [63:0] ID_EX_rs,
    input  wire [63:0] ID_EX_rt,
    input  wire [3:0]  ID_EX_rs_addr,
    input  wire [3:0]  ID_EX_rt_addr,
    input  wire [3:0]  ID_EX_rd,
    input  wire [63:0] ID_EX_imms_ext_64,
    input  wire [31:0] ID_EX_branch_target,
    input  wire [3:0]  ID_EX_ALUOp,
    input  wire        ID_EX_ALUSrc,
    input  wire        ID_EX_Branch,
    input  wire [5:0]  ID_EX_instr_opcode,

    // Outputs to EX/MEM register 
    output wire [63:0] EX_alu_result,
    output wire [63:0] EX_rt_for_store,
    output wire [3:0]  EX_dest_reg,

    // Branch outputs 
    output wire        pc_src_branch,
    output wire [31:0] branch_target_out
);

    // Operands: no forwarding, using ID/EX values directly
    wire [63:0] operandA;
    wire [63:0] operandB;

    assign operandA = ID_EX_rs;
    assign operandB = (ID_EX_ALUSrc == 1'b1) ? ID_EX_rt : ID_EX_imms_ext_64;

    // ALU Output Flags
    wire zero_flag;
    wire less_than_flag;
    wire greater_equal_flag;
    wire less_equal_flag;

    // ALU
    ALU alu_inst (
        .A(operandA),
        .B(operandB),
        .ALUOp(ID_EX_ALUOp),
        .result(EX_alu_result),
        .zero(zero_flag),
        .less_than(less_than_flag),
        .greater_equal(greater_equal_flag),
        .less_equal(less_equal_flag)
    );

    // Branch Unit 
    wire branch_taken;
    branch_unit branch_inst (
        .Branch(ID_EX_Branch),
        .instr_opcode(ID_EX_instr_opcode),
        .less_than(less_than_flag),
        .greater_equal(greater_equal_flag),
        .less_equal(less_equal_flag),
        .branch_taken(branch_taken)
    );

    assign pc_src_branch     = branch_taken;
    assign branch_target_out = ID_EX_branch_target;

    // Store data (no forwarding)
    assign EX_rt_for_store = ID_EX_rt;

    // Destination register
    assign EX_dest_reg = ID_EX_rd;

endmodule