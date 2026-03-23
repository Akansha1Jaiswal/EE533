//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    21:15:20 03/20/2026 
// Design Name: 
// Module Name:    tensore_core 
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

module tensor_core #(
    parameter LATENCY = 3   // number of cycles tensor takes
)(
    input              clk,
    input              reset,

    input              enable,        // start tensor op
    input      [63:0]  srcA,
    input      [63:0]  srcB,
    input      [63:0]  srcC,

    output reg [63:0]  result,
    output reg         valid_out,
    output reg         stall          // HIGH while tensor busy
);

////////////////////////////////////////////////////////////
// Lane Extraction (4 x 16-bit)
////////////////////////////////////////////////////////////

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
// Internal Registers
////////////////////////////////////////////////////////////

reg [2:0]  counter;
reg        busy;

reg signed [31:0] mac0, mac1, mac2, mac3;

////////////////////////////////////////////////////////////
// Tensor Core FSM (flat logic)
////////////////////////////////////////////////////////////

always @(posedge clk or posedge reset) begin
    if (reset) begin
        busy      <= 0;
        stall     <= 0;
        counter   <= 0;
        valid_out <= 0;
        result    <= 64'd0;
    end
    else begin
        valid_out <= 0;   // default

        //////////////////////////////////////////////////////
        // START CONDITION
        //////////////////////////////////////////////////////
        if (enable && !busy) begin
            busy    <= 1;
            stall   <= 1;
            counter <= LATENCY - 1;

            // Perform MAC computation immediately (stored)
            mac0 <= (a0 * b0) + c0;
            mac1 <= (a1 * b1) + c1;
            mac2 <= (a2 * b2) + c2;
            mac3 <= (a3 * b3) + c3;
        end

        //////////////////////////////////////////////////////
        // BUSY STATE
        //////////////////////////////////////////////////////
        else if (busy) begin
            if (counter != 0) begin
                counter <= counter - 1;
            end
            else begin
                // DONE
                busy      <= 0;
                stall     <= 0;
                valid_out <= 1;

                // Truncate back to 16-bit per lane
                result <= {
                    mac3[15:0],
                    mac2[15:0],
                    mac1[15:0],
                    mac0[15:0]
                };
            end
        end
    end
end

endmodule