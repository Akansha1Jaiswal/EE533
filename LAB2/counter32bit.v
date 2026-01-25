module counter32bit (
    input wire clk,
    input wire rst,
    output reg [31:0] Q
);
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            Q <= 32'b0;
        end else begin
            Q <= Q + 1;
        end
    end
endmodule
