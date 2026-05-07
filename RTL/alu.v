module alu (
		input wire clk,
		input wire rst,
		input wire [31:0] a,
		input wire [31:0] b,
		input wire [3:0] op,
		output reg [31:0] result
		);

   always @(posedge clk) begin
      if (rst)
	  	result <= 0;
      else
		case (op)
			4'b0000:	result <= a + b; // ADD
			4'b0001:	result <= a - b; // SUB
			4'b0010:	result <= a & b; // AND
			4'b0011:	result <= a | b; // OR
			4'b0100:	result <= a ^ b; // XOR
			default:	result <= 0;
		endcase
   end
endmodule // alu
