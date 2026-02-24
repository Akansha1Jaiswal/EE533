`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    22:30:41 02/20/2026 
// Design Name: 
// Module Name:    cond_eval 
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
module cond_eval(
    input  [3:0] cond,
    input        N,
    input        Z,
    input        C,
    input        V,
    output reg   cond_true
    );

always @(*) begin
    case(cond)
        4'b0000: cond_true = Z;                // EQ
        4'b0001: cond_true = ~Z;               // NE
        4'b1010: cond_true = (N == V);         // GE
        4'b1011: cond_true = (N != V);         // LT
        4'b1100: cond_true = (~Z) & (N == V);  // GT
        4'b1101: cond_true = Z | (N != V);     // LE
        4'b1110: cond_true = 1'b1;             // AL
        default: cond_true = 1'b0;
    endcase
end

endmodule
