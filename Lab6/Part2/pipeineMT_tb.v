`timescale 1ns / 1ps
module tb_simple_4thread;

    reg clk, reset;
    initial clk = 0;
    always #5 clk = ~clk;

    integer cycle;
    initial cycle = 0;
    always @(posedge clk) cycle = cycle + 1;

    pipeline_top_4thread dut (
        .clk(clk),
        .reset(reset)
    );

    // Shadow RF
    reg [31:0] shadow_rf      [0:3][0:15];
    reg        shadow_written [0:3][0:15];
    integer t, r;

    task clear_shadow;
        begin
            for (t = 0; t < 4; t = t+1)
                for (r = 0; r < 16; r = r+1) begin
                    shadow_rf[t][r]      = 32'hDEADBEEF;
                    shadow_written[t][r] = 0;
                end
        end
    endtask

    // WB capture
    always @(posedge clk) begin
        if (!reset && dut.WRegEn_WB_internal) begin
            shadow_rf[dut.thread_id_WB_internal][dut.Rd_WB_internal]
                <= dut.write_data_WB;
            shadow_written[dut.thread_id_WB_internal][dut.Rd_WB_internal]
                <= 1;
            $display("[%04d] CAPTURE: T%0d R%0d <= %0d",
                cycle,
                dut.thread_id_WB_internal,
                dut.Rd_WB_internal,
                dut.write_data_WB);
        end
    end

    // Pass/Fail
    integer pass_count, fail_count;
    initial begin pass_count=0; fail_count=0; end

    task check;
        input [1:0]  thread;
        input [3:0]  reg_num;
        input [31:0] expected;
        input [79:0] name;
        reg [31:0] got;
        begin
            got = shadow_written[thread][reg_num]
                ? shadow_rf[thread][reg_num]
                : dut.regfile.mem[{thread,reg_num}];

            if (got === expected) begin
                $display("  PASS | %s | T%0d R%0d = %0d",
                    name, thread, reg_num, got);
                pass_count = pass_count + 1;
            end else begin
                $display("  FAIL | %s | T%0d R%0d = %0d (expected %0d)",
                    name, thread, reg_num, got, expected);
                fail_count = fail_count + 1;
            end
        end
    endtask

    // IF monitor ? all cycles
    always @(posedge clk) begin
        if (!reset)
            $display("[%04d] IF:T%0d PC=%0d instr=%08h | ID:T%0d EX:T%0d WB:T%0d",
                cycle,
                dut.fetch_thread_reg,
                dut.fetch_pc_plus1_reg - 1,
                dut.instruction_IF,
                dut.thread_id_ID,
                dut.thread_id_EX,
                dut.thread_id_WB_internal);
    end

    // WB monitor
    always @(posedge clk) begin
        if (!reset && dut.WRegEn_WB_internal)
            $display("[%04d] WB: T%0d R%0d <= %0d",
                cycle,
                dut.thread_id_WB_internal,
                dut.Rd_WB_internal,
                dut.write_data_WB);
    end

    initial begin
        $dumpfile("simple_4thread.vcd");
        $dumpvars(0, tb_simple_4thread);

        clear_shadow();

        // Reset
        reset = 1;
        repeat(10) @(posedge clk);

        // Check PCs during reset
        $display("=== PC CHECK (during reset) ===");
        $display("  T0=%0d T1=%0d T2=%0d T3=%0d",
            dut.pc[0], dut.pc[1], dut.pc[2], dut.pc[3]);
        $display("  Expected: 0, 64, 128, 192");

        #1 reset = 0;
        $display("=== Running 3-instruction programs ===");

        // Only need ~50 cycles: 3 instrs x 4 threads x 5 pipeline stages
        repeat(100) @(posedge clk);

        // Check results
        $display("");
        $display("=== RESULTS ===");
        check(2'd0, 4'd2, 32'd8,  "T0_ADD"); // T0: R2 = 5+3  = 8
        check(2'd1, 4'd0, 32'd30, "T1_ADD"); // T1: R0 = 10+20= 30
        check(2'd2, 4'd0, 32'd9,  "T2_ADD"); // T2: R0 = 7+2  = 9
        check(2'd3, 4'd0, 32'd30, "T3_ADD"); // T3: R0 = 15+15= 30

        // Isolation: T0 R0 should be 5, not contaminated by T1/T2/T3
        $display("");
        $display("=== ISOLATION CHECK ===");
        $display("  T0 R0 = %0d (expect 5  - MOV R0,#5)",
            dut.regfile.mem[6'b00_0000]);
        $display("  T0 R1 = %0d (expect 3  - MOV R1,#3)",
            dut.regfile.mem[6'b00_0001]);
        $display("  T1 R1 = %0d (expect 20 - MOV R1,#20)",
            dut.regfile.mem[6'b01_0001]);
        $display("  T2 R1 = %0d (expect 2  - MOV R1,#2)",
            dut.regfile.mem[6'b10_0001]);
        $display("  T3 R1 = %0d (expect 15 - MOV R1,#15)",
            dut.regfile.mem[6'b11_0001]);

        $display("");
        $display("=== SUMMARY: %0d passed %0d failed ===",
            pass_count, fail_count);

        $finish;
    end

endmodule
//```

//---

//### Expected output if everything works:
//```
//=== PC CHECK (during reset) ===
