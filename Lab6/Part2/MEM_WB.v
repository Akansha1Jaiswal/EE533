`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Module Name: MEM_WB_mt
// Description: MEM/WB Pipeline Register — 4-Thread Version
//              Only change from single-thread: thread_id[1:0] is added
//              and carried through using the same stage_register_n primitive.
//              The WB stage uses thread_id to index the correct thread's
//              register bank in regfile_mt via {thread_id, rd} addressing.
//////////////////////////////////////////////////////////////////////////////////
module MEM_WB_mt(
    input  wire        clk,
    input  wire        reset,

    // Inputs from MEM (unchanged)
    input  wire [31:0] alu_result_in,
    input  wire [31:0] mem_data_in,
    input  wire [3:0]  rd_in,
    input  wire        WRegEn_in,
    input  wire        MemToReg_in,
    input  wire [1:0]  thread_id_in,       // NEW

    // Outputs to WB (unchanged)
    output wire [31:0] alu_result_out,
    output wire [31:0] mem_data_out,
    output wire [3:0]  rd_out,
    output wire        WRegEn_out,
    output wire        MemToReg_out,
    output wire [1:0]  thread_id_out       // NEW
);

    // ----------------------------------------------------------------
    // All existing registers — completely unchanged from original
    // ----------------------------------------------------------------
    stage_register_n #(32) alu_reg  (.clk(clk), .reset(reset), .d(alu_result_in), .q(alu_result_out));
    stage_register_n #(32) mem_reg  (.clk(clk), .reset(reset), .d(mem_data_in),   .q(mem_data_out));
    stage_register_n #(4)  rd_reg   (.clk(clk), .reset(reset), .d(rd_in),         .q(rd_out));
    stage_register_n #(1)  wreg_reg (.clk(clk), .reset(reset), .d(WRegEn_in),     .q(WRegEn_out));
    stage_register_n #(1)  mtr_reg  (.clk(clk), .reset(reset), .d(MemToReg_in),   .q(MemToReg_out));

    // ----------------------------------------------------------------
    // NEW: thread_id register — same primitive, 2-bit wide
    // ----------------------------------------------------------------
    stage_register_n #(2)  tid_reg  (.clk(clk), .reset(reset), .d(thread_id_in),  .q(thread_id_out));

    // ----------------------------------------------------------------
    // Debug monitor — updated to show thread_id
    // ----------------------------------------------------------------
    always @(posedge clk)
        $display("WB: thread=%0d WRegEn=%b Rd=%d MemToReg=%b mem_data=%h alu=%h",
                 thread_id_out, WRegEn_out, rd_out, MemToReg_out,
                 mem_data_out, alu_result_out);

endmodule