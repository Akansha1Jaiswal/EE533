`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   23:19:02 02/11/2026
// Design Name:   alu64
// Module Name:   C:/Xilinx/10.1/ISE/Lab_YLR/lab5_2/alu64_test.v
// Project Name:  lab5_2
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: alu64
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module alu64_test;

	// Inputs
	reg [63:0] A;
	reg [63:0] B;
	reg [3:0] opcode;

	// Outputs
	wire [63:0] result;
	wire zero_flag;
	wire Cout;
	wire overflow_flag;
	wire SLT;

	// Instantiate the Unit Under Test (UUT)
	alu64 uut (
		.A(A), 
		.B(B), 
		.opcode(opcode), 
		.result(result), 
		.zero_flag(zero_flag), 
		.Cout(Cout), 
		.overflow_flag(overflow_flag), 
		.SLT(SLT)
	);

	initial begin
		// Initialize Inputs
		A = 0;
		B = 0;
		opcode = 0;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here
		A = 64'd25; B = 64'd10; opcode = 4'b0000; #20;

		A = 64'd25; B = 64'd30; opcode = 4'b0001; #20;

		A = 64'hFF00FF00FF00FF00; 
		B = 64'h0F0F0F0F0F0F0F0F; 
		opcode = 4'b0010; #20;

		opcode = 4'b0011; #20;

		opcode = 4'b0100; #20;

		A = -64'd5; 
		B = 64'd3; 
		opcode = 4'b0101; #20;

		A = 64'h0000000000000001; 
		B = 64'd4; 
		opcode = 4'b0110; #20;

		A = 64'h8000000000000000; 
		B = 64'd4; 
		opcode = 4'b0111; #20;

		A = 64'h000000000000AAAA; 
		B = 64'hFFFFFFFFFFFFAAAA; 
		opcode = 4'b1000; #20;

		A = 64'd2; 
		B = 64'd3; 
		opcode = 4'b1001; #20;

		A = 64'd1; 
		B = 64'd3; 
		opcode = 4'b1001; #20;

		$stop;

	end
      
endmodule

