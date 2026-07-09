module instr_mem (
    input  logic [31:0] address,
    output logic [31:0] instr
);

    reg [31:0] mem [0:255];

    initial begin
        $readmemh("SOFTWARE/main.hex", mem);
    end

    assign instr = mem[address[31:2]];

endmodule
