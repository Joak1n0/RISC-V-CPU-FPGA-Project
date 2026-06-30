#include "Vcpu_top.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);

    Vcpu_top* top = new Vcpu_top;

    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    tfp->open("simx.vcd");

    vluint64_t sim_time = 0;
    const vluint64_t CLK_PERIOD = 10;
    const vluint64_t HALF_PERIOD = CLK_PERIOD / 2;

    top->clk = 0;
    top->rst = 1;

    // Use C++ binary literals, not Verilog 32'b syntax
    top->instr = 0b00000000000000000000000000100000; // ADD

    while (!Verilated::gotFinish() && sim_time < 140) {
        if (sim_time == 20) {
            top->rst = 0;
        } else if (sim_time == 40) {
            top->instr = 0b00000000000000000000000000100010; // SUB
        } else if (sim_time == 60) {
            top->instr = 0b00000000000000000000000000100100; // AND
        } else if (sim_time == 80) {
            top->instr = 0b00000000000000000000000000100101; // OR
        } else if (sim_time == 100) {
            top->instr = 0b00000000000000000000000000100110; // XOR
        }

        top->clk = !top->clk;

        top->eval();
        tfp->dump(sim_time);

        sim_time += HALF_PERIOD;
    }

    tfp->close();

    delete tfp;
    delete top;

    return 0;
}