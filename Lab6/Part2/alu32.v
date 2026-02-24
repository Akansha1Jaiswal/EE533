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
    output [31:0] result,
    output zero_flag, //Z
    output Cout, //C
    output overflow_flag, //V
    output neg_flag //N
    );


	 
    wire ADD,SUB;
    wire MOV,CMP;

    opcode_decoder dec(
        opcode,
        ADD,SUB,
        MOV,CMP
    );

    wire [31:0] add_res;
    wire final_carry;
    wire carry_31;

    ripple_adder32 addsub(
        .a(A),
        .b(B),
        .binv(SUB | CMP), //CMP also does SUB only
        .cin(SUB | CMP),
        .sum(add_res),
        .cout(final_carry),
        .carry_31(carry_31)
    );

    wire [31:0] and_res, or_res, xnor_res;

    bitwise_and32  u1(A,B,and_res);
    //bitwise_or32   u2(A,B,or_res);//redundant for now
    //bitwise_xnor32 u3(A,B,xnor_res);//redundant for now

    wire [31:0] lshift_res, rshift_res;
	 wire carry_out;//from leftshift
	 wire [31:0] mov_res;

    barrel_left_32  bl(B,shamt,lshift_res,carry_out); //A and B are reversed - operand 2 is the data on which shift happens
    //barrel_right_32 br(A,B[5:0],rshift_res);
	 assign mov_res = lshift_res;

//    wire sub16_eq;
//    equal16 eq16(A[15:0],B[15:0],sub16_eq);
//    wire [63:0] substr_res;
//    assign substr_res = {63'b0, sub16_eq};
//
//    wire shift_eq;
//    equal64 eq64(lshift_res,B,shift_eq);
//    wire [63:0] shiftcmp_res;
//    assign shiftcmp_res = {63'b0, shift_eq};

	 
	 result_mux32 mux(
		 add_res,      
       mov_res,
       ADD,
		 SUB,
       MOV,
       result
    );
	 
	 wire [31:0] flags_input;
	 assign flags_input = (CMP) ? add_res : result; //CMP doesn't write to result so for flags computation for CMP adding a mux here
	 
    zero_flag32 zf(
		  .result(flags_input),
		  .zero_flag(zero_flag)
	 );
	 
	 assign neg_flag = flags_input[31];

	 assign Cout = (ADD | SUB | CMP) ? final_carry : carry_out;//either adder carry or lsl carry

    overflow_flag32 of2(
        .carry_31(carry_31),
        .carry_32(final_carry),
        .is_add(ADD),
        .is_sub(SUB | CMP),
        .overflow_flag(overflow_flag)
    );

endmodule
