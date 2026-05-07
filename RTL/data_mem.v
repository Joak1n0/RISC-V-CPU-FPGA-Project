module data_mem (
    input wire clk,
    input wire rst,
    input wire [31:0] addr,
    input wire [31:0] din,
    input wire [3:0] we,
    output reg [31:0] dout
);

    reg [31:0] mem [0:255]; // 256-word memory

    always @(posedge clk) begin
        if (rst) begin
            for (int i = 0; i < 256; i = i + 1) begin
                mem[i] <= 0;
            end
        end else begin
            if (we != 0) begin
                mem[addr[7:2]] <= din;
            end
        end
    end

    always @(*) begin
        dout = mem[addr[7:2]];
    end

endmodule // data_mem
