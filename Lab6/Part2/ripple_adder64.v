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
module ripple_adder32(
    input  [31:0] a,
    input  [31:0] b,
    input         binv,
    input         cin,
    output [31:0] sum,
    output        cout,
    output        carry_31
);

    wire [31:0] b_mod;
    wire [32:0] carry;

    assign carry[0] = cin;

    genvar i;

    generate
        for(i=0; i<32; i=i+1) begin : invert_block
            xor (b_mod[i], b[i], binv);
        end
    endgenerate

    generate
        for(i=0; i<32; i=i+1) begin : adder_chain
            full_adder FA (
                a[i],
                b_mod[i],
                carry[i],
                sum[i],
                carry[i+1]
            );
        end
    endgenerate

    assign cout     = carry[32];
    assign carry_31 = carry[31];

endmodule