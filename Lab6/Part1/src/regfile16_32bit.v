`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    18:38:30 02/20/2026 
// Design Name: 
// Module Name:    regfile16_32bit 
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
module regfile16_32bit (
    input  wire        clk,
    input  wire        reset,
    input  wire        we,
    input  wire [3:0]  wr_addr,
    input  wire [31:0] wr_data,
    input  wire [3:0]  rd_addr1,
    input  wire [3:0]  rd_addr2,
    output wire [31:0] rd_data1,
    output wire [31:0] rd_data2
);

    // 16 registers
    reg [31:0] regs [0:15];

    integer i;

    // Write + reset
    always @(posedge clk) begin
        if (reset) begin
            for (i = 0; i < 16; i = i + 1)
                regs[i] <= 32'b0;

            regs[13] <= 32'h00000200;  // SP reset value
        end
        else if (we) begin
            regs[wr_addr] <= wr_data;
        end
    end

    // Raw read
    wire [31:0] rd1_raw = regs[rd_addr1];
    wire [31:0] rd2_raw = regs[rd_addr2];

    // Same-cycle write-through (bypass)
    assign rd_data1 = (we && (wr_addr == rd_addr1)) ? wr_data : rd1_raw;
    assign rd_data2 = (we && (wr_addr == rd_addr2)) ? wr_data : rd2_raw;

endmodule