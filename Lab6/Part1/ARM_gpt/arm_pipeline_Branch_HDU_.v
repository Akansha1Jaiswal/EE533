
module arm_pipeline64 (
    input clk,
    input reset
);

parameter DATA_WIDTH = 64;
parameter ADDR_WIDTH = 9;
parameter REG_ADDR   = 4;

// =====================================================
// ===================== IF STAGE ======================
// =====================================================

reg  [ADDR_WIDTH-1:0] PC_reg;
wire [ADDR_WIDTH-1:0] PC_plus4;
wire [ADDR_WIDTH-1:0] PC_next;
wire [DATA_WIDTH-1:0] MEMWB_wdata;

assign PC_plus4 = PC_reg + 4;

always @(posedge clk or posedge reset) begin
    if (reset)
        PC_reg <= 0;
    else if (!stall)
        PC_reg <= PC_next;
end

wire [31:0] instr_IF;

IMem imem (
    .clk(clk),
    .addr(PC_reg),
    .dout(instr_IF)
);

// IF/ID pipeline register
reg [31:0] IFID_instr;
reg [ADDR_WIDTH-1:0] IFID_PC;

always @(posedge clk or posedge reset) begin
    if (reset) begin
        IFID_instr <= 0;
        IFID_PC <= 0;
    end
    else if (flush) begin
        IFID_instr <= 0; 
        IFID_PC    <= 0;   // missing in your code
end
        
        // insert NOP
    end
    else if (!stall) begin
        IFID_instr <= instr_IF;
        IFID_PC <= PC_reg;
    end
end

// =====================================================
// ===================== ID STAGE ======================
// =====================================================

wire [REG_ADDR-1:0] Rn = IFID_instr[19:16];
wire [REG_ADDR-1:0] Rd = IFID_instr[15:12];
wire [REG_ADDR-1:0] Rm = IFID_instr[3:0];

wire RegWrite_ID, MemRead_ID, MemWrite_ID;
wire MemToReg_ID, ALUSrc_ID, Branch_ID;
wire [3:0] ALUControl_ID;

arm_decoder decoder (
    .instr(IFID_instr),
    .RegWrite(RegWrite_ID),
    .MemRead(MemRead_ID),
    .MemWrite(MemWrite_ID),
    .MemToReg(MemToReg_ID),
    .ALUSrc(ALUSrc_ID),
    .Branch(Branch_ID),
    .ALUControl(ALUControl_ID)
);

// Register File
wire [DATA_WIDTH-1:0] reg_rdata1;
wire [DATA_WIDTH-1:0] reg_rdata2;

regfile64x16 RF (
    .clk(clk),
    .RegWrite(MEMWB_RegWrite),
    .rs1(Rn),
    .rs2(Rm),
    .rd(MEMWB_Rd),
    .wdata(MEMWB_wdata),
    .rdata1(reg_rdata1),
    .rdata2(reg_rdata2)
);

// Immediate extend
wire [DATA_WIDTH-1:0] imm_ext;
assign imm_ext = {{52{IFID_instr[11]}}, IFID_instr[11:0]};

// ================= EARLY BRANCH =================

wire branch_condition;
assign branch_condition = (reg_rdata1 == reg_rdata2);

wire [ADDR_WIDTH-1:0] branch_target_ID;
assign branch_target_ID = IFID_PC + (imm_ext[ADDR_WIDTH-1:0] << 2);

wire BranchTaken_ID;
assign BranchTaken_ID = Branch_ID & branch_condition;

assign flush = BranchTaken_ID;
assign PC_next = BranchTaken_ID ? branch_target_ID : PC_plus4;

// =====================================================
// ================ LOAD-USE HAZARD ====================
// =====================================================

assign stall = (IDEX_MemRead &&
               ((IDEX_Rd == Rn) || (IDEX_Rd == Rm)));

// =====================================================
// =================== ID/EX STAGE =====================
// =====================================================

reg [DATA_WIDTH-1:0] IDEX_A, IDEX_B, IDEX_imm;
reg [REG_ADDR-1:0]   IDEX_Rd, IDEX_Rn, IDEX_Rm;
reg IDEX_RegWrite, IDEX_MemRead;
reg IDEX_MemWrite, IDEX_MemToReg, IDEX_ALUSrc;
reg [3:0] IDEX_ALUControl;

always @(posedge clk or posedge reset) begin
    if (reset || stall) begin
        IDEX_RegWrite <= 0;
        IDEX_MemRead  <= 0;
        IDEX_MemWrite <= 0;
        IDEX_MemToReg <= 0;
    end
    else begin
        IDEX_A <= reg_rdata1;
        IDEX_B <= reg_rdata2;
        IDEX_imm <= imm_ext;
        IDEX_Rd <= Rd;
        IDEX_Rn <= Rn;
        IDEX_Rm <= Rm;
        IDEX_RegWrite <= RegWrite_ID;
        IDEX_MemRead  <= MemRead_ID;
        IDEX_MemWrite <= MemWrite_ID;
        IDEX_MemToReg <= MemToReg_ID;
        IDEX_ALUSrc   <= ALUSrc_ID;
        IDEX_ALUControl <= ALUControl_ID;
    end
end

// =====================================================
// ===================== FORWARDING ====================
// =====================================================

wire [1:0] ForwardA, ForwardB;

forwarding_unit FWD(
    .IDEX_Rn(IDEX_Rn),
    .IDEX_Rm(IDEX_Rm),
    .EXMEM_Rd(EXMEM_Rd),
    .EXMEM_RegWrite(EXMEM_RegWrite),
    .MEMWB_Rd(MEMWB_Rd),
    .MEMWB_RegWrite(MEMWB_RegWrite),
    .ForwardA(ForwardA),
    .ForwardB(ForwardB)
);

wire [DATA_WIDTH-1:0] ALU_in1;
wire [DATA_WIDTH-1:0] ALU_in2_pre;

assign ALU_in1 =
    (ForwardA == 2'b10) ? EXMEM_aluResult :
    (ForwardA == 2'b01) ? MEMWB_wdata :
                          IDEX_A;

assign ALU_in2_pre =
    (ForwardB == 2'b10) ? EXMEM_aluResult :
    (ForwardB == 2'b01) ? MEMWB_wdata :
                          IDEX_B;

wire [DATA_WIDTH-1:0] ALU_in2 =
    IDEX_ALUSrc ? IDEX_imm : ALU_in2_pre;

// =====================================================
// ====================== EX STAGE =====================
// =====================================================

wire [DATA_WIDTH-1:0] alu_result;

alu64 ALU (
    .A(ALU_in1),
    .B(ALU_in2),
    .alu_ctrl(IDEX_ALUControl),
    .result(alu_result)
);

// EX/MEM
reg [DATA_WIDTH-1:0] EXMEM_aluResult;
reg [DATA_WIDTH-1:0] EXMEM_WriteData;
reg [REG_ADDR-1:0]   EXMEM_Rd;
reg EXMEM_RegWrite, EXMEM_MemRead;
reg EXMEM_MemWrite, EXMEM_MemToReg;

always @(posedge clk or posedge reset) begin
    if (reset) begin
        EXMEM_RegWrite <= 0;
    end else begin
        EXMEM_aluResult <= alu_result;
        EXMEM_WriteData <= ALU_in2_pre;
        EXMEM_Rd <= IDEX_Rd;
        EXMEM_RegWrite <= IDEX_RegWrite;
        EXMEM_MemRead  <= IDEX_MemRead;
        EXMEM_MemWrite <= IDEX_MemWrite;
        EXMEM_MemToReg <= IDEX_MemToReg;
    end
end

// =====================================================
// ====================== MEM STAGE ====================
// =====================================================

wire [DATA_WIDTH-1:0] mem_rdata;

DataMem dmem (
    .clk(clk),
    .addr(EXMEM_aluResult[ADDR_WIDTH-1:0]),
    .MemRead(EXMEM_MemRead),
    .MemWrite(EXMEM_MemWrite),
    .wdata(EXMEM_WriteData),
    .rdata(mem_rdata)
);

// MEM/WB
reg [DATA_WIDTH-1:0] MEMWB_memData;
reg [DATA_WIDTH-1:0] MEMWB_aluResult;
reg [REG_ADDR-1:0]   MEMWB_Rd;
reg MEMWB_RegWrite, MEMWB_MemToReg;

always @(posedge clk or posedge reset) begin
    if (reset) begin
        MEMWB_RegWrite <= 0;
    end else begin
        MEMWB_memData <= mem_rdata;
        MEMWB_aluResult <= EXMEM_aluResult;
        MEMWB_Rd <= EXMEM_Rd;
        MEMWB_RegWrite <= EXMEM_RegWrite;
        MEMWB_MemToReg <= EXMEM_MemToReg;
    end
end

assign MEMWB_wdata = MEMWB_MemToReg ?
                     MEMWB_memData :
                     MEMWB_aluResult;

endmodule