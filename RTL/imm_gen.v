module imm_gen (
		input wire clk,
		input wire [31:0] instr,
		output reg [31:0] imm
		);
   always @* begin
      case (instr [6:0])
	7'b0010011: begin // I-type
	   case (instr[14:12])
	     3'b001, 3'b101: imm = $signed(instr[24:20]);
	     default: imm = $signed(instr[31:20]);
	   endcase // case (instr[14:12])
	end
	7'b0000011: begin // I-type Load
		imm = {{20{instr[31]}},instr[31:20]}; 
	end
	7'b0100011: begin // S-type
	   imm = $signed({instr[31:25],instr[11:7]});
	end
	7'b1100011: begin // B-type
	   imm = {instr[31:25],instr[11:7]};
	end
	7'b0110111: begin // U-type
	   imm = instr[31:12];
	end
	7'b1101111: begin // J-type --JAC:TO CORRECT
	   imm = {{12{instr[31]}}, instr[19:12], instr[20], instr[30:21], 1'b0};
	end
	default: // unknown instruction
        imm = 0;
       endcase // case (instr [6:0])
     end // always @ *
	 
  endmodule // imm_gen
