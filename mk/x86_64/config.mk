CC = g++
AS = nasm
LD = ld
AR = ar

CFLAGSO = -nostdlib -ffreestanding -nodefaultlibs -Dx86_64 -fno-builtin
CPPFLAGSO = $(CFLAGSO) -fno-exceptions -std=c++20 -fno-rtti 

CFLAGS = $(CFLAGSO) 
CPPFLAGS = $(CPPFLAGSO)

ClibFLAGS = $(CFLAGSO) -D__LIB_BUILD__
CPPlibFALGS = $(CPPFLAGS) -D__LIB_BUILD__

ASFLAGS = -f ELF64
LDFLAGS = -nostdlib -static -L$(BUILD_DIR) #-T $(ROOT_DIR)/mk/x86_64/sec.ld
ARFLAGS = rcs

export CC AS LD AR CPPFLAGS CFLAGS ClibFLAGS CPPlibFALGS ASFLAGS LDFLAGS ARFLAGS 