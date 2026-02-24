`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    15:55:04 02/22/2026 
// Design Name: 
// Module Name:    control_unit 
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
module control_unit(
    input is_dp,
    input is_ldr,
    input is_str,
    input is_branch,
    input [3:0] dp_opcode,
    input I,
    input U,

    output reg [3:0] alu_opcode,
    output reg ALUSrc,
    output reg MemRead,
    output reg MemWrite,
    output reg RegWrite,
    output reg MemToReg
);

always @(*) begin

    // Default values (VERY IMPORTANT)
    alu_opcode = 4'b0000;
    ALUSrc     = 0;
    MemRead    = 0;
    MemWrite   = 0;
    RegWrite   = 0;
    MemToReg   = 0;

    if (is_dp) begin
        alu_opcode = dp_opcode;
        ALUSrc     = I;
        RegWrite   = 1;
    end

    else if (is_ldr) begin
        alu_opcode = U ? 4'b0100 : 4'b0010;
        ALUSrc     = 1;
        MemRead    = 1;
        RegWrite   = 1;
        MemToReg   = 1;
    end

    else if (is_str) begin
        alu_opcode = U ? 4'b0100 : 4'b0010;
        ALUSrc     = 1;
        MemWrite   = 1;
    end

    else if (is_branch) begin
        alu_opcode = 4'b0100;
        ALUSrc     = 1;
    end

end

endmodule
