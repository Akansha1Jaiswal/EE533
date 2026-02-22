module ex_mem_reg (
    input  wire        clk,
    input  wire        reset,

    input  wire [31:0] alu_in,
    input  wire [31:0] reg2_in,
    input  wire [3:0]  rd_in,

    input  wire        RegWrite_in,
    input  wire        MemRead_in,
    input  wire        MemWrite_in,
    input  wire        MemtoReg_in,

    output reg  [31:0] alu_out,
    output reg  [31:0] reg2_out,
    output reg  [3:0]  rd_out,

    output reg         RegWrite_out,
    output reg         MemRead_out,
    output reg         MemWrite_out,
    output reg         MemtoReg_out
);

    always @(posedge clk or posedge reset) begin
        if (reset) begin
            alu_out <= 0; reg2_out <= 0; rd_out <= 0;
            RegWrite_out <= 0; MemRead_out <= 0;
            MemWrite_out <= 0; MemtoReg_out <= 0;
        end else begin
            alu_out <= alu_in;
            reg2_out <= reg2_in;
            rd_out <= rd_in;

            RegWrite_out <= RegWrite_in;
            MemRead_out <= MemRead_in;
            MemWrite_out <= MemWrite_in;
            MemtoReg_out <= MemtoReg_in;
        end
    end

endmodule