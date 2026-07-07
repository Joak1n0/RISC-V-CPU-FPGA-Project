module alu (
	input logic [3:0] alu_control,
	input logic [31:0] a,
	input logic [31:0] b,
	
	output logic [31:0] result,
	output logic zero,
	output logic last_bit 
);

import pkg_riscvi32::*;

wire [4:0] shamt;
assign shamt = b[4:0]; // shift amount is the lower 5 bits

always_comb begin
	case (alu_control)
		ALU_ADD: result = a + b; // addition
		ALU_SUB: result = a - b; //or result = a + (~b + 1); two's complement subtraction
		ALU_AND: result = a & b; // bitwise AND
		ALU_OR:  result = a | b; // bitwise OR
		ALU_SLL: result = a << shamt; // logical left shift
		ALU_SLT: result = ($signed(a) < $signed(b)) ? 32'd1 : 32'd0; // signed less than comparison
		ALU_SRL: result = a >> shamt; // logical right shift
		ALU_SLTU: result = (a < b) ? 32'd1 : 32'd0; // unsigned less than comparison
		ALU_XOR: result = a ^ b; // bitwise XOR
		ALU_SRA: result = $signed(a) >>> shamt; // arithmetic right shift
		default: result = 32'd0; // default case
	endcase
end

assign zero = (result == 32'd0); // set zero flag if result is zero
assign last_bit = result[31]; // set last_bit flag to the most significant bit of the result
   
endmodule // alu
