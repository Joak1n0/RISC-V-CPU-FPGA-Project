module cpu_top (
    input wire clk,
    input wire rst,
    input wire [31:0] instr,
    output reg [31:0] pc
);

    wire [3:0] alu_op;
    wire [31:0] alu_result;
    wire [31:0] data_out;

    control_unit cu (
        .clk(clk),
        .rst(rst),
        .instr(instr),
        .alu_op(alu_op),
        .pc(pc)
    );

    alu alu (
        .clk(clk),
        .rst(rst),
        .a(32'h00000000), // Placeholder for register value
        .b(32'h00000000), // Placeholder for register value
        .op(alu_op),
        .result(alu_result)
    );

    data_mem dm (
        .clk(clk),
        .rst(rst),
        .addr(alu_result), // Address from ALU result
        .din(32'h00000000), // Placeholder for data to write
        .we(4'b0000), // Placeholder for write enable
        .dout(data_out)
    );
endmodule
