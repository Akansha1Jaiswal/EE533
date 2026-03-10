`timescale 1ns / 1ps
module program_counter (
    input  wire        clk,
    input  wire        reset,
	 input  wire        cpu_enable,

    input  wire        pc_src_branch,
    input  wire        pc_src_jump,
    input  wire [31:0] branch_target,
    input  wire [31:0] jump_target,
    input  wire [1:0]  EX_thread_id,
    input  wire [1:0]  ID_thread_id,

    output reg  [31:0] pc,
    output reg  [1:0]  thread_id
);

    reg [31:0] pc_reg [0:3];
    reg [1:0]  current_thread;

    integer i;

    always @(posedge clk) begin
        if (reset) begin
            current_thread <= 2'd0;
            thread_id      <= 2'd0;
            pc             <= 32'd0;
            for (i = 0; i < 4; i = i + 1)
                pc_reg[i] <= 32'd0;
        end
        else if (cpu_enable) begin
            thread_id <= current_thread;
            pc        <= pc_reg[current_thread];

            for (i = 0; i < 4; i = i + 1) begin      //Updating all the threads pcs at the same time for branch, jump or next instr pc
                if (pc_src_jump && (ID_thread_id == i))
                    pc_reg[i] <= jump_target;

                else if (pc_src_branch && (EX_thread_id == i))
                    pc_reg[i] <= branch_target;

                else if (i == current_thread)
                    pc_reg[i] <= pc_reg[i] + 32'd4;

                else
                    pc_reg[i] <= pc_reg[i];
            end
            current_thread <= current_thread + 2'd1; //Moving to the next instruction
        end
		  
		  else begin
				 // CPU disabled
				 pc        <= 32'd0;
				 thread_id <= 2'd0;
		  end
    end

endmodule
