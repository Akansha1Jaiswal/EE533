`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    01:26:29 02/26/2026 
// Design Name: 
// Module Name:    ALU 
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
module ALU (
    input  wire [63:0] A,
    input  wire [63:0] B,
    input  wire [3:0]  ALUOp,

    output reg  [63:0] result,
    output wire        zero,          //BEQ
    output wire        less_than,     //BLT
    output wire        greater_equal, //BGE
    output wire        less_equal     //BLE
);

always @(*) begin
    case (ALUOp)
        4'b0000: result = A + B;               // ADD, ADDI uses the same ALU operation, mux in EX module chooses between rt or immediate value 
        4'b0001: result = A - B;               // SUB
        4'b0010: result = A << B[5:0];         // SLL (shift amount from lower bits of B)
        default: result = 64'd0;
    endcase
end

assign zero          = (result == 64'd0);
assign less_than     = ($signed(A) < $signed(B));
assign greater_equal = ($signed(A) >= $signed(B));
assign less_equal    = ($signed(A) <= $signed(B));

endmodule
