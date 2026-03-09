`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    01:31:09 02/26/2026 
// Design Name: 
// Module Name:    MEM_WB 
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
module MEM_WB (
    input  wire        clk,
    input  wire        reset,

    // Inputs from MEM stage 
    input  wire [63:0] mem_read_data_in,
    input  wire [63:0] alu_result_in,
    input  wire [3:0]  rd_in,

    input  wire        RegWrite_in,
    input  wire        MemToReg_in,

    // Outputs to WB stage 
    output reg  [63:0] mem_read_data_out,
    output reg  [63:0] alu_result_out,
    output reg  [3:0]  rd_out,

    output reg         RegWrite_out,
    output reg         MemToReg_out
);

always @(posedge clk) begin
    if (reset) begin
        //mem_read_data_out <= 64'd0;
        alu_result_out    <= 64'd0;
        rd_out            <= 4'd0;

        RegWrite_out <= 1'b0;
        MemToReg_out <= 1'b0;
    end
    else begin
        //mem_read_data_out <= mem_read_data_in; // For Load instruction
        alu_result_out    <= alu_result_in;    // For storing ALU Results in registers - arithematic/logical operations
        rd_out            <= rd_in;            // Destination Register to store alu_result_out

        RegWrite_out <= RegWrite_in;           // Load & ALU Register Operation
        MemToReg_out <= MemToReg_in;           // Selects between memory data or alu result to store
    end
end

endmodule
