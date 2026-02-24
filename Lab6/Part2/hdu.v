module hdu_mt(
    input  wire        ID_EX_MemRead,
    input  wire [3:0]  ID_EX_Rd,
    input  wire [1:0]  ID_EX_thread,
    input  wire [3:0]  IF_ID_Rs,
    input  wire [3:0]  IF_ID_Rt,
    input  wire [1:0]  IF_ID_thread,
    output reg         PC_write,
    output reg         IF_ID_write,
    output reg         ID_EX_flush
);

    wire same_thread = (ID_EX_thread == IF_ID_thread);

    always @(*) begin
        PC_write    = 1'b1;
        IF_ID_write = 1'b1;
        ID_EX_flush = 1'b0;

        // Load-use hazard: only stall if same thread
        if (ID_EX_MemRead && same_thread &&
            ((ID_EX_Rd == IF_ID_Rs) || (ID_EX_Rd == IF_ID_Rt))) begin
            PC_write    = 1'b0;
            IF_ID_write = 1'b0;
            ID_EX_flush = 1'b1;
        end
    end

endmodule