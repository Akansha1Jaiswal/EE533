`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Module Name: regfile_mt
// Description: 4-Thread Register File using a single block memory
//
// Address scheme: {thread_id[1:0], reg_num[3:0]} = 6-bit address
//   - Thread 0: addresses 0x00 - 0x0F  (r0-r15)
//   - Thread 1: addresses 0x10 - 0x1F  (r0-r15)
//   - Thread 2: addresses 0x20 - 0x2F  (r0-r15)
//   - Thread 3: addresses 0x30 - 0x3F  (r0-r15)
//
// Double-clocking:
//   - READ  on posedge clk  (combinational pass-through with write-first)
//   - WRITE on negedge clk  (off-phase to avoid read/write port conflict)
//
// This replaces the dec4to16 + 16x stage_register_we + 2x mux16to1_32
// structure with a single 64x32 memory array.
//////////////////////////////////////////////////////////////////////////////////
module regfile_bram_mt(
    input  wire        clk,
    input  wire        reset,

    // Write port (from WB stage)
    input  wire        we,
    input  wire [1:0]  wr_thread,      // which thread is writing back
    input  wire [3:0]  wr_addr,        // register number (0-15)
    input  wire [31:0] wr_data,

    // Read port 1 (Rn / Rs)
    input  wire [1:0]  rd_thread1,     // which thread is reading
    input  wire [3:0]  rd_addr1,       // register number
    output reg  [31:0] rd_data1,

    // Read port 2 (Rm / Rt)
    input  wire [1:0]  rd_thread2,
    input  wire [3:0]  rd_addr2,
    output reg  [31:0] rd_data2
);

    // ----------------------------------------------------------------
    // 64-entry x 32-bit memory: index = {thread_id[1:0], reg_num[3:0]}
    // ----------------------------------------------------------------
    reg [31:0] mem [0:63];

    // Full 6-bit addresses
    wire [5:0] wr_full_addr = {wr_thread,  wr_addr };
    wire [5:0] rd_full_addr1 = {rd_thread1, rd_addr1};
    wire [5:0] rd_full_addr2 = {rd_thread2, rd_addr2};

    // ----------------------------------------------------------------
    // Initialise all registers to 0, except each thread's R13 (SP)
    // Thread 0 SP = mem[0x0D], Thread 1 SP = mem[0x1D]
    // Thread 2 SP = mem[0x2D], Thread 3 SP = mem[0x3D]
    // ----------------------------------------------------------------
    integer i;
    initial begin
        for (i = 0; i < 64; i = i + 1)
            mem[i] = 32'd0;
        // Initialise stack pointers for all 4 threads
        mem[6'h0D] = 32'h00000200;   // Thread 0 SP
        mem[6'h1D] = 32'h00000400;   // Thread 1 SP
        mem[6'h2D] = 32'h00000600;   // Thread 2 SP
        mem[6'h3D] = 32'h00000800;   // Thread 3 SP
    end

    // ----------------------------------------------------------------
    // WRITE on negedge (double-clocking: off-phase from the reads)
    // ----------------------------------------------------------------
    always @(negedge clk) begin
        if (we)
            mem[wr_full_addr] <= wr_data;
    end

    // ----------------------------------------------------------------
    // READ on posedge (registered outputs)
    // Write-first: if reading the address being written this cycle,
    // return the new write data immediately (bypass).
    // ----------------------------------------------------------------
    always @(posedge clk or posedge reset) begin
        if (reset) begin
            rd_data1 <= 32'd0;
            rd_data2 <= 32'd0;
        end else begin
            // Port 1 — write-first bypass
            if (we && (wr_full_addr == rd_full_addr1))
                rd_data1 <= wr_data;
            else
                rd_data1 <= mem[rd_full_addr1];

            // Port 2 — write-first bypass
            if (we && (wr_full_addr == rd_full_addr2))
                rd_data2 <= wr_data;
            else
                rd_data2 <= mem[rd_full_addr2];
        end
    end

    // ----------------------------------------------------------------
    // Debug monitor
    // ----------------------------------------------------------------
    always @(posedge clk) begin
        $display("[DBG_REGFILE_MT] t=%0t | RD1 T%0d[r%02d]=%08h | RD2 T%0d[r%02d]=%08h | WB T%0d[r%02d]=%08h we=%b",
            $time,
            rd_thread1, rd_addr1, rd_data1,
            rd_thread2, rd_addr2, rd_data2,
            wr_thread,  wr_addr,  wr_data, we);
    end

endmodule