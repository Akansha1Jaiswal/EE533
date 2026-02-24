`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    23:12:39 02/11/2026 
// Design Name: 
// Module Name:    barrel_left_64 
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
module barrel_left_32(
    input  [31:0] in,
    input  [4:0] shamt,
    output [31:0] out,
	 output carry_out
    );

    wire [31:0] s1,s2,s4,s8,s16;

    genvar i;

    // Shift by 1
    generate
        for(i=0;i<32;i=i+1) begin :shift_1
            assign s1[i] = shamt[0] ? (i==0 ? 1'b0 : in[i-1]) : in[i];
        end
    endgenerate

    // Shift by 2
    generate
        for(i=0;i<32;i=i+1) begin :shift_2
            assign s2[i] = shamt[1] ? (i<2 ? 1'b0 : s1[i-2]) : s1[i];
        end
    endgenerate

    // Shift by 4
    generate
        for(i=0;i<32;i=i+1) begin :shift_4
            assign s4[i] = shamt[2] ? (i<4 ? 1'b0 : s2[i-4]) : s2[i];
        end
    endgenerate

    // Shift by 8
    generate
        for(i=0;i<32;i=i+1) begin :shift_8
            assign s8[i] = shamt[3] ? (i<8 ? 1'b0 : s4[i-8]) : s4[i];
        end
    endgenerate

    // Shift by 16
    generate
        for(i=0;i<32;i=i+1) begin :shift_16
            assign s16[i] = shamt[4] ? (i<16 ? 1'b0 : s8[i-16]) : s8[i];
        end
    endgenerate

    assign out = s16;  

assign carry_out = (shamt == 0) ? 
                   1'b0 : 
                   in[32 - shamt];
 
endmodule
