CC = riscv64-unknown-elf-gcc
OBJDUMP = riscv64-unknown-elf-objdump
OBJCOPY = riscv64-unknown-elf-objcopy

CFLAGS = -march=rv32i -mabi=ilp32 -nostdlib -nostartfiles -O0

TOP_MODULE = tb_cpu

VERILATOR_FLAGS = \
	--binary\
	-Wall \
	-Wno-UNUSEDSIGNAL \
	--cc \
	--exe \
	--build \
	--unroll-count 256 \
	--trace \
	--top-module $(TOP_MODULE)

RTL_PATH = ../RTL
PKG_PATH = ../PACKAGE
TB_PATH= ../TESTBENCH

PKG_SRCS = $(PKG_PATH)/pkg_riscvi32.sv

RTL_SRCS = \
	$(RTL_PATH)/instr_mem.sv \
	$(RTL_PATH)/reg_file.sv \
	$(RTL_PATH)/sign_extension.sv \
	$(RTL_PATH)/load_store_decoder.sv \
	$(RTL_PATH)/data_reader.sv \
	$(RTL_PATH)/alu.sv \
	$(RTL_PATH)/control_unit.sv \
	$(RTL_PATH)/data_mem.sv \
	$(RTL_PATH)/cpu_top.sv

TB_SRCS = $(TB_PATH)/tb_cpu.sv


all: main.elf main.dump main.bin

main.elf: crt0.S main.c link.ld
	$(CC) $(CFLAGS) -T link.ld crt0.S main.c -o main.elf

main.dump: main.elf
	$(OBJDUMP) -d -M no-aliases main.elf > main.dump

main.bin: main.elf
	$(OBJCOPY) -O binary main.elf main.bin

hex: main.bin
	xxd -p -c 4 main.bin

hex_gen:
	riscv64-unknown-elf-objcopy -O verilog main.elf main.hex

sim:
	verilator $(VERILATOR_FLAGS) $(PKG_SRCS) $(RTL_SRCS) $(TB_SRCS) --top-module $(TOP_MODULE)


clean:
	rm -f main.elf main.dump main.bin
