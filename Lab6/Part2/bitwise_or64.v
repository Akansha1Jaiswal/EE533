`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    23:09:25 02/11/2026 
// Design Name: 
// Module Name:    bitwise_or64 
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
module bitwise_or32(
    input  [31:0] A,
    input  [31:0] B,
    output [31:0] Y
    );

    genvar i;
    generate
        for(i=0;i<32;i=i+1) begin : or_block
            or (Y[i], A[i], B[i]);
        end
    endgenerate

endmodule
