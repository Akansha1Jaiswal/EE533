`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    23:13:20 02/11/2026 
// Design Name: 
// Module Name:    barrel_right_64 
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
module barrel_right_32(
    input  [31:0] in,
    input  [4:0] shamt,
    output [31:0] out
    );

    wire [31:0] s1,s2,s4,s8;//s16;

    genvar i;

    generate
        for(i=0;i<32;i=i+1) begin
            assign s1[i] = shamt[0] ?
                          (i==31 ? 1'b0 : in[i+1]) :
                          in[i];
        end
    endgenerate

    generate
        for(i=0;i<32;i=i+1) begin
            assign s2[i] = shamt[1] ?
                          (i>29 ? 1'b0 : s1[i+2]) :
                          s1[i];
        end
    endgenerate

    generate
        for(i=0;i<32;i=i+1) begin
            assign s4[i] = shamt[2] ?
                          (i>27 ? 1'b0 : s2[i+4]) :
                          s2[i];
        end
    endgenerate

    generate
        for(i=0;i<32;i=i+1) begin
            assign s8[i] = shamt[3] ?
                          (i>23 ? 1'b0 : s4[i+8]) :
                          s4[i];
        end
    endgenerate

//    generate
//        for(i=0;i<64;i=i+1) begin
//            assign s16[i] = shamt[4] ?
//                           (i>47 ? 1'b0 : s8[i+16]) :
//                           s8[i];
//        end
//    endgenerate

    generate
        for(i=0;i<64;i=i+1) begin
            assign out[i] = shamt[5] ?
                           (i>31 ? 1'b0 : s16[i+32]) :
                           s16[i];
        end
    endgenerate

endmodule
