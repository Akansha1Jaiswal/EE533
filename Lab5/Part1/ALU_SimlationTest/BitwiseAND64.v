`timescale 1ns / 1ps

module AND64 (
    input  [63:0] A,
    input  [63:0] B,
    output [63:0] Y
);

genvar i;

generate
    for (i = 0; i < 64; i = i + 1) begin : AND_STAGE
        and (Y[i], A[i], B[i]);
    end
endgenerate

endmodule
