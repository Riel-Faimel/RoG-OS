$(BUILD_DIR)boot/init.o: $(SRC_DIR)boot/init.cpp

$(BUILD_DIR)boot.o: \
	$(BUILD_DIR)boot/init.o
	
	$(call MKDIR_F,$@)
	$(LDCMD) $@ $^