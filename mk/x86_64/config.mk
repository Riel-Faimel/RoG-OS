CC = x86_64-elf-g++
AS = nasm
LD = x86_64-elf-g++
AR = x86_64-elf-ar

CFLAGSO = -nostdlib -ffreestanding -nodefaultlibs -Dx86_64 -fno-builtin -I "$(SRC_DIR)" -H
CPPFLAGSO = $(CFLAGSO) -fno-exceptions -std=c++20 -fno-rtti -fno-use-cxa-atexit -fno-threadsafe-statics

CFLAGS = $(CFLAGSO) 
CPPFLAGS = $(CPPFLAGSO)

ClibFLAGS = $(CFLAGSO) -D__LIB_BUILD__
CPPlibFALGS = $(CPPFLAGS) -D__LIB_BUILD__

ASFLAGS = -f ELF64
LDFLAGS = -nostdlib -r -L$(BUILD_DIR) #-T $(ROOT_DIR)/mk/x86_64/sec.ld
ARFLAGS = rcs

export CC AS LD AR CPPFLAGS CFLAGS ClibFLAGS CPPlibFALGS ASFLAGS LDFLAGS ARFLAGS 