`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    23:15:44 02/11/2026 
// Design Name: 
// Module Name:    carry_out_flag 
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
module carry_out_flag(
    input  final_carry,
    input  is_add,
    input  is_sub,
    output Cout
    );

    wire add_or_sub;

    or  g1 (add_or_sub, is_add, is_sub);
    and g2 (Cout, add_or_sub, final_carry);

endmodule
