`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    01:28:01 02/26/2026 
// Design Name: 
// Module Name:    ex_stage 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
// Previously, the forwarding unit always attempted to forward into operand B
// whenever ID_EX_rt matched a destination register from later pipeline stages.
//
// However, this is incorrect for LW instructions.
//
// In this ISA:
//   - ADD/SUB/BLT use both rs and rt as source operands.
//   - LW uses ONLY rs as source (rt field is NOT a source register).
//   - SW uses rs (address base) and rt (store data).
//
// For LW:
//   ALUSrc = 0 ? ALU must use the immediate, NOT the rt register.
//
// The bug:
// Forwarding logic was still trying to forward into operand B even when
// the instruction did not use rt as an ALU operand. This corrupted the
// address calculation for loads, producing incorrect byte addresses
// (e.g., 8 became 10 or 9 due to adding forwarded register values).
//
// The fix:
// Only allow forwarding for operand B when the instruction actually
// uses rt as a source operand. In this design, that condition is:
//     ALUSrc == 1
//
// When ALUSrc == 0 (LW/SW address calculation), operand B must come
// strictly from the immediate field, and forwarding must not interfere.
//
// This restores correct address generation and prevents memory corruption.
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module ex_stage (

    //ID/EX inputs 
    input  wire [63:0] ID_EX_rs,
    input  wire [63:0] ID_EX_rt,
    input  wire [3:0]  ID_EX_rs_addr,
    input  wire [3:0]  ID_EX_rt_addr,
    input  wire [3:0]  ID_EX_rd,
    input  wire [63:0] ID_EX_imms_ext_64,
    input  wire [31:0] ID_EX_branch_target,
    input  wire [3:0]  ID_EX_ALUOp,
    input  wire        ID_EX_ALUSrc,
    input  wire        ID_EX_Branch,
    input  wire [5:0]  ID_EX_instr_opcode,

    //EX/MEM inputs (for forwarding)
    input  wire [3:0]  EX_MEM_rd,
    input  wire        EX_MEM_RegWrite,
    input  wire [63:0] EX_MEM_alu_result,
	 input  wire        EX_MEM_MemRead,

    //MEM/WB inputs (for forwarding)
    input  wire [3:0]  MEM_WB_rd,
    input  wire        MEM_WB_RegWrite,
    input  wire [63:0] MEM_WB_write_data,

    //Outputs to EX/MEM register 
    output wire [63:0] EX_alu_result,
    output wire [63:0] EX_rt_for_store,
    output wire [3:0]  EX_dest_reg,

    //Branch outputs 
    output wire        pc_src_branch,
    output wire [31:0] branch_target_out,
    output wire        BU_if_id_flush
);

    // Forwarding Unit

    wire [1:0] ForwardA;  // 00=ID_EX_rs, 01=MEM_WB, 10=EX_MEM
    wire [1:0] ForwardB;  // 00=ID_EX_rt, 01=MEM_WB, 10=EX_MEM

    forwarding_unit fwd_inst (
        .ID_EX_rs(ID_EX_rs_addr),
        .ID_EX_rt(ID_EX_rt_addr),
        .EX_MEM_rd(EX_MEM_rd),
        .EX_MEM_RegWrite(EX_MEM_RegWrite),
		  .EX_MEM_MemRead(EX_MEM_MemRead),
        .MEM_WB_rd(MEM_WB_rd),
        .MEM_WB_RegWrite(MEM_WB_RegWrite),
        .ForwardA(ForwardA),
        .ForwardB(ForwardB)
    );

    // Forwarding Muxes

    wire [63:0] operandA;
    wire [63:0] operandB_pre;
	 
	 // operandA forwarding 
	 assign operandA = (ForwardA == 2'b10) ? EX_MEM_alu_result : (ForwardA == 2'b01) ? MEM_WB_write_data : ID_EX_rs;

	 // Determine when rt is a true source that must accept forwarding.
	 // ALUSrc==1 => ALU uses rt as operand B.
	 // SW (opcode 6'b000110) => rt is store data and must accept forwarding even though ALUSrc==0.
	 wire uses_rt_for_alu   = (ID_EX_ALUSrc == 1'b1);
	 wire uses_rt_for_store = (ID_EX_instr_opcode == 6'b000110); // SW opcode from your decoder

	 // Allow forwarding into operandB_pre whenever rt is a source (ALU or STORE).
	 assign operandB_pre = (uses_rt_for_alu || uses_rt_for_store) ?
									 ((ForwardB == 2'b10) ? EX_MEM_alu_result : (ForwardB == 2'b01) ? MEM_WB_write_data : ID_EX_rt)
									 : ID_EX_rt;

    // ALUSrc Mux

    wire [63:0] operandB;

    assign operandB = (ID_EX_ALUSrc == 1'b1) ? operandB_pre : ID_EX_imms_ext_64;

    // ALU

    wire zero_flag;
    wire less_than_flag;
    wire greater_equal_flag;
    wire less_equal_flag;


	 
    ALU alu_inst (
        .A(operandA),
        .B(operandB),
        .ALUOp(ID_EX_ALUOp),
        .result(EX_alu_result),
        .zero(zero_flag),
        .less_than(less_than_flag),
        .greater_equal(greater_equal_flag),
        .less_equal(less_equal_flag)
    );

    // Branch Unit

    wire branch_taken;

    branch_unit branch_inst (
        .Branch(ID_EX_Branch),
        .instr_opcode(ID_EX_instr_opcode),
        .less_than(less_than_flag),
        .greater_equal(greater_equal_flag),
        .less_equal(less_equal_flag),
        .branch_taken(branch_taken)
    );

    assign pc_src_branch   = branch_taken;
    assign BU_if_id_flush  = branch_taken;
    assign branch_target_out = ID_EX_branch_target;

	 // Store Data Forwarding (always allow forwarding for store data)
	 assign EX_rt_for_store = (ForwardB == 2'b10) ? EX_MEM_alu_result :
									  (ForwardB == 2'b01) ? MEM_WB_write_data :
									   ID_EX_rt;

    // Destination Register

    assign EX_dest_reg = ID_EX_rd;

endmodule



