`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    23:05:34 03/02/2026 
// Design Name: 
// Module Name:    regfile 
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
module regfile(
    input  wire [3:0]  addra,   // read address A
    input  wire [3:0]  addrb,   // read address B
    input  wire        clk,
    input  wire        reset,
    input  wire [3:0]  waddr,   // write address
    input  wire [63:0] wdata,   // write data
    input  wire        we,      // write enable
    output wire [63:0] douta,   // read data A
    output wire [63:0] doutb    // read data B
);

// 16 x 64-bit register file
reg [63:0] rf [0:15];

integer i;

// synchronous write + synchronous reset
always @(posedge clk) begin
    if (reset) begin
        for (i = 0; i < 16; i = i + 1)
            rf[i] <= 64'd0;
    end
    else if (we) begin
        rf[waddr] <= wdata;
    end
end

// combinational read with write-through
assign douta = (we && (waddr == addra)) ? wdata : rf[addra];
assign doutb = (we && (waddr == addrb)) ? wdata : rf[addrb];

endmodule
