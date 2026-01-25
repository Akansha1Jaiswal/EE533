module shifter(

    input [31:0] A,
    input wire shift,
    output [31:0] Q,
);
    always @(*) begin
        if (shift) begin
            Q = A << 1;
        end else begin
            Q = A >> 1;
        end
    end
endmodule