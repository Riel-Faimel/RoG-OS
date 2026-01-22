$(BUILD_DIR)modf/modifier.o: $(SRC_DIR)modf/modifier.cpp
$(BUILD_DIR)modf/shell.o: $(SRC_DIR)modf/shell.cpp
$(BUILD_DIR)modf/connecter.o: $(SRC_DIR)modf/connecter.cpp

$(BUILD_DIR)modf.o:\
	$(BUILD_DIR)modf/modifier.o\
	$(BUILD_DIR)modf/shell.o\
	$(BUILD_DIR)modf/connecter.o
	
	$(call MKDIR_F,$@)
	$(LDCMD) $@ $^