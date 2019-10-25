# You may need to change this to match your JTAG adapter
XC3SPROG_OPTS := -c jtaghs2 -v

# You may need to change this to match ISE on your system
XILINX_DIR = /opt/Xilinx/14.7/ISE_DS/
XILINX_BIN = $(XILINX_DIR)/ISE/bin/lin64

ifeq ($(TOPDIR),)
TOPDIR := .
endif

XC3SPROG := xc3sprog
XC3SPROG_BIT_FILE := $(TOPDIR)/fpga/xc3sprog/pano_g1.bit
BIN2MIF := $(TOPDIR)/tools/bin2mif/bin2mif
BIN2C := $(TOPDIR)/tools/bin2c/bin2c
BIT_FILE := $(TOPDIR)/xilinx/work/pano_top
FW_BIN := $(TOPDIR)/fw/hello_world/hello.bin
MCS_FILE := $(TOPDIR)/xilinx/pano_hello_g1.mcs
CREATE_MIF := $(TOPDIR)/tools/create_mif.rb
TOOLCHAIN_PREFIX = riscv32-unknown-elf-

prog_msc:  $(MCS_FILE)
	$(XC3SPROG) $(XC3SPROG_OPTS) -I$(XC3SPROG_BIT_FILE) $(MCS_FILE):W:0:MCS
	$(XC3SPROG) $(XC3SPROG_OPTS) $(BIT_FILE).bit

prog_all: $(FW_BIN) $(BIT_FILE).bit
	$(XC3SPROG) $(XC3SPROG_OPTS) -I$(XC3SPROG_BIT_FILE) $(BIT_FILE):W:0:BIT
	$(XC3SPROG) $(XC3SPROG_OPTS) -I$(XC3SPROG_BIT_FILE) $(FW_BIN):W:786432:BIN
	$(XC3SPROG) $(XC3SPROG_OPTS) $(BIT_FILE).bit

prog_fpga: $(BIT_FILE).bit
	$(XC3SPROG) $(XC3SPROG_OPTS) -I$(XC3SPROG_BIT_FILE) $(BIT_FILE):W:0:BIT
	$(XC3SPROG) $(XC3SPROG_OPTS) $(BIT_FILE).bit

reload:
	$(XC3SPROG) $(XC3SPROG_OPTS) $(BIT_FILE).bit

#override CFLAGS for native compiles
$(BIN2C) $(BIN2MIF) : CFLAGS =

$(BIN2MIF): $(BIN2MIF).cpp

$(BIN2C) : $(BIN2C).c 

.PHONY: prog_msc prog_all prog_fpga reload

