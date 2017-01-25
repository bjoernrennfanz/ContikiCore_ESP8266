# base directory of the ESP8266 Open SDK package, absolute
ESP8266_SDK_ROOT ?= /opt/esp-open-sdk

# base directory for the compiler
XTENSA_TOOLS_ROOT ?= $(ESP8266_SDK_ROOT)/xtensa-lx106-elf/bin

# select which tools to use as compiler, librarian and linker
AR  := $(XTENSA_TOOLS_ROOT)/xtensa-lx106-elf-ar
CC  := $(XTENSA_TOOLS_ROOT)/xtensa-lx106-elf-gcc
CXX := $(XTENSA_TOOLS_ROOT)/xtensa-lx106-elf-gcc
LD  := $(XTENSA_TOOLS_ROOT)/xtensa-lx106-elf-gcc

# compiler flags using during compilation of source files
CFLAGS = -I. -mlongcalls -DICACHE_FLASH -Os

# library name
LIB = libcontikicore

# list of source code files
SRC = lib/list.c \
	  sys/arg.c \
	  sys/autostart.c \
	  sys/ctimer.c \
	  sys/etimer.c \
	  sys/process.c \
	  sys/procinit.c \
	  sys/stimer.c \
	  sys/timer.c \
	  contiki-clock-esp8266.c \
	  contiki-core-esp8266.c

OBJ = $(SRC:.c=.o)

%.o: %.c
	@echo "CC	$<"
	@$(CC) -c $(CFLAGS) $< -o $@
    
$(LIB).a : $(OBJ)
	@echo "AR	$@"
	@$(AR) rcs $@ $^

all: $(LIB).a

clean:
	rm -rf $(OBJ) 
	rm -rf $(LIB).a