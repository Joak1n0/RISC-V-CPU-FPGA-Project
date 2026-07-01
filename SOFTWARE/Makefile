CC = riscv64-unknown-elf-gcc
OBJDUMP = riscv64-unknown-elf-objdump
OBJCOPY = riscv64-unknown-elf-objcopy

CFLAGS = -march=rv32i -mabi=ilp32 -nostdlib -nostartfiles -O0

all: main.elf main.dump main.bin

main.elf: crt0.S main.c link.ld
	$(CC) $(CFLAGS) -T link.ld crt0.S main.c -o main.elf

main.dump: main.elf
	$(OBJDUMP) -d -M no-aliases main.elf > main.dump

main.bin: main.elf
	$(OBJCOPY) -O binary main.elf main.bin

hex: main.bin
	xxd -p -c 4 main.bin

clean:
	rm -f main.elf main.dump main.bin
