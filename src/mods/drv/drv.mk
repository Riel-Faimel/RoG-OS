ifeq ($(ARCH), Win2x86_64)
	include $(SRC_DIR)mods/drv/x86_64/*.mk
endif
ifeq ($(ARCH), Win2STM32)
	include $(SRC_DIR)mods/drv/STM32/*.mk
endif
ifeq ($(ARCH), Linux2x86_64)
	include $(SRC_DIR)mods/drv/x86_64/*.mk
endif
ifeq ($(ARCH), Linux2STM32)
	include $(SRC_DIR)mods/drv/STM32/*.mk
endif