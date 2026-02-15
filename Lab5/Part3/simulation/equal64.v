`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    23:11:57 02/11/2026 
// Design Name: 
// Module Name:    equal64 
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
module equal64(
    input  [63:0] A,
    input  [63:0] B,
    output eq
    );

    wire [63:0] x;
    wire [31:0] l1;
    wire [15:0] l2;
    wire [7:0]  l3;
    wire [3:0]  l4;
    wire [1:0]  l5;

    genvar i;

    generate
        for(i=0;i<64;i=i+1) begin
            xnor (x[i], A[i], B[i]);
        end
    endgenerate

    generate
        for(i=0;i<32;i=i+1) begin
            and (l1[i], x[2*i], x[2*i+1]);
        end
    endgenerate

    generate
        for(i=0;i<16;i=i+1) begin
            and (l2[i], l1[2*i], l1[2*i+1]);
        end
    endgenerate

    generate
        for(i=0;i<8;i=i+1) begin
            and (l3[i], l2[2*i], l2[2*i+1]);
        end
    endgenerate

    generate
        for(i=0;i<4;i=i+1) begin
            and (l4[i], l3[2*i], l3[2*i+1]);
        end
    endgenerate

    and (l5[0], l4[0], l4[1]);
    and (l5[1], l4[2], l4[3]);

    and (eq, l5[0], l5[1]);

endmodule
