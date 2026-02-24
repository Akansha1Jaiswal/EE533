`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    18:46:56 02/12/2026 
// Design Name: 
// Module Name:    instruction_decoder 
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
module instruction_decoder(
    input  [31:0] instr,

    // Basic
    output [3:0] cond,

    // Data Processing
    output        is_dp,
    output [3:0]  dp_opcode,
    output        S,
    output        I,           // immediate operand flag (kept as output)
	 output [31:0] imm32,       // immediate 32 bit value
    output [3:0]  Rn,
    output [3:0]  Rd,
    output [3:0]  Rm,
    output [4:0]  shamt,       // <-- ADDED: 5-bit shift amount for LSL/LSR/ASR

    // Single Data Transfer
    output        is_ldr,
    output        is_str,
    output        P,
    output        U,
    output        W,
    output        B,
    output [11:0] offset12,

    // Block Transfer
    output        is_block,
    output        block_L,
    output        block_W,
    output [15:0] reg_list,

    // Branch
    output        is_branch,
    output signed [31:0] branch_offset,

    // BX
    output        is_bx
);
//---------------------------------------------------
	 // Immediate parsing for MOV
wire [7:0] imm8 = instr[7:0];
wire [3:0] rotate_imm = instr[11:8];

// Rotate right function
function [31:0] ror32;
    input [31:0] val;
    input [4:0] r;
    begin
        ror32 = (val >> r) | (val << (32 - r));
    end
endfunction

assign imm32 = ror32({24'b0, imm8}, rotate_imm * 2);
//-------------------------------------------------	 
    // Condition
    assign cond = instr[31:28];

    // Data Processing detection and fields
    assign is_dp = (instr[27:26] == 2'b00);

    assign I         = instr[25];
    assign dp_opcode = instr[24:21];
    assign S         = instr[20];

    assign Rn = instr[19:16];
    assign Rd = instr[15:12];
    assign Rm = instr[3:0];

    // Shift amount: for register/imm shifts, bits [11:7] encode the immediate shift
    // (If I==1 then operand2 is immediate; shift amt is not used in that case)
    assign shamt = instr[11:7];

    // Single data transfer (LDR/STR)
    wire single_transfer = (instr[27:26] == 2'b01);

    assign P = instr[24];
    assign U = instr[23];
    assign B = instr[22];
    assign W = instr[21];

    wire L = instr[20];

    assign is_ldr = single_transfer & L;
    assign is_str = single_transfer & ~L;

    assign offset12 = instr[11:0];

    // Block data transfer (LDM/STM)
    assign is_block = (instr[27:25] == 3'b100);

    assign block_L = instr[20];   // 1=LDM, 0=STM
    assign block_W = instr[21];   // writeback

    assign reg_list = instr[15:0];

    // Branch (B / BL)
    assign is_branch = (instr[27:25] == 3'b101);

    wire signed [23:0] imm24 = instr[23:0];

    // Word-based offset (you previously used sign-extend of 24 bits to 32 ? keep that)
    assign branch_offset = {{8{imm24[23]}}, imm24};

    // BX detection (pattern match)
    localparam [23:0] BX_PATTERN = 24'b000100101111111111110001;
    assign is_bx = (instr[27:4] == BX_PATTERN);

endmodule