/* file: gpu_tensor_core.v
 * Description: Pipelined Bfloat16 Dot-Product + ReLU Tensor Core
 *
 * Implements a simple GPU-style tensor core that:
 *   1. Accepts two vectors of Bfloat16 operands read from dual BRAM ports
 *   2. Computes element-wise multiply-accumulate (dot product) in Bfloat16
 *   3. Applies ReLU activation to the accumulated result
 *   4. Outputs a 32-bit result (Bfloat16 in upper 16 bits, zero-padded)
 *
 * Bfloat16 format: [15] sign | [14:7] exponent (8-bit) | [6:0] mantissa (7-bit)
 *
 * Pipeline stages (latency = 4 clock cycles):
 *   Stage 1: Unpack Bfloat16 operands, align exponents
 *   Stage 2: Multiply mantissas (partial products)
 *   Stage 3: Accumulate partial products
 *   Stage 4: Normalize, ReLU, repack to Bfloat16
 *
 * Parameters:
 *   VEC_LEN     – number of Bfloat16 elements per vector (default 4)
 *   DATA_WIDTH  – BRAM port width (default 72, carries 4x Bf16 + metadata)
 */

`ifndef GPU_TENSOR_CORE_V
`define GPU_TENSOR_CORE_V

module gpu_tensor_core #(
    parameter VEC_LEN    = 4,   // elements per dot-product vector
    parameter DATA_WIDTH = 72   // BRAM dual-port combined width
)(
    input  wire        clk,
    input  wire        rst_n,

    // ----------------------------------------------------------------
    // Control interface (from ARM CPU / Simple CPU)
    // ----------------------------------------------------------------
    input  wire        start,          // pulse: begin computation
    output reg         done,           // pulse: result ready
    output reg         busy,           // asserted during pipeline fill

    // ----------------------------------------------------------------
    // BRAM dual-port data input
    // Port A (addr N)   → vector A operands
    // Port B (addr N+1) → vector B operands
    // Each 72-bit word carries 4 × Bfloat16 (64 bits) + 8 tag bits
    // ----------------------------------------------------------------
    input  wire [71:0] bram_port_a_data,  // 4 × Bf16 operands, vector A
    input  wire [71:0] bram_port_b_data,  // 4 × Bf16 operands, vector B

    // ----------------------------------------------------------------
    // Result output
    // ----------------------------------------------------------------
    output reg  [15:0] result_bf16,    // ReLU(dot(A,B)) in Bfloat16
    output reg  [31:0] result_fp32,    // same value widened to fp32
    output reg         result_valid    // result_bf16/fp32 valid
);

    // ================================================================
    // Bfloat16 unpacking — extract 4 elements from each 72-bit word
    // Bits [71:64] are metadata/tag, ignored by tensor core.
    // Layout: [63:48]=e0, [47:32]=e1, [31:16]=e2, [15:0]=e3
    // ================================================================
    wire [15:0] a [0:3];
    wire [15:0] b [0:3];

    genvar gi;
    generate
        for (gi = 0; gi < 4; gi = gi + 1) begin : unpack
            assign a[gi] = bram_port_a_data[16*(3-gi) +: 16];
            assign b[gi] = bram_port_b_data[16*(3-gi) +: 16];
        end
    endgenerate

    // ================================================================
    // Bfloat16 field extraction helpers (combinational, per element)
    // ================================================================
    // sign     = [15]
    // exponent = [14:7]
    // mantissa = [6:0] (implicit leading 1 when exp != 0)

    // ================================================================
    // Pipeline registers
    // ================================================================

    // --- Stage 1: unpack & align ------------------------------------
    reg        s1_valid;
    reg [7:0]  s1_exp_a  [0:3];
    reg [7:0]  s1_exp_b  [0:3];
    reg [7:0]  s1_mant_a [0:3];  // 7-bit + implicit 1 → stored as 8-bit
    reg [7:0]  s1_mant_b [0:3];
    reg        s1_sign_a [0:3];
    reg        s1_sign_b [0:3];

    // --- Stage 2: multiply mantissas --------------------------------
    reg        s2_valid;
    reg [15:0] s2_prod_mant [0:3];   // 8×8 product
    reg [8:0]  s2_prod_exp  [0:3];   // exp_a + exp_b – bias(127)
    reg        s2_prod_sign [0:3];

    // --- Stage 3: accumulate ----------------------------------------
    reg        s3_valid;
    // We accumulate in a 32-bit fixed-point scratch space after
    // aligning each product to a common exponent (max exponent).
    reg signed [31:0] s3_accum;
    reg [8:0]         s3_max_exp;

    // --- Stage 4: normalize + ReLU + repack -------------------------
    // (outputs result_bf16, result_valid)

    // ================================================================
    // Stage 1: unpack (registered)
    // ================================================================
    integer i;
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            s1_valid <= 1'b0;
        end else begin
            s1_valid <= start;
            for (i = 0; i < 4; i = i + 1) begin
                s1_sign_a[i] <= a[i][15];
                s1_exp_a [i] <= a[i][14:7];
                // prepend implicit leading 1 (treat subnormals as zero)
                s1_mant_a[i] <= (a[i][14:7] == 8'h00) ? 8'h00
                                                       : {1'b1, a[i][6:0]};
                s1_sign_b[i] <= b[i][15];
                s1_exp_b [i] <= b[i][14:7];
                s1_mant_b[i] <= (b[i][14:7] == 8'h00) ? 8'h00
                                                       : {1'b1, b[i][6:0]};
            end
        end
    end

    // ================================================================
    // Stage 2: multiply mantissas & add exponents (registered)
    // ================================================================
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            s2_valid <= 1'b0;
        end else begin
            s2_valid <= s1_valid;
            for (i = 0; i < 4; i = i + 1) begin
                s2_prod_mant[i] <= s1_mant_a[i] * s1_mant_b[i];
                // exponent: add raw exponents, subtract one bias (127)
                s2_prod_exp [i] <= {1'b0, s1_exp_a[i]}
                                 + {1'b0, s1_exp_b[i]}
                                 - 9'd127;
                s2_prod_sign[i] <= s1_sign_a[i] ^ s1_sign_b[i];
            end
        end
    end

    // ================================================================
    // Stage 3: align products to common exponent & accumulate
    // ================================================================
    // Find max exponent across the 4 products (combinational for brevity)
    wire [8:0] max_exp_01 = (s2_prod_exp[0] >= s2_prod_exp[1])
                            ? s2_prod_exp[0] : s2_prod_exp[1];
    wire [8:0] max_exp_23 = (s2_prod_exp[2] >= s2_prod_exp[3])
                            ? s2_prod_exp[2] : s2_prod_exp[3];
    wire [8:0] max_exp    = (max_exp_01 >= max_exp_23)
                            ? max_exp_01 : max_exp_23;

    // Right-shift each product mantissa to align with max_exp
    wire [8:0]  shift     [0:3];
    wire [15:0] aligned   [0:3];   // shifted mantissa (always positive here)
    wire signed [15:0] signed_aligned [0:3];

    genvar gj;
    generate
        for (gj = 0; gj < 4; gj = gj + 1) begin : align
            assign shift[gj]   = max_exp - s2_prod_exp[gj];
            // Clamp shift to 15 to avoid undefined behaviour
            assign aligned[gj] = (shift[gj] >= 9'd15) ? 16'h0000
                                 : (s2_prod_mant[gj] >> shift[gj][3:0]);
            // Apply sign
            assign signed_aligned[gj] = s2_prod_sign[gj]
                                        ? -$signed({1'b0, aligned[gj]})
                                        :  $signed({1'b0, aligned[gj]});
        end
    endgenerate

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            s3_valid   <= 1'b0;
            s3_accum   <= 32'sd0;
            s3_max_exp <= 9'h000;
        end else begin
            s3_valid   <= s2_valid;
            s3_max_exp <= max_exp;
            s3_accum   <= $signed({{16{signed_aligned[0][15]}}, signed_aligned[0]})
                        + $signed({{16{signed_aligned[1][15]}}, signed_aligned[1]})
                        + $signed({{16{signed_aligned[2][15]}}, signed_aligned[2]})
                        + $signed({{16{signed_aligned[3][15]}}, signed_aligned[3]});
        end
    end

    // ================================================================
    // Stage 4: normalize, ReLU, repack to Bfloat16 (registered)
    // ================================================================
    // Determine leading-zero count to normalize the accumulator
    // For simplicity we use a 16-bit normalized window of s3_accum.

    reg [15:0] norm_mant;
    reg [8:0]  norm_exp;
    reg        norm_sign;

    // Combinational normalization (simplified — assumes accum fits 16 bits
    // after alignment; a production core would use a full LZC + shifter)
    always @(*) begin
        norm_sign = s3_accum[31];   // sign of accumulator

        if (s3_accum == 32'sd0) begin
            norm_mant = 16'h0000;
            norm_exp  = 9'h000;
        end else begin
            // Take absolute value
            automatic reg [31:0] abs_acc;
            abs_acc = norm_sign ? (~s3_accum + 1) : s3_accum;

            // Locate the most-significant '1' bit (priority encode, bits 31..0)
            automatic integer msb;
            msb = 0;
            begin : msb_search
                integer k;
                for (k = 0; k < 32; k = k + 1)
                    if (abs_acc[k]) msb = k;
            end

            // Align mantissa so MSB is at bit 7 (Bf16 has 7 explicit mantissa bits)
            if (msb >= 7)
                norm_mant = abs_acc[msb -: 8];   // top 8 bits (incl. implicit 1)
            else
                norm_mant = abs_acc[7:0];

            // Adjust exponent: s3_max_exp corresponds to abs_acc bit position 'msb'
            norm_exp = s3_max_exp + msb;
        end
    end

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            result_bf16  <= 16'h0000;
            result_fp32  <= 32'h0000_0000;
            result_valid <= 1'b0;
            done         <= 1'b0;
        end else begin
            result_valid <= s3_valid;
            done         <= s3_valid;

            if (s3_valid) begin
                // ReLU: zero out negative results
                if (norm_sign) begin
                    result_bf16 <= 16'h0000;  // ReLU clips negatives to 0
                    result_fp32 <= 32'h0000_0000;
                end else begin
                    // Pack Bfloat16: [15]=0 (positive), [14:7]=exp, [6:0]=mant[6:0]
                    result_bf16 <= {1'b0, norm_exp[7:0], norm_mant[6:0]};
                    // Widen to fp32: Bf16 occupies upper 16 bits of fp32
                    result_fp32 <= {1'b0, norm_exp[7:0], norm_mant[6:0], 16'h0000};
                end
            end
        end
    end

    // ================================================================
    // Busy signal: asserted from start until done
    // ================================================================
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n)
            busy <= 1'b0;
        else if (start)
            busy <= 1'b1;
        else if (done)
            busy <= 1'b0;
    end

endmodule
`endif // GPU_TENSOR_CORE_V
