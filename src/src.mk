$(BUILD_DIR)arch\mod_no_tools.o: $(BUILD_DIR)kernel_memory_allocate\kmalloc.o $(BUILD_DIR)00.o 
	$(call MKDIR_F,$@)
	$(LDCMD) $@ $^

#ifeq ($(ARCH) == x86_64)