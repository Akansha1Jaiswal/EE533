`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    19:15:55 02/12/2026 
// Design Name: 
// Module Name:    PC 
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
module PC(
    input  wire        clk,
    input  wire        reset,
    input  wire        pc_write,
    input  wire [31:0] pc_next,
    output reg  [31:0] pc_out
);

always @(posedge clk) begin
    if (reset)
        pc_out <= 32'b0;
    else if (pc_write)
        pc_out <= pc_next;
    else
        pc_out <= pc_out;  
end

endmodule