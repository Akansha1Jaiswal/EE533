module id_ex_reg (
    input  wire        clk,
    input  wire        reset,
    input  wire        flush,          // Branch flush

    // ========================
    // Data Inputs
    // ========================
    input  wire [31:0] pc_in,
    input  wire [31:0] reg1_in,
    input  wire [31:0] reg2_in,
    input  wire [31:0] imm_in,
    input  wire [3:0]  rd_in,

    // ========================
    // Control Inputs
    // ========================
    input  wire        RegWrite_in,
    input  wire        MemRead_in,
    input  wire        MemWrite_in,
    input  wire        MemtoReg_in,
    input  wire        ALUSrc_in,
    input  wire [3:0]  ALUControl_in,
    input  wire        Branch_in,

    // ========================
    // Data Outputs
    // ========================
    output reg  [31:0] pc_out,
    output reg  [31:0] reg1_out,
    output reg  [31:0] reg2_out,
    output reg  [31:0] imm_out,
    output reg  [3:0]  rd_out,

    // ========================
    // Control Outputs
    // ========================
    output reg         RegWrite_out,
    output reg         MemRead_out,
    output reg         MemWrite_out,
    output reg         MemtoReg_out,
    output reg         ALUSrc_out,
    output reg  [3:0]  ALUControl_out,
    output reg         Branch_out
);

    always @(posedge clk or posedge reset) begin
        if (reset) begin
            // Clear everything
            pc_out <= 32'd0;
            reg1_out <= 32'd0;
            reg2_out <= 32'd0;
            imm_out <= 32'd0;
            rd_out <= 4'd0;

            RegWrite_out <= 1'b0;
            MemRead_out  <= 1'b0;
            MemWrite_out <= 1'b0;
            MemtoReg_out <= 1'b0;
            ALUSrc_out   <= 1'b0;
            ALUControl_out <= 4'd0;
            Branch_out <= 1'b0;
        end

        else if (flush) begin
            // Inject bubble (NOP)
            pc_out <= 32'd0;
            reg1_out <= 32'd0;
            reg2_out <= 32'd0;
            imm_out <= 32'd0;
            rd_out <= 4'd0;

            RegWrite_out <= 1'b0;
            MemRead_out  <= 1'b0;
            MemWrite_out <= 1'b0;
            MemtoReg_out <= 1'b0;
            ALUSrc_out   <= 1'b0;
            ALUControl_out <= 4'd0;
            Branch_out <= 1'b0;
        end

        else begin
            // Normal pipeline advance
            pc_out <= pc_in;
            reg1_out <= reg1_in;
            reg2_out <= reg2_in;
            imm_out <= imm_in;
            rd_out <= rd_in;

            RegWrite_out <= RegWrite_in;
            MemRead_out  <= MemRead_in;
            MemWrite_out <= MemWrite_in;
            MemtoReg_out <= MemtoReg_in;
            ALUSrc_out   <= ALUSrc_in;
            ALUControl_out <= ALUControl_in;
            Branch_out <= Branch_in;
        end
    end

endmodule