`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    01:21:22 02/26/2026 
// Design Name: 
// Module Name:    pipeline_top 
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
module pipeline_top (
	input clk,
	input reset,
	
	// NetFPGA / external control signals
	input  cpu_enable, // gated run/stop from wrapper

	// IMEM external programming interface 
	input         imem_we_ext,
	input  [8:0]  imem_addr_ext,
	input  [31:0] imem_data_ext,

	// DMEM external programming / read interface
	input         dmem_we_ext,
	input  [7:0]  dmem_addr_ext,
	input  [63:0] dmem_data_ext,
	input         dmem_re_ext,
	output [63:0] dmem_rdata_ext,

	// RegFile external read 
	input         regfile_re_ext,
	input  [3:0]  regfile_addr_ext,
	output [63:0] regfile_rdata_ext
	
	);
	
	wire [5:0] ID_EX_instr_opcode_out;

	wire [63:0] EX_alu_result;
	wire [63:0] EX_rt_for_store;
	wire [3:0]  EX_dest_reg;

	wire EX_pc_src_branch;
	wire [31:0] EX_branch_target;
	wire EX_flush_if_id;
	
	wire HDU_pc_write;
	
	wire [63:0] ID_EX_rs_out;
	wire [63:0] ID_EX_rt_out;
	wire [63:0] ID_EX_imms_ext_64_out;
	wire [31:0] ID_EX_branch_target_out;

	wire [3:0]  ID_EX_rs_addr_out;
	wire [3:0]  ID_EX_rt_addr_out;
	wire [3:0]  ID_EX_rd_out;
	
	wire ID_EX_RegWrite_out;
	wire ID_EX_MemRead_out;
	wire ID_EX_MemWrite_out;
	wire ID_EX_MemToReg_out;
	wire ID_EX_ALUSrc_out;
	wire ID_EX_Branch_out;
	wire ID_EX_Jump_out;
	wire [3:0] ID_EX_ALUOp_out;
	wire [5:0] ID_EX_instr_opcode;
	
	wire [63:0] EX_MEM_alu_result_out;
	wire [63:0] EX_MEM_rt_for_store_out;

	wire EX_MEM_RegWrite_out;
	wire EX_MEM_MemWrite_out;
	wire EX_MEM_MemToReg_out;
	
	wire pc_write;                 
	wire pc_src_branch;
	wire pc_src_jump;
	wire [31:0] branch_target;
	wire [31:0] jump_target;
	wire [31:0] pc_out;
	
	wire [3:0] ID_rs_addr, ID_rt_addr, ID_rd_addr;
	wire [11:0] ID_imm12;
	wire [63:0] ID_imms_ext64;
	wire [31:0] ID_jump_target, ID_branch_target;
	wire ID_RegWrite, ID_MemRead, ID_MemWrite, ID_MemToReg, ID_ALUSrc, ID_Branch, ID_Jump;
	wire [3:0] ID_ALUOp;
	wire [5:0] ID_instr_opcode;
	
	// Program Counter
	
/* 	wire pc_write;                 
	wire pc_src_branch;
	wire pc_src_jump;
	wire [31:0] branch_target;
	wire [31:0] jump_target;
	wire [31:0] pc_out; */
	
	assign pc_src_branch  = EX_pc_src_branch;
	assign branch_target  = EX_branch_target;
	
	assign pc_src_jump    = ID_Jump;
	assign jump_target    = ID_jump_target;
	
	program_counter pc_inst (
		.clk(clk),
		.reset(reset),
		.pc_write(pc_write),           // From HDU in ID
		.pc_src_branch(pc_src_branch), // From Branch Unit in EX
		.pc_src_jump(pc_src_jump),     // From Control Unit in ID
		.branch_target(branch_target), // From BU in EX
		.jump_target(jump_target),     // From Control Unit in ID
		
		.pc(pc_out)
	);

	// Instruction Memory
	
	wire [31:0] imem_instr_out;
	
/* 	IMEM imem_inst (
		.addr(pc_out[10:2]),      //PC is byte addressable but IMEM is word addressed
		.clk(clk),
		.din(32'b0),          //Have to add mux for NetFPGA integration
		
		.dout(imem_instr_out),//For simulation output come from .coe file but for NetFPGA it comes from the Instruction being fed
		.we(1'b0)             //Again for simulation not needed but needed for NetFPGA
	); */

	// IMEM external programming mux
	wire [8:0]  imem_addr_mux;
	wire [31:0] imem_din_mux;
	wire        imem_we_mux;

	assign imem_addr_mux = imem_we_ext ? imem_addr_ext : pc_out[10:2];
	assign imem_din_mux  = imem_we_ext ? imem_data_ext : 32'b0;
	assign imem_we_mux   = imem_we_ext;

	IMEM imem_inst (
		.addr(imem_addr_mux),   // either external address or PC[10:2]
		.clk(clk),
		.din(imem_din_mux),
		.dout(imem_instr_out),
		.we(imem_we_mux)
	);

	
	// IF_ID Stage Register
	
	wire [31:0] IF_ID_pc_plus4_out;
	wire HDU_if_id_write;
	wire BU_if_id_flush;
	wire [31:0] IF_ID_instr_out;
	
	wire [31:0] pc_plus4_if_id_in;
	assign pc_plus4_if_id_in = pc_out + 32'd4; // For branch calculation we need PC + 4 not just PC
	assign BU_if_id_flush = EX_flush_if_id | pc_src_jump ;//| ID_Jump;    // If branch is taken or jump instruction is present

	IF_ID if_id_inst (
		.clk(clk),
		.reset(reset),
		.if_id_write(HDU_if_id_write),
		.if_id_flush(BU_if_id_flush),
		.pc_plus4_in(pc_plus4_if_id_in),
		.instr_in(imem_instr_out),
		.pc_in(pc_out),
		
		.pc_plus4_out(IF_ID_pc_plus4_out),
		.instr_out(IF_ID_instr_out),
		.pc_out(IF_ID_pc_out)
		);
			
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
	// Instruction Decoder + Control Logic
	
/* 	wire [3:0] ID_rs_addr, ID_rt_addr, ID_rd_addr;
	wire [11:0] ID_imm12;
	wire [63:0] ID_imms_ext64;
	wire [31:0] ID_jump_target, ID_branch_target;
	wire ID_RegWrite, ID_MemRead, ID_MemWrite, ID_MemToReg, ID_ALUSrc, ID_Branch, ID_Jump;
	wire [3:0] ID_ALUOp;
	wire [5:0] ID_instr_opcode; */


	instruction_decoder_control id_ctrl_inst (
		.instr_in    (IF_ID_instr_out),
		.pc_plus4_in (IF_ID_pc_plus4_out),
		.pc_raw_in   (IF_ID_pc_out),

		.rs_addr     (ID_rs_addr),
		.rt_addr     (ID_rt_addr),
		.rd_addr     (ID_rd_addr),
		.imm12       (ID_imm12),
		.imms_ext_64 (ID_imms_ext64),
		.instr_opcode (ID_instr_opcode),

		.jump_target (ID_jump_target),
		.branch_target (ID_branch_target),

		.RegWrite    (ID_RegWrite),
		.MemRead     (ID_MemRead),
		.MemWrite    (ID_MemWrite),
		.MemToReg    (ID_MemToReg),
		.ALUSrc      (ID_ALUSrc),
		.Branch      (ID_Branch),
		.Jump        (ID_Jump),
		.ALUOp       (ID_ALUOp)
	);
	
	// Register File

	wire [63:0] regfile_rs_data;
	wire [63:0] regfile_rt_data;

	wire [3:0]  MEM_WB_rd;           // from MEM/WB stage 
	wire [63:0] MEM_WB_write_data;   // from MEM/WB stage 
	wire        MEM_WB_RegWrite;     // from MEM/WB stage 

	regfile regfile_inst (
    .addra (ID_rs_addr),
    .addrb (ID_rt_addr),
    .clk   (clk),
    .reset (reset),
    .waddr (MEM_WB_rd),
    .wdata (MEM_WB_write_data),
    .we    (MEM_WB_RegWrite),
    .douta (regfile_rs_data),
    .doutb (regfile_rt_data)
);

	//If read and write are happening at the same time for rt reg 
	wire [63:0] regfile_rt_data_bypassed;

	assign regfile_rt_data_bypassed =(MEM_WB_RegWrite && (MEM_WB_rd != 4'd0) && (MEM_WB_rd == ID_rt_addr)) ?
												  MEM_WB_write_data :
												  regfile_rt_data;
		
	// HDU
	
	wire ID_EX_MemRead;               // driven by ID_EX pipeline register (from decoded control)
	wire [3:0] ID_EX_rd;              // driven by ID_EX pipeline register (destination reg in EX)
	wire [3:0] IF_ID_rs;              // derived from IF/ID.instr
	wire [3:0] IF_ID_rt;              // derived from IF/ID.instr
	wire EX_MEM_MemRead_out;          // driven by EX_MEM pipeline register
	wire [3:0]  EX_MEM_rd_out;        // driven by EX_MEM pipeline register
	
	//wire pc_write;                  // output from HDU -> connect to program_counter -> already declared in the program counter section
	//wire HDU_if_id_write;           // output from HDU -> connect to IF_ID.if_id_write -> declared in IF_ID Stage Register
	wire id_ex_insert_bubble;         // output from HDU -> connect to ID_EX insert-bubble input
	// wire HDU_pc_write;
	
	//PC write = 0 when CPU disabled
	assign pc_write = HDU_pc_write & cpu_enable;
	
	
	assign IF_ID_rs = ID_rs_addr;
	assign IF_ID_rt = ID_rt_addr;
	
	hazard_detection_unit hdu_inst (
		.ID_EX_MemRead(ID_EX_MemRead_out),
		.ID_EX_rd     (ID_EX_rd_out),
		.IF_ID_rs     (IF_ID_rs),
		.IF_ID_rt     (IF_ID_rt),

		.pc_write            (HDU_pc_write),
		.if_id_write         (HDU_if_id_write),
		.id_ex_insert_bubble (id_ex_insert_bubble)
	);
		
	// ID_EX Stage Register
	
/* 	wire [63:0] ID_EX_rs_out;
	wire [63:0] ID_EX_rt_out;
	wire [63:0] ID_EX_imms_ext_64_out;
	wire [31:0] ID_EX_branch_target_out;

	wire [3:0]  ID_EX_rs_addr_out;
	wire [3:0]  ID_EX_rt_addr_out;
	wire [3:0]  ID_EX_rd_out; */

/* 	wire ID_EX_RegWrite_out;
	wire ID_EX_MemRead_out;
	wire ID_EX_MemWrite_out;
	wire ID_EX_MemToReg_out;
	wire ID_EX_ALUSrc_out;
	wire ID_EX_Branch_out;
	wire ID_EX_Jump_out;
	wire [3:0] ID_EX_ALUOp_out;
	wire [5:0] ID_EX_instr_opcode; */
	
	ID_EX id_ex_inst (
		.clk(clk),
		.reset(reset),
		.insert_bubble(id_ex_insert_bubble), //When branch is resolved in EX stage then only IF/ID and PC should be flushed 

		// data inputs from ID stage
		.rs_in              (regfile_rs_data),               
		.rt_in              (regfile_rt_data_bypassed),             
		.imms_ext_64_in     (ID_imms_ext64),
		.branch_target_in   (ID_branch_target),
		.rs_addr_in         (ID_rs_addr),
		.rt_addr_in         (ID_rt_addr),
		.rd_addr_in         (ID_rd_addr),
		.instr_opcode_in    (ID_instr_opcode),

		// control inputs from decoder
		.RegWrite_in (ID_RegWrite),
		.MemRead_in  (ID_MemRead),
		.MemWrite_in (ID_MemWrite),
		.MemToReg_in (ID_MemToReg),
		.ALUSrc_in   (ID_ALUSrc),
		.Branch_in   (ID_Branch),
		.Jump_in     (ID_Jump),
		.ALUOp_in    (ID_ALUOp),

		// data outputs to EX
		.rs_out              (ID_EX_rs_out),
		.rt_out              (ID_EX_rt_out),
		.imms_ext_64_out     (ID_EX_imms_ext_64_out),
		.branch_target_out   (ID_EX_branch_target_out),
		.rs_addr_out         (ID_EX_rs_addr_out),
		.rt_addr_out         (ID_EX_rt_addr_out),
		.rd_addr_out         (ID_EX_rd_out),
		.instr_opcode_out    (ID_EX_instr_opcode),

		// control outputs to EX
		.RegWrite_out (ID_EX_RegWrite_out),
		.MemRead_out  (ID_EX_MemRead_out),
		.MemWrite_out (ID_EX_MemWrite_out),
		.MemToReg_out (ID_EX_MemToReg_out),
		.ALUSrc_out   (ID_EX_ALUSrc_out),
		.Branch_out   (ID_EX_Branch_out),
		.Jump_out     (ID_EX_Jump_out),
		.ALUOp_out    (ID_EX_ALUOp_out)
	);
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// EX Stage

/* 	wire [5:0] ID_EX_instr_opcode_out;

	wire [63:0] EX_alu_result;
	wire [63:0] EX_rt_for_store;
	wire [3:0]  EX_dest_reg;

	wire EX_pc_src_branch;
	wire [31:0] EX_branch_target;
	wire EX_flush_if_id; */
	
	ex_stage ex_inst (
		.ID_EX_rs              (ID_EX_rs_out),
		.ID_EX_rt              (ID_EX_rt_out),
		.ID_EX_rs_addr         (ID_EX_rs_addr_out),
		.ID_EX_rt_addr         (ID_EX_rt_addr_out),
		.ID_EX_rd              (ID_EX_rd_out),
		.ID_EX_imms_ext_64     (ID_EX_imms_ext_64_out),
		.ID_EX_branch_target   (ID_EX_branch_target_out),
		.ID_EX_ALUOp           (ID_EX_ALUOp_out),
		.ID_EX_ALUSrc          (ID_EX_ALUSrc_out),
		.ID_EX_Branch          (ID_EX_Branch_out),
		.ID_EX_instr_opcode    (ID_EX_instr_opcode),

		.EX_MEM_rd             (EX_MEM_rd_out),
		.EX_MEM_RegWrite       (EX_MEM_RegWrite_out),
		.EX_MEM_alu_result     (EX_MEM_alu_result_out),
		.EX_MEM_MemRead        (EX_MEM_MemRead_out),

		.MEM_WB_rd             (MEM_WB_rd),
		.MEM_WB_RegWrite       (MEM_WB_RegWrite),
		.MEM_WB_write_data     (MEM_WB_write_data),

		.EX_alu_result         (EX_alu_result),
		.EX_rt_for_store       (EX_rt_for_store),
		.EX_dest_reg           (EX_dest_reg),

		.pc_src_branch         (EX_pc_src_branch),
		.branch_target_out     (EX_branch_target),
		.BU_if_id_flush        (EX_flush_if_id)
	);
	
	// EX_MEM Stage Register

/* 	wire [63:0] EX_MEM_alu_result_out;
	wire [63:0] EX_MEM_rt_for_store_out;

	wire EX_MEM_RegWrite_out;
	wire EX_MEM_MemWrite_out;
	wire EX_MEM_MemToReg_out; */
	
	EX_MEM ex_mem_inst (
		.clk(clk),
		.reset(reset),

		.alu_result_in   (EX_alu_result),
		.rt_for_store_in (EX_rt_for_store),
		.rd_in           (EX_dest_reg),

		.RegWrite_in (ID_EX_RegWrite_out),
		.MemRead_in  (ID_EX_MemRead_out),
		.MemWrite_in (ID_EX_MemWrite_out),
		.MemToReg_in (ID_EX_MemToReg_out),

		.alu_result_out   (EX_MEM_alu_result_out),
		.rt_for_store_out (EX_MEM_rt_for_store_out),
		.rd_out           (EX_MEM_rd_out),

		.RegWrite_out (EX_MEM_RegWrite_out),
		.MemRead_out  (EX_MEM_MemRead_out),
		.MemWrite_out (EX_MEM_MemWrite_out),
		.MemToReg_out (EX_MEM_MemToReg_out)
	);
	
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// -----------------------------------------MEM Stage -------------------------------------------------------
	wire [63:0] MEM_read_data;

	// Directly driving DMEM BRAM from EX_MEM outputs 
	DMEM dmem_inst (
		//Port A - For Simulation
		.addra (EX_MEM_alu_result_out[10:3]),   // address from EX_MEM (registered in EX_MEM)
		.clka  (clk),
		.dina  (EX_MEM_rt_for_store_out),
		.douta (MEM_read_data),      // synchronous read: valid next rising edge
		.wea   (EX_MEM_MemWrite_out),

		// Port B - For NetFPGA
		.addrb (dmem_addr_ext),
		.clkb  (clk),
		.dinb  (dmem_data_ext),
		.doutb (dmem_rdata_ext),
		.web   (dmem_we_ext)
	);


//MEM_WB Stage Register

	// MEM/WB wires (outputs from MEM_WB instance)
	wire [63:0] MEM_WB_mem_read_data_out;
	wire [63:0] MEM_WB_alu_result_out;
	wire        MEM_WB_MemToReg;

	MEM_WB mem_wb_inst (
		 .clk(clk),
		 .reset(reset),

		 .mem_read_data_in (MEM_read_data),  //Redundant
		 .alu_result_in    (EX_MEM_alu_result_out),
		 .rd_in            (EX_MEM_rd_out),

		 .RegWrite_in      (EX_MEM_RegWrite_out),
		 .MemToReg_in      (EX_MEM_MemToReg_out),

		 .mem_read_data_out(MEM_WB_mem_read_data_out), //Redundant
		 .alu_result_out   (MEM_WB_alu_result_out),
		 .rd_out           (MEM_WB_rd),

		 .RegWrite_out     (MEM_WB_RegWrite),
		 .MemToReg_out     (MEM_WB_MemToReg)
	);
////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// WB Stage
	
	assign MEM_WB_write_data = (MEM_WB_MemToReg == 1'b1) ? MEM_read_data : MEM_WB_alu_result_out;
///////////////////////////////////////////////////////////////////////////////////////////////////////

	//Register Shadow File for NetFPGA Reading

	reg [63:0] regfile_shadow [0:15]; // small shadow of 16 x 64-bit registers
	integer __i_shadow;

	// Keeping shadow in sync with write-back stage so external reads don't disturb the pipeline
	always @(posedge clk) begin
		if (reset) begin
			for (__i_shadow = 0; __i_shadow < 16; __i_shadow = __i_shadow + 1)
				regfile_shadow[__i_shadow] <= 64'd0;
		end
		else begin
			if (MEM_WB_RegWrite) begin
				regfile_shadow[MEM_WB_rd] <= MEM_WB_write_data;
			end
		end
	end

	// Providing combinational readback to external interface
	assign regfile_rdata_ext = regfile_re_ext ? regfile_shadow[regfile_addr_ext] : 64'd0;
	
endmodule
