`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Module Name: forwarding_unit_mt
// Description: 4-Thread Forwarding Unit
//
// Core rule: forwarding is only valid between instructions of the SAME thread.
// A result in EX/MEM belonging to Thread 1 must never be forwarded into
// Thread 2's EX stage — they have completely separate register banks.
//
// Thread-ID tags flow through every pipeline register (ID/EX, EX/MEM, MEM/WB)
// and are compared here before any forwarding decision is made.
//
// Encoding for forwardA / forwardB (unchanged from single-thread):
//   2'b00 => no forwarding       (use register file output)
//   2'b01 => forward from EX/MEM (ALU result from previous same-thread instr)
//   2'b10 => forward from MEM/WB (writeback value from same-thread instr)
//////////////////////////////////////////////////////////////////////////////////
module forwarding_unit_mt(
    // ID/EX source registers + thread
    input  wire [3:0] ID_EX_Rs,
    input  wire [3:0] ID_EX_Rt,
    input  wire [1:0] ID_EX_thread,       // NEW

    // EX/MEM destination + thread
    input  wire [3:0] EX_MEM_Rd,
    input  wire       EX_MEM_RegWrite,
    input  wire [1:0] EX_MEM_thread,      // NEW

    // MEM/WB destination + thread
    input  wire [3:0] MEM_WB_Rd,
    input  wire       MEM_WB_RegWrite,
    input  wire [1:0] MEM_WB_thread,      // NEW

    // Outputs (encoding unchanged)
    output reg  [1:0] forwardA,
    output reg  [1:0] forwardB
);

    // Thread-match wires: pre-compute once, use in both forwardA and forwardB
    wire exmem_same = (EX_MEM_thread == ID_EX_thread);
    wire memwb_same = (MEM_WB_thread == ID_EX_thread);

    always @(*) begin
        // Default: no forwarding
        forwardA = 2'b00;
        forwardB = 2'b00;

        // ----------------------------------------------------------
        // forwardA — first source operand (ID_EX_Rs / Rn)
        // ----------------------------------------------------------
        if (EX_MEM_RegWrite && exmem_same &&
            (EX_MEM_Rd != 4'b0) && (EX_MEM_Rd == ID_EX_Rs)) begin
            forwardA = 2'b01;   // ALU result from EX/MEM, same thread
        end else if (MEM_WB_RegWrite && memwb_same &&
            (MEM_WB_Rd != 4'b0) && (MEM_WB_Rd == ID_EX_Rs)) begin
            forwardA = 2'b10;   // writeback value from MEM/WB, same thread
        end

        // ----------------------------------------------------------
        // forwardB — second source operand (ID_EX_Rt / Rm)
        // ----------------------------------------------------------
        if (EX_MEM_RegWrite && exmem_same &&
            (EX_MEM_Rd != 4'b0) && (EX_MEM_Rd == ID_EX_Rt)) begin
            forwardB = 2'b01;   // ALU result from EX/MEM, same thread
        end else if (MEM_WB_RegWrite && memwb_same &&
            (MEM_WB_Rd != 4'b0) && (MEM_WB_Rd == ID_EX_Rt)) begin
            forwardB = 2'b10;   // writeback value from MEM/WB, same thread
        end
    end

endmodule