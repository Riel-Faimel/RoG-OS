ARCH ?= x86_64
ROOT_DIR := $(CURDIR)
BUILD_DIR = $(ROOT_DIR)/build/
SRC_DIR = $(ROOT_DIR)/src/

define MKDIR_F
	@if not exist "$(dir $(1))" mkdir "$(dir $(1))"
endef

ifeq ($(ARCH), x86_64)
	include $(ROOT_DIR)/mk/x86_64/*.mk
endif
ifeq ($(ARCH), STM32)
	include $(ROOT_DIR)/mk/STM32/*.mk
endif

LDCMD = $(LD) $(LDFLAGS) -o

include $(SRC_DIR)memalloc/memalloc.mk
include $(SRC_DIR)kernel_memory_allocate\kmalloc.mk
include $(SRC_DIR)las\las.mk
include $(SRC_DIR)src.mk

include $(SRC_DIR)fs\fs.mk

KO = $(FS_KO)

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

result: $(BUILD_DIR)arch\mod_no_tools.o $(BUILD_DIR)las\fs.o

ko: $(KO)

clean:
	rmdir /s "$(BUILD_DIR)"