$(BUILD_DIR)memalloc/memalloc.o: $(SRC_DIR)memalloc/memalloc.cpp
$(BUILD_DIR)memalloc/memalloc_self.o: $(SRC_DIR)memalloc/memalloc_self.cpp
$(BUILD_DIR)memalloc/tools_forMemalloc_s.o: $(SRC_DIR)memalloc/tools_forMemalloc_s.asm
$(BUILD_DIR)memalloc/tools_forMemalloc.o: $(SRC_DIR)memalloc/tools_forMemalloc.c



$(BUILD_DIR)mmgr.o: \
	$(BUILD_DIR)memalloc/memalloc.o \
	$(BUILD_DIR)memalloc/memalloc_self.o \
	$(BUILD_DIR)memalloc/tools_forMemalloc.o \
	$(BUILD_DIR)memalloc/tools_forMemalloc_s.o\
	$(BUILD_DIR)kernel_memory_allocate/kmalloc.o\
	$(BUILD_DIR)global/log.o

#depend: log.o kmalloc.o

	$(call MKDIR_F,$@)
	$(LDCMD) $@ $^