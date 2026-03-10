`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    01:27:24 02/26/2026 
// Design Name: 
// Module Name:    EX_MEM 
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
module EX_MEM (
    input  wire         clk,
    input  wire         reset,

    // Inputs from EX stage 
    input  wire [63:0]  alu_result_in,
    input  wire [63:0]  rt_for_store_in,
    input  wire [3:0]   rd_in,
	input  wire [1:0]   EX_thread_id,

    input  wire         RegWrite_in,
    input  wire         MemRead_in,
    input  wire         MemWrite_in,
    input  wire         MemToReg_in,

    // Outputs to MEM stage
    output reg  [63:0]  alu_result_out,
    output reg  [63:0]  rt_for_store_out,
    output reg  [3:0]   rd_out,
	output reg  [1:0]   MEM_thread_id,

    output reg          RegWrite_out,
    output reg          MemRead_out,
    output reg          MemWrite_out,
    output reg          MemToReg_out
);

always @(posedge clk) begin
    if (reset) begin
        alu_result_out   <= 64'd0;
        rt_for_store_out <= 64'd0;
        rd_out           <= 4'd0;
		MEM_thread_id    <= 2'd0;

        RegWrite_out <= 1'b0;
        MemRead_out  <= 1'b0;
        MemWrite_out <= 1'b0;
        MemToReg_out <= 1'b0;
    end
    else begin
        alu_result_out   <= alu_result_in;
        rt_for_store_out <= rt_for_store_in;
        rd_out           <= rd_in;
		MEM_thread_id    <= EX_thread_id;

        RegWrite_out <= RegWrite_in;
        MemRead_out  <= MemRead_in;
        MemWrite_out <= MemWrite_in;
        MemToReg_out <= MemToReg_in;
    end
end

endmodule
