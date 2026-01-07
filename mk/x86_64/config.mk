CC = x86_64-elf-g++
AS = nasm
LD = x86_64-elf-ld

CPPFLAGS = -nostdlib -ffreestanding -nodefaultlibs -Dx86_64 -fno-exceptions -fno-rtti
CFLAGS = -nostdlib -ffreestanding -nodefaultlibs -Dx86_64 -fno-exceptions -fno-rtti
ASFLAGS = -f ELF64
LDFLAGS = -nostdlib -static -T $(ROOT_DIR)/mk/x86_64/sec.ld

export CC AS LD CPPFLAGS CFLAGS ASFLAGS LDFLAGS 