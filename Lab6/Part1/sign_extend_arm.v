module sign_extend_arm (
    input  [31:0] instr,
    output reg [31:0] imm_out
);

    always @(*) begin
        case (instr[27:25])

            3'b101: begin
                imm_out = {{6{instr[23]}}, instr[23:0], 2'b00};
            end

            default: begin
                case (instr[27:26])

                    2'b00:
                        imm_out = {24'd0, instr[7:0]};

                    2'b01:
                        imm_out = {20'd0, instr[11:0]};

                    default:
                        imm_out = 32'd0;
                endcase
            end

        endcase
    end
endmodule