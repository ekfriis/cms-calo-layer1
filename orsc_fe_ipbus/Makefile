# oRSC front SPI test

HW=../orsc_fe_hw
BSP=../orsc_fe_bsp

INCLUDES=-I../common/buffer-types \
	 -I../common/spi-stream

include ../Makefile

# Make a single megalibrary of all user code.
SRCS=$(wildcard src/*.c) $(wildcard ../common/spi-stream/*.c) \
     $(wildcard ../common/buffer-types/*.c) 

orsc_fe_spi_echo_test.elf: $(SRCS)
	$(COMPILE) -o $@ $^

all: orsc_fe_spi_echo_test.elf \
  orsc_fe_spi_echo_test.elf.size \
  orsc_fe_spi_echo_test.elf.check
