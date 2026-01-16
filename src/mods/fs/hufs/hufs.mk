$(BUILD_DIR)mods/fs/hufs/hufs.o: $(SRC_DIR)mods/fs/hufs/hufs.cpp
$(BUILD_DIR)mods/fs/hufs/rgt.o: $(SRC_DIR)mods/fs/hufs/rgt.cpp

$(BUILD_DIR)arch/mods/fs/hufs/hufs.mod: $(BUILD_DIR)mods/fs/hufs/hufs.o $(BUILD_DIR)mods/fs/hufs/rgt.o
	$(call MKDIR_F, $@)
	$(LDCMD) $@ $^ -los
#-T $(SRC_DIR)fs\fs.ld

HUFS = $(BUILD_DIR)arch/mods/fs/hufs/hufs.mod
export HUFS