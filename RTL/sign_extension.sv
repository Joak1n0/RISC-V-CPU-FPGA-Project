module sign_extension (
    input logic [24:0] source,
    input logic [2:0] imm_source,
    output logic [31:0] immediate
);

always_comb begin : sign_extension_logic
    case (imm_source)
        3'b000: immediate = {{20{source[24]}}, source[24:13]}; // I-Type
        3'b001: immediate = {{20{source[24]}}, source[24:18], source[4:0]}; // S-Type
        3'b010: immediate = {{20{source[24]}}, source[0], source[23:18], source[4:1], 1'b0}; // B-Type
        3'b011: immediate = {{12{source[24]}}, source[12:5], source[13], source[23:14], 1'b0}; // J-Type
        3'b100: immediate = {{{source[24:5]}},12'b0}; // U-Type
        default: immediate = 32'b0; // Default case (should not occur)
    endcase
end

endmodule // sign_extension
