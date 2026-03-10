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
	 input  wire [1:0]  ID_thread_id,
	 input  wire [1:0]  WB_thread_id,
    input  wire        clk,
    input  wire        reset,
    input  wire [3:0]  waddr,   // write address
    input  wire [63:0] wdata,   // write data
    input  wire        we,      // write enable
	
    output wire [63:0] douta,   // read data A
    output wire [63:0] doutb    // read data B
);

// 4 threads × 16 registers = 64 total registers
reg [63:0] rf [0:63];

// Constructing full addresses
wire [5:0] raddrA;
wire [5:0] raddrB;
wire [5:0] waddr_full;
assign raddrA     = {ID_thread_id, addra};
assign raddrB     = {ID_thread_id, addrb};
assign waddr_full = {WB_thread_id, waddr};
integer i;

// synchronous write + synchronous reset
always @(posedge clk) begin
    if (reset) begin
        for (i = 0; i < 64; i = i + 1)
            rf[i] <= 64'd0;
    end
    else if (we) begin
        rf[waddr_full] <= wdata;
    end
end

// combinational read with write-through
assign douta = (we && (waddr_full == raddrA)) ? wdata : rf[raddrA];
assign doutb = (we && (waddr_full == raddrB)) ? wdata : rf[raddrB];

endmodule

