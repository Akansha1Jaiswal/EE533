`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    23:05:14 02/11/2026 
// Design Name: 
// Module Name:    alu64 
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


module alu32(
    input  [31:0] A,
    input  [31:0] B,
    input  [3:0]  opcode,
    input  [4:0]  shamt,

    output reg [31:0] result,
    output reg zero_flag,
    output reg Cout,
    output reg overflow_flag,
    output reg neg_flag
);

    reg [32:0] tmp;
    reg [31:0] shifted_B;

    always @(*) begin

        // Default
        result        = 32'b0;
        zero_flag     = 1'b0;
        Cout          = 1'b0;
        overflow_flag = 1'b0;
        neg_flag      = 1'b0;

        // Logical left shift for MOV operand2
        shifted_B = B << shamt;

        case (opcode)

            4'b0100: begin // ADD
                tmp    = {1'b0, A} + {1'b0, B};
                result = tmp[31:0];
                Cout   = tmp[32];
                overflow_flag = (~(A[31] ^ B[31])) & (A[31] ^ result[31]);
            end

            4'b0010: begin // SUB
                tmp    = {1'b0, A} - {1'b0, B};
                result = tmp[31:0];
                Cout   = ~tmp[32];  // ARM borrow convention
                overflow_flag = (A[31] ^ B[31]) & (A[31] ^ result[31]);
            end

            4'b1010: begin // CMP (A - B, flags only)
                tmp    = {1'b0, A} - {1'b0, B};
                result = 32'b0;     // no writeback
                Cout   = ~tmp[32];
                overflow_flag = (A[31] ^ B[31]) & (A[31] ^ tmp[31]);
            end

            4'b1101: begin // MOV (with shift)
                result = shifted_B;
					     if (shamt == 0)
                        Cout = 1'b0;
                    else
                        Cout = B[31 - (shamt - 1)];
            end

            default: begin
                result = 32'b0;
            end
        endcase

        // Flags based on arithmetic result (CMP uses tmp)
        if (opcode == 4'b1010) begin
            neg_flag  = tmp[31];
            zero_flag = (tmp[31:0] == 32'b0);
        end else begin
            neg_flag  = result[31];
            zero_flag = (result == 32'b0);
        end

    end

endmodule