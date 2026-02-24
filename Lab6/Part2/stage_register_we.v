`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    18:28:12 02/20/2026 
// Design Name: 
// Module Name:    stage_register_we 
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
module stage_register_we #(parameter WIDTH = 32)(
    input clk,
    input reset,
    input we,
    input [WIDTH-1:0] d,
    output [WIDTH-1:0] q
);

wire [WIDTH-1:0] d_internal;

genvar i;

generate
    for (i = 0; i < WIDTH; i = i + 1) begin : dff_gen
        assign d_internal[i] = we ? d[i] : q[i];

        dff_reset dff_inst (
            .clk(clk),
            .reset(reset),
            .D(d_internal[i]),
            .Q(q[i])
        );
    end
endgenerate

endmodule


