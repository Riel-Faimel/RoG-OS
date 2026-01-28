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

export CC AS LD ARCH ROOT_DIR BUILD_DIR SRC_DIR CFLAGS ASFLAGS LDFLAGS 

libs: $(BUILD_DIR)libos.a 

result: $(BUILD_DIR)arch/kernel.o

mod: $(MOD)

clean:
	rmdir /s "$(BUILD_DIR)"