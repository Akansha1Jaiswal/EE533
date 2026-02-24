`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    21:52:03 02/20/2026 
// Design Name: 
// Module Name:    hdu 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
// Inputs:
//  - ID_EX_MemRead   : true if EX-stage instruction is a load
//  - ID_EX_Rd        : destination reg index of load in EX stage
//  - IF_ID_Rs        : source reg 1 of instruction in ID
//  - IF_ID_Rt        : source reg 2 of instruction in ID
//  - EX_MEM_MemToReg : true if MEM-stage instruction is a load (BRAM latency stall)
//
// Outputs:
//  - PC_write        : 1 => PC updates; 0 => stall PC
//  - IF_ID_write     : 1 => IF/ID advances; 0 => hold IF/ID
//  - ID_EX_flush     : 1 => inject bubble into ID/EX
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////

module hdu(
    input  wire        ID_EX_MemRead,
    input  wire [3:0]  ID_EX_Rd,
    input  wire [3:0]  IF_ID_Rs,
    input  wire [3:0]  IF_ID_Rt,
    input  wire        EX_MEM_MemToReg,

    output reg         PC_write,
    output reg         IF_ID_write,
    output reg         ID_EX_flush
);

    always @(*) begin
        // default: no stall
        PC_write     = 1'b1;
        IF_ID_write  = 1'b1;
        ID_EX_flush  = 1'b0;

        // load-use hazard (EX stage load)
        if (ID_EX_MemRead &&
            ((ID_EX_Rd == IF_ID_Rs) || (ID_EX_Rd == IF_ID_Rt))) begin
            PC_write    = 1'b0;
            IF_ID_write = 1'b0;
            ID_EX_flush = 1'b1;
        end
    end

endmodule