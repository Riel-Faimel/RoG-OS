LIB_OBJS = \
	$(BUILD_DIR)libs/kernel_memory_allocate/kmalloc.o\
	$(BUILD_DIR)libs/memop/mop.o

$(BUILD_DIR)libos.a: $(LIB_OBJS)
	$(AR) $(ARFLAGS) $@ $^