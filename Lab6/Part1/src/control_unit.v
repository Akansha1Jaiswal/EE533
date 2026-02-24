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
`timescale 1ns / 1ps
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
    // Safe defaults
    alu_opcode = 4'b0000;
    ALUSrc     = 1'b0;
    MemRead    = 1'b0;
    MemWrite   = 1'b0;
    RegWrite   = 1'b0;
    MemToReg   = 1'b0;

    if (is_dp) begin
        alu_opcode = dp_opcode;
        ALUSrc     = I;
        RegWrite   = 1'b1;
    end

    else if (is_ldr) begin
        alu_opcode = U ? 4'b0100 : 4'b0010;  // ADD/SUB
        ALUSrc     = 1'b1;
        MemRead    = 1'b1;
        RegWrite   = 1'b1;
        MemToReg   = 1'b1;
    end

    else if (is_str) begin
        alu_opcode = U ? 4'b0100 : 4'b0010;
        ALUSrc     = 1'b1;
        MemWrite   = 1'b1;
    end

    else if (is_branch) begin
        alu_opcode = 4'b0100;  // ADD PC + offset
        ALUSrc     = 1'b1;
        // no reg write
    end
end

endmodule