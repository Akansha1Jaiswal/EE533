`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    19:04:39 02/12/2026 
// Design Name: 
// Module Name:    EX_MEM 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
// Fields stored:
//  - alu_result (32)
//  - rt_data (32) : store data for STR
//  - rd (4)       : destination register index
//  - control signals: WRegEn, WMemEn, MemToReg
//  - address (32) : optional memory address if you prefer to store separately
//  - branch signals (optional): branch_taken, branch_target
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module EX_MEM(
    input  wire        clk,
    input  wire        reset,

    // inputs from EX
    input  wire [31:0] alu_result_in,
    input  wire [31:0] rt_data_in,
    input  wire [3:0]  rd_in,
    input  wire        WRegEn_in,
    input  wire        WMemEn_in,
    input  wire        MemToReg_in,
    input  wire [31:0] mem_addr_in,
    input  wire        branch_taken_in,
    input  wire [31:0] branch_target_in,

    // registered outputs to MEM stage
    output reg  [31:0] alu_result_out,
    output reg  [31:0] rt_data_out,
    output reg  [3:0]  rd_out,
    output reg         WRegEn_out,
    output reg         WMemEn_out,
    output reg         MemToReg_out,
    output reg  [31:0] mem_addr_out,
    output reg         branch_taken_out,
    output reg  [31:0] branch_target_out
);

always @(posedge clk) begin
    if (reset) begin
        alu_result_out   <= 32'b0;
        rt_data_out      <= 32'b0;
        rd_out           <= 4'b0;
        WRegEn_out       <= 1'b0;
        WMemEn_out       <= 1'b0;
        MemToReg_out     <= 1'b0;
        mem_addr_out     <= 32'b0;
        branch_taken_out <= 1'b0;
        branch_target_out<= 32'b0;
    end
    else begin
        alu_result_out   <= alu_result_in;
        rt_data_out      <= rt_data_in;
        rd_out           <= rd_in;
        WRegEn_out       <= WRegEn_in;
        WMemEn_out       <= WMemEn_in;
        MemToReg_out     <= MemToReg_in;
        mem_addr_out     <= mem_addr_in;
        branch_taken_out <= branch_taken_in;
        branch_target_out<= branch_target_in;
    end
end

endmodule