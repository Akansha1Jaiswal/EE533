module or32bit (
    input  wire [31:0] a,
    input  wire [31:0] b,
    output wire [31:0] Q
);
    assign Q = a | b;
endmodule