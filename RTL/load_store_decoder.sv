module load_store_decoder (
    input logic [2:0] funct3,
    input logic [31:0] alu_result_address,
    input logic [31:0] reg_read_data,

    output logic [3:0] mem_byte_enable,
    output logic [31:0] data
);

import pkg_riscvi32::*;

logic [1:0] address_offset;

assign address_offset = alu_result_address[1:0];

always_comb begin
    case(funct3)
        F3_BYTE, F3_BYTE_U: begin
            case(address_offset)
                2'b00: begin
                    mem_byte_enable = 4'b0001; // Enable only the lowest byte
                    data = (reg_read_data & 32'h000000FF); // Use only the lowest byte of the register value
                end
                2'b01: begin
                    mem_byte_enable = 4'b0010; // Enable only the second byte
                    data = (reg_read_data & 32'h0000FF00) >> 8; // Use only the second byte of the register value
                end
                2'b10: begin
                    mem_byte_enable = 4'b0100; // Enable only the third byte
                    data = (reg_read_data & 32'h00FF0000) >> 16; // Use only the third byte of the register value
                end
                2'b11: begin
                    mem_byte_enable = 4'b1000; // Enable only the highest byte
                    data = (reg_read_data & 32'hFF000000) >> 24; // Use only the highest byte of the register value
                end
                default: begin
                    mem_byte_enable = 4'b0000; // Default case (should not occur)
                    data = 32'b0; // Default case (should not occur)
                end
            endcase
        end
        F3_BYTE_U: begin
            case(address_offset)
                2'b00: begin
                    mem_byte_enable = 4'b0001; // Enable only the lowest byte
                    data = {24'b0, reg_read_data[7:0]}; // Zero-extend the lowest byte for unsigned byte access
                end
                2'b01: begin
                    mem_byte_enable = 4'b0010; // Enable only the second byte
                    data = {24'b0, reg_read_data[15:8]}; // Zero-extend the second byte for unsigned byte access
                end
                2'b10: begin
                    mem_byte_enable = 4'b0100; // Enable only the third byte
                    data = {24'b0, reg_read_data[23:16]}; // Zero-extend the third byte for unsigned byte access
                end
                2'b11: begin
                    mem_byte_enable = 4'b1000; // Enable only the highest byte
                    data = {24'b0, reg_read_data[31:24]}; // Zero-extend the highest byte for unsigned byte access
                end
                default: begin
                    mem_byte_enable = 4'b0000; // Default case (should not occur)
                    data = 32'b0; // Default case (should not occur)
                end
            endcase
        end
        F3_WORD: begin
            mem_byte_enable = (address_offset == 2'b00) ? 4'b1111 : 4'b0000; // Enable all bytes for word access
            data = reg_read_data; // Use the entire register value for word access
        end
        F3_HALFWORD, F3_HALFWORD_U: begin
            case (address_offset)
                2'b00: begin
                    mem_byte_enable = 4'b0011; // Enable lower halfword
                    data = (reg_read_data & 32'h0000FFFF); // Use only the lower halfword of the register value
                end
                2'b10: begin
                    mem_byte_enable = 4'b1100; // Enable upper halfword
                    data = (reg_read_data & 32'hFFFF0000) >> 16; // Use only the upper halfword of the register value
                end
                default: begin
                    mem_byte_enable = 4'b0000; // Default case (should not occur)
                    data = 32'b0; // Default case (should not occur)
                end
            endcase
        end
       
        
        default: begin
            mem_byte_enable = 4'b0000; // Default case (should not occur)
            data = 32'b0; // Default case (should not occur)
        end
    endcase
end

endmodule // load_store_decoder