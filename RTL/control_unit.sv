module control_unit (
    input logic [6:0] op,
    input logic [2:0] funct3,
    input logic [6:0] funct7,
    input logic alu_zero,
    input logic alu_last_bit,

    output logic [3:0] alu_control,
    output logic [2:0] imm_source,
    output logic mem_write,
    output logic reg_write,
    output logic alu_source,
    output logic [1:0] write_back_source,
    output logic pc_source,
    output logic [1:0] second_add_source
    
);

import pkg_riscvi32::*;

    /**
    * Main Decoder
    */

    logic [1:0] alu_op;
    logic branch;
    logic jump;

    always_comb begin
        case (op) 
            // I-Type Instructions
            OPCODE_I_TYPE_LOAD: begin
                reg_write = 1'b1;
                imm_source = 3'b000; // I-Type immediate
                mem_write = 1'b0;
                alu_op = 2'b00; // ALU operation for load/store
                alu_source = 1'b1; // Use immediate value
                write_back_source = 2'b01; // Write back from memory
                branch = 1'b0;
                jump = 1'b0;
            end   
            // ALU I-type Instructions
            OPCODE_I_TYPE_ALU: begin
                imm_source = 3'b000; // I-Type immediate
                alu_source = 1'b1; // Use immediate value
                mem_write = 1'b0;
                alu_op = 2'b10; // ALU operation for math
                write_back_source = 2'b00; // Write back from ALU
                branch = 1'b0;
                jump = 1'b0;
                // Note from HolyCore: Shift instructions with constant require funct7 check for SRA
                // ie :     TODO: look if this works properly JAC
                // - 7 upper bits are interpreted as a "f7", ony valid for a restricted selection tested below
                // - 5 lower as shamt (because max shift is 32bits and 2^5 = 32).
                reg_write = 1'b1; // reg_write is set to 1 for ALU I-type instructions, but we need to check funct3 and funct7 for shift instructions
                if (func3 == F3_SLL) begin
                    reg_write = (func7 == F7_SLL_SRL);
                end
                else if (func3 == F3_SRL_SRA) begin
                    reg_write = (func7 == F7_SLL_SRL) || (func7 == F7_SRA);
                end
            end
            // S-Type Instructions
            OPCODE_S_TYPE: begin
                reg_write = 1'b0;
                mem_write = 1'b1;
                alu_op = 2'b00; // ALU operation for load/store
                alu_source = 1'b1; // Use immediate value
                imm_source = 3'b001; // S-Type immediate
                branch = 1'b0;
                jump = 1'b0;
            end
            // R-Type Instructions
            OPCODE_R_TYPE: begin
                reg_write = 1'b1;
                mem_write = 1'b0;
                alu_op = 2'b10; // ALU operation for math
                alu_source = 1'b0; // Use register value
                write_back_source = 2'b00; // Write back from ALU
                branch = 1'b0;
                jump = 1'b0;
            end
            // B-Type Instructions
            OPCODE_B_TYPE: begin
                reg_write = 1'b0;
                mem_write = 1'b0;
                alu_op = 2'b01; // ALU operation for branches
                alu_source = 1'b0; // Use register value
                branch = 1'b1;
                jump = 1'b0;
                second_add_source = 2'b00; // Use immediate value for branch target
            end
            // J-Type Instructions +JALR
            OPCODE_J_TYPE, OPCODE_J_TYPE_JALR: begin
                reg_write = 1'b1;
                mem_write = 1'b0;
                imm_source = (op == OPCODE_J_TYPE) ? 3'b011 : 3'b000; // J-Type immediate for JAL, I-Type immediate for JALR
                second_add_source = (op == OPCODE_J_TYPE) ? 2'b00 : 2'b10; // Use immediate value for JAL, use register value for JALR
            end
            // U-Type Instructions
            OPCODE_U_TYPE_LUI, OPCODE_U_TYPE_AUIPC: begin
                reg_write = 1'b1;
                mem_write = 1'b0;
                imm_source = 3'b100; // U-Type immediate
                write_back_source = 2'b11; // Write back from ALU
                branch = 1'b0;
                jump = 1'b0;
                second_add_source = ( op == OPCODE_U_TYPE_LUI) ? 2'b01 : 2'b00; // Use immediate value for LUI, use PC for AUIPC
            end
            default: begin
                reg_write = 1'b0;
                mem_write = 1'b0;
                jump = 1'b0;
                branch = 1'b0;

                $display("Unknown/Unsupported opcode: %b", op);
            end
        endcase
    end

    /**
    * ALU Control Logic
    */
    always_comb begin
        case (alu_op)
            // ALU operation for load/store
            ALU_OP_LOAD_STORE: begin
                alu_control = ALU_ADD; // ADD operation for address calculation
            end
            // ALU R-type and I-type operations
            ALU_OP_MATH: begin
                case (funct3)
                    F3_ADD_SUB: begin
                        alu_control = ALU_ADD; // ADD operation
                        if (op == OPCODE_R_TYPE && funct7 == F7_SUB) begin
                            alu_control = ALU_SUB; // SUB operation for R-type with funct7 = 0100000
                        end
                    end
                    //AND, OR, XOR, SLL, SRL, SRA, SLT, SLTU
                    F3_AND: begin
                        alu_control = ALU_AND; // AND operation
                    end
                    F3_OR: begin
                        alu_control = ALU_OR; // OR operation
                    end
                    F3_XOR: begin
                        alu_control = ALU_XOR; // XOR operation
                    end
                    F3_SRL_SRA: begin
                        if (funct7 == F7_SRA) begin
                            alu_control = ALU_SRA; // Shift Right Arithmetic
                        end else begin
                            alu_control = ALU_SRL; // Shift Right Logical
                        end
                    end 
                    F3_SLL: begin
                        alu_control = ALU_SLL; // Shift Left Logical
                    end
                    F3_SLT: begin
                        alu_control = ALU_SLT; // Set Less Than
                    end
                    F3_SLTU: begin
                        alu_control = ALU_SLTU; // Set Less Than Unsigned   
                    end
                endcase
            end
            // ALU operation for branches
            ALU_OP_BRANCHES: begin
                case (funct3)
                    F3_BEQ, F3_BNE: alu_control = ALU_SUB; // SUB operation for BEQ and BNE
                    F3_BLT, F3_BGE: alu_control = ALU_SLT; // SLT operation for BLT and BGE 
                    F3_BLTU, F3_BGEU: alu_control = ALU_SLTU; // SLTU operation for BLTU and BGEU
                    default : alu_control = 4'b1111; // Default to do nothing in ALU                endcase
                endcase
            end
            default : alu_control = 4'b1111; // Default to do nothing in ALU 
        endcase
    end

    /**
    * PC Source Logic
    */

    logic assert_branch; 
    
    always_comb begin : branch_logic_decode
        assert_branch = 1'b0;
        if (branch) begin
            case (funct3)
                F3_BEQ: assert_branch = alu_zero; // Branch if equal
                F3_BNE: assert_branch = ~alu_zero; // Branch if not equal
                F3_BLT: assert_branch = alu_last_bit; // Branch if less than (signed)
                F3_BGE: assert_branch = ~alu_last_bit; // Branch if greater than or equal (signed)
                F3_BLTU: assert_branch = alu_last_bit; // Branch if less than (unsigned)
                F3_BGEU: assert_branch = ~alu_last_bit; // Branch if greater than or equal (unsigned)
            endcase
        end
    end

    assign pc_source = jump | assert_branch; // PC source is determined by jump or branch conditions


endmodule
