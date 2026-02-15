`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    23:08:03 02/11/2026 
// Design Name: 
// Module Name:    ripple_adder64 
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
module ripple_adder64(
    input  [63:0] a,
    input  [63:0] b,
    input  binv,
    input  cin,
    output [63:0] sum,
    output cout,
    output carry_63
    );

    wire [63:0] b_mod;
    wire [64:0] carry;

    assign carry[0] = cin;

    genvar i;

    // Conditional invert of B
    generate
        for(i=0;i<64;i=i+1) begin : invert_block
            xor (b_mod[i], b[i], binv);
        end
    endgenerate

    // 64 full adders
    generate
        for(i=0;i<64;i=i+1) begin : adder_chain
            full_adder FA(
                a[i],
                b_mod[i],
                carry[i],
                sum[i],
                carry[i+1]
            );
        end
    endgenerate

    assign cout = carry[64];
    assign carry_63 = carry[63];

endmodule
