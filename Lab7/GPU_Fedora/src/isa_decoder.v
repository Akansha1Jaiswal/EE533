//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    21:09:48 03/20/2026 
// Design Name: 
// Module Name:    isa_decoder 
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
module isa_decoder (
    input  [31:0] instruction,
    output reg [4:0]  opcode_isa,
    output reg        DT,
    output reg [3:0]  rd,
    output reg [3:0]  ra,
    output reg [3:0]  rb,
    output reg [3:0]  rc,
    output reg [15:0] imm16,
    output reg        is_rtype,
    output reg        is_itype,
    output reg        is_mtype,
    output reg        is_wtype
);

wire [1:0] format  = instruction[25:24];
wire [4:0] opcode  = instruction[31:27];

// Within format=00: LOAD=00000, STORE=00001 are M-type
// Everything else in format=00 is R-type or W-type
wire is_mem_op = (format == 2'b00) &&
                 ((opcode == 5'b00000) || (opcode == 5'b00001));
wire is_store  = (format == 2'b00) && (opcode == 5'b00001);

always @(*) begin
    opcode_isa = opcode;
    DT         = instruction[26];
    rd         = 4'd0;
    ra         = 4'd0;
    rb         = 4'd0;
    rc         = 4'd0;
    imm16      = 16'd0;
    is_rtype   = 1'b0;
    is_itype   = 1'b0;
    is_mtype   = 1'b0;
    is_wtype   = 1'b0;

    case (format)

        // ----------------------------------------------------------
        // format=00: R-type, W-type, or M-type (LOAD/STORE)
        // Opcode decides which:
        //   00000 ? LOAD   (M-type)
        //   00001 ? STORE  (M-type)
        //   11000 ? MMA    (W-type / tensor)
        //   all others ? ALU R-type
        // ----------------------------------------------------------
        2'b00: begin
            if (is_mem_op) begin
                // M-type: base in ra, data/dest in rd/rb field
                ra = instruction[19:16];   // base address register
                // No imm16 in format=00, offset is 0
                if (is_store) begin
                    rd = 4'd0;                 // STORE: no RF writeback
                    rb = instruction[23:20];   // store data source register
                end else begin                 // LOAD
                    rd = instruction[23:20];   // destination register
                    rb = 4'd0;
                end
                is_mtype = 1'b1;
            end
            else begin
                rd = instruction[23:20];
                ra = instruction[19:16];
                rb = instruction[15:12];
                rc = instruction[11:8];
                if (opcode == 5'b11000)
                    is_wtype = 1'b1;
                else
                    is_rtype = 1'b1;
            end
        end

        // ----------------------------------------------------------
        // format=01: I-type (immediate)
        // ----------------------------------------------------------
        2'b01: begin
            rd    = instruction[23:20];
            ra    = instruction[19:16];
            imm16 = instruction[15:0];
            is_itype = 1'b1;
        end

        // ----------------------------------------------------------
        // format=10/11: reserved, treat as NOP
        // ----------------------------------------------------------
        default: begin end

    endcase
end

endmodule