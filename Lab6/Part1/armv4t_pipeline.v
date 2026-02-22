module armv4t_pipeline (
    input  wire clk,
    input  wire reset
);

    // =====================
    // IF STAGE
    // =====================
    wire [31:0] pc_current;
    wire [31:0] pc_plus4;
    wire [31:0] pc_next;
    wire [31:0] instruction_if;

    assign pc_plus4 = pc_current + 32'd4;

    // =====================
    // Branch Signals
    // =====================
    wire        Branch_id;
    wire        Branch_ex;
    wire [31:0] branch_target_ex;
    wire        branch_taken;

    // =====================
    // IF/ID
    // =====================
    wire [31:0] ifid_pc;
    wire [31:0] ifid_instr;
    wire        flush;

    // =====================
    // ID signals
    // =====================
    wire [3:0] rd, rn, rm;
    wire [31:0] reg_data1, reg_data2;
    wire [31:0] imm_ext;

    wire RegWrite, MemRead, MemWrite, MemtoReg, ALUSrc;
    wire [3:0] ALUControl;

    // =====================
    // ID/EX
    // =====================
    wire [31:0] idex_pc;
    wire [31:0] idex_reg1;
    wire [31:0] idex_reg2;
    wire [31:0] idex_imm;
    wire [3:0]  idex_rd;
    wire idex_RegWrite, idex_MemRead, idex_MemWrite;
    wire idex_MemtoReg, idex_ALUSrc;
    wire [3:0] idex_ALUControl;
    wire idex_Branch;

    // =====================
    // EX
    // =====================
    wire [31:0] alu_operand2;
    wire [31:0] alu_result;

    assign alu_operand2 = idex_ALUSrc ? idex_imm : idex_reg2;

    // Branch target calculation
    assign branch_target_ex = idex_pc + 32'd8 + idex_imm;
    assign branch_taken = idex_Branch;

    // =====================
    // EX/MEM
    // =====================
    wire [31:0] exmem_alu_result;
    wire [31:0] exmem_reg2;
    wire [3:0]  exmem_rd;
    wire exmem_RegWrite, exmem_MemRead, exmem_MemWrite, exmem_MemtoReg;

    // =====================
    // MEM
    // =====================
    wire [31:0] mem_read_data;

    // =====================
    // MEM/WB
    // =====================
    wire [31:0] memwb_mem_data;
    wire [31:0] memwb_alu_result;
    wire [3:0]  memwb_rd;
    wire memwb_RegWrite, memwb_MemtoReg;

    wire [31:0] writeback_data;

    // =====================
    // PC MUX
    // =====================
    assign pc_next = branch_taken ? branch_target_ex : pc_plus4;

    pc pc_inst (
        .clk(clk),
        .reset(reset),
        .pc_next(pc_next),
        .pc_current(pc_current)
    );

    instruction_memory imem (
        .addr(pc_current),
        .instr(instruction_if)
    );

    assign flush = branch_taken;

    if_id_reg if_id (
        .clk(clk),
        .reset(reset),
        .flush(flush),
        .pc_in(pc_current),
        .instr_in(instruction_if),
        .pc_out(ifid_pc),
        .instr_out(ifid_instr)
    );

    // =====================
    // ID STAGE
    // =====================
    assign rn = ifid_instr[19:16];
    assign rd = ifid_instr[15:12];
    assign rm = ifid_instr[3:0];

    register_file rf (
        .clk(clk),
        .we(memwb_RegWrite),
        .ra1(rn),
        .ra2(rm),
        .wa(memwb_rd),
        .wd(writeback_data),
        .rd1(reg_data1),
        .rd2(reg_data2)
    );

    arm_control_unit control (
        .instr(ifid_instr),
        .RegWrite(RegWrite),
        .MemRead(MemRead),
        .MemWrite(MemWrite),
        .MemtoReg(MemtoReg),
        .ALUSrc(ALUSrc),
        .ALUControl(ALUControl),
        .Branch(Branch_id)
    );

    sign_extend_arm se (
        .instr(ifid_instr),
        .imm_out(imm_ext)
    );

    id_ex_reg id_ex (
        .clk(clk),
        .reset(reset),
        .flush(flush),
        .pc_in(ifid_pc),
        .reg1_in(reg_data1),
        .reg2_in(reg_data2),
        .imm_in(imm_ext),
        .rd_in(rd),
        .RegWrite_in(RegWrite),
        .MemRead_in(MemRead),
        .MemWrite_in(MemWrite),
        .MemtoReg_in(MemtoReg),
        .ALUSrc_in(ALUSrc),
        .ALUControl_in(ALUControl),
        .Branch_in(Branch_id),
        .pc_out(idex_pc),
        .reg1_out(idex_reg1),
        .reg2_out(idex_reg2),
        .imm_out(idex_imm),
        .rd_out(idex_rd),
        .RegWrite_out(idex_RegWrite),
        .MemRead_out(idex_MemRead),
        .MemWrite_out(idex_MemWrite),
        .MemtoReg_out(idex_MemtoReg),
        .ALUSrc_out(idex_ALUSrc),
        .ALUControl_out(idex_ALUControl),
        .Branch_out(idex_Branch)
    );

    alu alu_inst (
        .A(idex_reg1),
        .B(alu_operand2),
        .ALUControl(idex_ALUControl),
        .Result(alu_result)
    );

    ex_mem_reg ex_mem (
        .clk(clk),
        .reset(reset),
        .alu_in(alu_result),
        .reg2_in(idex_reg2),
        .rd_in(idex_rd),
        .RegWrite_in(idex_RegWrite),
        .MemRead_in(idex_MemRead),
        .MemWrite_in(idex_MemWrite),
        .MemtoReg_in(idex_MemtoReg),
        .alu_out(exmem_alu_result),
        .reg2_out(exmem_reg2),
        .rd_out(exmem_rd),
        .RegWrite_out(exmem_RegWrite),
        .MemRead_out(exmem_MemRead),
        .MemWrite_out(exmem_MemWrite),
        .MemtoReg_out(exmem_MemtoReg)
    );

    data_memory dmem (
        .clk(clk),
        .MemRead(exmem_MemRead),
        .MemWrite(exmem_MemWrite),
        .addr(exmem_alu_result),
        .write_data(exmem_reg2),
        .read_data(mem_read_data)
    );

    mem_wb_reg mem_wb (
        .clk(clk),
        .reset(reset),
        .mem_data_in(mem_read_data),
        .alu_in(exmem_alu_result),
        .rd_in(exmem_rd),
        .RegWrite_in(exmem_RegWrite),
        .MemtoReg_in(exmem_MemtoReg),
        .mem_data_out(memwb_mem_data),
        .alu_out(memwb_alu_result),
        .rd_out(memwb_rd),
        .RegWrite_out(memwb_RegWrite),
        .MemtoReg_out(memwb_MemtoReg)
    );

    assign writeback_data =
        memwb_MemtoReg ? memwb_mem_data : memwb_alu_result;

endmodule