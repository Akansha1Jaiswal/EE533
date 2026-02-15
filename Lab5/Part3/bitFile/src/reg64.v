`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    23:30:55 02/11/2026 
// Design Name: 
// Module Name:    reg64 
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
module reg64_(
    input clk,
    input [63:0] D,
    output [63:0] Q
    );

    genvar i;

    generate
        for (i = 0; i < 64; i = i + 1) begin : reg_block
            dff dff_inst (
                .clk(clk),
                .D(D[i]),
                .Q(Q[i])
            );
        end
    endgenerate

endmodule
