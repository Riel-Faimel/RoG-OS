$(BUILD_DIR)boot/init.o: $(SRC_DIR)boot/init.cpp
$(BUILD_DIR)boot/_start.o: $(SRC_DIR)boot/_start.asm

$(BUILD_DIR)boot/boot.bin: $(SRC_DIR)boot/boot.asm


$(BUILD_DIR)boot.o: $(BUILD_DIR)boot/init.o
#$(BUILD_DIR)boot/_start.o
	$(call MKDIR_F,$@)
	$(LDCMD) $@ $^