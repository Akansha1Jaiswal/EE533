/* file: tb_convertible_fifo.v
 * Testbench — Convertible FIFO / Dual-Port SRAM
 * Compatible with Xilinx ISim (ISE 14.x)
 *
 * ISim restrictions observed:
 *   - No localparam in testbench modules  → use `define
 *   - No packed-string task inputs used as %s args  → use `define macro checks
 *   - No integer loop variables in initial blocks   → use repeat + reg counter
 *   - No automatic tasks
 *   - Avoid %0s; use %d / %h format specifiers only
 *
 * Tests:
 *   1. NetFPGA writes a 4-word packet (sof→eof) → pkt_ready pulse, fifo_full
 *   2. Processor drains packet via pop_en       → fifo_full clears
 *   3. Processor SRAM random write (cpu_sel=1) then random read (Port-B)
 *   4. Processor direct head/tail register writes
 *   5. NetFPGA upstream stalled (tail frozen) while fifo_full
 */

`timescale 1ns/1ps

`define DW 32
`define AW 10

// Inline pass/fail macro — avoids packed-string task args that crash ISim.
// 'msg' is an unquoted identifier used as a label in $display; ISim
// accepts bare identifiers in string positions inside macros.
`define CHECK(cond, msg) \
    if (cond) begin \
        $display("  PASS: msg"); \
        pass_count = pass_count + 8'd1; \
    end else begin \
        $display("  FAIL: msg  (head=%d tail=%d full=%b empty=%b)", \
                 head_addr_out, tail_addr_out, fifo_full, fifo_empty); \
        fail_count = fail_count + 8'd1; \
    end

module tb_convertible_fifo;

    // ------------------------------------------------------------------
    // DUT ports
    // ------------------------------------------------------------------
    reg              clk;
    reg              rst_n;
    reg              cpu_sel;
    reg              pop_en;
    reg              din_valid;
    reg              din_sof;
    reg              din_eof;
    reg  [`DW-1:0]   din;
    reg  [`AW-1:0]   cpu_a_addr;
    reg  [`DW-1:0]   cpu_a_din;
    reg              cpu_a_we;
    reg  [`AW-1:0]   cpu_b_addr;
    reg              cpu_b_re;
    reg              cpu_head_we;
    reg              cpu_tail_we;
    reg  [`AW-1:0]   cpu_head_din;
    reg  [`AW-1:0]   cpu_tail_din;

    wire             fifo_full;
    wire             fifo_empty;
    wire             pkt_ready;
    wire [`DW-1:0]   sram_a_dout;
    wire [`DW-1:0]   fifo_dout;
    wire [`AW-1:0]   head_addr_out;
    wire [`AW-1:0]   tail_addr_out;

    // ------------------------------------------------------------------
    // DUT
    // ------------------------------------------------------------------
    convertible_fifo #(
        .DATA_WIDTH (`DW),
        .ADDR_WIDTH (`AW)
    ) dut (
        .clk          (clk),
        .rst_n        (rst_n),
        .cpu_sel      (cpu_sel),
        .pop_en       (pop_en),
        .fifo_full    (fifo_full),
        .fifo_empty   (fifo_empty),
        .pkt_ready    (pkt_ready),
        .din_valid    (din_valid),
        .din_sof      (din_sof),
        .din_eof      (din_eof),
        .din          (din),
        .cpu_a_addr   (cpu_a_addr),
        .cpu_a_din    (cpu_a_din),
        .cpu_a_we     (cpu_a_we),
        .sram_a_dout  (sram_a_dout),
        .cpu_b_addr   (cpu_b_addr),
        .cpu_b_re     (cpu_b_re),
        .fifo_dout    (fifo_dout),
        .head_addr_out(head_addr_out),
        .tail_addr_out(tail_addr_out),
        .cpu_head_we  (cpu_head_we),
        .cpu_head_din (cpu_head_din),
        .cpu_tail_we  (cpu_tail_we),
        .cpu_tail_din (cpu_tail_din)
    );

    // ------------------------------------------------------------------
    // 10 ns clock
    // ------------------------------------------------------------------
    initial clk = 1'b0;
    always #5 clk = ~clk;

    // ------------------------------------------------------------------
    // Counters (plain reg — ISim safe)
    // ------------------------------------------------------------------
    reg [7:0] pass_count;
    reg [7:0] fail_count;
    reg [7:0] pop_cnt;

    // ------------------------------------------------------------------
    // Tasks  (ISim: simple scalar inputs only)
    // ------------------------------------------------------------------
    task tick;
        begin
            @(posedge clk);
            #1;
        end
    endtask

    task net_write_word;
        input [`DW-1:0] data;
        input           sof;
        input           eof;
        begin
            din_valid = 1'b1;
            din       = data;
            din_sof   = sof;
            din_eof   = eof;
            tick;
            din_valid = 1'b0;
            din_sof   = 1'b0;
            din_eof   = 1'b0;
        end
    endtask

    // ------------------------------------------------------------------
    // Stimulus
    // ------------------------------------------------------------------
    initial begin
        rst_n        = 1'b0;
        cpu_sel      = 1'b0;
        pop_en       = 1'b0;
        din_valid    = 1'b0;
        din_sof      = 1'b0;
        din_eof      = 1'b0;
        din          = {`DW{1'b0}};
        cpu_a_addr   = {`AW{1'b0}};
        cpu_a_din    = {`DW{1'b0}};
        cpu_a_we     = 1'b0;
        cpu_b_addr   = {`AW{1'b0}};
        cpu_b_re     = 1'b0;
        cpu_head_we  = 1'b0;
        cpu_tail_we  = 1'b0;
        cpu_head_din = {`AW{1'b0}};
        cpu_tail_din = {`AW{1'b0}};
        pass_count   = 8'd0;
        fail_count   = 8'd0;
        pop_cnt      = 8'd0;

        repeat(3) tick;
        rst_n = 1'b1;
        tick;

        // ==============================================================
        $display("");
        $display("=== Test 1: NetFPGA writes a 4-word packet ===");
        // ==============================================================
        `CHECK(fifo_empty == 1'b1,  initially_empty)
        `CHECK(fifo_full  == 1'b0,  not_full_before_packet)

        net_write_word(32'hDEAD0001, 1'b1, 1'b0);   // SOF
        net_write_word(32'hDEAD0002, 1'b0, 1'b0);
        net_write_word(32'hDEAD0003, 1'b0, 1'b0);
        net_write_word(32'hDEAD0004, 1'b0, 1'b1);   // EOF

        `CHECK(pkt_ready     == 1'b1,   pkt_ready_pulse_after_EOF)
        `CHECK(fifo_full     == 1'b1,   fifo_full_raised_after_packet)
        `CHECK(fifo_empty    == 1'b0,   not_empty_after_write)
        `CHECK(tail_addr_out == 10'd4,  tail_advanced_to_4)

        tick;
        `CHECK(pkt_ready == 1'b0, pkt_ready_deasserted_next_cycle)

        // ==============================================================
        $display("");
        $display("=== Test 2: Processor drains packet via pop_en ===");
        // ==============================================================
        // Port-B BRAM output is registered (1-cycle latency).
        // head_r is the read address presented to Port-B.
        // Sequence per word:
        //   - head_r already points at the word we want to read
        //   - Wait one tick so BRAM output captures bram[head_r]
        //   - Display fifo_dout (now valid)
        //   - Assert pop_en for one tick to advance head_r to next word
        pop_cnt = 8'd0;
        repeat(4) begin
            // Step 1: let BRAM latch the current head address
            tick;
            // Step 2: fifo_dout is now valid for bram[head_r-before-pop]
            $display("  word[%d] = 0x%h  (head=%d)", pop_cnt, fifo_dout, head_addr_out);
            // Step 3: advance head to next word
            pop_en = 1'b1; tick;
            pop_en = 1'b0;
            pop_cnt = pop_cnt + 8'd1;
        end
        tick;

        `CHECK(fifo_empty              == 1'b1,  empty_after_draining_4_words)
        `CHECK(fifo_full               == 1'b0,  fifo_full_cleared_when_drained)
        `CHECK(head_addr_out == tail_addr_out,   head_equals_tail_after_drain)

        // ==============================================================
        $display("");
        $display("=== Test 3: CPU SRAM random-access write then read ===");
        // ==============================================================
        // Cycle 0: write CAFEBABE to address 100 via Port-A (cpu_sel=1)
        // Cycle 1: hold cpu_b_addr=100, cpu_b_re=1 so Port-B address
        //          is stable at 100 when the clock edge fires
        // Cycle 2: BRAM registered output now contains bram[100]; sample
        cpu_sel    = 1'b1;
        cpu_a_addr = 10'd100;
        cpu_a_din  = 32'hCAFEBABE;
        cpu_a_we   = 1'b1;
        // Also pre-set Port-B address this cycle so it is stable
        cpu_b_addr = 10'd100;
        cpu_b_re   = 1'b1;
        tick;                   // Cycle 0→1: write committed to BRAM
        cpu_a_we   = 1'b0;
        // Port-B addr still 100, cpu_b_re still 1
        tick;                   // Cycle 1→2: BRAM Port-B latches addr 100
        cpu_b_re   = 1'b0;
        // fifo_dout now valid
        `CHECK(fifo_dout == 32'hCAFEBABE, cpu_random_write_readback)
        cpu_sel = 1'b0;

        // ==============================================================
        $display("");
        $display("=== Test 4: CPU direct head/tail register writes ===");
        // ==============================================================
        cpu_head_we  = 1'b1;
        cpu_head_din = 10'd50;
        tick;
        cpu_head_we = 1'b0;
        tick;
        `CHECK(head_addr_out == 10'd50, cpu_direct_head_write)

        cpu_sel      = 1'b1;
        cpu_tail_we  = 1'b1;
        cpu_tail_din = 10'd75;
        tick;
        cpu_tail_we = 1'b0;
        cpu_sel     = 1'b0;
        tick;
        `CHECK(tail_addr_out == 10'd75, cpu_direct_tail_write_via_cpu_sel)

        // ==============================================================
        $display("");
        $display("=== Test 5: NetFPGA blocked while fifo_full ===");
        // ==============================================================
        // Reset head and tail to 0
        cpu_head_we  = 1'b1;
        cpu_head_din = 10'd0;
        tick;
        cpu_head_we = 1'b0;

        cpu_sel      = 1'b1;
        cpu_tail_we  = 1'b1;
        cpu_tail_din = 10'd0;
        tick;
        cpu_tail_we = 1'b0;
        cpu_sel     = 1'b0;
        tick;

        // 1-word packet (SOF + EOF same word)
        net_write_word(32'hABCD1234, 1'b1, 1'b1);
        tick;
        `CHECK(fifo_full == 1'b1, fifo_full_after_1word_packet)

        // Attempt blocked write — tail must stay at 1
        net_write_word(32'hFFFFFFFF, 1'b1, 1'b0);
        tick;
        `CHECK(tail_addr_out == 10'd1, tail_frozen_while_fifo_full)

        // ==============================================================
        $display("");
        $display("=== Summary ===");
        $display("  Passed : %d", pass_count);
        $display("  Failed : %d", fail_count);
        if (fail_count == 8'd0)
            $display("  ALL TESTS PASSED");
        else
            $display("  SOME TESTS FAILED");
        $display("");

        $finish;
    end

    initial begin
        #50000;
        $display("TIMEOUT");
        $finish;
    end

endmodule
