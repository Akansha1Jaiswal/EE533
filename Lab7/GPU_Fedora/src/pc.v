`timescale 1ns/1ps

module gpu_pc (
    input  wire        clk,
    input  wire        reset,
    input  wire        en,      // 1 = advance, 0 = freeze (stall)
    output reg  [8:0] pc
);

always @(posedge clk) begin
    if (reset)
        pc <= 8'b0;
    else if (en)
        pc <= pc + 1;
    // else: hold current PC
end

endmodule
