/* file: convertible_fifo.v
 * Description: Convertible FIFO / Dual-Port SRAM (BlockRAM-based)
 *
 * Implements a packet-aware FIFO that buffers exactly one network packet
 * at a time before signalling the processor.  Either BRAM port can be
 * muxed to serve as the processor's memory-mapped SRAM window, giving
 * the CPU full read/write access to packet data, head, and tail registers.
 *
 * Port A  →  WRITE side  (NetFPGA / network pipeline input)
 *            - Tail pointer auto-increments on every write
 *            - Processor can override Port-A address/data via cpu_sel=1
 *
 * Port B  →  READ side   (Processor / FIFO output)
 *            - Head pointer auto-increments when processor pops a word
 *            - Also exposed as optional 2nd SRAM address/data-out port
 *
 * Packet framing:
 *   - din_sof (start-of-frame) marks the first word of a packet
 *   - din_eof (end-of-frame)   marks the last  word of a packet
 *   - On eof the module asserts pkt_ready for one cycle and raises
 *     fifo_full until the processor has consumed all words (head==tail).
 *
 * Controller arbitration (cpu_sel):
 *   0 → FIFO / NetFPGA owns Port-A  (normal FIFO write mode)
 *   1 → Processor  owns Port-A      (random-access SRAM write mode)
 *   Port-B is always readable by the processor.
 *
 * Parameters:
 *   DATA_WIDTH  – word width in bits          (default 32)
 *   ADDR_WIDTH  – BRAM address bits           (default 10 → 1024 words)
 */

`ifndef CONVERTIBLE_FIFO_V
`define CONVERTIBLE_FIFO_V

module convertible_fifo #(
    parameter DATA_WIDTH = 32,
    parameter ADDR_WIDTH = 10
)(
    input  wire                  clk,
    input  wire                  rst_n,

    // ----------------------------------------------------------------
    // Controller interface (Processor / NetFPGA control signals)
    // ----------------------------------------------------------------
    input  wire                  cpu_sel,       // 1 = processor owns Port-A
    input  wire                  pop_en,        // processor: advance head (FIFO read)
    output wire                  fifo_full,     // stall upstream; one packet buffered
    output wire                  fifo_empty,    // head == tail
    output wire                  pkt_ready,     // one-cycle pulse: packet fully buffered

    // ----------------------------------------------------------------
    // Port-A  — FIFO input (NetFPGA pipeline) OR processor SRAM write
    // ----------------------------------------------------------------
    // NetFPGA / FIFO write side
    input  wire                  din_valid,     // upstream data valid
    input  wire                  din_sof,       // start-of-frame
    input  wire                  din_eof,       // end-of-frame
    input  wire [DATA_WIDTH-1:0] din,           // packet data word

    // Processor Port-A override (active when cpu_sel=1)
    input  wire [ADDR_WIDTH-1:0] cpu_a_addr,   // processor write address
    input  wire [DATA_WIDTH-1:0] cpu_a_din,    // processor write data
    input  wire                  cpu_a_we,     // processor write enable

    // SRAM Port-A data-out (always driven by BRAM)
    output wire [DATA_WIDTH-1:0] sram_a_dout,

    // ----------------------------------------------------------------
    // Port-B  — FIFO output / processor SRAM read (2nd data-out port)
    // ----------------------------------------------------------------
    // Processor read address (random access or sequential FIFO pop)
    input  wire [ADDR_WIDTH-1:0] cpu_b_addr,   // processor read address
    input  wire                  cpu_b_re,     // read enable (registered BRAM)

    // FIFO Output / SRAM 2nd Data-Out
    output wire [DATA_WIDTH-1:0] fifo_dout,    // Port-B read data

    // ----------------------------------------------------------------
    // Head / Tail register access (processor memory-mapped registers)
    // ----------------------------------------------------------------
    output wire [ADDR_WIDTH-1:0] head_addr_out,
    output wire [ADDR_WIDTH-1:0] tail_addr_out,

    // Processor can write head/tail directly (e.g. to reset after drain)
    input  wire                  cpu_head_we,
    input  wire [ADDR_WIDTH-1:0] cpu_head_din,
    input  wire                  cpu_tail_we,
    input  wire [ADDR_WIDTH-1:0] cpu_tail_din
);

    // ================================================================
    // Parameters / localparams
    // ================================================================
    localparam DEPTH = 1 << ADDR_WIDTH;   // 2^ADDR_WIDTH words

    // ================================================================
    // Head / Tail registers
    // ================================================================
    reg [ADDR_WIDTH-1:0] head_r;   // next word to read  (Port-B)
    reg [ADDR_WIDTH-1:0] tail_r;   // next word to write (Port-A)

    assign head_addr_out = head_r;
    assign tail_addr_out = tail_r;

    // Occupancy (wrapping arithmetic)
    wire [ADDR_WIDTH-1:0] occupancy = tail_r - head_r;
    assign fifo_empty = (occupancy == {ADDR_WIDTH{1'b0}});

    // ----------------------------------------------------------------
    // Packet framing state
    // ----------------------------------------------------------------
    // fifo_full is raised after a complete packet lands (eof seen) and
    // held until the processor drains it (head catches up to tail).
    reg pkt_buffered;          // one packet is sitting in BRAM

    assign fifo_full  = pkt_buffered;

    // One-cycle pkt_ready pulse when eof is written
    reg pkt_ready_r;
    assign pkt_ready = pkt_ready_r;

    // ----------------------------------------------------------------
    // FIFO write logic (NetFPGA side, cpu_sel=0)
    // ----------------------------------------------------------------
    wire net_write = din_valid & ~cpu_sel & ~pkt_buffered;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            tail_r       <= {ADDR_WIDTH{1'b0}};
            head_r       <= {ADDR_WIDTH{1'b0}};
            pkt_buffered <= 1'b0;
            pkt_ready_r  <= 1'b0;
        end else begin
            pkt_ready_r <= 1'b0;   // default: de-assert pulse

            // -- Tail: FIFO writes (net side) -----------------------
            if (net_write) begin
                tail_r <= tail_r + 1'b1;
                if (din_eof) begin
                    pkt_buffered <= 1'b1;
                    pkt_ready_r  <= 1'b1;
                end
            end

            // -- Tail: processor write (cpu_sel=1, cpu_a_we) --------
            // Processor can manually advance tail after injecting data.
            if (cpu_sel & cpu_tail_we)
                tail_r <= cpu_tail_din;

            // -- Head: pop by processor ------------------------------
            if (pop_en & ~fifo_empty)
                head_r <= head_r + 1'b1;

            // -- Head: processor direct write (reset / drain) --------
            if (cpu_head_we)
                head_r <= cpu_head_din;

            // -- Clear pkt_buffered when packet is fully drained -----
            // (head has wrapped back to tail after processor read-out)
            if (pkt_buffered && (head_r == tail_r))
                pkt_buffered <= 1'b0;
        end
    end

    // ================================================================
    // Port-A mux: NetFPGA FIFO write  vs  processor random-access write
    // ================================================================
    wire [ADDR_WIDTH-1:0] bram_a_addr = cpu_sel ? cpu_a_addr  : tail_r;
    wire [DATA_WIDTH-1:0] bram_a_din  = cpu_sel ? cpu_a_din   : din;
    wire                  bram_a_we   = cpu_sel ? cpu_a_we    : net_write;

    // ================================================================
    // Port-B mux: sequential FIFO pop  vs  processor random-access read
    // ================================================================
    // When cpu_b_re is asserted the processor supplies its own address;
    // otherwise Port-B tracks the head pointer for transparent FIFO reads.
    wire [ADDR_WIDTH-1:0] bram_b_addr = cpu_b_re ? cpu_b_addr : head_r;

    // ================================================================
    // Dual-Port BlockRAM (inferred — synthesis maps to BRAM primitives)
    // Simple Dual-Port: Port-A write-capable, Port-B read-only.
    // Both ports are synchronous (registered outputs, 1-cycle latency).
    // ================================================================
    reg [DATA_WIDTH-1:0] bram [0:DEPTH-1];

    // Port-A: synchronous write, synchronous read-back
    reg [DATA_WIDTH-1:0] bram_a_dout_r;
    always @(posedge clk) begin
        if (bram_a_we)
            bram[bram_a_addr] <= bram_a_din;
        bram_a_dout_r <= bram[bram_a_addr];
    end
    assign sram_a_dout = bram_a_dout_r;

    // Port-B: synchronous read-only
    reg [DATA_WIDTH-1:0] bram_b_dout_r;
    always @(posedge clk) begin
        bram_b_dout_r <= bram[bram_b_addr];
    end
    assign fifo_dout = bram_b_dout_r;

endmodule

`endif // CONVERTIBLE_FIFO_V
