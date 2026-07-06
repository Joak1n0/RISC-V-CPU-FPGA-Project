module tb_cpu;

    reg clk = 0;
    reg rst = 1;
    reg [31:0] instr;
    wire [31:0] pc;

    cpu_top dut (
        .clk(clk),
        .rst(rst),
        .instr(instr),
        .pc(pc)
    );

    always #5 clk = ~clk;

    initial begin
        $dumpfile("waveform.vcd");
        $dumpvars(0, tb_cpu);

        #20;
        rst = 0;

        #500;
        $finish;
    end

endmodule
