`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    18:36:28 02/20/2026 
// Design Name: 
// Module Name:    mux16to1_32 
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

//////////////////////////////////////////////////////////////////////////////////
module mux16to1_32(
    input  [31:0] in0,
    input  [31:0] in1,
    input  [31:0] in2,
    input  [31:0] in3,
    input  [31:0] in4,
    input  [31:0] in5,
    input  [31:0] in6,
    input  [31:0] in7,
    input  [31:0] in8,
    input  [31:0] in9,
    input  [31:0] in10,
    input  [31:0] in11,
    input  [31:0] in12,
    input  [31:0] in13,
    input  [31:0] in14,
    input  [31:0] in15,
    input  [3:0]  sel,
    output reg [31:0] y
	 );

always @(*) begin
    case (sel)
        4'd0:  y = in0;
        4'd1:  y = in1;
        4'd2:  y = in2;
        4'd3:  y = in3;
        4'd4:  y = in4;
        4'd5:  y = in5;
        4'd6:  y = in6;
        4'd7:  y = in7;
        4'd8:  y = in8;
        4'd9:  y = in9;
        4'd10: y = in10;
        4'd11: y = in11;
        4'd12: y = in12;
        4'd13: y = in13;
        4'd14: y = in14;
        4'd15: y = in15;
        default: y = 32'b0;
    endcase
end

endmodule