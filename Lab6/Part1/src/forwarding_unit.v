`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    21:49:26 02/20/2026 
// Design Name: 
// Module Name:    forwarding_unit 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
// Compares destination registers in EX/MEM and MEM/WB stages to source registers in ID/EX.
// Outputs 2-bit selectors for ALU operand multiplexers in EX stage.
//
// Encoding for forwardX:
//   2'b00 => no forward (use ID/EX register file values)
//   2'b01 => forward from EX/MEM (ALU result from previous cycle)
//   2'b10 => forward from MEM/WB (value that will be written back)
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module forwarding_unit(
    // ID/EX source register indices (the registers whose values are needed in EX)
    input  wire [3:0] ID_EX_Rs,   // first source (typically Rn)
    input  wire [3:0] ID_EX_Rt,   // second source (typically Rm for store)

    // EX/MEM destination
    input  wire [3:0] EX_MEM_Rd,
    input  wire       EX_MEM_RegWrite,

    // MEM/WB destination
    input  wire [3:0] MEM_WB_Rd,
    input  wire       MEM_WB_RegWrite,

    // Outputs
    output reg  [1:0] forwardA,
    output reg  [1:0] forwardB
    );
	 
    always @(*) begin
        // default: no forwarding
        forwardA = 2'b00;
        forwardB = 2'b00;

        // forward A (ID_EX_Rs)
        if (EX_MEM_RegWrite && (EX_MEM_Rd != 4'b0) && (EX_MEM_Rd == ID_EX_Rs)) begin
            forwardA = 2'b01; // take ALU result from EX/MEM
        end else if (MEM_WB_RegWrite && (MEM_WB_Rd != 4'b0) && (MEM_WB_Rd == ID_EX_Rs)) begin
            forwardA = 2'b10; // take result from MEM/WB
        end

        // forward B (ID_EX_Rt)
        if (EX_MEM_RegWrite && (EX_MEM_Rd != 4'b0) && (EX_MEM_Rd == ID_EX_Rt)) begin
            forwardB = 2'b01;
        end else if (MEM_WB_RegWrite && (MEM_WB_Rd != 4'b0) && (MEM_WB_Rd == ID_EX_Rt)) begin
            forwardB = 2'b10;
        end
    end

endmodule
