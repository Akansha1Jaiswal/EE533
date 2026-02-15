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
    input  [3:0] opcode,
    output WMemEn,
    output WRegEn,
    output MemToReg
    );

    wire op3, op2, op1, op0;
    wire not_op2, not_op0;
    wire store, nop;
    wire store_or_nop;

    // Opcode bits
    assign op3 = opcode[3];
    assign op2 = opcode[2];
    assign op1 = opcode[1];
    assign op0 = opcode[0];

    // Inverters
    not (not_op2, op2);
    not (not_op0, op0);

    // STORE = 1011
    and (store, op3, not_op2, op1, op0);

    // NOP = 1111
    and (nop, op3, op2, op1, op0);

    // WMemEn = STORE
    assign WMemEn = store;

    // MemToReg = LOAD = 1010
    and (MemToReg, op3, not_op2, op1, not_op0);

    // WRegEn = ~(store | nop)
    or  (store_or_nop, store, nop);
    not (WRegEn, store_or_nop);

endmodule
