module data_mem #(
    parameter WORDS = 256,
    parameter ADDRESS_BITS = $clog2(WORDS), // TODO : Verify that this is correct for the memory size
    parameter mem_init_file = "data_mem_init.hex"
) (
    input logic clk,
    input logic rst_n,
    input logic [ADDRESS_BITS-1:0] address,
    input logic [31:0] write_data,
    input logic write_enable,
    input logic [3:0] byte_enable,
    
    output logic [31:0] read_data
);


    reg [31:0] mem [0:WORDS-1]; // WORDS-word data memory

    initial begin
        if (mem_init_file != "") begin
            $readmemh(mem_init_file, mem);
        end     
    end

    always_ff @(posedge clk) begin : data_mem_write_read
        if (rst_n == 1'b0) begin
            for (int i = 0; i < WORDS; i = i + 1) begin
                mem[i] <= 0;
            end
        end else begin
            if (address[1:0] != 2'b00) begin
                $display("Warning: Unaligned memory access at address %h", address);
            end else begin
                for(int i = 0; i < 4; i = i + 1) begin
                    if (byte_enable[i] && write_enable) begin
                        mem[address[9:2]][i*8 +: 8] <= write_data[i*8 +: 8]; //TODO: Verify address slicing is correct for the memory size
                    end
                end
            end
            
        end
    end

    always_comb begin
        read_data = mem[address[9:2]]; // Word-aligned access
    end
endmodule // data_mem
