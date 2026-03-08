/* file: user_datapath.v
 * Description: Top-level User Datapath
 *
 * Integrates the following blocks as shown in the architecture diagram:
 *
 *   ┌─────────────────────────────────────────────────────────────┐
 *   │                       user_datapath                         │
 *   │                                                             │
 *   │  8G Network ──► Custom FIFO ──► Convertible Mem/FIFO ──►   │
 *   │                     (BRAM, dual-port, 72-bit/144-bit)       │
 *   │                        │  ▲                    │            │
 *   │                   ARM ISA CPU        GPU Arbiter MUX        │
 *   │                        │              │                     │
 *   │                   Simple CPU ──► Tensor Core (Bf16 ReLU)   │
 *   │                                        │                    │
 *   │                            GPU result ─┴──► Network Output  │
 *   └─────────────────────────────────────────────────────────────┘
 *
 * Packet flow:
 *   1. Incoming 8 Gbps packet enters convertible_fifo via din_* signals.
 *   2. On pkt_ready (eof seen), ARM CPU is interrupted.
 *   3. ARM programs gpu_base_addr and asserts gpu_start.
 *   4. gpu_bram_arbiter double-reads BRAM (ports A & B at N, N+1)
 *      providing 144 bits/cycle to gpu_tensor_core.
 *   5. Tensor core pipelines Bfloat16 dot-product + ReLU (4-cycle latency).
 *   6. Result is either written back to BRAM or forwarded directly to
 *      the output mux and emitted as a new network packet.
 *
 * Parameters:
 *   DATA_WIDTH  – BRAM word width (default 32; set to 72 for full 72-bit mode)
 *   ADDR_WIDTH  – BRAM address bits (default 10 → 1024 words)
 */

`ifndef USER_DATAPATH_V
`define USER_DATAPATH_V

`include "convertible_fifo.v"
`include "gpu_bram_arbiter.v"
`include "gpu_tensor_core.v"

module user_datapath #(
    parameter DATA_WIDTH = 32,
    parameter ADDR_WIDTH = 10
)(
    input  wire clk,
    input  wire rst_n,

    // ----------------------------------------------------------------
    // 8 Gbps Network Input (from Custom FIFO Circuit)
    // ----------------------------------------------------------------
    input  wire                  din_valid,
    input  wire                  din_sof,
    input  wire                  din_eof,
    input  wire [DATA_WIDTH-1:0] din,

    // ----------------------------------------------------------------
    // 8 Gbps Network Output
    // ----------------------------------------------------------------
    output reg  [DATA_WIDTH-1:0] dout,
    output reg                   dout_valid,
    output reg                   dout_sof,
    output reg                   dout_eof,

    // ----------------------------------------------------------------
    // ARM CPU interface
    // ----------------------------------------------------------------
    input  wire [ADDR_WIDTH-1:0] arm_a_addr,
    input  wire [DATA_WIDTH-1:0] arm_a_din,
    input  wire                  arm_a_we,
    input  wire [ADDR_WIDTH-1:0] arm_b_addr,
    input  wire                  arm_b_re,
    output wire [DATA_WIDTH-1:0] arm_a_dout,
    output wire [DATA_WIDTH-1:0] arm_b_dout,

    // ARM controls FIFO head/tail directly
    input  wire                  arm_pop_en,
    input  wire                  arm_cpu_head_we,
    input  wire [ADDR_WIDTH-1:0] arm_cpu_head_din,
    input  wire                  arm_cpu_tail_we,
    input  wire [ADDR_WIDTH-1:0] arm_cpu_tail_din,

    // ARM triggers GPU
    input  wire                  gpu_start,
    input  wire [ADDR_WIDTH-1:0] gpu_base_addr,
    input  wire                  gpu_fwd_en,       // 1=forward result to net out
    input  wire [ADDR_WIDTH-1:0] gpu_result_addr,  // writeback address

    // ----------------------------------------------------------------
    // Status / interrupts to ARM
    // ----------------------------------------------------------------
    output wire                  pkt_ready,        // interrupt: packet buffered
    output wire                  fifo_full,
    output wire                  fifo_empty,
    output wire [ADDR_WIDTH-1:0] head_addr_out,
    output wire [ADDR_WIDTH-1:0] tail_addr_out,
    output wire                  gpu_busy,
    output wire                  gpu_done
);

    // ================================================================
    // Internal wires — FIFO ↔ Arbiter
    // ================================================================
    wire [ADDR_WIDTH-1:0] cf_cpu_a_addr;
    wire [DATA_WIDTH-1:0] cf_cpu_a_din;
    wire                  cf_cpu_a_we;
    wire                  cf_cpu_sel;
    wire [ADDR_WIDTH-1:0] cf_cpu_b_addr;
    wire                  cf_cpu_b_re;
    wire [DATA_WIDTH-1:0] cf_sram_a_dout;
    wire [DATA_WIDTH-1:0] cf_fifo_dout;

    // ================================================================
    // Internal wires — Arbiter ↔ Tensor Core
    // ================================================================
    wire [71:0] gpu_port_a_data;
    wire [71:0] gpu_port_b_data;
    wire        gpu_data_valid;

    wire        tc_done;
    wire        tc_busy;
    wire [15:0] tc_result_bf16;
    wire [31:0] tc_result_fp32;
    wire        tc_result_valid;

    // GPU result write-back
    wire [DATA_WIDTH-1:0] gpu_result_data = tc_result_fp32[DATA_WIDTH-1:0];
    wire                  gpu_result_we   = tc_result_valid;

    // GPU forward path (bypass BRAM → straight to network output)
    wire [DATA_WIDTH-1:0] gpu_fwd_data;
    wire                  gpu_fwd_valid;

    assign gpu_done = tc_done;
    assign gpu_busy = tc_busy;

    // ================================================================
    // 1. Convertible FIFO (Block RAM)
    // ================================================================
    convertible_fifo #(
        .DATA_WIDTH(DATA_WIDTH),
        .ADDR_WIDTH(ADDR_WIDTH)
    ) u_cf (
        .clk            (clk),
        .rst_n          (rst_n),

        // Controller / CPU
        .cpu_sel        (cf_cpu_sel),
        .pop_en         (arm_pop_en),
        .fifo_full      (fifo_full),
        .fifo_empty     (fifo_empty),
        .pkt_ready      (pkt_ready),

        // Network FIFO write
        .din_valid      (din_valid),
        .din_sof        (din_sof),
        .din_eof        (din_eof),
        .din            (din),

        // Port-A CPU override (from arbiter)
        .cpu_a_addr     (cf_cpu_a_addr),
        .cpu_a_din      (cf_cpu_a_din),
        .cpu_a_we       (cf_cpu_a_we),
        .sram_a_dout    (cf_sram_a_dout),

        // Port-B CPU read (from arbiter)
        .cpu_b_addr     (cf_cpu_b_addr),
        .cpu_b_re       (cf_cpu_b_re),
        .fifo_dout      (cf_fifo_dout),

        // Head / Tail register access
        .head_addr_out  (head_addr_out),
        .tail_addr_out  (tail_addr_out),
        .cpu_head_we    (arm_cpu_head_we),
        .cpu_head_din   (arm_cpu_head_din),
        .cpu_tail_we    (arm_cpu_tail_we),
        .cpu_tail_din   (arm_cpu_tail_din)
    );

    // ================================================================
    // 2. GPU BRAM Arbiter (MUX / DEMUX)
    // ================================================================
    gpu_bram_arbiter #(
        .DATA_WIDTH(DATA_WIDTH),
        .ADDR_WIDTH(ADDR_WIDTH)
    ) u_arb (
        .clk            (clk),
        .rst_n          (rst_n),

        // → Convertible FIFO Port-A/B overrides
        .cf_cpu_a_addr  (cf_cpu_a_addr),
        .cf_cpu_a_din   (cf_cpu_a_din),
        .cf_cpu_a_we    (cf_cpu_a_we),
        .cf_cpu_sel     (cf_cpu_sel),
        .cf_cpu_b_addr  (cf_cpu_b_addr),
        .cf_cpu_b_re    (cf_cpu_b_re),

        // ← FIFO BRAM readback
        .cf_sram_a_dout (cf_sram_a_dout),
        .cf_fifo_dout   (cf_fifo_dout),

        // ARM CPU pass-through
        .arm_a_addr     (arm_a_addr),
        .arm_a_din      (arm_a_din),
        .arm_a_we       (arm_a_we),
        .arm_b_addr     (arm_b_addr),
        .arm_b_re       (arm_b_re),
        .arm_a_dout     (arm_a_dout),
        .arm_b_dout     (arm_b_dout),

        // GPU tensor core data feed
        .gpu_req        (gpu_start),
        .gpu_base_addr  (gpu_base_addr),
        .gpu_port_a_data(gpu_port_a_data),
        .gpu_port_b_data(gpu_port_b_data),
        .gpu_data_valid (gpu_data_valid),

        // GPU result write-back / forward
        .gpu_result_we  (gpu_result_we),
        .gpu_result_addr(gpu_result_addr),
        .gpu_result_data(gpu_result_data),
        .gpu_fwd_en     (gpu_fwd_en),
        .gpu_fwd_data   (gpu_fwd_data),
        .gpu_fwd_valid  (gpu_fwd_valid),

        .arbiter_busy   ()
    );

    // ================================================================
    // 3. GPU Tensor Core — Pipelined Bfloat16 Dot-Product + ReLU
    // ================================================================
    gpu_tensor_core #(
        .VEC_LEN   (4),
        .DATA_WIDTH(72)
    ) u_tc (
        .clk            (clk),
        .rst_n          (rst_n),
        .start          (gpu_data_valid),
        .done           (tc_done),
        .busy           (tc_busy),
        .bram_port_a_data(gpu_port_a_data),
        .bram_port_b_data(gpu_port_b_data),
        .result_bf16    (tc_result_bf16),
        .result_fp32    (tc_result_fp32),
        .result_valid   (tc_result_valid)
    );

    // ================================================================
    // 4. Network Output MUX
    //    Normal path : FIFO read-out (cf_fifo_dout + FIFO head pointer)
    //    GPU forward : GPU result injected after packet header
    // ================================================================
    // Simple state machine: emit FIFO contents first, then append GPU result
    localparam OUT_IDLE    = 2'd0;
    localparam OUT_PKT     = 2'd1;   // streaming FIFO packet to network
    localparam OUT_GPU_INJ = 2'd2;   // injecting GPU result word

    reg [1:0] out_state;
    reg       pkt_sent;   // all FIFO words forwarded

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            out_state  <= OUT_IDLE;
            dout       <= {DATA_WIDTH{1'b0}};
            dout_valid <= 1'b0;
            dout_sof   <= 1'b0;
            dout_eof   <= 1'b0;
            pkt_sent   <= 1'b0;
        end else begin
            dout_valid <= 1'b0;
            dout_sof   <= 1'b0;
            dout_eof   <= 1'b0;

            case (out_state)
                OUT_IDLE: begin
                    if (pkt_ready) begin
                        out_state <= OUT_PKT;
                        pkt_sent  <= 1'b0;
                    end
                end

                OUT_PKT: begin
                    // Drain FIFO words to network output
                    if (!fifo_empty) begin
                        dout       <= cf_fifo_dout;
                        dout_valid <= 1'b1;
                        dout_sof   <= (head_addr_out == {ADDR_WIDTH{1'b0}});
                    end
                    // When FIFO drains, decide if we inject GPU result
                    if (fifo_empty) begin
                        pkt_sent  <= 1'b1;
                        out_state <= gpu_fwd_en ? OUT_GPU_INJ : OUT_IDLE;
                    end
                end

                OUT_GPU_INJ: begin
                    // Append GPU result word as trailing payload
                    if (gpu_fwd_valid) begin
                        dout       <= gpu_fwd_data;
                        dout_valid <= 1'b1;
                        dout_eof   <= 1'b1;   // this word ends the packet
                        out_state  <= OUT_IDLE;
                    end
                end

                default: out_state <= OUT_IDLE;
            endcase
        end
    end

endmodule
`endif // USER_DATAPATH_V
