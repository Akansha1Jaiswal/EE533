`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Module Name: ID_EX_mt
// Description: ID/EX Pipeline Register — 4-Thread Version
//              Only change from single-thread: thread_id[1:0] is added
//              as an input and carried through to the EX stage using
//              the same stage_register_n primitive as all other fields.
//////////////////////////////////////////////////////////////////////////////////
module ID_EX_mt(
    input  wire        clk,
    input  wire        reset,
    input  wire        flush,

    input  wire [31:0] rs_data_in,
    input  wire [31:0] rt_data_in,
    input  wire [31:0] pc_plus1_in,

    input  wire [3:0]  cond_in,
    input  wire [3:0]  dp_opcode_in,
    input  wire        S_in,
    input  wire        is_dp_in,
    input  wire        is_ldr_in,
    input  wire        is_str_in,
    input  wire        is_branch_in,
    input  wire        is_bx_in,
    input  wire signed [31:0] branch_offset_in,
    input  wire [3:0]  Rd_in,
    input  wire [4:0]  shamt_in,
    input  wire        I_in,
    input  wire [31:0] imm32_in,
    input  wire [3:0]  Rn_in,
    input  wire [3:0]  Rm_in,
    input  wire [11:0] offset12_in,
    input  wire        U_in,
    input  wire [3:0]  alu_opcode_in,
    input  wire        ALUSrc_in,
    input  wire [1:0]  thread_id_in,        // NEW

    output wire [3:0]  alu_opcode_out,
    output wire        ALUSrc_out,
    output wire [11:0] offset12_out,
    output wire        U_out,
    output wire [3:0]  Rn_out,
    output wire [3:0]  Rm_out,
    output wire        I_out,
    output wire [31:0] imm32_out,
    output wire [31:0] rs_data_out,
    output wire [31:0] rt_data_out,
    output wire [31:0] pc_plus1_out,
    output wire [3:0]  cond_out,
    output wire [3:0]  dp_opcode_out,
    output wire        S_out,
    output wire        is_dp_out,
    output wire        is_ldr_out,
    output wire        is_str_out,
    output wire        is_branch_out,
    output wire        is_bx_out,
    output wire signed [31:0] branch_offset_out,
    output wire [3:0]  Rd_out,
    output wire [4:0]  shamt_out,
    output wire [1:0]  thread_id_out         // NEW
);

    // ----------------------------------------------------------------
    // Flush muxes — identical to original, thread_id zeroed on flush
    // ----------------------------------------------------------------
    wire [31:0] rs_d   = flush ? 32'b0    : rs_data_in;
    wire [31:0] rt_d   = flush ? 32'b0    : rt_data_in;
    wire [31:0] pc_d   = flush ? 32'b0    : pc_plus1_in;
    wire [3:0]  cond_d = flush ? 4'b1110  : cond_in;
    wire [1:0]  tid_d  = flush ? 2'b0     : thread_id_in;  // NEW

    // ----------------------------------------------------------------
    // All existing registers — unchanged from original
    // ----------------------------------------------------------------
    stage_register_n #(12) offset12_reg (.clk(clk), .reset(reset), .d(flush ? 12'b0   : offset12_in),      .q(offset12_out));
    stage_register_n #(1)  U_reg        (.clk(clk), .reset(reset), .d(flush ? 1'b0    : U_in),             .q(U_out));
    stage_register_n #(32) rs_reg       (.clk(clk), .reset(reset), .d(rs_d),                               .q(rs_data_out));
    stage_register_n #(32) rt_reg       (.clk(clk), .reset(reset), .d(rt_d),                               .q(rt_data_out));
    stage_register_n #(32) pc_reg       (.clk(clk), .reset(reset), .d(pc_d),                               .q(pc_plus1_out));
    stage_register_n #(4)  cond_reg     (.clk(clk), .reset(reset), .d(cond_d),                             .q(cond_out));
    stage_register_n #(4)  opcode_reg   (.clk(clk), .reset(reset), .d(flush ? 4'b0    : dp_opcode_in),     .q(dp_opcode_out));
    stage_register_n #(1)  S_reg        (.clk(clk), .reset(reset), .d(flush ? 1'b0    : S_in),             .q(S_out));
    stage_register_n #(1)  dp_reg       (.clk(clk), .reset(reset), .d(flush ? 1'b0    : is_dp_in),         .q(is_dp_out));
    stage_register_n #(1)  ldr_reg      (.clk(clk), .reset(reset), .d(flush ? 1'b0    : is_ldr_in),        .q(is_ldr_out));
    stage_register_n #(1)  str_reg      (.clk(clk), .reset(reset), .d(flush ? 1'b0    : is_str_in),        .q(is_str_out));
    stage_register_n #(1)  br_reg       (.clk(clk), .reset(reset), .d(flush ? 1'b0    : is_branch_in),     .q(is_branch_out));
    stage_register_n #(1)  bx_reg       (.clk(clk), .reset(reset), .d(flush ? 1'b0    : is_bx_in),         .q(is_bx_out));
    stage_register_n #(32) off_reg      (.clk(clk), .reset(reset), .d(flush ? 32'sb0  : branch_offset_in), .q(branch_offset_out));
    stage_register_n #(4)  rd_reg       (.clk(clk), .reset(reset), .d(flush ? 4'b0    : Rd_in),            .q(Rd_out));
    stage_register_n #(5)  shamt_reg    (.clk(clk), .reset(reset), .d(flush ? 5'b0    : shamt_in),         .q(shamt_out));
    stage_register_n #(1)  I_reg        (.clk(clk), .reset(reset), .d(flush ? 1'b0    : I_in),             .q(I_out));
    stage_register_n #(32) imm32_reg    (.clk(clk), .reset(reset), .d(flush ? 32'b0   : imm32_in),         .q(imm32_out));
    stage_register_n #(4)  Rn_reg       (.clk(clk), .reset(reset), .d(flush ? 4'b0    : Rn_in),            .q(Rn_out));
    stage_register_n #(4)  Rm_reg       (.clk(clk), .reset(reset), .d(flush ? 4'b0    : Rm_in),            .q(Rm_out));
    stage_register_n #(4)  aluop_reg    (.clk(clk), .reset(reset), .d(flush ? 4'b0    : alu_opcode_in),    .q(alu_opcode_out));
    stage_register_n #(1)  alusrc_reg   (.clk(clk), .reset(reset), .d(flush ? 1'b0    : ALUSrc_in),        .q(ALUSrc_out));

    // ----------------------------------------------------------------
    // NEW: thread_id register — same primitive, 2-bit wide
    // ----------------------------------------------------------------
    stage_register_n #(2)  tid_reg      (.clk(clk), .reset(reset), .d(tid_d),                              .q(thread_id_out));

    // ----------------------------------------------------------------
    // Debug monitor — updated to show thread_id
    // ----------------------------------------------------------------
    always @(posedge clk) begin
        $display("------------------------------------------------");
        $display("[DBG_IDEX_MT] t=%0t  flush=%b  reset=%b  thread=%0d", $time, flush, reset, thread_id_in);

        $display("  IN : Rn=%0d Rm=%0d Rd=%0d I=%b imm32=%08h offset12=%03h U=%b",
                 Rn_in, Rm_in, Rd_in, I_in, imm32_in, offset12_in, U_in);
        $display("       rs_data=%08h rt_data=%08h pc_plus1=%08h",
                 rs_data_in, rt_data_in, pc_plus1_in);
        $display("       cond=%b dp_opcode=%b alu_opcode=%b ALUSrc=%b",
                 cond_in, dp_opcode_in, alu_opcode_in, ALUSrc_in);
        $display("       is_dp=%b is_ldr=%b is_str=%b is_branch=%b is_bx=%b",
                 is_dp_in, is_ldr_in, is_str_in, is_branch_in, is_bx_in);

        $display("  OUT: Rn=%0d Rm=%0d Rd=%0d I=%b imm32=%08h offset12=%03h U=%b thread=%0d",
                 Rn_out, Rm_out, Rd_out, I_out, imm32_out, offset12_out, U_out, thread_id_out);
        $display("       rs_data=%08h rt_data=%08h pc_plus1=%08h",
                 rs_data_out, rt_data_out, pc_plus1_out);
        $display("       cond=%b dp_opcode=%b alu_opcode=%b ALUSrc=%b",
                 cond_out, dp_opcode_out, alu_opcode_out, ALUSrc_out);
        $display("       is_dp=%b is_ldr=%b is_str=%b is_branch=%b is_bx=%b",
                 is_dp_out, is_ldr_out, is_str_out, is_branch_out, is_bx_out);
    end

endmodule