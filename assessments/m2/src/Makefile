#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM =HOST  
CFLAGS = -g  -Wall -std=c99 
LDFLAGS = -Wl,-Map=c1m2.map 
CPPFLAGS= -D$(PLATFORM)  $(INCLUDES)
OBJS = $(SOURCES:.c=.o) 
ifeq ($(PLATFORM),MSP432)
     LINKER_FILE =../msp432p401r.lds 
     CPU = cortex-m4 
     ARCH= armv7-m 
     SPECS=--specs=nosys.specs 
     CC = arm-none-eabi-gcc 
     CFLAGS += -mcpu=$(CPU)   -mthumb -mlittle-endian $(SPECS) 
     LDFLAGS += -T$(LINKER_FILE)
     LD = arm-none-eabi-ld
else 
    CC = gcc 
    SOURCES=main.c memory.c
endif 
%.i: %.c
	$(CC) -E $< -o $@ $(CPPFLAGS) $(CFLAGS) 
%.s: %.c
	$(CC) -S $< -o $@ $(CPPFLAGS) $(CFLAGS) 
%.o: %.c 
	$(CC) -c $< -o $@ $(CPPFLAGS) $(CFLAGS) 
.PHONY: compile-all 
compile-all:
	$(CC) -c $(SOURCES) $(CPPFLAGS) $(CFLAGS)  
.PHONY: build
build: $(OBJS)
	$(CC)   $(OBJS) -o c1m2.out $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) 
	size c1m2.out
.PHONY: clean
clean:
	rm -f *.s *.i *.o *.out *.map  
