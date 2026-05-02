module instr_mem (
		  input wire addr [31:0],
		  output wire instr [31:0]
		  );
   
   assign instr = mem[addr[31:2]];
   
	   
endmodule // instr_mem
