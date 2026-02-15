`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    23:11:13 02/11/2026 
// Design Name: 
// Module Name:    equal16 
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
module equal16(
    input  [15:0] A,
    input  [15:0] B,
    output eq
    );

    wire [15:0] x;
    wire [7:0] l1;
    wire [3:0] l2;
    wire [1:0] l3;

    genvar i;

    generate
        for(i=0;i<16;i=i+1) begin : xnor_stage
            xnor (x[i], A[i], B[i]);
        end
    endgenerate

    generate
        for(i=0;i<8;i=i+1) begin : l1_stage
            and (l1[i], x[2*i], x[2*i+1]);
        end
    endgenerate

    generate
        for(i=0;i<4;i=i+1) begin : l2_stage
            and (l2[i], l1[2*i], l1[2*i+1]);
        end
    endgenerate

    and (l3[0], l2[0], l2[1]);
    and (l3[1], l2[2], l2[3]);

    and (eq, l3[0], l3[1]);

endmodule
