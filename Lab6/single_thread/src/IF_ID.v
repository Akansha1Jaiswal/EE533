`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    01:29:57 02/26/2026 
// Design Name: 
// Module Name:    IF_ID 
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
module IF_ID (
    input  wire        clk,
    input  wire        reset,
    input  wire        if_id_write,   // stall control - from HDU in ID
    input  wire        if_id_flush,   // branch flush - from BU in EX
    input  wire [31:0] pc_plus4_in,
	 input  wire [31:0] pc_in,
    input  wire [31:0] instr_in,
    output reg  [31:0] pc_plus4_out,
	 output reg  [31:0] pc_out,
    output wire  [31:0] instr_out
	);
 
reg if_id_flush_reg;

//Priority order --> reset > flush > write (if_id_write == 1) > hold (if_id_write == 0)

always @(posedge clk) begin
    if (reset) begin
        pc_plus4_out <= 32'd0;
		  pc_out <= 32'd0;
        //instr_out    <= 32'd0;
    end
    else if (if_id_flush) begin      // Stalling from Branch taken given priority
        pc_plus4_out <= 32'd0;
		  pc_out <= 32'd0;
        //instr_out    <= 32'd0;
    end
    else if (if_id_write) begin      // 0 for stall from load_word hazard and 1 for no stall
        pc_plus4_out <= pc_plus4_in;
		  pc_out <= pc_in;
        //instr_out    <= instr_in;
    end	  
end

always @(posedge clk) begin
	  if (reset) 
		  if_id_flush_reg <= 1'b0;
	  else
	     if_id_flush_reg <= if_id_flush;
end
	  
localparam [31:0] NOP = 32'd0;

assign instr_out = (if_id_flush_reg) ? NOP : instr_in;

endmodule
