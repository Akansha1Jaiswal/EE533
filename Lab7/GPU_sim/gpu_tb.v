`timescale 1ns/1ps

module tb_gpu;

reg  clk;
reg  reset;
wire [63:0] debug_r3;

// -----------------------------------------------------------------------
// Instantiate GPU
// -----------------------------------------------------------------------
gpu DUT (
    .clk      (clk),
    .reset    (reset),
    .debug_r3 (debug_r3)
);

// -----------------------------------------------------------------------
// Clock: 10 ns period
// -----------------------------------------------------------------------
initial begin
    clk = 0;
    forever #5 clk = ~clk;
end

// -----------------------------------------------------------------------
// Reset: hold for 4 cycles
// -----------------------------------------------------------------------
initial begin
    reset = 1;
    #40;
    reset = 0;
end

// -----------------------------------------------------------------------
// Pipeline monitor
// -----------------------------------------------------------------------
always @(posedge clk)
    $display("T=%0t | PC=%0d | instr=%h | stall=%b hazard=%b tensor=%b",
        $time,
        DUT.pc,
        DUT.IF_ID_instr,
        DUT.stall,
        DUT.hazard_stall,
        DUT.tensor_stall);

// -----------------------------------------------------------------------
// Hazard slot monitor
// -----------------------------------------------------------------------
always @(posedge clk)
    $display("Haz A=%0d B=%0d C=%0d D=%0d E=%0d F=%0d",
        DUT.haz_dest_A, DUT.haz_dest_B, DUT.haz_dest_C,
        DUT.haz_dest_D, DUT.haz_dest_E, DUT.haz_dest_F);

// -----------------------------------------------------------------------
// Writeback monitor (skip r0)
// -----------------------------------------------------------------------
always @(posedge clk)
    if (DUT.MEM_WB_valid && DUT.MEM_WB_rd != 4'd0)
        $display("WB: r%0d = %h", DUT.MEM_WB_rd, DUT.MEM_WB_result);

// -----------------------------------------------------------------------
// Memory operation monitor
// -----------------------------------------------------------------------
always @(posedge clk) begin
    if (DUT.EX2_MEM_mem_write_dly)
        $display("STORE -> addr=%0d  data=%h",
            DUT.EX2_MEM_ALU_dly[7:0],
            DUT.EX2_MEM_store_data_dly);
    if (DUT.EX2_MEM_mem_read_Pass)
        $display("LOAD  -> addr=%0d",
            DUT.EX2_MEM_ALU_dly[7:0]);
end

// -----------------------------------------------------------------------
// Tensor monitor
// -----------------------------------------------------------------------
always @(posedge clk) begin
    if (DUT.EX1_tensor_enable) $display("Tensor started");
    if (DUT.tensor_valid_Final) $display("Tensor result = %h", DUT.tensor_result1);
    if (DUT.tensor_stall)       $display("Tensor stall active");
end

// -----------------------------------------------------------------------
// Pass/fail checker task
// -----------------------------------------------------------------------
task check;
    input [63:0] actual;
    input [63:0] expected;
    input integer rnum;
    begin
        if (actual === expected)
            $display("  PASS  R%0d = %h", rnum, actual);
        else
            $display("  FAIL  R%0d = %h  (expected %h)", rnum, actual, expected);
    end
endtask

// -----------------------------------------------------------------------
// Register dump task
// -----------------------------------------------------------------------
task print_registers;
    integer i;
    begin
        $display("\n==== REGISTER FILE ====");
        for (i = 0; i < 16; i = i + 1)
            $display("  R%0d = %h", i, DUT.RF.reg_array[i]);
        $display("=======================\n");
    end
endtask

// -----------------------------------------------------------------------
// End of simulation: wait for PC to stop advancing, flush, then check
// -----------------------------------------------------------------------
reg [8:0] last_pc;
integer   idle_count;

initial begin
    last_pc    = 9'd0;
    idle_count = 0;
    @(negedge reset);

    forever begin
        @(posedge clk);
        if (DUT.pc === last_pc)
            idle_count = idle_count + 1;
        else begin
            idle_count = 0;
            last_pc    = DUT.pc;
        end

        if (idle_count >= 20 || $time >= 50000) begin
            repeat(10) @(posedge clk);
            print_registers();

            $display("==== PASS/FAIL ====");
            check(DUT.RF.reg_array[1],  64'h000a000a000a000a, 1);
            check(DUT.RF.reg_array[2],  64'h0014001400140014, 2);
            check(DUT.RF.reg_array[3],  64'h001e001e001e001e, 3);
            check(DUT.RF.reg_array[4],  64'h0032003200320032, 4);
            check(DUT.RF.reg_array[5],  64'h05dc05dc05dc05dc, 5);
            check(DUT.RF.reg_array[6],  64'h3aac3aac3aac3aac, 6);
            check(DUT.RF.reg_array[9],  64'h0005000500050005, 9);
            check(DUT.RF.reg_array[10], 64'h000a000a000a000a, 10);
            check(DUT.RF.reg_array[11], 64'h0014001400140014, 11);
            check(DUT.RF.reg_array[12], 64'h00e600e600e600e6, 12);
            check(DUT.RF.reg_array[13], 64'h00fa00fa00fa00fa, 13);
            $display("===================");

            $display("Final debug_r3 = %h", debug_r3);
            $finish;
        end
    end
end

// -----------------------------------------------------------------------
// Waveform dump
// -----------------------------------------------------------------------
initial begin
    $dumpfile("tb_gpu.vcd");
    $dumpvars(2, tb_gpu);
end

endmodule