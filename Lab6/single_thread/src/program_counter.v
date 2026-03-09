`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    01:23:14 02/26/2026 
// Design Name: 
// Module Name:    program_counter 
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
module program_counter (
    input  wire        clk,
    input  wire        reset,
	// Control signals (will come from later stages)
    input  wire        pc_write,        // stall control - from hazard unit (pc_write == 0 --> stall)
    input  wire        pc_src_branch,   // branch select - branch taken (pc_src_branch == 1)
    input  wire        pc_src_jump,     // jump select - jump (pc_src_jump == 1)
    input  wire [31:0] branch_target,   // comes from ALU (EX stage) : same signal also goes to branch unit
    input  wire [31:0] jump_target,     // comes from ALU (EX Stage)
	
    output reg  [31:0] pc
	);

wire [31:0] pc_next;

// Default next PC
wire [31:0] pc_plus4;
assign pc_plus4 = pc + 32'd4;

// Next PC selection : Priority order --> Jump > Branch > Next Instruction
assign pc_next = (pc_src_jump) ? jump_target : (pc_src_branch) ? branch_target : pc_plus4;

// PC register
always @(posedge clk) begin
    if (reset)
        pc <= 32'd0;
    else if (pc_write)
        pc <= pc_next;
end

endmodule
