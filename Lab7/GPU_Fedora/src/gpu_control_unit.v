//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    21:10:49 03/20/2026 
// Design Name: 
// Module Name:    gpu_control_unit 
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
module gpu_control_unit (
    input  [4:0] opcode,
    input        DT,
    input        is_rtype_control,
    input        is_itype_control,
    input        is_mtype_control,
    input        is_wtype_control,
    output reg        alu_enable,
    output reg [4:0]  alu_op,
    output reg        tensor_enable,
    output reg        mem_read,
    output reg        mem_write,
    output reg        reg_write,
    output reg        use_immediate,
    output reg        data_type_bf16
);

always @(*) begin
    alu_enable     = 1'b0;
    alu_op         = 5'b00000;
    tensor_enable  = 1'b0;
    mem_read       = 1'b0;
    mem_write      = 1'b0;
    reg_write      = 1'b0;
    use_immediate  = 1'b0;
    data_type_bf16 = DT;

    // --------------------------------------------------------
    // R-TYPE (format=00, non-mem, non-tensor)
    // --------------------------------------------------------
    if (is_rtype_control) begin
        case (opcode)
            5'b00110: begin alu_enable=1; reg_write=1; alu_op=5'b00110; end // VADD
            5'b00111: begin alu_enable=1; reg_write=1; alu_op=5'b00111; end // VSUB
            5'b01000: begin alu_enable=1; reg_write=1; alu_op=5'b01000; end // VMUL
            5'b01001: begin alu_enable=1; reg_write=1; alu_op=5'b01001; end // VMAC
            5'b10001: begin alu_enable=1; reg_write=1; alu_op=5'b10001; end // SHL
            5'b10010: begin alu_enable=1; reg_write=1; alu_op=5'b10010; end // SHR
            5'b01010: begin alu_enable=1; reg_write=1; alu_op=5'b10011; end // VMAX
            5'b00100: begin alu_enable=1; reg_write=1; alu_op=5'b00100; end // VMOV
            default:  begin end
        endcase
    end

    // --------------------------------------------------------
    // I-TYPE (format=01)
    // --------------------------------------------------------
    else if (is_itype_control) begin
        case (opcode)
            5'b00000: begin alu_enable=1; reg_write=1; use_immediate=1; alu_op=5'b00110; end // ADDI
            5'b10001: begin alu_enable=1; reg_write=1; use_immediate=1; alu_op=5'b10001; end // SHLI
            5'b10010: begin alu_enable=1; reg_write=1; use_immediate=1; alu_op=5'b10010; end // SHRI
            5'b00100: begin alu_enable=1; reg_write=1; use_immediate=1; alu_op=5'b00110; end
            default:  begin end
        endcase
    end

    // --------------------------------------------------------
    // M-TYPE (format=00, opcode=00000 LOAD or 00001 STORE)
    // Both use ALU to compute address: ra + 0 (no immediate in format=00)
    // LOAD:  mem_read=1,  reg_write=1 (write to rd)
    // STORE: mem_write=1, reg_write=0 (no RF writeback)
    // --------------------------------------------------------
    else if (is_mtype_control) begin
        alu_enable    = 1'b1;
        use_immediate = 1'b0;   // format=00 has no imm ? address = ra + 0
        alu_op        = 5'b00110; // ADD (ra + 0 = ra)
        case (opcode)
            5'b00000: begin     // LOAD
                mem_read  = 1'b1;
                reg_write = 1'b1;
            end
            5'b00001: begin     // STORE
                mem_write = 1'b1;
                reg_write = 1'b0;
            end
            default: begin end
        endcase
    end

    // --------------------------------------------------------
    // W-TYPE (format=00, opcode=11000 MMA etc.)
    // --------------------------------------------------------
    else if (is_wtype_control) begin
        case (opcode)
            5'b11000: begin
                tensor_enable  = 1'b1;
                reg_write      = 1'b1;
                data_type_bf16 = 1'b1;
            end
            5'b11110: begin
                alu_enable     = 1'b1;
                alu_op         = 5'b00110;
                use_immediate  = 1'b1;
                mem_read       = 1'b1;
                reg_write      = 1'b1;
                data_type_bf16 = 1'b1;
            end
            5'b11111: begin
                alu_enable     = 1'b1;
                alu_op         = 5'b00110;
                use_immediate  = 1'b1;
                mem_write      = 1'b1;
                data_type_bf16 = 1'b1;
            end
            default: begin end
        endcase
    end

end

endmodule