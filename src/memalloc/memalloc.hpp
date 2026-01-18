#pragma once
#ifdef STM32
#include "../hard_tools/STM32/time_ths.hpp"
#endif
#ifdef x86_64
#include "../hard_tools/x86_64/time_ths.hpp"
#endif
#include <libs/kernel_memory_allocate/kmalloc.hpp>
#include <global/main.hpp>

namespace KRN::MM {
    typedef void (*FuncPtr)(void *args);
/**
 * Tail chain function
 * always void func()
 * params and return need
 * var outside
 */

    struct MemoryManager_AddressValue{
        unsigned char *Base_Address;
        void *ptr_list_Address;
        unsigned *status_list_Address;
    };

    struct MemoryManager_SizeValue{
        unsigned total_size_init; /*alloc to use*/
        unsigned block_quantity_init; /*used*/
        unsigned block_size_init = 4096;
        unsigned status_list_size_init = 256;
        unsigned ptr_list_size_init = 4096;
        unsigned PROTECT_SECTION_init = 0x10000;
    };

    struct MemoryManager_TailChain{
        void *ptr;
        unsigned size;
    };
    /**
     * there three struct above is for init 
     * of memory manager, 
     * AddressValue for memory map address.
     * SizeValue for memory section bytes.
     * TailChain for MemoryManager's own TailChain class.
     */

    class TailChain{
    public:
        enum FuncPriority{
            NULL_PRIORITY = -1,
            SELF_BLOCK = 0,
            NEXT_BLOCK = 1,
            OPTIMIZABLE = 2,
            BACKGROUND = 3
        };
    /**
     * the Tail chain function priority
     * 
     * NULL_PRIORITY: unknown priority, maybe sth. wrong
     * SELF_BLOCK: the function need to deal will block 
     * self main loop, should not block caller
     * NEXT_BLOCK: the function need to deal will block
     * important porcess but not main loop
     * OPTIMIZABLE: the function need to deal will quickly 
     * occupy and deplete resources but willn't block function
     * BACKGROUND: willn't block or deplete
     */

        struct TailChain_FuncList{
            FuncPtr func_ptr;
            void *args;
            FuncPriority priority;
            unsigned char is_null;
        } *list;

    private:
        void *search_for_struct_space();
        /*[[noreturn]] */void handle_overflow(FuncPtr func_ptr_in, void *args, FuncPriority priority_in);

    public:
        unsigned size;
        unsigned char sign__2 = 0;
        unsigned char sign__1 = 0;
    /**
     * size: TailChain_FuncList size
     * sign__2: shared sign
     * sign__1: shared sign
     * 
     * sometimes __1 use for error, __2 use for warning
     */
        unsigned char sign_0 = 0;
        unsigned char sign_1 = 0;
        unsigned char sign_2 = 0;
        unsigned char sign_3 = 0;
    /**
     * sign_0: SELF_BLOCK functions quanity
     * sign_1: NEXT_BLOCK functions quanity
     * sign_2: OPTIMIZABLE functions quanity
     * sign_3: BACKGROUND functions quanity
     */
        signed char over_sign_tansiting = 0;
    /**
     * sign for over flow twice
     */
        unsigned char over_sign_0 = 0;
        unsigned char over_sign_1 = 0;
        unsigned char over_sign_2 = 0;
        unsigned char over_sign_3 = 0;
    /**
     * over_sign_0
     * over_sign_1
     * over_sign_2
     * over_sign_3
     * all above is priority over flow sign
     * clear by time, so it is the standard
     * sign for handle function
     */
        TailChain(void *TailChain_Funclist_Ptr, unsigned size_init);
        TailChain(){};
        ~TailChain();

        void reg(FuncPtr func_ptr_in, void *args_in, FuncPriority priority_in);

        void clean(TailChain_FuncList *func);
    };

    class MMgr {
    private:
        unsigned *status_list;
        const struct ptr2size{
            void *ptr;
            unsigned size;
        } *ptr_list;
        //data struct
        unsigned char *Storage;
        unsigned Total_size;
        unsigned Block_Size;
        unsigned PROTECT_SECTION;
        unsigned status_list_size;
        unsigned ptr_list_size;
        //value of manager
        char sign_1;
        char sign_2;
    public:
        MMgr(
            MemoryManager_AddressValue mm_ad, 
            MemoryManager_SizeValue mm_sz,
            MemoryManager_TailChain mmtc_init
        );
        
        MMgr(){};

        // 分配指定大小的内存，返回指针
        void* allocate(unsigned size, unsigned alignment = 8);

        // 释放内存（标记为可用即可，不需要真正清零）
        void deallocate(void* ptr_in);

        // 获取内存池使用情况
        unsigned used_bytes() const;
        unsigned free_bytes() const;

        // 禁止拷贝（内核风格）
        MMgr(const MMgr&) = delete;
        MMgr& operator=(const MMgr&) = delete;
    private:
        inline unsigned len();
        unsigned char *addr_item(unsigned section_id);
        unsigned search_item(unsigned blk_size);
        void extern_item(unsigned section_id, unsigned blk_size);
        void compress_item(unsigned section_id, unsigned blk_size);
        void delete_item(unsigned section_id);
        void turncate_item(unsigned section_id, unsigned from, unsigned to);
        //ptr2size function list
        void reg2_ptr2size_list(void *ptr, unsigned size);
        void clear_ptr2size_list(ptr2size *ptr);

    public:
        TailChain mmtc;

    private:
    /*void descript_type_handle[_part|default for _func]*/
        struct Unable2Reg_error_tail_input{
            void *ptr;
            unsigned size;
        };
        static void Unable2Reg_error_tail(Unable2Reg_error_tail_input *input);

        struct Need2UpdateStatusList_warning_tail_input{
            ;
        };
        static void Need2UpdateStatusList_warning_tail(Need2UpdateStatusList_warning_tail_input *input);

        struct StatusListBroken_error_rescue_input{
            /* data */
        };
        static void StatusListBroken_error_rescue(StatusListBroken_error_rescue_input *input);
    }; 

    extern MMgr mm;
    extern MMgr *mm_ptr;
}