module reg_file (
		 input wire	   clk,
		 input wire	   we,  // write enable
		 input wire [4:0]  rs1, // read register 1
	         input wire [4:0]  rs2, // read register 2
		 input wire [4:0]  rd,  // destination register
		 input wire [31:0] wd,  // write data
		 
		 output reg [31:0] rd1, // read data 1
		 output reg [31:0] rd2  // read data 2
		 );
   // define 32 registers of 32 bits
   reg [31:0] regs [0:31];

   //READ Operation
   assign rd1 = (rs1 == 5'd0) ? 32'd0 : regs[rs1];
   assign rd2 = (rs2 == 5'd0) ? 32'd0 : regs[rs2];
   

   //WRITE Operation
   always @(posedge clk) begin
      if (we && (rd != 5'd0)) begin
	regs[rd] <= wd;
      end
   end

endmodule
