`timescale 1ns / 1ps


// 1-bit Full Subtractor 

module full_subtractor (
    input  wire a,
    input  wire b,
    input  wire bin,
    output wire diff,
    output wire bout
);

    wire axorb;
    wire b1, b2;

    assign axorb = a ^ b;
    assign diff  = axorb ^ bin;

    assign b1 = (~a) & b;
    assign b2 = (~axorb) & bin;

    assign bout = b1 | b2;

endmodule


// 64-bit Ripple Borrow Subtractor

module SUB64 (
    input  wire [63:0] A,
    input  wire [63:0] B,
    output wire [63:0] Diff,
    output wire        Borrow
);

    wire [64:0] borrow;

    assign borrow[0] = 1'b0;

    genvar i;
    generate
        for (i = 0; i < 64; i = i + 1) begin : SUB_STAGE
            full_subtractor FS (
                .a   (A[i]),
                .b   (B[i]),
                .bin (borrow[i]),
                .diff(Diff[i]),
                .bout(borrow[i+1])
            );
        end
    endgenerate

    assign Borrow = borrow[64];

endmodule
