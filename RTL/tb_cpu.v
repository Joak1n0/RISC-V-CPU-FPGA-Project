module tb_cpu (
    parameter CLK_PERIOD = 10
);
    reg clk;
    reg rst;
    reg [31:0] instr;
    wire [3:0] alu_op;
    wire [31:0] pc;

    // Instantiate the control unit
    control_unit uut (
        .clk(clk),
        .rst(rst),
        .instr(instr),
        .alu_op(alu_op),
        .pc(pc)
    );

    // Clock generation
    initial begin
        clk = 0;
        forever #(CLK_PERIOD/2) clk = ~clk; // Toggle clock every half period
    end

    // Test sequence
    initial begin
        // Initialize inputs
        rst = 1; // Assert reset
        instr = 32'b000000_00000_00000_00000_00000_100000; // ADD instruction (R-type)
        
        #20; // Wait for some time
        
        rst = 0; // Deassert reset
        
        #20; // Wait for some time
        
        instr = 32'b000000_00000_00000_00000_00000_100010; // SUB instruction (R-type)
        
        #20; // Wait for some time
        
        instr = 32'b000000_00000_00000_00000_00000_100100; // AND instruction (R-type)
        
        #20; // Wait for some time
        
        instr = 32'b000000_00000_00000_00000_00000_100101; // OR instruction (R-type)
        
        #20; // Wait for some time
        
        instr = 32'b000000_00000_00000_00000_00000_100110; // XOR instruction (R-type)
        
        #20; // Wait for some time
        
        $finish; // End simulation
    end
endmodule