# Makefile for simulation of CPU using Verilator

RTL_PATH = ../RTL
PKG_PATH = ../PACKAGE

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

SIM_SRCS = \
	sim_cpu_main.cpp

all: $(TARGET)

$(TARGET): $(PKG_SRCS) $(RTL_SRCS) $(SIM_SRCS)
	verilator $(VERILATOR_FLAGS) -o $(TARGET) $(PKG_SRCS) $(RTL_SRCS) $(SIM_SRCS)

run: $(TARGET)
	./obj_dir/$(TARGET)

clean:
	rm -rf obj_dir

.PHONY: all run clean
