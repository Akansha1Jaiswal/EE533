`timescale 1ns/1ps
// register_file.v
// 16 x 64-bit register file for simple_gpu
// Ports match simple_gpu instantiation exactly:
//   rs1/rs2/rs3 = read addresses, rd = write address
//   read_data1/2/3, write_data, we
module register_file (
    input  wire        clk,
	 input  wire        reset,
    input  wire [3:0]  rs1,
    input  wire [3:0]  rs2,
    input  wire [3:0]  rs3,
    input  wire [3:0]  rd,
    input  wire [63:0] write_data,
    input  wire        we,
    output wire [63:0] read_data1,
    output wire [63:0] read_data2,
    output wire [63:0] read_data3
);
    reg [63:0] reg_array [0:15];
    integer i;
    always @(posedge clk) begin
        if (reset) begin
            for (i = 0; i < 16; i = i + 1)
                reg_array[i] <= 64'd0;
        end
        else if (we && (rd != 4'd0)) begin
            reg_array[rd] <= write_data;
        end
    end


    assign read_data1 = reg_array[rs1];
    assign read_data2 = reg_array[rs2];
    assign read_data3 = reg_array[rs3];
endmodule
