`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    23:16:24 02/11/2026 
// Design Name: 
// Module Name:    overflow_flag64 
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
module overflow_flag32(
    input  carry_31,
    input  carry_32,
    input  is_add,
    input  is_sub,
    output overflow_flag
    );

    wire raw_overflow;
    wire add_or_sub;

    xor g1 (raw_overflow, carry_31, carry_32);
    or  g2 (add_or_sub, is_add, is_sub);
    and g3 (overflow_flag, add_or_sub, raw_overflow);

endmodule
