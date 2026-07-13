module tb_cpu;

    logic clk = 0;
    logic rst_n = 0;


    cpu_top dut (
        .clk(clk),
        .rst_n(rst_n)
    );

    always #5 clk <= ~clk; 

    initial begin
        $dumpfile("waveform.vcd");
        $dumpvars(0, tb_cpu);

        #20;
        rst_n = 1;

        #1000;
        $finish;
    end

endmodule
