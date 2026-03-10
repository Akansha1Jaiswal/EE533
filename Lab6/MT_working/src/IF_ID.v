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
    //input  wire        if_id_write,   // stall control - from HDU in ID
    //input  wire        if_id_flush,   // branch flush - from BU in EX
    input  wire [31:0] pc_plus4_in,
    //input  wire [31:0] instr_in,
	input  wire [1:0]  IF_thread_id,
	
    output reg  [31:0] pc_plus4_out,
	output reg  [31:0] pc_out,
	output reg [1:0]  ID_thread_id
    //output wire [31:0] instr_out
	);

always @(posedge clk) begin
    if (reset) begin
        pc_plus4_out <= 32'd0;
		ID_thread_id <= 2'd0;
        //instr_out    <= 32'd0;
    end
    else begin      
        pc_plus4_out <= pc_plus4_in;
		ID_thread_id <= IF_thread_id;
        //instr_out    <= instr_in;
    end	  
end

endmodule
