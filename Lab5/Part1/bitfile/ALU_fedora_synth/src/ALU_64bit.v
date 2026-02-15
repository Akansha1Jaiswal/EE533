`timescale 1ns / 1ps


//`include look_ahead_adder_64.v
//`include BitwiseAND64.v
//`include BitwiseOR64.v
//`include Mux2x1_64Bit.v
//`include Mux4x1_64Bit.v
//`include Mux8x1_64Bit.v
//`include One_Bit_XNOR.v
//`include xnor_64bit.v
//`include shift_then_compare.v
//`include Comparator_64bit.v
//`include Left_Right_64bit_Shifter.v
 
module ALU64 (
    input clk,
    input rst,
    input  [63:0] A, B,
    input  [2:0]  sel,
    output reg [63:0] Result
);

wire [63:0] and_out, or_out, xnor_out;
wire [63:0] add_out, sub_out,Res;
wire A_gt_B, A_lt_B, A_eq_B, Carry;

AND64  u1 (A,B,and_out);
OR64   u2 (A,B,or_out);
XNOR64 u3 (A,B,xnor_out);
look_ahead_adder_64 u4 (A,B,add_out,Carry);
SUB64  u5 (A,B,sub_out);

Shifter_64bit u6 (A,B[5:0],Res);
Comparator_64bit u7 (A,B,A_gt_B,A_lt_B,A_eq_B);
wire [63:0] mux_out;

Mux8x1_64Bit u9 (
    and_out,     // 000
    or_out,      // 001
    xnor_out,    // 010

    add_out,     // 011
    sub_out,     // 100
    Res,         // 101
    {63'b0,A_eq_B}, // 110
    64'b0,       // 111
    sel,
    mux_out
);

always @(posedge clk or posedge rst)
begin
	if(rst)
		Result <= 64'b0;
	else 
		Result <= mux_out;
	end


endmodule
