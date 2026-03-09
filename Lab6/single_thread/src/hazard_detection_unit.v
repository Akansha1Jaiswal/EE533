`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    01:29:01 02/26/2026 
// Design Name: 
// Module Name:    hazard_detection_unit 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module hazard_detection_unit (
    input  wire        ID_EX_MemRead,
    input  wire [3:0]  ID_EX_rd,
    input  wire [3:0]  IF_ID_rs,
    input  wire [3:0]  IF_ID_rt,

    output reg         pc_write,
    output reg         if_id_write,
    output reg         id_ex_insert_bubble
);

always @(*) begin
    // default: no hazard
    pc_write           = 1'b1;
    if_id_write        = 1'b1;
    id_ex_insert_bubble = 1'b0;

    if (ID_EX_MemRead && ((ID_EX_rd == IF_ID_rs) || (ID_EX_rd == IF_ID_rt))) begin

        pc_write            = 1'b0;  // stall PC
        if_id_write         = 1'b0;  // stall IF/ID
        id_ex_insert_bubble = 1'b1;  // insert bubble into EX
    end
end

endmodule