$(BUILD_DIR)las/las.o: $(SRC_DIR)las/las.cpp

$(BUILD_DIR)las.o: \
	$(BUILD_DIR)las/las.o
	
	$(call MKDIR_F,$@)
	$(LDCMD) $@ $^