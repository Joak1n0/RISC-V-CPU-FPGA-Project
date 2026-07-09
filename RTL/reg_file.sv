module reg_file (
	input logic	   clk,
   input logic      rst_n,
	
   input logic [4:0]	address1, 
   input logic [4:0] address2,
   output logic [31:0] read_data1,
   output logic [31:0] read_data2,

   input logic    write_enable,
   input logic [31:0] write_data,
   input logic [4:0] address3


);
   reg [31:0] registers [0:31];

   // Synchronous reset and write (x0 is hardwired to 0)
   always_ff @(posedge clk) begin
      if (!rst_n) begin
         for (int i = 0; i < 32; i++) begin
            registers[i] <= 32'b0;
         end
      end else begin
         if (write_enable && address3 != 0) begin
            registers[address3] <= write_data;
         end
      end
   end

   // Combinational read ports (reads return 0 for address 0)
   always_comb begin
      if (address1 == 5'd0)
         read_data1 = 32'b0;
      else
         read_data1 = registers[address1];

      if (address2 == 5'd0)
         read_data2 = 32'b0;
      else
         read_data2 = registers[address2];
   end

endmodule
