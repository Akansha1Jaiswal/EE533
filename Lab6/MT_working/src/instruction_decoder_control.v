`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    01:30:22 02/26/2026 
// Design Name: 
// Module Name:    instruction_decoder_control 
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
module instruction_decoder_control (
    input  wire [31:0] instr_in,         // IF/ID.instr_out
    input  wire [31:0] pc_plus4_in,      // IF/ID.pc_plus4_out (used to compute branch target)
	 input  wire [1:0]  ID_thread_id,
    // decoded fields
    output wire [3:0]  rs_addr,
    output wire [3:0]  rt_addr,
    output wire [3:0]  rd_addr,
    output wire [11:0] imm12,            // raw immediate field (bits 13:2)
    output wire [63:0] imms_ext_64,      // sign-extended immediate to 64-bit (imm12 -> 64)
	output wire [5:0]  instr_opcode,
    // targets
    output wire [31:0] jump_target,      // absolute jump (from imm[8:0] << 2)
    output wire [31:0] branch_target,    // relative branch: pc_plus4 + (sign_ext(imm12) << 2)
    // control signals
    output reg         RegWrite,
    output reg         MemRead,
    output reg         MemWrite,
    output reg         MemToReg,
    output reg         ALUSrc,           // NOTE: ALUSrc 1 -> use rt, 0 -> use immediate
    output reg         Branch,
    output reg         Jump,
    output reg  [3:0]  ALUOp             // 4-bit ALU operation code
);

//
// Field extraction:
// 31:26 opcode (6 bits)
// 25:22 rs (4 bits)
// 21:18 rt (4 bits)
// 17:14 rd (4 bits)
// 13:2  imm (12 bits)
// 1:0   unused
//

assign instr_opcode = instr_in[31:26];
assign rs_addr = instr_in[25:22];
assign rt_addr = instr_in[21:18];
assign rd_addr = instr_in[17:14];
assign imm12   = instr_in[13:2];

// sign-extend imm12 to 64 bits (arithmetic)
wire [63:0] imm12s_ext_64;
assign imm12s_ext_64 = {{52{imm12[11]}}, imm12}; 
assign imms_ext_64 = imm12s_ext_64;

// branch_target: relative branch (word-offset in imm12). We add to pc_plus4.
// Note: pc_plus4_in should be 32-bit byte address (pc+4).
assign branch_target = (pc_plus4_in) + (imm12s_ext_64 << 2); // imm12s_ext_64 shifted by 2 for branch pc value

// jump_target: absolute jump. Use lower 9 bits of imm12 as IMEM word index.
// Form 32-bit byte address: {zero, imm9, 2'b00}
wire [8:0] imm9;
assign imm9 = imm12[8:0];
assign jump_target = {23'd0, imm9, 2'b00};

// default control values
always @(*) begin
    // defaults
    RegWrite = 1'b0;
    MemRead  = 1'b0;
    MemWrite = 1'b0;
    MemToReg = 1'b0;
    ALUSrc   = 1'b1; // default choose RT as operand 
    Branch   = 1'b0;
    Jump     = 1'b0;
    ALUOp    = 4'b0000;

    case (instr_opcode)
        6'b000000: begin // NOP
				MemWrite = 1'b0;
            // all zeros (bubble)
        end

        6'b000001: begin // ADD  (R-type: rs + rt)
            RegWrite = 1'b1;
            ALUSrc   = 1'b1;    // use rt
            ALUOp    = 4'b0000; // ADD
				MemWrite = 1'b0;
        end

        6'b000010: begin // ADDI (rs + imm)
            RegWrite = 1'b1;
            ALUSrc   = 1'b0;    // use immediate
            ALUOp    = 4'b0000; // ADD
				MemWrite = 1'b0;
        end

        6'b000011: begin // SUB (rs - rt)
            RegWrite = 1'b1;
            ALUSrc   = 1'b1;    // use rt
            ALUOp    = 4'b0001; // SUB
				MemWrite = 1'b0;
        end

        6'b000100: begin // SLL (shift rs by imm[4:0])
            RegWrite = 1'b1;
            ALUSrc   = 1'b0;    // use immediate (shift amount encoded in imm)
            ALUOp    = 4'b0010; // SLL
				MemWrite = 1'b0;
        end

        6'b000101: begin // LW  (load 64-bit) address = rs + imm
            RegWrite = 1'b1;
            MemRead  = 1'b1;
            MemToReg = 1'b1;
            ALUSrc   = 1'b0;    // use immediate
            ALUOp    = 4'b0000; // ADD for address calc
				MemWrite = 1'b0;
        end

        6'b000110: begin // SW  (store 64-bit) address = rs + imm ; mem[address] = rt value
            RegWrite = 1'b0;
            MemWrite = 1'b1;
            ALUSrc   = 1'b0;    // use immediate
            ALUOp    = 4'b0000; // ADD for address calc
        end

        6'b000111: begin // BLT (branch if rs < rt)
            RegWrite = 1'b0;
            Branch   = 1'b1;
            ALUSrc   = 1'b1;    // compare with rt
            ALUOp    = 4'b0001; // SUB to set flags / compute rs-rt
				MemWrite = 1'b0;
        end

        6'b001000: begin // BGE (branch if rs >= rt)
            RegWrite = 1'b0;
            Branch   = 1'b1;
            ALUSrc   = 1'b1;
            ALUOp    = 4'b0001;
				MemWrite = 1'b0;
        end

        6'b001001: begin // BLE (branch if rs <= rt)
            RegWrite = 1'b0;
            Branch   = 1'b1;
            ALUSrc   = 1'b1;
            ALUOp    = 4'b0001;
				MemWrite = 1'b0;
        end

        6'b001010: begin // J (absolute jump using imm bits)
            RegWrite = 1'b0;
            Jump     = 1'b1;
				MemWrite = 1'b0;
            // ALUSrc / ALUOp doesn't matter
        end

        default: begin
            // treat as NOP
        end
    endcase
end

endmodule
