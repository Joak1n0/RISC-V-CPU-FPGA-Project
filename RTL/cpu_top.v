module cpu_top (
    input wire clk,
    input wire rst_n
);

    \*
     * Program Counter
     *\

    reg [31:0] pc;
    wire [31:0] pc_next;
    wire [31:0] pc_plus_second_add;
    wire pc_source;

    wire [1:0] second_add_source;
    
    case (pc_source)
            1'b0 : pc_next =  pc + 4;
            1'b1 : pc_next = pc_plus_second_add;
    endcase
    
    case (second_add_source)
            2'b00 : pc_plus_second_add =  pc + 4;
            2'b01 : pc_plus_second_add = imm;
            2'b10 : pc_plus_second_add = read_reg1 + imm;
            default : pc_plus_second_add = 32'd0;
    endcase

    always @(posedge clk) begin
      if (rst)	
	  	pc <= 32'b0;
      else
		pc <= pc_next;
    end

    \*
     * Instruction Memory
     *\

    // Isntruction Memory is a read-only memory that stores the program instructions. 
    //It is accessed using the program counter (PC) to fetch the current instruction to be executed.
    wire [31:0] instr;

    instr_mem im (
        .address(pc), // Address from Program Counter
        
        .dout(instr)
    );


    \*
     * Control Unit
     *\

    wire [3:0] alu_op;
    wire [31:0] alu_result;
    wire [31:0] data_out;

    control_unit cu (
        .clk(clk),
        .rst(rst),
        .instr(instr),
        .alu_op(alu_op),
        .pc(pc)
    );

    \*
     * Register File
     *\

    reg_file rf (
        .clk(clk),
        .rst(rst),
        .rs1(instr[25:21]), // Source register 1
        .rs2(instr[20:16]), // Source register 2
        .rd(instr[15:11]),  // Destination register
        .we(4'b0000),       // Placeholder for write enable
        .din(data_out),     // Data to write (from data memory)
        .dout_a(),          // Output for source register 1
        .dout_b()           // Output for source register 2
    );

    \*
     * Arithmetic Logic Unit
     *\

    alu alu (
        .clk(clk),
        .rst(rst),
        .a(32'h00000000), // Placeholder for register value
        .b(32'h00000000), // Placeholder for register value
        .op(alu_op),
        .result(alu_result)
    );

    \*
     * Data Memory
     *\

    data_mem dm (
        .clk(clk),
        .rst(rst),
        .addr(alu_result), // Address from ALU result
        .din(32'h00000000), // Placeholder for data to write
        .we(4'b0000), // Placeholder for write enable
        .dout(data_out)
    );
endmodule
