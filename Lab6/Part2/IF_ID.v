`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Module Name: IF_ID_mt
// Description: IF/ID Pipeline Register — 4-Thread Version
//              Adds thread_id field that travels with the instruction
//              through the pipeline so every downstream stage knows
//              which thread it is working on.
//////////////////////////////////////////////////////////////////////////////////
module IF_ID_mt(
    input  wire        clk,
    input  wire        reset,
    input  wire        write_enable,       // from HDU (stall)
    input  wire        flush,              // from branch_taken
    input  wire [31:0] instruction_in,
    input  wire [31:0] pc_plus1_in,
    input  wire [1:0]  thread_id_in,       // NEW: which thread is fetching

    output wire [31:0] instruction_out,
    output wire [31:0] pc_plus1_out,
    output wire [1:0]  thread_id_out       // NEW: carries thread_id to ID stage
);

localparam NOP = 32'hE1A00000;

wire [31:0] inst_d = flush ? NOP    : instruction_in;
wire [31:0] pc_d   = flush ? 32'b0  : pc_plus1_in;
wire [1:0]  tid_d  = flush ? 2'b0   : thread_id_in;  // flush zeroes thread_id too

stage_register_we #(32) inst_reg ( .clk(clk), .reset(reset), .we(write_enable), .d(inst_d), .q(instruction_out) );
stage_register_we #(32) pc_reg   ( .clk(clk), .reset(reset), .we(write_enable), .d(pc_d),   .q(pc_plus1_out)    );
stage_register_we #(2)  tid_reg  ( .clk(clk), .reset(reset), .we(write_enable), .d(tid_d),  .q(thread_id_out)   );

endmodule