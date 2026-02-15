`timescale 1ns / 1ps
//`include Mux2x1_64Bit.v
//`include Mux4x1_64Bit.v


module Mux8x1_64Bit (
    input  [63:0] in0,
    input  [63:0] in1,
    input  [63:0] in2,
    input  [63:0] in3,
    input  [63:0] in4,
    input  [63:0] in5,
    input  [63:0] in6,
    input  [63:0] in7,
    input  [2:0]  sel,
    output [63:0] mux_out
);

wire [63:0] w0;
wire [63:0] w1;


/* Lower 4 inputs */
Mux4x1_64Bit M4_0 (
    .in0(in0),
    .in1(in1),
    .in2(in2),
    .in3(in3),
    .sel(sel[1:0]),
    .mux_out(w0)
);

/* Upper 4 inputs */
Mux4x1_64Bit M4_1 (
    .in0(in4),
    .in1(in5),
    .in2(in6),
    .in3(in7),
    .sel(sel[1:0]),
    .mux_out(w1)
);

/* Final selection */
Mux2x1_64Bit M2_final (
    .in0(w0),
    .in1(w1),
    .sel(sel[2]),
    .mux_out(mux_out)
);

endmodule
