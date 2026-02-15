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
module alu64(
    input  [63:0] A,
    input  [63:0] B,
    input  [3:0]  opcode,
    output [63:0] result,
    output zero_flag,
    output Cout,
    output overflow_flag,
    output SLT
    );

    wire ADD,SUB,AND_OP,OR_OP,XNOR_OP;
    wire CMP,LSHIFT,RSHIFT,SUBSTR_CMP,SHIFT_CMP;

    opcode_decoder dec(
        opcode,
        ADD,SUB,AND_OP,OR_OP,XNOR_OP,
        CMP,LSHIFT,RSHIFT,SUBSTR_CMP,SHIFT_CMP
    );

    wire [63:0] add_res;
    wire final_carry;
    wire carry_63;

    ripple_adder64 addsub(
        .a(A),
        .b(B),
        .binv(SUB),
        .cin(SUB),
        .sum(add_res),
        .cout(final_carry),
        .carry_63(carry_63)
    );

    wire [63:0] and_res, or_res, xnor_res;

    bitwise_and64  u1(A,B,and_res);
    bitwise_or64   u2(A,B,or_res);
    bitwise_xnor64 u3(A,B,xnor_res);

    wire [63:0] lshift_res, rshift_res;

    barrel_left_64  bl(A,B[5:0],lshift_res);
    barrel_right_64 br(A,B[5:0],rshift_res);

    wire cmp_overflow;
    wire sub_msb;

    overflow_flag64 ov_unit(
        carry_63,
        final_carry,
        ADD,
        SUB,
        cmp_overflow
    );

    assign sub_msb = add_res[63];

    slt_signed slt_unit(
        sub_msb,
        cmp_overflow,
        SLT
    );

    wire [63:0] cmp_res;
    assign cmp_res = {63'b0, SLT};

    wire sub16_eq;
    equal16 eq16(A[15:0],B[15:0],sub16_eq);
    wire [63:0] substr_res;
    assign substr_res = {63'b0, sub16_eq};

    wire shift_eq;
    equal64 eq64(lshift_res,B,shift_eq);
    wire [63:0] shiftcmp_res;
    assign shiftcmp_res = {63'b0, shift_eq};

    result_mux64 mux(
        add_res,
        and_res,
        or_res,
        xnor_res,
        cmp_res,
        lshift_res,
        rshift_res,
        substr_res,
        shiftcmp_res,
        ADD,SUB,AND_OP,OR_OP,XNOR_OP,
        CMP,LSHIFT,RSHIFT,SUBSTR_CMP,SHIFT_CMP,
        result
    );

    zero_flag64 zf(result,zero_flag);

    carry_out_flag cf(
        final_carry,
        ADD,
        SUB,
        Cout
    );

    overflow_flag64 of2(
        carry_63,
        final_carry,
        ADD,
        SUB,
        overflow_flag
    );

endmodule
