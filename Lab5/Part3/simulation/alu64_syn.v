////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 1995-2008 Xilinx, Inc.  All rights reserved.
////////////////////////////////////////////////////////////////////////////////
//   ____  ____ 
//  /   /\/   / 
// /___/  \  /    Vendor: Xilinx 
// \   \   \/     Version : 10.1
//  \   \         Application : sch2verilog
//  /   /         Filename : alu64_syn.vf
// /___/   /\     Timestamp : 02/11/2026 23:40:27
// \   \  /  \ 
//  \___\/\___\ 
//
//Command: C:\Xilinx\10.1\ISE\bin\nt\unwrapped\sch2verilog.exe -intstyle ise -family virtex2p -w C:/Xilinx/10.1/ISE/Lab_YLR/lab5_2/alu64_syn.sch alu64_syn.vf
//Design Name: alu64_syn
//Device: virtex2p
//Purpose:
//    This verilog netlist is translated from an ECS schematic.It can be 
//    synthesized and simulated, but it should not be modified. 
//
`timescale 1ns / 1ps

module alu64_syn(A, 
                 B, 
                 clk, 
                 opcode, 
                 Cout, 
                 Overflow_flag, 
                 Result, 
                 SLT, 
                 Zero_flag);

    input [63:0] A;
    input [63:0] B;
    input clk;
    input [3:0] opcode;
   output Cout;
   output Overflow_flag;
   output [63:0] Result;
   output SLT;
   output Zero_flag;
   
   wire [63:0] XLXN_15;
   wire [63:0] XLXN_16;
   wire [3:0] XLXN_17;
   wire XLXN_18;
   wire XLXN_19;
   wire XLXN_20;
   wire XLXN_21;
   wire [63:0] XLXN_22;
   
   alu64 XLXI_1 (.A(XLXN_15[63:0]), 
                 .B(XLXN_16[63:0]), 
                 .opcode(XLXN_17[3:0]), 
                 .Cout(XLXN_19), 
                 .overflow_flag(XLXN_20), 
                 .result(XLXN_22[63:0]), 
                 .SLT(XLXN_21), 
                 .zero_flag(XLXN_18));
   reg64_ XLXI_2 (.clk(clk), 
                  .D(A[63:0]), 
                  .Q(XLXN_15[63:0]));
   reg64_ XLXI_3 (.clk(clk), 
                  .D(B[63:0]), 
                  .Q(XLXN_16[63:0]));
   reg64_ XLXI_4 (.clk(clk), 
                  .D(XLXN_22[63:0]), 
                  .Q(Result[63:0]));
   reg4 XLXI_5 (.clk(clk), 
                .D(opcode[3:0]), 
                .Q(XLXN_17[3:0]));
   FD XLXI_6 (.C(clk), 
              .D(XLXN_18), 
              .Q(Zero_flag));
   defparam XLXI_6.INIT = 1'b0;
   FD XLXI_7 (.C(clk), 
              .D(XLXN_19), 
              .Q(Cout));
   defparam XLXI_7.INIT = 1'b0;
   FD XLXI_8 (.C(clk), 
              .D(XLXN_20), 
              .Q(Overflow_flag));
   defparam XLXI_8.INIT = 1'b0;
   FD XLXI_9 (.C(clk), 
              .D(XLXN_21), 
              .Q(SLT));
   defparam XLXI_9.INIT = 1'b0;
endmodule
