module data_reader (
    input logic [31:0] mem_data,
    input logic [3:0] be_mask,
    input logic [2:0] func3,
    output logic [31:0] wb_data,
    output logic wb_valid
);

import pkg_riscvi32::*;

logic sign_extend;
assign sign_extend = ~func3[2]; // Sign extend for signed load instructions (LB, LH, LBU, LHU)

logic [31:0] masked_data; // Data after applying byte enable mask
logic [31:0] shifted_data; // Data after shifting based on address offset

always_comb begin : masked_data_logic
    for (int i = 0; i < 4; i++) begin
        if (be_mask[i]) begin
            masked_data[i*8 +: 8] = mem_data[i*8 +: 8];
        end else begin
            masked_data[i*8 +: 8] = 8'b0;
        end
    end
end

always_comb begin : shifted_data_logic
    case (func3)
        F3_WORD: begin
            shifted_data = masked_data; // No shift for word access
        end
        F3_BYTE, F3_BYTE_U: begin
            case (be_mask)
                4'b0001: shifted_data = {24'b0, masked_data[7:0]}; // Byte 0
                4'b0010: shifted_data = {24'b0, masked_data[15:8]}; // Byte 1
                4'b0100: shifted_data = {24'b0, masked_data[23:16]}; // Byte 2
                4'b1000: shifted_data = {24'b0, masked_data[31:24]}; // Byte 3
                default: shifted_data = 32'b0; // Invalid case
            endcase
        end

        F3_HALFWORD, F3_HALFWORD_U: begin
            case (be_mask)
                4'b0011: shifted_data = {16'b0, masked_data[15:0]}; // Halfword 0
                4'b1100: shifted_data = {16'b0, masked_data[31:16]}; // Halfword 1
                default: shifted_data = 32'b0; // Invalid case
            endcase
        end

        default: begin
            shifted_data = 32'b0; // Default case (should not occur)
        end
        
    endcase
end

always_comb begin : sign_extend_logic
    case (func3)
        F3_WORD: begin // LW
            wb_data = shifted_data; // No sign extension for word loads
        end
        F3_BYTE, F3_BYTE_U: begin // LB, LBU
            wb_data = sign_extend ? {{24{shifted_data[7]}}, shifted_data[7:0]} : {24'b0, shifted_data[7:0]}; // Sign extend for signed byte load, zero extend for unsigned
        end
        F3_HALFWORD, F3_HALFWORD_U: begin // LH, LHU
            wb_data = sign_extend ? {{16{shifted_data[15]}}, shifted_data[15:0]} : {16'b0, shifted_data[15:0]}; // Sign extend for signed halfword load, zero extend for unsigned
        end
        default: begin
            wb_data = 32'b0; // Default case (should not occur)
        end
    endcase

    wb_valid = |be_mask; // Valid if any byte is enabled
    
end

endmodule // data_reader
