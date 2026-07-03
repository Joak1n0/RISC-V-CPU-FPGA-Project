module control_unit (
    input wire clk,
    input wire rst,
    input wire [6:0] op,
    input wire [2:0] funct3,
    input wire [6:0] funct7,
    input wire zero;

    output reg pc_src,
    output reg ResultSrc,
    output reg MemWrite,
    output reg [2:0] ALUControl;
    output reg ALUSrc,
    output reg [1:0] ImmSrc,
    output reg RegWrite,
    
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
