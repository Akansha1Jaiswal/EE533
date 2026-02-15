// Verilog test fixture created from schematic C:\Xilinx\10.1\ISE\Lab_YLR\lab5_2\alu64_syn.sch - Wed Feb 11 23:42:35 2026

`timescale 1ns / 1ps

module alu64_syn_alu64_syn_sch_tb();

// Inputs
   reg clk;
   reg [63:0] A;
   reg [63:0] B;
   reg [3:0] opcode;

// Output
   wire [63:0] Result;
   wire SLT;
   wire Overflow_flag;
   wire Cout;
   wire Zero_flag;

// Bidirs

// Instantiate the UUT
   alu64_syn UUT (
		.clk(clk), 
		.A(A), 
		.B(B), 
		.opcode(opcode), 
		.Result(Result), 
		.SLT(SLT), 
		.Overflow_flag(Overflow_flag), 
		.Cout(Cout), 
		.Zero_flag(Zero_flag)
   );
	
	initial clk = 0;
   always #10 clk = ~clk;

// Initialize Inputs
	
	   initial begin
        A = 0;
        B = 0;
        opcode = 0;

        #25;

        A = 64'd25; B = 64'd10; opcode = 4'b0000; #40;
        A = 64'd25; B = 64'd30; opcode = 4'b0001; #40;

        A = 64'hFF00FF00FF00FF00; 
        B = 64'h0F0F0F0F0F0F0F0F; 
        opcode = 4'b0010; #40;

        opcode = 4'b0011; #40;
        opcode = 4'b0100; #40;

        A = -64'd5; B = 64'd3; opcode = 4'b0101; #40;

        A = 64'h0000000000000001; 
        B = 64'd4; 
        opcode = 4'b0110; #40;

        A = 64'h8000000000000000; 
        B = 64'd4; 
        opcode = 4'b0111; #40;

        A = 64'h000000000000AAAA; 
        B = 64'hFFFFFFFFFFFFAAAA; 
        opcode = 4'b1000; #40;

        A = 64'd2; B = 64'd3; opcode = 4'b1001; #40;
        A = 64'd1; B = 64'd3; opcode = 4'b1001; #40;

        $stop;
   end

endmodule
