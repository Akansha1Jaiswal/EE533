module alu_32bit (
    input        clk,
    input        rst_n,
    input [31:0] A,
    input [31:0] B,
    input [2:0]  Alu_op,
    output reg [31:0] result
);

    reg [31:0] counter;

    // -----------------------------
    // 32-bit Counter (Sequential)
    // -----------------------------
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n)
            counter <= 32'b0;
        else
            counter <= counter + 32'b1;
    end

  
    always @(*) begin
        case (Alu_op)

            3'b000: result = A + B;          // ADD (32-bit)
            3'b001: result = A - B;          // SUB (32-bit)
            3'b010: result = A | B;          // OR  (32-bit)
            3'b011: result = A << 1;         // 1-bit left shift
            3'b100: result = A >> 1;         // 1-bit right shift
            3'b101: result = counter;        // 32-bit counter

            default: result = 32'b0;

        endcase
    end

endmodule
