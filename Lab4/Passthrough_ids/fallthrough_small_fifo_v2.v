///////////////////////////////////////////////////////////////////////////////
// $Id: small_fifo.v 1998 2007-07-21 01:22:57Z grg $
//
// Module: fallthrough_small_fifo.v
// Project: utils
// Description: small fifo with fallthrough i.e. data valid when rd is high
//
// Change history: 
//   7/20/07 -- Set nearly full to 2^MAX_DEPTH_BITS - 1 by default so that it 
//              goes high a clock cycle early.
//   2/11/09 -- jnaous: Rewrote to make much more efficient.
///////////////////////////////////////////////////////////////////////////////
`timescale 1ns/1ps

  module fallthrough_small_fifo
    #(parameter WIDTH = 72,
      parameter MAX_DEPTH_BITS = 3,
      parameter PROG_FULL_THRESHOLD = 2**MAX_DEPTH_BITS - 1)
    (
                   
     input [WIDTH-1:0] din,     // Data in
     input          wr_en,   // Write enable
     
     input          rd_en,   // Read the next word 
     
     output [WIDTH-1:0]  dout,    // Data out
     output         full,
     output         nearly_full,
     output         prog_full,
     output reg     empty,
     
     input          reset,
     input          clk
     );




    assign dout        = din;
    assign empty       = ~wr_en;
    assign full        = 1'b0;
    assign nearly_full = 1'b0;
    assign prog_full   = 1'b0;

endmodule // fallthrough_small_fifo

      


  
   

