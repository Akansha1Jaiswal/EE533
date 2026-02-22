module register_file (
    input  wire        clk,
    input  wire        we,
    input  wire [3:0]  ra1,
    input  wire [3:0]  ra2,
    input  wire [3:0]  wa,
    input  wire [31:0] wd,
    output wire [31:0] rd1,
    output wire [31:0] rd2
);

    reg [31:0] regfile [0:15];

    assign rd1 = regfile[ra1];
    assign rd2 = regfile[ra2];

    always @(posedge clk) begin
        if (we && wa != 4'd15)   // avoid writing PC here
            regfile[wa] <= wd;
    end

endmodule