//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    21:15:46 03/20/2026 
// Design Name: 
// Module Name:    simd_alu2 
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
`timescale 1ns/1ps
module simd_alu2 (

    input         enable,          // start operation

    input  [15:0] r0_s1,
    input  [15:0] r1_s1,
    input  [15:0] r2_s1,
    input  [15:0] r3_s1,
    

    output reg [63:0] result,
    output reg  valid_out
);

////////////////////////////////////////////////////////////
// Stage 2 (Pack result)
////////////////////////////////////////////////////////////

always @(*) begin
    if (enable) begin
        result = {
            r3_s1,
            r2_s1,
            r1_s1,
            r0_s1
        };
        valid_out = 1'b1;
    end
    else begin
        result = 64'b0;
        valid_out = 1'b0;
    end
end

endmodule
