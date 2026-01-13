$(BUILD_DIR)\arch\fs_mod\ext4\ext4.o: $(BUILD_DIR)fs\ext4\ext4.o
	$(call MKDIR_F,$@)
	$(LDCMD) $@ $^