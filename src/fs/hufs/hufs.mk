$(BUILD_DIR)fs\hufs\hufs.o: $(SRC_DIR)fs\hufs\hufs.cpp
$(BUILD_DIR)fs\hufs\mount.o: $(SRC_DIR)fs\hufs\mount.cpp

$(BUILD_DIR)arch\fs\hufs\hufs.ko: $(BUILD_DIR)fs\hufs\hufs.o $(BUILD_DIR)fs\hufs\mount.o
	$(call MKDIR_F, $@)
	$(LDCMD) $@ $^ 
#-T $(SRC_DIR)fs\fs.ld

HUFS = $(BUILD_DIR)arch\fs\hufs\hufs.ko
export HUFS