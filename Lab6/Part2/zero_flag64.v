`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    23:14:42 02/11/2026 
// Design Name: 
// Module Name:    zero_flag64 
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
module zero_flag32(
    input  [31:0] result,
    output zero_flag
);

    wire [15:0] l1;
    wire [7:0]  l2;
    wire [3:0]  l3;
    wire [1:0]  l4;
    wire any_one;

    genvar i;

    // Level 1: 32 -> 16
    generate
        for (i=0; i<16; i=i+1) begin : lvl1
            or g (l1[i], result[2*i], result[2*i+1]);
        end
    endgenerate

    // Level 2: 16 -> 8
    generate
        for (i=0; i<8; i=i+1) begin : lvl2
            or g (l2[i], l1[2*i], l1[2*i+1]);
        end
    endgenerate

    // Level 3: 8 -> 4
    generate
        for (i=0; i<4; i=i+1) begin : lvl3
            or g (l3[i], l2[2*i], l2[2*i+1]);
        end
    endgenerate

    // Level 4: 4 -> 2
    generate
        for (i=0; i<2; i=i+1) begin : lvl4
            or g (l4[i], l3[2*i], l3[2*i+1]);
        end
    endgenerate

    // Final reduction: 2 -> 1
    or g5 (any_one, l4[0], l4[1]);

    not g6 (zero_flag, any_one);

endmodule