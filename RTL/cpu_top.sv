module cpu_top (
    input wire clk,
    input wire rst_n
);

/**
* Program Counter
*/

    reg [31:0] pc;
    logic [31:0] pc_next;
    logic [31:0] pc_plus_second_add;
    logic pc_source;

    wire [1:0] second_add_source;

    always_comb begin : pc_selector
        case (pc_source)
            1'b0 : pc_next =  pc + 4;
            1'b1 : pc_next = pc_plus_second_add;
        endcase
    end
    
    always_comb begin : second_add_source_selector
        case (second_add_source)
            2'b00 : pc_plus_second_add =  pc + immediate;
            2'b01 : pc_plus_second_add = immediate;
            2'b10 : pc_plus_second_add = read_reg1 + immediate;
            default : pc_plus_second_add = 32'd0;
        endcase    
    end
    

    always_ff @(posedge clk) begin
        if (rst_n==1'b0) begin 	
	  	    pc <= 32'b0;
        end else begin
	        pc <= pc_next;
        end  
    end       

    /*
     * Instruction Memory
     */

    // Isntruction Memory is a read-only memory that stores the program instructions. 
    //It is accessed using the program counter (PC) to fetch the current instruction to be executed.
    wire [31:0] instr;

    instr_mem im (
        .address(pc), // Address from Program Counter
        
        .dout(instr)
    );


    /*
     * Control Unit
     */
    logic [6:0] op;
    assign op = instr[6:0]; // opcode
    logic [2:0] funct3;
    assign funct3 = instr[14:12]; // funct3
    logic [6:0] funct7;
    assign funct7 = instr[31:25]; // funct7
    wire alu_zero;
    wire alu_last_bit;

    //out of control unit
    wire [3:0] alu_control;
    wire [2:0] imm_source;
    wire mem_write;
    wire reg_write;

    //out mux
    wire alu_source;
    wire [1:0] write_back_source;
    wire pc_source;
    wire [1:0] second_add_source;


    control_unit cu (
        .op(op),
        .funct3(funct3),
        .funct7(funct7),
        .alu_zero(alu_zero),
        .alu_last_bit(alu_last_bit),

        //OUT 
        .alu_control(alu_control),
        .imm_source(imm_source),
        .mem_write(mem_write),
        .reg_write(reg_write),

        // Mux out
        .alu_source(alu_source),
        .write_back_source(write_back_source),
        .pc_source(pc_source),
        .second_add_source(second_add_source)
    );

    /**
     * Register File
     */

    logic [4:0] reg_source1;
    assign reg_source1 = instr[19:15]; // Source register 1
    logic [4:0] reg_source2;
    assign reg_source2 = instr[24:20]; // Source register 2

    logic [4:0] reg_dest;
    assign reg_dest = instr[11:7]; // Destination register

    wire [31:0] read_reg1;
    wire [31:0] read_reg2;
    logic wb_valid;

    logic [31:0] write_back_data;

    always_comb begin : write_back_data_selector
        case (write_back_source)
            2'b00 : begin 
                write_back_data = alu_result;
                wb_valid = 1'b1; // Enable write-back for ALU result
            end
            2'b01 : begin 
                write_back_data = mem_read_write_back_data;
                wb_valid = mem_read_write_back_valid; // Enable write-back for memory read data
            end
            2'b10 : begin 
                write_back_data = pc + 4; // For JAL instruction
                wb_valid = 1'b1; // Enable write-back for PC + 4
            end
            2'b11 : begin
                write_back_data = pc_plus_second_add; // For JALR instruction
                wb_valid = 1'b1; // Enable write-back for PC + immediate
            end
        endcase
    end

    reg_file rf (
        .clk(clk),
        .rst_n(rst_n),

        .rs1(reg_source1), // Source register 1
        .rs2(reg_source2), // Source register 2

        .read_reg1(read_reg1), // Output for source register 1
        .read_reg2(read_reg2), // Output for source register 2

        .we(reg_write & wb_valid),       // Placeholder for write enable
        .write_data(write_back_data),     // Data to write (from data memory)
        .address3(reg_dest) // Destination register address
    );

    /**
     * Sign Extension
     */

     logic [24:0] brute_immediate;
     assign brute_immediate = instr[31:7];
     wire [31:0] immediate;

    sign_ext seu(
        .brute_immediate(brute_immediate),
        .imm_source(imm_source),
        .immediate(immediate)
    );

    /**
     * Arithmetic Logic Unit
     */

    wire [31:0] alu_result;
    logic [31:0] alu_operand_b;

    always_comb begin :alu_source_select
        case (alu_source)
            1'b0 : alu_operand_b = read_reg2; // Use register value
            1'b1 : alu_operand_b = immediate; // Use immediate value
        endcase
    end

    alu alu (
        .alu_control(alu_control),
        .a(read_reg1), // Operand A from register file
        .b(alu_operand_b), // Operand B from mux (register or immediate)
        .result(alu_result),
        .zero(alu_zero),
        .last_bit(alu_last_bit)
    );

    /**
     * Load/Store Decoder
     */
    
    wire [3:0] mem_byte_enable;
    wire [31:0] mem_write_data;

    load_store_decoder lsd (
        .alu_result_address(alu_result),
        .reg_read_data(read_reg2),
        .funct3(funct3),
        .byte_enable(mem_byte_enable),
        .data(mem_write_data)
    );

    /**
     * Data Memory
     */
    wire [31:0] mem_read;

    data_mem dm (
        .clk(clk),
        .rst_n(rst_n),
        
        .address({alu_result[31:2], 2'b00}), // Address from ALU result
        .write_data(mem_write_data), // Data to write (from register file)
        .write_enable(mem_write), // Write enable signal from control unit
        .byte_enable(mem_byte_enable), // Byte enable signals from load/store decoder
        .read_data(mem_read) // Data read from memory
    );

    /**
     * Memory Read Write Back Selector
     */

    logic mem_read_write_back_valid;
    logic [31:0] mem_read_write_back_data;

    read_write_back_selector rwbs (
        .mem_read(mem_read),
        .be_mask(mem_byte_enable),
        .funct3(funct3),
        .write_back_data(mem_read_write_back_data),
        .valid(mem_read_write_back_valid)
    );
endmodule
