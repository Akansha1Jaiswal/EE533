`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    01:28:32 02/26/2026 
// Design Name: 
// Module Name:    forwarding_unit 
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
module forwarding_unit (
    input  wire [3:0] ID_EX_rs,
    input  wire [3:0] ID_EX_rt,

    input  wire [3:0] EX_MEM_rd,
    input  wire       EX_MEM_RegWrite,

    input  wire [3:0] MEM_WB_rd,
    input  wire       MEM_WB_RegWrite,
	 input  wire       EX_MEM_MemRead,   //For load word detection

    output reg  [1:0] ForwardA,
    output reg  [1:0] ForwardB
);

always @(*) begin

    // default: no forwarding
    ForwardA = 2'b00;
    ForwardB = 2'b00;

    // Forward for rs (operand A)
    if (EX_MEM_RegWrite && !EX_MEM_MemRead && (EX_MEM_rd != 4'd0) && (EX_MEM_rd == ID_EX_rs)) //No forwarding from MEM stage (EX_MEM stage reg) if the instruction is load word
        ForwardA = 2'b10;

    else if (MEM_WB_RegWrite && (MEM_WB_rd != 4'd0) && (MEM_WB_rd == ID_EX_rs)) //overwrites EX_MEM Forwarding
        ForwardA = 2'b01;

    // Forward for rt (operand B before ALUSrc mux)
    if (EX_MEM_RegWrite && !EX_MEM_MemRead && (EX_MEM_rd != 4'd0) && (EX_MEM_rd == ID_EX_rt))      
        ForwardB = 2'b10;

    else if (MEM_WB_RegWrite && (MEM_WB_rd != 4'd0) && (MEM_WB_rd == ID_EX_rt)) //overwrites EX_MEM Forwarding
        ForwardB = 2'b01;

end

endmodule
