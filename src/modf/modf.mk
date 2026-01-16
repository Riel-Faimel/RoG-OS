$(BUILD_DIR)modf/modifier.o: $(SRC_DIR)modf/modifier.cpp
$(BUILD_DIR)modf/shell.o: $(SRC_DIR)modf/shell.cpp

$(BUILD_DIR)modf.o:\
	$(BUILD_DIR)modf/modifier.o\
	$(BUILD_DIR)modf/shell.o
	
	$(call MKDIR_F,$@)
	$(LDCMD) $@ $^