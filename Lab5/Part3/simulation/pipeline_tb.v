`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   20:34:03 02/12/2026
// Design Name:   pipeline_top
// Module Name:   C:/Xilinx/10.1/ISE/Lab_YLR/lab5_2/pipeline_tb.v
// Project Name:  lab5_2
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: pipeline_top
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module pipeline_tb;

	// Inputs
	reg clk;
	reg reset;

	// Instantiate the Unit Under Test (UUT)
	pipeline_top uut (
		.clk(clk), 
		.reset(reset)
	);

   always #10 clk = ~clk;
	
	initial begin
		// Initialize Inputs
		clk = 0;
		reset = 1;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here
      #15;
      reset = 0;
	   #300;
	   $stop;

	end
      
endmodule

