module imm_gen (
		input wire clk,
		input wire instr [31:0],
		output wire imm [31:0]
		);
   always @* begin
      case (instr [6:0])
	7'b0010011: begin // I-type
	   case (instr[14:12])
	     3'b001, 3'b101: imm <= $signed(instr[24:20]);
	     default: imm_out <= $signed(instr[31:20]);
	   endcase // case (instr[14:12])
	end
	7'b0000011: begin // I-type Load
		imm_out <= instr[31:20];
	end
	7'b0100011: begin // S-type
	   imm_out <= $signed({instr[31:25],instr[11:7]});
	end
	7'b1100011: begin // B-type
	   imm_out <= {instr[31:25],instr[11:7]};
	end
	7'b0110111: begin // U-type
	   imm_out <= instr[31:12];
	end
	7'b1101111: begin // J-type --JAC:TO CORRECT
	   imm_out <= {{12{instruction[31]}}, instruction[19:12], instruction[20], instruction[30:21], 1'b0};
	end
       endcase // case (instr [6:0])
     end // always @ *
  endmodule // imm_gen
		       
	       
	
				
     
