
`timescale 1ns / 1ps

module detect7B(
    input        ce,
    input        clk,
    input [63:0] hwregA,
    input        match_en,
    input        mrst,
    input [71:0] pipe1,
    output       match
);

    // --------------------------------------------------
    // Passthrough IDS detector
    // --------------------------------------------------
    // No internal state
    // No matching
    // No side effects
    // --------------------------------------------------

    assign match = 1'b0;

endmodule
