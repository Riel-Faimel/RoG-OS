$(BUILD_DIR)ctl/ctl.cpp: $(SRC_DIR)ctl/ctl.cpp

$(BUILD_DIR)ctl.o: $(BUILD_DIR)ctl/ctl.o

	$(call MKDIR_F,$@)
	$(LDCMD) $@ $^