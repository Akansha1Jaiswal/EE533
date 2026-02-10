///////////////////////////////////////////////////////////////////////////////
// $Id: small_fifo.v 5205 2009-03-08 18:54:46Z grg $
//
// Module: small_fifo.v
// Project: UNET
// Description: small fifo with no fallthrough i.e. data valid after rd is high
//
// Change history: 
//   7/20/07 -- Set nearly full to 2^MAX_DEPTH_BITS - 1 by default so that it 
//              goes high a clock cycle early.
//
///////////////////////////////////////////////////////////////////////////////
`timescale 1ns/1ps

  module small_fifo
    #(parameter WIDTH = 72,
      parameter MAX_DEPTH_BITS = 3,
      parameter NEARLY_FULL = 2**MAX_DEPTH_BITS - 1)
    (
		   
     input [WIDTH-1:0] din,     // Data in
     input          wr_en,   // Write enable
     
     input          rd_en,   // Read the next word 
     
     output reg [WIDTH-1:0]  dout,    // Data out
     output         full,
     output         nearly_full,
     output         empty,
     
     input          reset,
     input          clk
     );

  

   assign dout        = din;
   assign empty       = ~wr_en;
   assign full        = 1'b0;
   assign nearly_full = 1'b0;



endmodule // small_fifo


/* vim:set shiftwidth=3 softtabstop=3 expandtab: */
