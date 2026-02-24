`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    19:01:09 02/12/2026 
// Design Name: 
// Module Name:    ID_EX 
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

module ID_EX(
    input  wire        clk,
    input  wire        reset,
    input  wire        flush,

    input  wire [31:0] rs_data_in,
    input  wire [31:0] rt_data_in,
    input  wire [31:0] pc_plus1_in,

    input  wire [3:0]  cond_in,
    input  wire [3:0]  dp_opcode_in,
    input  wire        S_in,
    input  wire        is_dp_in,
    input  wire        is_ldr_in,
    input  wire        is_str_in,
    input  wire        is_branch_in,
    input  wire        is_bx_in,
    input  wire signed [31:0] branch_offset_in,
    input  wire [3:0]  Rd_in,
    input  wire [4:0]  shamt_in,
    input  wire        I_in,
    input  wire [31:0] imm32_in,
    input  wire [3:0]  Rn_in,
    input  wire [3:0]  Rm_in,

    input  wire [11:0] offset12_in,
    input  wire        U_in,
    input  wire [3:0]  alu_opcode_in,
    input  wire        ALUSrc_in,

    output reg  [3:0]  alu_opcode_out,
    output reg         ALUSrc_out,

    output reg  [11:0] offset12_out,
    output reg         U_out,

    output reg  [3:0]  Rn_out,
    output reg  [3:0]  Rm_out,
    output reg         I_out,
    output reg  [31:0] imm32_out,
    output reg  [31:0] rs_data_out,
    output reg  [31:0] rt_data_out,
    output reg  [31:0] pc_plus1_out,

    output reg  [3:0]  cond_out,
    output reg  [3:0]  dp_opcode_out,
    output reg         S_out,
    output reg         is_dp_out,
    output reg         is_ldr_out,
    output reg         is_str_out,
    output reg         is_branch_out,
    output reg         is_bx_out,
    output reg signed [31:0] branch_offset_out,
    output reg  [3:0]  Rd_out,
    output reg  [4:0]  shamt_out
);

always @(posedge clk) begin
    if (reset) begin
        rs_data_out        <= 32'b0;
        rt_data_out        <= 32'b0;
        pc_plus1_out       <= 32'b0;

        cond_out           <= 4'b0;
        dp_opcode_out      <= 4'b0;
        S_out              <= 1'b0;
        is_dp_out          <= 1'b0;
        is_ldr_out         <= 1'b0;
        is_str_out         <= 1'b0;
        is_branch_out      <= 1'b0;
        is_bx_out          <= 1'b0;
        branch_offset_out  <= 32'b0;
        Rd_out             <= 4'b0;
        shamt_out          <= 5'b0;

        I_out              <= 1'b0;
        imm32_out          <= 32'b0;
        Rn_out             <= 4'b0;
        Rm_out             <= 4'b0;

        offset12_out       <= 12'b0;
        U_out              <= 1'b0;

        alu_opcode_out     <= 4'b0;
        ALUSrc_out         <= 1'b0;
    end
    else if (flush) begin
        rs_data_out        <= 32'b0;
        rt_data_out        <= 32'b0;
        pc_plus1_out       <= 32'b0;

        cond_out           <= 4'b1110;   // same as your original flush behavior
        dp_opcode_out      <= 4'b0;
        S_out              <= 1'b0;
        is_dp_out          <= 1'b0;
        is_ldr_out         <= 1'b0;
        is_str_out         <= 1'b0;
        is_branch_out      <= 1'b0;
        is_bx_out          <= 1'b0;
        branch_offset_out  <= 32'b0;
        Rd_out             <= 4'b0;
        shamt_out          <= 5'b0;

        I_out              <= 1'b0;
        imm32_out          <= 32'b0;
        Rn_out             <= 4'b0;
        Rm_out             <= 4'b0;

        offset12_out       <= 12'b0;
        U_out              <= 1'b0;

        alu_opcode_out     <= 4'b0;
        ALUSrc_out         <= 1'b0;
    end
    else begin
        rs_data_out        <= rs_data_in;
        rt_data_out        <= rt_data_in;
        pc_plus1_out       <= pc_plus1_in;

        cond_out           <= cond_in;
        dp_opcode_out      <= dp_opcode_in;
        S_out              <= S_in;
        is_dp_out          <= is_dp_in;
        is_ldr_out         <= is_ldr_in;
        is_str_out         <= is_str_in;
        is_branch_out      <= is_branch_in;
        is_bx_out          <= is_bx_in;
        branch_offset_out  <= branch_offset_in;
        Rd_out             <= Rd_in;
        shamt_out          <= shamt_in;

        I_out              <= I_in;
        imm32_out          <= imm32_in;
        Rn_out             <= Rn_in;
        Rm_out             <= Rm_in;

        offset12_out       <= offset12_in;
        U_out              <= U_in;

        alu_opcode_out     <= alu_opcode_in;
        ALUSrc_out         <= ALUSrc_in;
    end
end

endmodule