`timescale 1ns / 1ps

module XNOR1 (
    input  A,
    input  B,
    output Y
);

wire nA, nB;
wire w1, w2;

not (nA, A);
not (nB, B);
and (w1, A, B);
and (w2, nA, nB);
or  (Y, w1, w2);

endmodule
