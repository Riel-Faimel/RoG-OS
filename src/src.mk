LDOUTPUT = -nostdlib -static -L$(BUILD_DIR) #-T $(ROOT_DIR)/mk/x86_64/sec.ld

$(BUILD_DIR)arch/kernel.o: \
	$(BUILD_DIR)mmgr.o \
	$(BUILD_DIR)las/las.o

	$(call MKDIR_F,$@)
	$(LD) $(LDOUTPUT) -o $@ $^ -los

#ifeq ($(ARCH) == x86_64)