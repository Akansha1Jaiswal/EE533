`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    18:58:23 02/12/2026 
// Design Name: 
// Module Name:    IF_ID 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
// Stores:
//   - instruction
//   - PC+1 (word-addressed)
//
// Supports:
//   - write_enable (stall)
//   - flush (branch)
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module IF_ID(
    input clk,
    input reset,
    input write_enable,
    input flush,
    input [31:0] instruction_in,
    input [31:0] pc_plus1_in,
	 
    output reg [31:0] instruction_out,
    output reg [31:0] pc_plus1_out
);

localparam NOP = 32'hE1A00000;

wire [31:0] inst_d;
wire [31:0] pc_d;

assign inst_d = flush ? NOP      : instruction_in;
assign pc_d   = flush ? 32'b0    : pc_plus1_in;

always @(posedge clk) begin
    if (reset) begin
        instruction_out <= 32'b0;
        pc_plus1_out    <= 32'b0;
    end
    else if (write_enable) begin
        instruction_out <= inst_d;
        pc_plus1_out    <= pc_d;
    end
end

endmodule
