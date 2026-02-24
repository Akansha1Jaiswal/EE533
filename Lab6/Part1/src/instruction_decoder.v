`timescale 1ns / 1ps
module instruction_decoder(
    input  [31:0] instr,

    // Basic
    output [3:0] cond,

    // Data Processing
    output        is_dp,
    output [3:0]  dp_opcode,
    output        S,
    output        I,           // immediate operand flag
    output [31:0] imm32,       // immediate 32 bit value
    output [3:0]  Rn,
    output [3:0]  Rd,
    output [3:0]  Rm,
    output [4:0]  shamt,       // 5-bit shift amount

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

// ---------------- imm / rotate ----------------
wire [7:0] imm8       = instr[7:0];
wire [3:0] rotate_imm = instr[11:8];
wire [31:0] imm_ext   = {24'b0, imm8};

// rotate amount in bits (0..30)
wire [5:0] rotate_bits = {rotate_imm, 1'b0}; // multiply by 2

// function safe ROR with modulo 32
function [31:0] ror32;
    input [31:0] val;
    input [5:0]  r; // up to 63, we'll mask to 0..31
    reg   [4:0]  s;
    begin
        s = r[4:0]; // r % 32
        ror32 = (val >> s) | (val << (32 - s));
    end
endfunction

assign imm32 = (rotate_bits == 6'd0) ? imm_ext : ror32(imm_ext, rotate_bits);

// ---------------- basic fields ----------------
assign cond = instr[31:28];

assign is_dp     = (instr[27:26] == 2'b00);
assign I         = instr[25];
assign dp_opcode = instr[24:21];
assign S         = instr[20];

assign Rn   = instr[19:16];
assign Rd   = instr[15:12];
assign Rm   = instr[3:0];

assign shamt = instr[11:7];

// ---------------- single data transfer ----------------
wire single_transfer = (instr[27:26] == 2'b01);

assign P = instr[24];
assign U = instr[23];
assign B = instr[22];
assign W = instr[21];

wire L = instr[20];

assign is_ldr = single_transfer & L;
assign is_str = single_transfer & ~L;

assign offset12 = instr[11:0];

// ---------------- block transfer ----------------
assign is_block = (instr[27:25] == 3'b100);
assign block_L  = instr[20];
assign block_W  = instr[21];
assign reg_list = instr[15:0];

// ---------------- branch ----------------
assign is_branch = (instr[27:25] == 3'b101);
wire [23:0] imm24 = instr[23:0];
// imm24 << 2 then sign-extend to 32 bits
assign branch_offset = {{6{imm24[23]}}, imm24, 2'b00};

// ---------------- BX ----------------
localparam [23:0] BX_PATTERN = 24'b000100101111111111110001;
assign is_bx = (instr[27:4] == BX_PATTERN);

endmodule