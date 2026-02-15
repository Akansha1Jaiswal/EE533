`timescale 1ns / 1ps
//#`include Mux2x1_64Bit.v


module Mux4x1_64Bit (
    input  [63:0] in0,
    input  [63:0] in1,
    input  [63:0] in2,
    input  [63:0] in3,
    input  [1:0]  sel,
    output [63:0] mux_out
);

wire [63:0] w0;
wire [63:0] w1;

Mux2x1_64Bit M0 (.in0(in0), .in1(in1), .sel(sel[0]), .mux_out(w0));
Mux2x1_64Bit M1 (.in0(in2), .in1(in3), .sel(sel[0]), .mux_out(w1));
Mux2x1_64Bit M2 (.in0(w0),  .in1(w1),  .sel(sel[1]), .mux_out(mux_out));

endmodule
