`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    23:02:38 02/11/2026 
// Design Name: 
// Module Name:    opcode_decoder 
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
module opcode_decoder(
	 input  [3:0] opcode,
    output ADD, //0100
    output SUB, //0010
	 output MOV, //1101
    //output AND_OP,
    //output OR_OP,
    //output XNOR_OP,
    output CMP //1010
    //output LSHIFT,
    //output RSHIFT,
    //output SUBSTR_CMP,
    //output SHIFT_CMP
    );

    wire n3,n2,n1,n0;
    not (n3, opcode[3]);
    not (n2, opcode[2]);
    not (n1, opcode[1]);
    not (n0, opcode[0]);

    // 0100
    and (ADD, n3,opcode[2],n1,n0);

    // 0010
    and (SUB, n3,n2,opcode[1],n0);
	 
	 // 1101
    and (MOV, opcode[3],opcode[2],n1,opcode[0]);

    // 0010
    //and (AND_OP, n3,n2,opcode[1],n0);

    // 0011
    //and (OR_OP, n3,n2,opcode[1],opcode[0]);

    // 0100
    //and (XNOR_OP, n3,opcode[2],n1,n0);

    // 1010
    and (CMP, opcode[3],n2,opcode[1],n0);

    // 0110
    //and (LSHIFT, opcode[3],opcode[2],n1,opcode[0]);

    // 0111
    //and (RSHIFT, n3,opcode[2],opcode[1],opcode[0]);

    // 1000
    //and (SUBSTR_CMP, opcode[3],n2,n1,n0);

    // 1001
    //and (SHIFT_CMP, opcode[3],n2,n1,opcode[0]);

endmodule
