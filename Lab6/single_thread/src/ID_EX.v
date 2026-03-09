`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    01:29:21 02/26/2026 
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
module ID_EX (
    input  wire         clk,
    input  wire         reset,               
    input  wire         insert_bubble,       // when 1 -> insert NOP into EX (clear control signals) -> For Stall --> Load-word Hazard

    // data inputs
    input  wire [63:0]  rs_in,
    input  wire [63:0]  rt_in,
    input  wire [63:0]  imms_ext_64_in,
    input  wire [31:0]  branch_target_in,
    input  wire [3:0]   rs_addr_in,
	input  wire [3:0]   rt_addr_in,
	input  wire [3:0]   rd_addr_in,

    // control inputs
	input  wire [5:0]   instr_opcode_in,
    input  wire         RegWrite_in,
    input  wire         MemRead_in,
    input  wire         MemWrite_in,
    input  wire         MemToReg_in,
    input  wire         ALUSrc_in,
    input  wire         Branch_in,
    input  wire         Jump_in,
    input  wire [3:0]   ALUOp_in,

    // data outputs
    output reg  [63:0]  rs_out,
    output reg  [63:0]  rt_out,
    output reg  [63:0]  imms_ext_64_out,
    output reg  [31:0]  branch_target_out,
    output reg  [3:0]   rs_addr_out,
	output reg  [3:0]   rt_addr_out,
	output reg  [3:0]   rd_addr_out,

    // control outputs
	output reg [5:0]   instr_opcode_out,
    output reg          RegWrite_out,
    output reg          MemRead_out,
    output reg          MemWrite_out,
    output reg          MemToReg_out,
    output reg          ALUSrc_out,
    output reg          Branch_out,
    output reg          Jump_out,
    output reg  [3:0]   ALUOp_out
);

always @(posedge clk) begin
    if (reset) begin
        // clear data
        rs_out            <= 64'd0;
        rt_out            <= 64'd0;
        imms_ext_64_out   <= 64'd0;
        branch_target_out <= 32'd0;
        rs_addr_out       <= 4'd0;
		rt_addr_out       <= 4'd0;
		rd_addr_out       <= 4'd0;
        // clear control
        RegWrite_out <= 1'b0;
        MemRead_out  <= 1'b0;
        MemWrite_out <= 1'b0;
        MemToReg_out <= 1'b0;
        ALUSrc_out   <= 1'b0;
        Branch_out   <= 1'b0;
        Jump_out     <= 1'b0;
        ALUOp_out    <= 4'd0;
		instr_opcode_out <= 6'd0;
    end
    else if (insert_bubble) begin
        // insert bubble: clear control signals (data cleared too for cleanliness)
        rs_out            <= 64'd0;
        rt_out            <= 64'd0;
        imms_ext_64_out   <= 64'd0;
        branch_target_out <= 32'd0;
        rs_addr_out       <= 4'd0;
		rt_addr_out       <= 4'd0;
		rd_addr_out       <= 4'd0;
        RegWrite_out <= 1'b0;
        MemRead_out  <= 1'b0;
        MemWrite_out <= 1'b0;
        MemToReg_out <= 1'b0;
        ALUSrc_out   <= 1'b0;
        Branch_out   <= 1'b0;
        Jump_out     <= 1'b0;
        ALUOp_out    <= 4'd0;
		instr_opcode_out <= 6'd0;
    end
    else begin
        rs_out            <= rs_in;
        rt_out            <= rt_in;
        imms_ext_64_out   <= imms_ext_64_in;
        branch_target_out <= branch_target_in;
        rs_addr_out       <= rs_addr_in;
		rt_addr_out       <= rt_addr_in;
		rd_addr_out       <= rd_addr_in;
        RegWrite_out <= RegWrite_in;
        MemRead_out  <= MemRead_in;
        MemWrite_out <= MemWrite_in;
        MemToReg_out <= MemToReg_in;
        ALUSrc_out   <= ALUSrc_in;
        Branch_out   <= Branch_in;
        Jump_out     <= Jump_in;
        ALUOp_out    <= ALUOp_in;
		instr_opcode_out <= instr_opcode_in;
    end
end

endmodule
