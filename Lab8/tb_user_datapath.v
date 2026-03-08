/* file: tb_user_datapath.v
 * Description: Self-checking testbench for user_datapath GPU integration
 *
 * Test sequence:
 *   1. Send a 4-word network packet (SOF→data→data→EOF) into the FIFO.
 *   2. Wait for pkt_ready interrupt.
 *   3. Pre-load BRAM with two Bfloat16 vectors via ARM CPU write port.
 *   4. Assert gpu_start to trigger arbiter + tensor core.
 *   5. Wait for gpu_done.
 *   6. Read back result from BRAM and verify it is non-zero (positive).
 *   7. Repeat with gpu_fwd_en=1, checking network output carries result.
 *
 * Bfloat16 constants used:
 *   1.0  → 16'h3F80   (exp=127, mant=0)
 *   2.0  → 16'h4000   (exp=128, mant=0)
 *   dot([1,1,1,1],[2,2,2,2]) = 8.0 → 16'h4100  (before ReLU, positive → pass)
 */

`timescale 1ns/1ps

`include "user_datapath.v"

module tb_user_datapath;

    // ----------------------------------------------------------------
    // Parameters
    // ----------------------------------------------------------------
    localparam DATA_WIDTH = 32;
    localparam ADDR_WIDTH = 10;
    localparam CLK_PERIOD = 10;   // 100 MHz

    // ----------------------------------------------------------------
    // DUT signals
    // ----------------------------------------------------------------
    reg                   clk;
    reg                   rst_n;

    // Network input
    reg                   din_valid;
    reg                   din_sof;
    reg                   din_eof;
    reg  [DATA_WIDTH-1:0] din;

    // Network output
    wire [DATA_WIDTH-1:0] dout;
    wire                  dout_valid;
    wire                  dout_sof;
    wire                  dout_eof;

    // ARM CPU
    reg  [ADDR_WIDTH-1:0] arm_a_addr;
    reg  [DATA_WIDTH-1:0] arm_a_din;
    reg                   arm_a_we;
    reg  [ADDR_WIDTH-1:0] arm_b_addr;
    reg                   arm_b_re;
    wire [DATA_WIDTH-1:0] arm_a_dout;
    wire [DATA_WIDTH-1:0] arm_b_dout;

    reg                   arm_pop_en;
    reg                   arm_cpu_head_we;
    reg  [ADDR_WIDTH-1:0] arm_cpu_head_din;
    reg                   arm_cpu_tail_we;
    reg  [ADDR_WIDTH-1:0] arm_cpu_tail_din;

    // GPU control
    reg                   gpu_start;
    reg  [ADDR_WIDTH-1:0] gpu_base_addr;
    reg                   gpu_fwd_en;
    reg  [ADDR_WIDTH-1:0] gpu_result_addr;

    // Status
    wire                  pkt_ready;
    wire                  fifo_full;
    wire                  fifo_empty;
    wire [ADDR_WIDTH-1:0] head_addr_out;
    wire [ADDR_WIDTH-1:0] tail_addr_out;
    wire                  gpu_busy;
    wire                  gpu_done;

    // ----------------------------------------------------------------
    // DUT instantiation
    // ----------------------------------------------------------------
    user_datapath #(
        .DATA_WIDTH(DATA_WIDTH),
        .ADDR_WIDTH(ADDR_WIDTH)
    ) dut (
        .clk             (clk),
        .rst_n           (rst_n),
        .din_valid       (din_valid),
        .din_sof         (din_sof),
        .din_eof         (din_eof),
        .din             (din),
        .dout            (dout),
        .dout_valid      (dout_valid),
        .dout_sof        (dout_sof),
        .dout_eof        (dout_eof),
        .arm_a_addr      (arm_a_addr),
        .arm_a_din       (arm_a_din),
        .arm_a_we        (arm_a_we),
        .arm_b_addr      (arm_b_addr),
        .arm_b_re        (arm_b_re),
        .arm_a_dout      (arm_a_dout),
        .arm_b_dout      (arm_b_dout),
        .arm_pop_en      (arm_pop_en),
        .arm_cpu_head_we (arm_cpu_head_we),
        .arm_cpu_head_din(arm_cpu_head_din),
        .arm_cpu_tail_we (arm_cpu_tail_we),
        .arm_cpu_tail_din(arm_cpu_tail_din),
        .gpu_start       (gpu_start),
        .gpu_base_addr   (gpu_base_addr),
        .gpu_fwd_en      (gpu_fwd_en),
        .gpu_result_addr (gpu_result_addr),
        .pkt_ready       (pkt_ready),
        .fifo_full       (fifo_full),
        .fifo_empty      (fifo_empty),
        .head_addr_out   (head_addr_out),
        .tail_addr_out   (tail_addr_out),
        .gpu_busy        (gpu_busy),
        .gpu_done        (gpu_done)
    );

    // ----------------------------------------------------------------
    // Clock generation
    // ----------------------------------------------------------------
    initial clk = 1'b0;
    always #(CLK_PERIOD/2) clk = ~clk;

    // ----------------------------------------------------------------
    // Test tracking
    // ----------------------------------------------------------------
    integer test_num;
    integer pass_count;
    integer fail_count;

    task check;
        input [127:0] name_bits;   // up to 16 ASCII chars packed
        input         condition;
        begin
            if (condition) begin
                $display("[PASS] t=%0t  %s", $time, name_bits);
                pass_count = pass_count + 1;
            end else begin
                $display("[FAIL] t=%0t  %s", $time, name_bits);
                fail_count = fail_count + 1;
            end
        end
    endtask

    // ----------------------------------------------------------------
    // Helper: ARM CPU write to BRAM via Port-A
    // ----------------------------------------------------------------
    task arm_write;
        input [ADDR_WIDTH-1:0] addr;
        input [DATA_WIDTH-1:0] data;
        begin
            @(posedge clk); #1;
            arm_a_addr = addr;
            arm_a_din  = data;
            arm_a_we   = 1'b1;
            @(posedge clk); #1;
            arm_a_we   = 1'b0;
        end
    endtask

    // ----------------------------------------------------------------
    // Helper: ARM CPU read from BRAM via Port-B
    // ----------------------------------------------------------------
    task arm_read;
        input  [ADDR_WIDTH-1:0] addr;
        output [DATA_WIDTH-1:0] rdata;
        begin
            @(posedge clk); #1;
            arm_b_addr = addr;
            arm_b_re   = 1'b1;
            @(posedge clk); #1;
            arm_b_re   = 1'b0;
            @(posedge clk); #1;   // registered BRAM: 1-cycle latency
            rdata = arm_b_dout;
        end
    endtask

    // ----------------------------------------------------------------
    // Helper: Send a minimal network packet into the FIFO
    // ----------------------------------------------------------------
    task send_packet;
        input [DATA_WIDTH-1:0] w0, w1, w2, w3;
        begin
            @(posedge clk); #1;
            din_valid = 1'b1; din_sof = 1'b1; din_eof = 1'b0; din = w0;
            @(posedge clk); #1;
            din_sof = 1'b0; din = w1;
            @(posedge clk); #1;
            din = w2;
            @(posedge clk); #1;
            din_eof = 1'b1; din = w3;
            @(posedge clk); #1;
            din_valid = 1'b0; din_eof = 1'b0;
        end
    endtask

    // ----------------------------------------------------------------
    // Main test sequence
    // ----------------------------------------------------------------
    reg [DATA_WIDTH-1:0] read_data;

    initial begin
        $dumpfile("tb_user_datapath.vcd");
        $dumpvars(0, tb_user_datapath);

        // Initialise
        pass_count       = 0;
        fail_count       = 0;
        rst_n            = 1'b0;
        din_valid        = 1'b0;
        din_sof          = 1'b0;
        din_eof          = 1'b0;
        din              = {DATA_WIDTH{1'b0}};
        arm_a_addr       = {ADDR_WIDTH{1'b0}};
        arm_a_din        = {DATA_WIDTH{1'b0}};
        arm_a_we         = 1'b0;
        arm_b_addr       = {ADDR_WIDTH{1'b0}};
        arm_b_re         = 1'b0;
        arm_pop_en       = 1'b0;
        arm_cpu_head_we  = 1'b0;
        arm_cpu_head_din = {ADDR_WIDTH{1'b0}};
        arm_cpu_tail_we  = 1'b0;
        arm_cpu_tail_din = {ADDR_WIDTH{1'b0}};
        gpu_start        = 1'b0;
        gpu_base_addr    = {ADDR_WIDTH{1'b0}};
        gpu_fwd_en       = 1'b0;
        gpu_result_addr  = 10'd8;   // writeback slot (after packet)

        repeat(5) @(posedge clk);
        rst_n = 1'b1;
        repeat(2) @(posedge clk);

        // ============================================================
        // TEST 1: Send a packet, verify pkt_ready
        // ============================================================
        $display("\n=== TEST 1: Packet ingestion & pkt_ready ===");
        send_packet(32'hDEAD_BEEF, 32'h0102_0304, 32'hCAFE_BABE, 32'hFFFF_0000);

        // Wait for pkt_ready (up to 20 cycles)
        begin : wait_ready
            integer cnt;
            cnt = 0;
            while (!pkt_ready && cnt < 20) begin
                @(posedge clk); cnt = cnt + 1;
            end
        end
        check("pkt_ready asserted", pkt_ready);
        check("fifo_full asserted", fifo_full);
        check("fifo NOT empty   ", !fifo_empty);

        // ============================================================
        // TEST 2: ARM pre-loads two Bfloat16 vectors into BRAM
        //   addr 0: vector A = [1.0, 1.0, 1.0, 1.0] = 4 × 16'h3F80
        //   addr 1: vector B = [2.0, 2.0, 2.0, 2.0] = 4 × 16'h4000
        //   Expected dot product = 8.0 = 16'h4100 (positive → ReLU pass)
        // ============================================================
        $display("\n=== TEST 2: ARM writes Bfloat16 vectors to BRAM ===");
        // Each 32-bit word holds 2 × Bfloat16
        arm_write(10'd20, {16'h3F80, 16'h3F80});   // A[0], A[1]
        arm_write(10'd21, {16'h3F80, 16'h3F80});   // A[2], A[3]
        arm_write(10'd22, {16'h4000, 16'h4000});   // B[0], B[1]
        arm_write(10'd23, {16'h4000, 16'h4000});   // B[2], B[3]

        arm_read(10'd20, read_data);
        check("Vector A[0-1] stored", read_data == {16'h3F80, 16'h3F80});
        arm_read(10'd22, read_data);
        check("Vector B[0-1] stored", read_data == {16'h4000, 16'h4000});

        // ============================================================
        // TEST 3: GPU tensor core execution (writeback mode)
        // ============================================================
        $display("\n=== TEST 3: GPU dot-product + ReLU, writeback ===");
        gpu_base_addr   = 10'd20;   // arbiter reads addr 20 (A) and 21 (B)
        gpu_result_addr = 10'd30;   // result goes to addr 30
        gpu_fwd_en      = 1'b0;

        @(posedge clk); #1;
        gpu_start = 1'b1;
        @(posedge clk); #1;
        gpu_start = 1'b0;

        // Wait for gpu_done (up to 30 cycles)
        begin : wait_gpu
            integer cnt;
            cnt = 0;
            while (!gpu_done && cnt < 30) begin
                @(posedge clk); cnt = cnt + 1;
            end
        end
        check("GPU done asserted  ", gpu_done);
        check("GPU no longer busy ", !gpu_busy);

        // Read back result
        arm_read(10'd30, read_data);
        check("GPU result non-zero", read_data != 32'h0);
        // MSB should be 0 (positive, ReLU preserved)
        check("GPU result positive", read_data[DATA_WIDTH-1] == 1'b0);
        $display("    GPU result word = 0x%08X", read_data);

        // ============================================================
        // TEST 4: GPU result forwarded to network output (fwd mode)
        // ============================================================
        $display("\n=== TEST 4: GPU result appended to network packet ===");
        gpu_base_addr   = 10'd20;
        gpu_result_addr = 10'd31;
        gpu_fwd_en      = 1'b1;   // forward to output mux

        @(posedge clk); #1;
        gpu_start = 1'b1;
        @(posedge clk); #1;
        gpu_start = 1'b0;

        // Wait for dout_eof (GPU result appended)
        begin : wait_fwd
            integer cnt;
            cnt = 0;
            while (!dout_eof && cnt < 60) begin
                @(posedge clk); cnt = cnt + 1;
            end
        end
        check("GPU fwd: dout_eof seen  ", dout_eof);
        check("GPU fwd: dout_valid high", dout_valid);
        check("GPU fwd: result non-zero", dout != 32'h0);
        $display("    Network output result = 0x%08X", dout);

        // ============================================================
        // TEST 5: Negative input → ReLU clips to zero
        // ============================================================
        $display("\n=== TEST 5: ReLU clips negative dot-product ===");
        // Vector A = [1.0, 1.0, 1.0, 1.0], Vector B = [-2.0,-2.0,-2.0,-2.0]
        // -2.0 in Bfloat16 = 16'hC000 (sign=1, exp=128, mant=0)
        arm_write(10'd40, {16'h3F80, 16'h3F80});
        arm_write(10'd41, {16'h3F80, 16'h3F80});
        arm_write(10'd42, {16'hC000, 16'hC000});
        arm_write(10'd43, {16'hC000, 16'hC000});

        gpu_base_addr   = 10'd40;
        gpu_result_addr = 10'd50;
        gpu_fwd_en      = 1'b0;

        @(posedge clk); #1;
        gpu_start = 1'b1;
        @(posedge clk); #1;
        gpu_start = 1'b0;

        begin : wait_relu
            integer cnt;
            cnt = 0;
            while (!gpu_done && cnt < 30) begin
                @(posedge clk); cnt = cnt + 1;
            end
        end
        arm_read(10'd50, read_data);
        check("ReLU clips negative→0", read_data == 32'h0);
        $display("    ReLU result word  = 0x%08X (expected 0x00000000)", read_data);

        // ============================================================
        // TEST 6: FIFO head/tail drain
        // ============================================================
        $display("\n=== TEST 6: FIFO drains when processor pops ===");
        begin : drain
            integer k;
            for (k = 0; k < 4; k = k + 1) begin
                @(posedge clk); #1;
                arm_pop_en = 1'b1;
                @(posedge clk); #1;
                arm_pop_en = 1'b0;
            end
        end
        @(posedge clk);
        check("FIFO empty after drain", fifo_empty);
        check("FIFO full cleared     ", !fifo_full);

        // ============================================================
        // Summary
        // ============================================================
        $display("\n========================================");
        $display(" RESULTS: %0d PASS  /  %0d FAIL", pass_count, fail_count);
        $display("========================================\n");

        if (fail_count == 0)
            $display("ALL TESTS PASSED ✓");
        else
            $display("SOME TESTS FAILED ✗  — see above");

        $finish;
    end

    // Timeout watchdog
    initial begin
        #100000;
        $display("[TIMEOUT] Simulation exceeded 100 us — aborting.");
        $finish;
    end

endmodule
