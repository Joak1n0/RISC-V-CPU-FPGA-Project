module control_unit (
    input wire clk,
    input wire rst,
    input wire [31:0] instr,
    output reg [3:0] alu_op,
    output reg [31:0] pc
);
    always @(posedge clk) begin
        if (rst) begin
            alu_op <= 0;
            pc <= 0;
        end else begin
            case (instr[31:26]) // opcode
                6'b000000: begin // R-type
                case (instr[5:0]) // funct
                    6'b100000: alu_op <= 4'b0000; // ADD
                    6'b100010: alu_op <= 4'b0001; // SUB
                    6'b100100: alu_op <= 4'b0010; // AND
                    6'b100101: alu_op <= 4'b0011; // OR
                    6'b100110: alu_op <= 4'b0100; // XOR
                    default:   alu_op <= 0;
                endcase
                end
                default: alu_op <= 0;
            endcase
            pc <= pc + 4; // Increment PC by 4 for next instruction
        end
    end
    
endmodule
