module tb_cpu;

    reg clk = 0;
    reg reset = 1;

    cpu_top dut (
        .clk(clk),
        .reset(reset)
    );

    always #5 clk = ~clk;

    initial begin
        $dumpfile("waveform.vcd");
        $dumpvars(0, tb_cpu);

        #20;
        reset = 0;

        #500;
        $finish;
    end

endmodule
