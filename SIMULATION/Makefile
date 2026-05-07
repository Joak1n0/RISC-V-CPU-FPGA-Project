#Makefile for simulation of CPU using Verilator.

#PATH to RTL source files
RTL_PATH = ../RTL

#Verilator flags
VERILATOR_FLAGS = -Wall --cc --exe --build --unroll-count 256
#Source files for the simulation
RTL_SRCS = \
$(RTL_PATH)/p_count.v\
$(RTL_PATH)/instr_mem.v\
$(RTL_PATH)/reg_file.v\
$(RTL_PATH)/imm_gen.v\
$(RTL_PATH)/alu.v\
$(RTL_PATH)/control_unit.v\
$(RTL_PATH)/data_mem.v\
$(RTL_PATH)/cpu_top.v

#Source files for the testbench
SIM_SRCS = \
sim_cpu_main.cpp\
Vcpu.cpp

#Name of the executable
TARGET = sim_cpu
#Default target
all: $(TARGET)
#Rule to build the executable using Verilator
$(TARGET): $(SRCS)
	verilator $(VERILATOR_FLAGS) -o $(TARGET) $(SIM_SRCS) $(RTL_SRCS)
#Clean up generated files
clean:
	rm -rf obj_dir $(TARGET)
.PHONY: all clean
