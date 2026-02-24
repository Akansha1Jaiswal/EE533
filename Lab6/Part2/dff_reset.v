`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    20:58:23 02/12/2026 
// Design Name: 
// Module Name:    dff_reset 
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
module dff_reset(
    input clk,
    input D,
	 input reset,
    output Q
    );

    reg Q_reg;

    always @(posedge clk)
	 if (reset)
        Q_reg <= 0;
	 else
	 
		  Q_reg <= D;
		  
    assign Q = Q_reg;

endmodule
