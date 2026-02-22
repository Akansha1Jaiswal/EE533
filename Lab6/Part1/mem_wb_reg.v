module mem_wb_reg (
    input  wire        clk,
    input  wire        reset,

    input  wire [31:0] mem_data_in,
    input  wire [31:0] alu_in,
    input  wire [3:0]  rd_in,

    input  wire        RegWrite_in,
    input  wire        MemtoReg_in,

    output reg  [31:0] mem_data_out,
    output reg  [31:0] alu_out,
    output reg  [3:0]  rd_out,

    output reg         RegWrite_out,
    output reg         MemtoReg_out
);

    always @(posedge clk or posedge reset) begin
        if (reset) begin
            mem_data_out <= 0; alu_out <= 0; rd_out <= 0;
            RegWrite_out <= 0; MemtoReg_out <= 0;
        end else begin
            mem_data_out <= mem_data_in;
            alu_out <= alu_in;
            rd_out <= rd_in;
            RegWrite_out <= RegWrite_in;
            MemtoReg_out <= MemtoReg_in;
        end
    end

endmodule