`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    23:16:58 02/11/2026 
// Design Name: 
// Module Name:    slt_signed 
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
module slt_signed(
    input  sub_msb,
    input  overflow_flag,
    output SLT
    );
	 
    xor g1 (SLT, sub_msb, overflow_flag);

endmodule
