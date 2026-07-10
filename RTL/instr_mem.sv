module instr_mem (
    input  logic [31:0] address,
    output logic [31:0] instr
);

    reg [31:0] mem [0:255];

    initial begin
        $readmemh("SOFTWARE/main.hex", mem);
    end

    /* verilator lint_off WIDTHTRUNC */
    assign instr = mem[address[31:2]];
    /* verilator lint_on WIDTHTRUNC */

endmodule
