# Makefile for simulation of CPU using Verilator

RTL_PATH = ../RTL

TOP_MODULE = cpu_top
TARGET = sim_cpu

VERILATOR_FLAGS = \
	-Wall \
	-Wno-UNUSEDSIGNAL \
	--cc \
	--exe \
	--build \
	--unroll-count 256 \
	--trace \
	--top-module $(TOP_MODULE)

RTL_SRCS = \
	$(RTL_PATH)/p_count.v \
	$(RTL_PATH)/instr_mem.v \
	$(RTL_PATH)/reg_file.v \
	$(RTL_PATH)/imm_gen.v \
	$(RTL_PATH)/alu.v \
	$(RTL_PATH)/control_unit.v \
	$(RTL_PATH)/data_mem.v \
	$(RTL_PATH)/cpu_top.v

SIM_SRCS = \
	sim_cpu_main.cpp

all: $(TARGET)

$(TARGET): $(RTL_SRCS) $(SIM_SRCS)
	verilator $(VERILATOR_FLAGS) -o $(TARGET) $(RTL_SRCS) $(SIM_SRCS)

run: $(TARGET)
	./obj_dir/$(TARGET)

clean:
	rm -rf obj_dir

.PHONY: all run clean
