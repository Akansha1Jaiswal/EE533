// ============================================================
// FILE: arm_pipeline_top.v
// Top-Level Structural ARM Pipeline
// Instantiates and wires all submodules
// ============================================================

module arm_pipeline_top (
    input  wire clk,
    input  wire rst_n
);

    // ----------------------------------------------------------------
    // Internal wires between modules
    // ----------------------------------------------------------------

    // --- PC / IF ---
    wire [31:0] pc_out, pc_plus4, fetch_instr;
    wire [31:0] branch_target;
    wire        branch_taken;
    wire        stall, flush;

    // --- IF/ID register outputs ---
    wire [31:0] ifid_pc, ifid_instr;
    wire        ifid_valid;

    // --- Decode outputs ---
    wire [3:0]  dec_Rn, dec_Rm, dec_Rd;
    wire [3:0]  dec_cond, dec_aluop;
    wire [31:0] dec_imm;
    wire        dec_ALUSrc, dec_MemRead, dec_MemWrite;
    wire        dec_RegWrite, dec_MemToReg;
    wire        dec_Branch, dec_Link, dec_SetFlags;

    // --- Register file outputs ---
    wire [31:0] rf_RD1, rf_RD2;

    // --- ID/EX register outputs ---
    wire [31:0] idex_pc, idex_RD1, idex_RD2, idex_imm;
    wire [3:0]  idex_Rs, idex_Rt, idex_Rd;
    wire [3:0]  idex_aluop, idex_cond;
    wire        idex_ALUSrc, idex_MemRead, idex_MemWrite;
    wire        idex_RegWrite, idex_MemToReg;
    wire        idex_Branch, idex_Link, idex_SetFlags;
    wire        idex_valid;

    // --- Forwarding ---
    wire [1:0]  fwdA, fwdB;
    wire [31:0] ex_opA, ex_opB_reg, ex_opB;

    // --- EX/MEM register outputs ---
    wire [31:0] exmem_alu, exmem_wdata, exmem_btarget;
    wire [3:0]  exmem_Rd;
    wire        exmem_MemRead, exmem_MemWrite;
    wire        exmem_RegWrite, exmem_MemToReg;
    wire        exmem_BranchTaken;
    wire        exmem_valid;

    // --- MEM/WB register outputs ---
    wire [31:0] memwb_rdata, memwb_alu;
    wire [3:0]  memwb_Rd;
    wire        memwb_RegWrite, memwb_MemToReg;
    wire        memwb_valid;

    // --- WB ---
    wire [31:0] wb_data;

    // --- ALU / Cond ---
    wire [31:0] alu_result;
    wire        alu_zero, alu_N, alu_C, alu_V;
    wire        cond_pass;

    // --- CPSR flags ---
    wire        flag_N, flag_Z, flag_C, flag_V;

    // ================================================================
    // MODULE INSTANTIATIONS
    // ================================================================

    // 1. Instruction Memory
    instr_mem u_imem (
        .addr   (pc_out),
        .instr  (fetch_instr)
    );

    // 2. PC Register
    pc_reg u_pc (
        .clk        (clk),
        .rst_n      (rst_n),
        .stall      (stall),
        .flush      (flush),
        .branch_tgt (branch_target),
        .pc_in      (pc_plus4),
        .pc_out     (pc_out)
    );

    // 3. PC+4 Adder
    adder u_pcadd (
        .A   (pc_out),
        .B   (32'd4),
        .Sum (pc_plus4)
    );

    // 4. IF/ID Pipeline Register
    ifid_reg u_ifid (
        .clk        (clk),
        .rst_n      (rst_n),
        .stall      (stall),
        .flush      (flush),
        .in_pc      (pc_out),
        .in_instr   (fetch_instr),
        .in_valid   (1'b1),
        .out_pc     (ifid_pc),
        .out_instr  (ifid_instr),
        .out_valid  (ifid_valid)
    );

    // 5. Instruction Decoder
    decoder u_dec (
        .instr      (ifid_instr),
        .Rn         (dec_Rn),
        .Rm         (dec_Rm),
        .Rd         (dec_Rd),
        .cond       (dec_cond),
        .aluop      (dec_aluop),
        .imm        (dec_imm),
        .ALUSrc     (dec_ALUSrc),
        .MemRead    (dec_MemRead),
        .MemWrite   (dec_MemWrite),
        .RegWrite   (dec_RegWrite),
        .MemToReg   (dec_MemToReg),
        .Branch     (dec_Branch),
        .Link       (dec_Link),
        .SetFlags   (dec_SetFlags)
    );

    // 6. Register File
    reg_file u_rf (
        .clk        (clk),
        .rst_n      (rst_n),
        .RdAddr1    (dec_Rn),
        .RdAddr2    (dec_Rm),
        .WrAddr     (memwb_Rd),
        .WrData     (wb_data),
        .WrEn       (memwb_RegWrite & memwb_valid),
        .RD1        (rf_RD1),
        .RD2        (rf_RD2)
    );

    // 7. Hazard Detection Unit
    hazard_unit u_hazard (
        .idex_MemRead   (idex_MemRead),
        .idex_Rd        (idex_Rd),
        .dec_Rn         (dec_Rn),
        .dec_Rm         (dec_Rm),
        .stall          (stall)
    );

    // 8. ID/EX Pipeline Register
    idex_reg u_idex (
        .clk        (clk),
        .rst_n      (rst_n),
        .flush      (flush | stall),   // stall inserts bubble
        .in_pc      (ifid_pc),
        .in_RD1     (rf_RD1),
        .in_RD2     (rf_RD2),
        .in_imm     (dec_imm),
        .in_Rs      (dec_Rn),
        .in_Rt      (dec_Rm),
        .in_Rd      (dec_Rd),
        .in_aluop   (dec_aluop),
        .in_ALUSrc  (dec_ALUSrc),
        .in_MemRead (dec_MemRead),
        .in_MemWrite(dec_MemWrite),
        .in_RegWrite(dec_RegWrite),
        .in_MemToReg(dec_MemToReg),
        .in_Branch  (dec_Branch),
        .in_Link    (dec_Link),
        .in_SetFlags(dec_SetFlags),
        .in_cond    (dec_cond),
        .in_valid   (ifid_valid),
        .out_pc     (idex_pc),
        .out_RD1    (idex_RD1),
        .out_RD2    (idex_RD2),
        .out_imm    (idex_imm),
        .out_Rs     (idex_Rs),
        .out_Rt     (idex_Rt),
        .out_Rd     (idex_Rd),
        .out_aluop  (idex_aluop),
        .out_ALUSrc (idex_ALUSrc),
        .out_MemRead(idex_MemRead),
        .out_MemWrite(idex_MemWrite),
        .out_RegWrite(idex_RegWrite),
        .out_MemToReg(idex_MemToReg),
        .out_Branch (idex_Branch),
        .out_Link   (idex_Link),
        .out_SetFlags(idex_SetFlags),
        .out_cond   (idex_cond),
        .out_valid  (idex_valid)
    );

    // 9. Forwarding Unit
    forwarding_unit u_fwd (
        .idex_Rs        (idex_Rs),
        .idex_Rt        (idex_Rt),
        .exmem_RegWrite (exmem_RegWrite),
        .exmem_Rd       (exmem_Rd),
        .memwb_RegWrite (memwb_RegWrite),
        .memwb_Rd       (memwb_Rd),
        .ForwardA       (fwdA),
        .ForwardB       (fwdB)
    );

    // 10. Forward MUX A (EX stage operand A)
    mux3_32 u_muxA (
        .sel    (fwdA),
        .D0     (idex_RD1),
        .D1     (wb_data),
        .D2     (exmem_alu),
        .Y      (ex_opA)
    );

    // 11. Forward MUX B (EX stage operand B before ALUSrc)
    mux3_32 u_muxB (
        .sel    (fwdB),
        .D0     (idex_RD2),
        .D1     (wb_data),
        .D2     (exmem_alu),
        .Y      (ex_opB_reg)
    );

    // 12. ALUSrc MUX (register vs immediate)
    mux2_32 u_muxALUSrc (
        .sel    (idex_ALUSrc),
        .D0     (ex_opB_reg),
        .D1     (idex_imm),
        .Y      (ex_opB)
    );

    // 13. Condition Check Unit
    cond_check u_cond (
        .cond   (idex_cond),
        .N      (flag_N),
        .Z      (flag_Z),
        .C      (flag_C),
        .V      (flag_V),
        .pass   (cond_pass)
    );

    // 14. ALU
    alu u_alu (
        .op     (idex_aluop),
        .A      (ex_opA),
        .B      (ex_opB),
        .cin    (flag_C),
        .Result (alu_result),
        .Zero   (alu_zero),
        .N_out  (alu_N),
        .C_out  (alu_C),
        .V_out  (alu_V)
    );

    // 15. CPSR Register (flags)
    cpsr_reg u_cpsr (
        .clk        (clk),
        .rst_n      (rst_n),
        .SetFlags   (idex_SetFlags & cond_pass & idex_valid),
        .N_in       (alu_N),
        .Z_in       (alu_zero),
        .C_in       (alu_C),
        .V_in       (alu_V),
        .N_out      (flag_N),
        .Z_out      (flag_Z),
        .C_out      (flag_C),
        .V_out      (flag_V)
    );

    // 16. Branch Unit
    branch_unit u_branch (
        .pc         (idex_pc),
        .offset     (idex_imm),
        .is_branch  (idex_Branch),
        .cond_pass  (cond_pass),
        .valid      (idex_valid),
        .branch_tgt (branch_target),
        .branch_taken(branch_taken)
    );

    assign flush = branch_taken;

    // 17. EX/MEM Pipeline Register
    exmem_reg u_exmem (
        .clk            (clk),
        .rst_n          (rst_n),
        .in_ALUResult   (cond_pass & idex_valid ? alu_result : 32'b0),
        .in_WriteData   (ex_opB_reg),
        .in_Rd          (idex_Rd),
        .in_BranchTarget(branch_target),
        .in_BranchTaken (branch_taken),
        .in_MemRead     (idex_MemRead  & cond_pass & idex_valid),
        .in_MemWrite    (idex_MemWrite & cond_pass & idex_valid),
        .in_RegWrite    (idex_RegWrite & cond_pass & idex_valid),
        .in_MemToReg    (idex_MemToReg),
        .in_valid       (idex_valid),
        .out_ALUResult  (exmem_alu),
        .out_WriteData  (exmem_wdata),
        .out_Rd         (exmem_Rd),
        .out_BranchTarget(exmem_btarget),
        .out_BranchTaken(exmem_BranchTaken),
        .out_MemRead    (exmem_MemRead),
        .out_MemWrite   (exmem_MemWrite),
        .out_RegWrite   (exmem_RegWrite),
        .out_MemToReg   (exmem_MemToReg),
        .out_valid      (exmem_valid)
    );

    // 18. Data Memory
    wire [31:0] dmem_rdata;
    data_mem u_dmem (
        .clk        (clk),
        .addr       (exmem_alu),
        .wdata      (exmem_wdata),
        .MemRead    (exmem_MemRead),
        .MemWrite   (exmem_MemWrite),
        .rdata      (dmem_rdata)
    );

    // 19. MEM/WB Pipeline Register
    memwb_reg u_memwb (
        .clk            (clk),
        .rst_n          (rst_n),
        .in_ReadData    (dmem_rdata),
        .in_ALUResult   (exmem_alu),
        .in_Rd          (exmem_Rd),
        .in_RegWrite    (exmem_RegWrite),
        .in_MemToReg    (exmem_MemToReg),
        .in_valid       (exmem_valid),
        .out_ReadData   (memwb_rdata),
        .out_ALUResult  (memwb_alu),
        .out_Rd         (memwb_Rd),
        .out_RegWrite   (memwb_RegWrite),
        .out_MemToReg   (memwb_MemToReg),
        .out_valid      (memwb_valid)
    );

    // 20. WB MUX (MemToReg)
    mux2_32 u_muxWB (
        .sel    (memwb_MemToReg),
        .D0     (memwb_alu),
        .D1     (memwb_rdata),
        .Y      (wb_data)
    );

endmodule