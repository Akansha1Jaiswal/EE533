`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    01:27:02 02/26/2026 
// Design Name: 
// Module Name:    branch_unit 
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
module branch_unit (
    input  wire        Branch,
    input  wire [5:0]  instr_opcode,
    input  wire        less_than,
    input  wire        greater_equal,
    input  wire        less_equal,

    output reg         branch_taken
);

always @(*) begin
    branch_taken = 1'b0;

    if (Branch) begin
        case (instr_opcode)
            6'b000111: branch_taken = less_than;      // BLT
            6'b001000: branch_taken = greater_equal;  // BGE
            6'b001001: branch_taken = less_equal;     // BLE
            default:   branch_taken = 1'b0;
        endcase
    end
end

endmodule