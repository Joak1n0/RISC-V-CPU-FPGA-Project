module data_mem (
    input wire clk,
    input wire rst,
    input wire [31:0] addr,
    input wire [31:0] din,
    input wire [3:0] we,
    output reg [31:0] dout
);

    reg [31:0] mem [0:255]; // 256-word data memory

    always @(posedge clk) begin
        if (rst) begin
            for (int i = 0; i < 256; i = i + 1) begin
                mem[i] <= 0;
            end
        end else begin
            if (we[0]) mem[addr[9:2]][7:0]   <= din[7:0];
            if (we[1]) mem[addr[9:2]][15:8]  <= din[15:8];
            if (we[2]) mem[addr[9:2]][23:16] <= din[23:16];
            if (we[3]) mem[addr[9:2]][31:24] <= din[31:24];
            dout <= mem[addr[9:2]]; // Word-aligned access
        end
    end
endmodule // data_mem
