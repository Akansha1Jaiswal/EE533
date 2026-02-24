`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    14:29:51 02/20/2026 
// Design Name: 
// Module Name:    result_muc32 
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
module result_mux32(
    input [31:0] add_res,
    //input [31:0] and_res,
    //input [63:0] or_res,
    //input [63:0] xnor_res,
    input [31:0] mov_res,
    //input [63:0] rshift_res,
    //input [63:0] substr_res,
    //input [63:0] shiftcmp_res,
    input ADD,SUB,//AND_OP,//OR_OP,XNOR_OP,
    input MOV,//RSHIFT,SUBSTR_CMP,SHIFT_CMP,
    output [31:0] result
    );

    genvar i;
    generate
        for(i=0;i<32;i=i+1) begin : mux_bits
            wire m0,m1,m2,m3,m4;//,m5,m6,m7,m8,m9;

            and (m0, ADD, add_res[i]);
            and (m1, SUB, add_res[i]);
            //and (m2, AND_OP, and_res[i]);
            //and (m3, OR_OP, or_res[i]);
            //and (m4, XNOR_OP, xnor_res[i]);
            and (m2, MOV, mov_res[i]); //no CMP as compare doesnt write the result
            //and (m4, LSHIFT, lshift_res[i]);
            //and (m7, RSHIFT, rshift_res[i]);
            //and (m8, SUBSTR_CMP, substr_res[i]);
            //and (m9, SHIFT_CMP, shiftcmp_res[i]);

            wire o1;

            or (o1,m0,m1);
            //or (o2,m2,m3);
				//or (o3,o1,o2);
				
            //or (o3,m4,m5);
            //or (o4,m6,m7);
            //or (o5,m8,m9);

            //wire o6,o7;
            //or (o6,o1,o2);
            //or (o7,o3,o4);

            //wire o8;
            //or (o8,o6,o7);

            or (result[i],o1,m2);
        end
    endgenerate

endmodule
