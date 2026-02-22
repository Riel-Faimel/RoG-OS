ARCH ?= Win2x86_64
ROOT_DIR := $(CURDIR)
BUILD_DIR = $(ROOT_DIR)/build/
SRC_DIR = $(ROOT_DIR)/src/


ifeq ($(ARCH), Win2x86_64)
	include $(ROOT_DIR)/mk/x86_64/*.mk
define MKDIR_F
	@if not exist "$(dir $(1))" mkdir "$(dir $(1))"
endef
endif
ifeq ($(ARCH), Win2STM32)
	include $(ROOT_DIR)/mk/STM32/*.mk
define MKDIR_F
	@if not exist "$(dir $(1))" mkdir "$(dir $(1))"
endef
endif
ifeq ($(ARCH), Linux2x86_64)
	include $(ROOT_DIR)/mk/x86_64/*.mk
define MKDIR_F
	@mkdir -p "$(dir $(1))"
endef
endif
ifeq ($(ARCH), Linux2STM32)
	include $(ROOT_DIR)/mk/STM32/*.mk
define MKDIR_F
	@mkdir -p "$(dir $(1))"
endef
endif

LDCMD = $(LD) $(LDFLAGS) -o

#libs
include $(SRC_DIR)libs/kernel_memory_allocate/kmalloc.mk
include $(SRC_DIR)libs/memop/memop.mk
include $(SRC_DIR)libs/lc/lc.mk
include $(SRC_DIR)libs/libs.mk

#global
include $(SRC_DIR)global/struct.mk

#static mods
include $(SRC_DIR)memalloc/memalloc.mk
include $(SRC_DIR)las/las.mk
include $(SRC_DIR)modf/modf.mk
include $(SRC_DIR)boot/boot.mk
include $(SRC_DIR)ctl/ctl.mk
include $(SRC_DIR)src.mk

#mods
include $(SRC_DIR)mods/fs/fs.mk
include $(SRC_DIR)mods/drv/drv.mk

MOD = $(FS_MOD)
MOD += $(DRV_MOD)

$(BUILD_DIR)%.o: $(SRC_DIR)%.cpp
	$(call MKDIR_F,$@)
	$(CC) $(CPPFLAGS) -c $< -o $@

$(BUILD_DIR)%.o: $(SRC_DIR)%.c 
	$(call MKDIR_F,$@)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)%.o: $(SRC_DIR)%.asm
	$(call MKDIR_F,$@)
	$(AS) $(ASFLAGS) $< -o $@

$(BUILD_DIR)%.bin: $(SRC_DIR)%.asm
	$(call MKDIR_F,$@)
	$(AS) -f bin $< -o $@

export CC AS LD ARCH ROOT_DIR BUILD_DIR SRC_DIR CFLAGS ASFLAGS LDFLAGS 

os.img: $(BUILD_DIR)arch/kernel.o $(BUILD_DIR)boot/boot.bin
	copy /b E:\texmanim\cpp\07\build\boot\boot.bin + E:\texmanim\cpp\07\build\arch\kernel.o E:\texmanim\cpp\07\build\arch\os.img  
	
#copy /b "$(BUILD_DIR)boot/boot.bin" + "$(BUILD_DIR)arch/kernel.o" "$(BUILD_DIR)arch/os.img"

libs: $(BUILD_DIR)libos.a 

result: $(BUILD_DIR)arch/kernel.o

done: os.img

mod: $(MOD)

QEMU = qemu-system-x86_64
run: 
	$(QEMU) -drive format=raw,index=0,file=$(BUILD_DIR)arch/os.img,media=disk -drive format=raw,index=1,file=share.vhd,media=disk -serial stdio

clean:
	rmdir /s "$(BUILD_DIR)"