module arm_control_unit (
    input  [31:0] instr,
    output reg RegWrite,
    output reg MemRead,
    output reg MemWrite,
    output reg MemtoReg,
    output reg ALUSrc,
    output reg [3:0] ALUControl,
    output reg Branch
);

    wire [1:0] type = instr[27:26];

    always @(*) begin
        RegWrite = 0;
        MemRead = 0;
        MemWrite = 0;
        MemtoReg = 0;
        ALUSrc = 0;
        ALUControl = 4'b0000;
        Branch = 0;

        case (instr[27:25])

            3'b101: begin
                Branch = 1;
            end

            default: begin
                case (type)

                    2'b00: begin
                        RegWrite = 1;
                        ALUSrc = instr[25];
                        ALUControl = instr[24:21];
                    end

                    2'b01: begin
                        ALUSrc = 1;
                        ALUControl = 4'b0100;
                        if (instr[20]) begin
                            MemRead = 1;
                            MemtoReg = 1;
                            RegWrite = 1;
                        end else begin
                            MemWrite = 1;
                        end
                    end

                endcase
            end

        endcase
    end
endmodule