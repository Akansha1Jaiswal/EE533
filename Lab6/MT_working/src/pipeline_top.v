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
	input  cpu_enable, // run/stop from wrapper

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
	
	//PC Signals
    wire pc_write;                 
	wire pc_src_branch;
	wire pc_src_jump;
	wire [31:0] branch_target;
	wire [31:0] jump_target;
	wire [31:0] pc_out;
	wire [1:0]  EX_thread_id;
	wire [1:0]  IF_thread_id;
	wire [1:0]  ID_thread_id;
	
	//IMEM Signals
	wire [8:0]  imem_addr_in; 
	wire [31:0] imem_instr_out;
		// IMEM external programming mux
	wire [8:0]  imem_addr_mux;
	wire [31:0] imem_din_mux;
	wire        imem_we_mux;
	
	//IF_ID Stage Reg Signals
	wire [31:0] IF_ID_pc_plus4_out;
	//wire [31:0] IF_ID_instr_out;
	wire [31:0] pc_plus4_if_id_in;
	
	//Instruction Decoder Control Signals
	wire [3:0]  ID_rs_addr, ID_rt_addr, ID_rd_addr;
	wire [11:0] ID_imm12;
	wire [63:0] ID_imms_ext64;
	wire [31:0] ID_jump_target, ID_branch_target;
	wire ID_RegWrite, ID_MemRead, ID_MemWrite, ID_MemToReg, ID_ALUSrc, ID_Branch, ID_Jump;
	wire [3:0]  ID_ALUOp;
	wire [5:0]  ID_instr_opcode;
	
	//RegFile Signals	
	wire [63:0] regfile_rs_data;
	wire [63:0] regfile_rt_data;
	
	//ID_EX Stage Register Signals 
	wire [63:0] ID_EX_rs_out;
	wire [63:0] ID_EX_rt_out;
	wire [63:0] ID_EX_imms_ext_64_out;
	wire [31:0] ID_EX_branch_target_out;
	wire [5:0]  ID_EX_instr_opcode_out;
	wire [3:0]  ID_EX_ALUOp_out;
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
	
	//EX Signals
	wire [63:0] EX_alu_result;
	wire [63:0] EX_rt_for_store;
	wire [3:0]  EX_dest_reg;

	wire EX_pc_src_branch;
	wire [31:0] EX_branch_target;
	
	//EX_MEM Stage Register Signals
	wire [63:0] EX_MEM_alu_result_out;
	wire [63:0] EX_MEM_rt_for_store_out;
	wire [1:0]  MEM_thread_id;
	wire [3:0]  EX_MEM_rd_out;

	wire EX_MEM_RegWrite_out;
	wire EX_MEM_MemWrite_out;
	wire EX_MEM_MemToReg_out;
	
	//MEM Signals
	wire [63:0] MEM_read_data;
	
	//MEM_WB Stage Register Signals
	wire [63:0] MEM_WB_mem_read_data_out;
	wire [63:0] MEM_WB_alu_result_out;
	wire        MEM_WB_MemToReg;
	wire [1:0]  WB_thread_id;
		
	wire [3:0]  MEM_WB_rd;      
	wire [63:0] MEM_WB_write_data;   
	wire        MEM_WB_RegWrite;     
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Program Counter
	
	assign pc_src_branch  = EX_pc_src_branch;
	assign branch_target  = EX_branch_target;
	
	assign pc_src_jump    = ID_Jump;
	assign jump_target    = ID_jump_target;
	
	program_counter pc_inst (
		.clk(clk),
		.reset(reset),
		.cpu_enable(cpu_enable),
		//.pc_write(pc_write),           // From HDU in ID
		.pc_src_branch(pc_src_branch), // From Branch Unit in EX
		.pc_src_jump(pc_src_jump),     // From Control Unit in ID
		.branch_target(branch_target), // From BU in EX
		.jump_target(jump_target),     // From Control Unit in ID
		.EX_thread_id(EX_thread_id),
		.ID_thread_id(ID_thread_id),
		
		.pc(pc_out),
		.thread_id(IF_thread_id)
	);

	// Instruction Memory
	assign imem_addr_in  = {IF_thread_id,pc_out[8:2]};
	assign imem_addr_mux = imem_we_ext ? imem_addr_ext : imem_addr_in;
	assign imem_din_mux  = imem_we_ext ? imem_data_ext : 32'b0;
	assign imem_we_mux   = imem_we_ext;

	IMEM imem_inst (
		.addr(imem_addr_mux),   // either external address or PC[8:2] concatenated with thread ID
		.clk(clk),
		.din(imem_din_mux),
		.dout(imem_instr_out),
		.we(imem_we_mux)
	);

	
	// IF_ID Stage Register
	
	assign pc_plus4_if_id_in = pc_out + 32'd4; // For branch calculation we need PC + 4 not just PC
	//assign BU_if_id_flush = EX_flush_if_id | pc_src_jump ;//| ID_Jump;    // If branch is taken or jump instruction is present

	IF_ID if_id_inst (
		.clk(clk),
		.reset(reset),
		//.if_id_write(HDU_if_id_write),
		//.if_id_flush(BU_if_id_flush),
		.pc_plus4_in(pc_plus4_if_id_in),
		//.instr_in(imem_instr_out),
		.IF_thread_id(IF_thread_id),
		
		.pc_plus4_out(IF_ID_pc_plus4_out),
		.ID_thread_id(ID_thread_id)
		//.instr_out(IF_ID_instr_out),
		);
			
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
	// Instruction Decoder + Control Logic

	instruction_decoder_control id_ctrl_inst (
		.instr_in    (imem_instr_out),
		.pc_plus4_in (IF_ID_pc_plus4_out),
		.ID_thread_id(ID_thread_id),
		
		.rs_addr     (ID_rs_addr),
		.rt_addr     (ID_rt_addr),
		.rd_addr     (ID_rd_addr),
		.imm12       (ID_imm12),
		.imms_ext_64 (ID_imms_ext64),
		.instr_opcode(ID_instr_opcode),

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

	regfile regfile_inst (
		.addra (ID_rs_addr),
		.addrb (ID_rt_addr),
		.ID_thread_id (ID_thread_id),
		.WB_thread_id (WB_thread_id),
		.clk   (clk),
		.reset (reset),
		.waddr (MEM_WB_rd),
		.wdata (MEM_WB_write_data),
		.we    (MEM_WB_RegWrite),
		.douta (regfile_rs_data),
		.doutb (regfile_rt_data)
	);

	//If read and write are happening at the same time for rt reg - NOT NEEDED FOR FGMT
	//wire [63:0] regfile_rt_data_bypassed;
	//assign regfile_rt_data_bypassed =(MEM_WB_RegWrite && (MEM_WB_rd != 4'd0) && (MEM_WB_rd == ID_rt_addr)) ? MEM_WB_write_data : regfile_rt_data;
		
		
	// ID_EX Stage Register
	
	ID_EX id_ex_inst (
		.clk(clk),
		.reset(reset),
		//.insert_bubble(id_ex_insert_bubble), //When branch is resolved in EX stage then only IF/ID and PC should be flushed 

		// data inputs from ID stage
		.rs_in              (regfile_rs_data),               
		.rt_in              (regfile_rt_data),             
		.imms_ext_64_in     (ID_imms_ext64),
		.branch_target_in   (ID_branch_target),
		.rs_addr_in         (ID_rs_addr),
		.rt_addr_in         (ID_rt_addr),
		.rd_addr_in         (ID_rd_addr),
		.instr_opcode_in    (ID_instr_opcode),
		.ID_thread_id       (ID_thread_id),

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
		.instr_opcode_out    (ID_EX_instr_opcode_out),
		.EX_thread_id        (EX_thread_id),

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
		.ID_EX_instr_opcode    (ID_EX_instr_opcode_out),

		.EX_alu_result         (EX_alu_result),
		.EX_rt_for_store       (EX_rt_for_store),
		.EX_dest_reg           (EX_dest_reg),

		.pc_src_branch         (EX_pc_src_branch),
		.branch_target_out     (EX_branch_target)
	);
	
	// EX_MEM Stage Register
	
	EX_MEM ex_mem_inst (
		.clk(clk),
		.reset(reset),

		.alu_result_in   (EX_alu_result),
		.rt_for_store_in (EX_rt_for_store),
		.rd_in           (EX_dest_reg),
		.EX_thread_id    (EX_thread_id),

		.RegWrite_in (ID_EX_RegWrite_out),
		.MemRead_in  (ID_EX_MemRead_out),
		.MemWrite_in (ID_EX_MemWrite_out),
		.MemToReg_in (ID_EX_MemToReg_out),

		.alu_result_out   (EX_MEM_alu_result_out),
		.rt_for_store_out (EX_MEM_rt_for_store_out),
		.rd_out           (EX_MEM_rd_out),
		.MEM_thread_id    (MEM_thread_id),

		.RegWrite_out (EX_MEM_RegWrite_out),
		.MemRead_out  (EX_MEM_MemRead_out),
		.MemWrite_out (EX_MEM_MemWrite_out),
		.MemToReg_out (EX_MEM_MemToReg_out)
	);
	
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// -----------------------------------------MEM Stage -------------------------------------------------------
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

	MEM_WB mem_wb_inst (
		 .clk(clk),
		 .reset(reset),

		 //.mem_read_data_in (MEM_read_data),  //Redundant
		 .alu_result_in    (EX_MEM_alu_result_out),
		 .rd_in            (EX_MEM_rd_out),
		 .MEM_thread_id    (MEM_thread_id),

		 .RegWrite_in      (EX_MEM_RegWrite_out),
		 .MemToReg_in      (EX_MEM_MemToReg_out),

		 //.mem_read_data_out(MEM_WB_mem_read_data_out), //Redundant
		 .alu_result_out   (MEM_WB_alu_result_out),
		 .rd_out           (MEM_WB_rd),
		 .WB_thread_id     (WB_thread_id),

		 .RegWrite_out     (MEM_WB_RegWrite),
		 .MemToReg_out     (MEM_WB_MemToReg)
	);
////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// WB Stage
	
	assign MEM_WB_write_data = (MEM_WB_MemToReg == 1'b1) ? MEM_read_data : MEM_WB_alu_result_out;
///////////////////////////////////////////////////////////////////////////////////////////////////////

	//Register Shadow File for NetFPGA Reading

	reg [63:0] regfile_shadow [0:63]; // small shadow of 16 x 64-bit registers
	integer __i_shadow;

	// Keeping shadow in sync with write-back stage so external reads don't disturb the pipeline
	always @(posedge clk) begin
		if (reset) begin
			for (__i_shadow = 0; __i_shadow < 64; __i_shadow = __i_shadow + 1)
				regfile_shadow[__i_shadow] <= 64'd0;
		end
		else begin
			if (MEM_WB_RegWrite) begin
				regfile_shadow[{WB_thread_id, MEM_WB_rd}] <= MEM_WB_write_data;
			end
		end
	end

	// Providing combinational readback to external interface
	assign regfile_rdata_ext = regfile_re_ext ? regfile_shadow[regfile_addr_ext] : 64'd0;
	
endmodule
