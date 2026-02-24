`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    19:06:07 02/12/2026 
// Design Name: 
// Module Name:    MEM_WB 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
// Stored:
//  - alu_result (32)
//  - mem_data (32)   : data read from memory (LDR)
//  - rd (4)          : destination register
//  - control signals : WRegEn, MemToReg
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module MEM_WB(
    input  wire        clk,
    input  wire        reset,

    // inputs from MEM
    input  wire [31:0] alu_result_in,
    input  wire [31:0] mem_data_in,
    input  wire [3:0]  rd_in,
    input  wire        WRegEn_in,
    input  wire        MemToReg_in,

    // registered outputs to WB
    output reg  [31:0] alu_result_out,
    output reg  [31:0] mem_data_out,
    output reg  [3:0]  rd_out,
    output reg         WRegEn_out,
    output reg         MemToReg_out
);

always @(posedge clk) begin
    if (reset) begin
        alu_result_out <= 32'b0;
        mem_data_out   <= 32'b0;
        rd_out         <= 4'b0;
        WRegEn_out     <= 1'b0;
        MemToReg_out   <= 1'b0;
    end
    else begin
        alu_result_out <= alu_result_in;
        mem_data_out   <= mem_data_in;
        rd_out         <= rd_in;
        WRegEn_out     <= WRegEn_in;
        MemToReg_out   <= MemToReg_in;
    end
end

endmodule