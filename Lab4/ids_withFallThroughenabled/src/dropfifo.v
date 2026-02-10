
`timescale 1ns / 1ps

module dropfifo(
    input        clk,
    input        drop_pkt,
    input        fiforead,
    input        fifowrite,
    input        firstword,
    input [71:0] in_fifo,
    input        lastword,
    input        rst,

    output [71:0] out_fifo,
    output        valid_data
);


    assign out_fifo  = in_fifo;
    assign valid_data = fiforead;

endmodule
