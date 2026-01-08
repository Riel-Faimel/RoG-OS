$(BUILD_DIR)fs\hufs\hufs.o: $(SRC_DIR)fs\hufs\hufs.cpp

$(BUILD_DIR)arch\fs\hufs\hufs.ko: $(BUILD_DIR)fs\hufs\hufs.o 
	$(call MKDIR_F, $@)
	$(LDCMD)

HUFS = $(BUILD_DIR)arch\fs\hufs\hufs.ko
export