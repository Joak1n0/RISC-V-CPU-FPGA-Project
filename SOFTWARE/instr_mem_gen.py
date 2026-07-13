# File to translate little endian mem into mem file for CPU
from pathlib import Path

data = Path("main.bin").read_bytes()

if len(data) % 4:
    data += bytes(4 - len(data) % 4)

with Path("main.mem").open("w") as output:
    for offset in range(0, len(data), 4):
        word = int.from_bytes(data[offset:offset + 4], byteorder="little")
        output.write(f"{word:08x}\n")