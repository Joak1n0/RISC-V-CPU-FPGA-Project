module instr_mem (
	input wire clk,
	input wire rst,
	input wire [31:0] addr,
	output reg [31:0] instr
);

	reg [31:0] mem [0:255]; // 256-word instruction memory

	always @(posedge clk) begin
		if (rst) begin
			for (int i = 0; i < 256; i = i + 1) begin
				mem[i] <= 0;
			end
		end else begin
			instr <= mem[addr[7:2]]; // Word-aligned access
		end
	end
endmodule // instr_mem
