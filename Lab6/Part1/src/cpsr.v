`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    20:44:34 02/20/2026 
// Design Name: 
// Module Name:    cpsr 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//  - EX stage computes flags (N_out,Z_out,C_out,V_out) and produces update_flags.
//  - Top level should connect update_flags to update_en of CPSR so flags are written
//    only when an instruction executed (cond true) requests an update (S bit / CMP).
//  - CPSR outputs are read by cond_eval when evaluating instruction conditions.
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module cpsr (
    input  wire clk,
    input  wire reset,
    input  wire update_en,    // write enable: update flags on rising edge
    input  wire N_in,
    input  wire Z_in,
    input  wire C_in,
    input  wire V_in,
    output reg  N_out,
    output reg  Z_out,
    output reg  C_out,
    output reg  V_out
    );

    always @(posedge clk or posedge reset) begin
        if (reset) begin
            N_out <= 1'b0;
            Z_out <= 1'b0;
            C_out <= 1'b0;
            V_out <= 1'b0;
        end
        else if (update_en) begin
            N_out <= N_in;
            Z_out <= Z_in;
            C_out <= C_in;
            V_out <= V_in;
        end
    end

endmodule


