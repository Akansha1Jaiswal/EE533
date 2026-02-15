`timescale 1ns / 1ps

module Shifter_64bit (
    input wire [63:0] A,       // 32-bit input data
    input wire [63:0] ShiftAmt, // Shift amount (0 to 31)
    input wire DIR,            // Direction (0: Left Shift, 1: Right Shift)
    output reg [64:0] Result   // Shifted output
);

    always @(*) begin
        if (DIR == 0)
            Result = A << ShiftAmt;  // Left Shift
        else
            Result = A >> ShiftAmt;  // Right Shift
    end

endmodule
