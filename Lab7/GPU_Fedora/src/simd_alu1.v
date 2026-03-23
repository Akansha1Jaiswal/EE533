//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    21:12:36 03/20/2026 
// Design Name: 
// Module Name:    simd_alu1 
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

module simd_alu1 (

    
    input  enable,          // start operation

    input  [63:0] srcA,
    input  [63:0] srcB,
	 input  [63:0] srcC,
    input  [4:0]  opcode,
    input         bf16_mode,
	input  [3:0]  shift,   
    output reg [15:0] r0_s1,  // Lane 0 result
    output reg [15:0] r1_s1,  // Lane 1 result
    output reg [15:0] r2_s1,  // Lane 2 result
    output reg [15:0] r3_s1,  // Lane 3 result
    output reg  valid_out
);

////////////////////////////////////////////////////////////
// Lane Extraction
////////////////////////////////////////////////////////////
initial $display("SIMD_ALU1 LOADED FROM CORRECT FILE");

wire signed [15:0] a0 = srcA[15:0];
wire signed [15:0] a1 = srcA[31:16];
wire signed [15:0] a2 = srcA[47:32];
wire signed [15:0] a3 = srcA[63:48];

wire signed [15:0] b0 = srcB[15:0];
wire signed [15:0] b1 = srcB[31:16];
wire signed [15:0] b2 = srcB[47:32];
wire signed [15:0] b3 = srcB[63:48];

wire signed [15:0] c0 = srcC[15:0];
wire signed [15:0] c1 = srcC[31:16];
wire signed [15:0] c2 = srcC[47:32];
wire signed [15:0] c3 = srcC[63:48];

////////////////////////////////////////////////////////////
// Stage 1 Registers
////////////////////////////////////////////////////////////

//reg signed [15:0] r0_s1, r1_s1, r2_s1, r3_s1;
//reg               valid_s1;


 //always @(*) begin
    //if (enable)
       // $display("ALU received opcode = %b", opcode);
always @(*) begin
	 r0_s1 = 0;
    r1_s1 = 0;
    r2_s1 = 0;
    r3_s1 = 0;
    valid_out = 0;
        if (enable) begin
		     $display("[ALU1 t=%0t] op=%b srcA=%h srcB=%h", $time, opcode, srcA, srcB);
				
            case(opcode)
					//ADD
                 5'b00110: begin
                    r0_s1 = a0 + b0;
                    r1_s1 = a1 + b1;
                    r2_s1 = a2 + b2;
                    r3_s1 = a3 + b3;
                end

                // SUB
                5'b00111: begin
                    r0_s1 = a0 - b0;
                    r1_s1 = a1 - b1;
                    r2_s1 = a2 - b2;
                    r3_s1 = a3 - b3;
						  
    
						$display("[ALU1-SUB] a=%h b=%h -> r0=%h r1=%h r2=%h r3=%h",
						srcA, srcB, r0_s1, r1_s1, r2_s1, r3_s1);
                end

                // MUL
                5'b01000: begin
                    r0_s1 = a0 * b0;
                    r1_s1 = a1 * b1;
                    r2_s1 = a2 * b2;
                    r3_s1 = a3 * b3;
                end

                // MAC (Fused Multiply Accumulate)
                5'b01001: begin
                    r0_s1 = (a0 * b0) + c0;
                    r1_s1 = (a1 * b1) + c1;
                    r2_s1 = (a2 * b2) + c2;
                    r3_s1 = (a3 * b3) + c3;
                end
					 
					 // SHL
                5'b10001: begin
                    r0_s1 = a0 <<< shift;
                    r1_s1 = a1 <<< shift;
                    r2_s1 = a2 <<< shift;
                    r3_s1 = a3 <<< shift;
                end

                // SHR (arithmetic)
                5'b10010: begin
                    r0_s1 = a0 >>> shift;
                    r1_s1 = a1 >>> shift;
                    r2_s1 = a2 >>> shift;
                    r3_s1 = a3 >>> shift;
                end

                // MAX
                5'b10011: begin
                    r0_s1 = (a0 > b0) ? a0 : b0;
                    r1_s1 = (a1 > b1) ? a1 : b1;
                    r2_s1 = (a2 > b2) ? a2 : b2;
                    r3_s1 = (a3 > b3) ? a3 : b3;
                end

                // MOVE
                5'b00100: begin
                    r0_s1 = a0;
                    r1_s1 = a1;
                    r2_s1 = a2;
                    r3_s1 = a3;
                end


                // RELU
                5'b01010: begin
                    r0_s1 = (a0 > 0) ? a0 : 0;
                    r1_s1 = (a1 > 0) ? a1 : 0;
                    r2_s1 = (a2 > 0) ? a2 : 0;
                    r3_s1 = (a3 > 0) ? a3 : 0;
                end

                default: begin
                    r0_s1 = 0;
                    r1_s1 = 0;
                    r2_s1 = 0;
                    r3_s1 = 0;
                end
            endcase

            valid_out = 1;
        end
        
    
	end


endmodule