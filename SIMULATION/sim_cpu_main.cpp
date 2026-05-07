#include "Vcpu.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Vcpu* top = new Vcpu;

    VerilatedVcdC* tfp = new VerilatedVcdC;
    Verilated::traceEverOn(tfp);
    top->trace(tfp, 99);
    tfp->open("simx.vcd");

    vluint64_t sim_time = 0;
    const vluint64_t CLK_PERIOD = 10;
    const vluint64_t HALF_PERIOD = CLK_PERIOD / 2;

    // Initialize
    top->clk = 0;
    top->rst = 1;
    top->instr = 32'b000000_00000_00000_00000_00000_100000; // ADD

    while (!Verilated::gotFinish() && sim_time < 140) {  // Run until finish or time limit
        // Set inputs based on simulation time
        if (sim_time == 20) {
            top->rst = 0;  // Deassert reset
        } else if (sim_time == 40) {
            top->instr = 32'b000000_00000_00000_00000_00000_100010; // SUB
        } else if (sim_time == 60) {
            top->instr = 32'b000000_00000_00000_00000_00000_100100; // AND
        } else if (sim_time == 80) {
            top->instr = 32'b000000_00000_00000_00000_00000_100101; // OR
        } else if (sim_time == 100) {
            top->instr = 32'b000000_00000_00000_00000_00000_100110; // XOR
        } else if (sim_time == 120) {
            // End simulation (equivalent to $finish)
            break;
        }

        // Toggle clock
        top->clk = !top->clk;

        // Evaluate the model
        top->eval();

        // Dump waveform
        tfp->dump(sim_time);

        // Advance time
        sim_time += HALF_PERIOD;
    }

    tfp->close();
    delete top;
    delete tfp;
    return 0;
}