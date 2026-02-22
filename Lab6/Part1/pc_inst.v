    pc pc_inst (
        .clk(clk),
        .reset(reset),
        .pc_next(pc_next),
        .pc_current(pc_current)
    );

    assign pc_next = pc_current + 32'd4;

    instruction_memory imem (
        .addr(pc_current),
        .instr(instruction_if)
    );

    if_id_reg if_id (
        .clk(clk),
        .reset(reset),
        .pc_in(pc_current),
        .instr_in(instruction_if),
        .pc_out(ifid_pc),
        .instr_out(ifid_instr)
    );