CC = g++
AS = nasm
LD = ld 

CPPFLAGS = -nostdlib -ffreestanding -nodefaultlibs -DSTM32 -fno-exceptions -fno-rtti
CFLAGS = -nostdlib -ffreestanding -nodefaultlibs -DSTM32 -fno-exceptions -fno-rtti
ASFLAGS = -f bin
LDFLAGS = -nostdlib -static -T $(ROOT_DIR)/mk/STM32/sec.ld

export CC AS LD CPPFLAGS CFLAGS ASFLAGS LDFLAGS