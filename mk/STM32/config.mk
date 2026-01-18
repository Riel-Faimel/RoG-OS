CC = D:\msys64\mingw64\bin\arm-none-eabi-g++
AS = D:\msys64\mingw64\arm-none-eabi\bin\as
LD = D:/msys64/mingw64/arm-none-eabi/bin/ld
AR = D:/msys64/mingw64/arm-none-eabi/bin/ar

CFLAGSO = -nostdlib -ffreestanding -nodefaultlibs -DSTM32 -fno-builtin -I "$(SRC_DIR)"
CPPFLAGSO = $(CFLAGSO) -fno-exceptions -std=c++20 -fno-rtti -fno-use-cxa-atexit -fno-threadsafe-statics

CFLAGS = $(CFLAGSO) 
CPPFLAGS = $(CPPFLAGSO)

ClibFLAGS = $(CFLAGSO) -D__LIB_BUILD__
CPPlibFALGS = $(CPPFLAGS) -D__LIB_BUILD__

ASFLAGS = -f bin
LDFLAGS = -nostdlib -r -L$(BUILD_DIR) #-T -T $(ROOT_DIR)/mk/STM32/sec.ld
ARFLAGS = rcs

export CC AS LD AR CPPFLAGS CFLAGS ClibFLAGS CPPlibFALGS ASFLAGS LDFLAGS ARFLAGS 
