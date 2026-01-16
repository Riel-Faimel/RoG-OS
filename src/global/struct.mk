$(BUILD_DIR)global/log.o: $(SRC_DIR)global/log.cpp
$(BUILD_DIR)global/main.o: $(SRC_DIR)global/main.cpp

$(BUILD_DIR)global.o: \
	$(BUILD_DIR)global/log.o\
	$(BUILD_DIR)global/main.o
	
	$(call MKDIR_F,$@)
	$(LDCMD) $@ $^