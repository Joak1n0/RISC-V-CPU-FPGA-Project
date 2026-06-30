module tb_cpu (
    input wire clk,
    input wire rst
);

    reg [31:0] instr;
    wire [31:0] pc;

    cpu_top cpu (
        .clk(clk),
        .rst(rst),
        .instr(instr),
        .pc(pc)
    );

    initial begin
        // Initialize the instruction memory with some test instructions
        instr = 32'h00000000; // NOP instruction (for example)
        #10;
        instr = 32'h00000001; // Some other instruction
        #10;
        instr = 32'h00000002; // Another instruction
        #10;
        $finish;
    end
endmodule
