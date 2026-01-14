$(BUILD_DIR)arch/kernel.o: \
	$(BUILD_DIR)mmgr.o \
	$(BUILD_DIR)las/las.o

	$(call MKDIR_F,$@)
	$(LDCMD) $@ $^ -los

#ifeq ($(ARCH) == x86_64)