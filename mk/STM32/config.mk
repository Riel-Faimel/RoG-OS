CC = x86_64-elf-g++
AS = nasm
LD = x86_64-elf-ld
AR = x86_64-elf-ar

CFLAGSO = -nostdlib -ffreestanding -nodefaultlibs -DSTM32 -fno-builtin
CPPFLAGSO = $(CFLAGSO) -fno-exceptions -std=c++20 -fno-rtti 

CFLAGS = $(CFLAGSO) 
CPPFLAGS = $(CPPFLAGSO)

ClibFLAGS = $(CFLAGSO) -D__LIB_BUILD__
CPPlibFALGS = $(CPPFLAGS) -D__LIB_BUILD__

ASFLAGS = -f bin
LDFLAGS = -nostdlib -r -L$(BUILD_DIR) #-T -T $(ROOT_DIR)/mk/STM32/sec.ld
ARFLAGS = rcs

export CC AS LD AR CPPFLAGS CFLAGS ClibFLAGS CPPlibFALGS ASFLAGS LDFLAGS ARFLAGS 
