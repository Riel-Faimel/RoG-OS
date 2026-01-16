#include "memalloc.hpp"
#define NULL_PTR 0

namespace KRN::MM {

    MMgr::MMgr(
        MemoryManager_AddressValue mm_ad,
        MemoryManager_SizeValue mm_sz,
        MemoryManager_TailChain mmtc_init
    ): 
    ptr_list(static_cast<ptr2size *>(mm_ad.ptr_list_Address)),
    status_list(mm_ad.status_list_Address),
    /*data struct address*/
    Storage(mm_ad.Base_Address),
    /*set Storage space basic address*/
    Total_size(mm_sz.total_size_init), 
    Block_Size(mm_sz.block_size_init), 
    /*basic value*/
    PROTECT_SECTION(mm_sz.PROTECT_SECTION_init),
    status_list_size(mm_sz.status_list_size_init), 
    ptr_list_size(mm_sz.ptr_list_size_init),
    /*all above the size value and address*/
    sign_1(0),
    sign_2(0),
    mmtc(mmtc_init.ptr, mmtc_init.size)
    /*clear sign*/{ 
        status_list[0] = mm_sz.block_quantity_init;
        for(int i = 1;i < status_list_size;i++){
            status_list[i] = 0;
        }/*status list clear*/

        for(int i = 0;i < ptr_list_size;i++){
            const_cast<ptr2size *>(ptr_list)[i] = {NULL_PTR, 0};
        }/*ptr-size struct list clear*/
    }

    inline unsigned MMgr::len() {
        unsigned count;
        for (count = 0;status_list[count];count++);
        return count;
    }

    unsigned char *MMgr::addr_item(
        unsigned section_id
    ){
    /**
     * give a section_id then output basic address
     */
        unsigned address = 0;
        for(int i = 0;i < section_id;i++){
            address += status_list[i];
        }
        address = address * Block_Size;
        return address + Storage;
    };

    unsigned MMgr::search_item(
        unsigned blk_size
    ){
        unsigned id = 2;
        while (status_list[id]) {
            if (status_list[id] > blk_size) {
                return id;
            }
            id += 2;
        }
    /**
     * skip first section: 
     * first is always null
     * maybe there're second or third section
     * then second become full always and goto third forth..
     * also the first section for nullptr_protect section
     */
        if (status_list[0] > blk_size) return 0;
    /**
     * no section except first section
     */
        sign_1 = (char )0xFF;
    /**
     * alwfor! no section
     * it's an error
     */
        return 0;
    }

    void MMgr::extern_item(
        unsigned section_id, 
        unsigned blk_size
    ){
        if(status_list[section_id + 1] <= blk_size){
            this->sign_1 = (char )0xFF;
            sys_warning((STXT )"status unknown error: extern broken", SYS_ERROR);
            StatusListBroken_error_rescue_input *in = new StatusListBroken_error_rescue_input{
                //
            };
            mmtc.reg(
                reinterpret_cast<FuncPtr >(StatusListBroken_error_rescue),
                in,
                KRN::MM::TailChain::SELF_BLOCK
            );
            return;
        };
    /**
     * there's no blocks for using
     * so yon can't use it to extern the last section
     * the next section's blocks quantity of last section always 0
     */
        status_list[section_id] += blk_size;
        status_list[section_id - 1] -= blk_size;
        return ;
    };

    void MMgr::compress_item(
        unsigned section_id, 
        unsigned blk_size
    ){
        if(status_list[section_id] <= blk_size){
            sign_1 = (char )0xFF;
            sys_warning((STXT )"status unknown error: compress broken", SYS_ERROR);
            StatusListBroken_error_rescue_input *in = new StatusListBroken_error_rescue_input{
                //
            };
            mmtc.reg(
                reinterpret_cast<FuncPtr >(StatusListBroken_error_rescue),
                in,
                KRN::MM::TailChain::SELF_BLOCK
            );
            return;
        };

        status_list[section_id] -= blk_size;
        status_list[section_id + 1] += blk_size;
        return;
    }

    void MMgr::turncate_item(
        unsigned section_id, 
        unsigned from, 
        unsigned to
    ){
/**
 * |=========|============|===>
 * ^         ^            ^
 * start     from         to
 * |<from--->|<to - from->|<status_list[section_id] - to
 */
        if (status_list[section_id] <= to) {
            sign_1 = (char )0xFF;
/**
 * turncate false, very bad!
 * SYS_ERROR!
 */
            sys_warning((STXT )"status unknown error: turncate broken", SYS_ERROR);
            StatusListBroken_error_rescue_input *in = new StatusListBroken_error_rescue_input{
                //
            };
            mmtc.reg(
                reinterpret_cast<FuncPtr >(StatusListBroken_error_rescue),
                in,
                KRN::MM::TailChain::SELF_BLOCK
            );
            return;
        };
        
        for (unsigned id = len() - 1;id > section_id;id --) {
            status_list[id+2] = status_list[id];
        }
/**
 * update status_list and give empty site for new section
 */
        status_list[section_id + 2] = status_list[section_id] - to;
        status_list[section_id + 1] = to - from;
        status_list[section_id] = from;

        status_list[len() + 2] = 0;
        return;
    }

    void MMgr::delete_item(
        unsigned section_id
    ){
        status_list[section_id - 1] += status_list[section_id] + status_list[section_id + 1];
        for (section_id;status_list[section_id];section_id++){
            status_list[section_id] = status_list[section_id + 2];
        };
        status_list[section_id] = 0;
        return;
    }

    void MMgr::reg2_ptr2size_list(
        void *ptr_in, 
        unsigned size_in
    ){
        for(ptr2size *i = const_cast<ptr2size *>(ptr_list);i < (ptr_list + ptr_list_size);i += 1){
            if(!(i->ptr)){
                i->ptr = ptr_in;
                i->size = size_in;
                return;
            }
        };
        sign_2 = 0;
/**
 * list is full
 */
        Unable2Reg_error_tail_input *in = new Unable2Reg_error_tail_input {
            ptr_in,
            size_in
        };
        mmtc.reg(
            reinterpret_cast<FuncPtr >(Unable2Reg_error_tail),
            static_cast<void *>(&in),
            TailChain::NEXT_BLOCK
/**
 * NEXT_BLOCK:
 * reg2 ptr-to-size list error will not
 * block the main loop, but it block the next
 * reg2_.... function, so it is next step block
 */
        );
/**
 * == right==
 * I need to add a tailchain
 * void * point at the params struct
 * 
 * now I use new
 */
        return ;
    }
/**
 * this can be called by allocate()
 * then yon can find it
 */

    void MMgr::clear_ptr2size_list(
        ptr2size *ptr
    ){
        for(ptr2size *i = const_cast<ptr2size *>(ptr_list);i < (ptr_list + ptr_list_size) || ptr != i;i += 1){
            if(!(ptr - i)){
                i->ptr = NULL_PTR;
                i->size = 0;
                return ;
            };
        };
/**
 * could not find this ptr with it's 
 * size in the list
 */
        sign_1 = (char )0xFF;
        return ;
    }

    void *MMgr::allocate(
        unsigned size, 
        unsigned alignment
    ){
        if(sign_1 == (char )0xFF)return NULL_PTR;
/**
 * this is from search_item()
 * this function will give back a NULL_PTR
 * when search is failed, so jump to 
 */
        if(sign_2 == (char )0xFF){
            sys_warning((STXT )"pointer to size list full!", SYS_WARNING);
        };
/**
 * full warning will deal by
 * reg2_ptr2size_list(), it has 
 * tail chainfor list_full
 * 
 * maybe manager is not ready
 * so I need to check its status
 */
        unsigned needed_blks = (size + Block_Size - 1) / Block_Size;
        unsigned sec_id_searched = search_item(needed_blks);
        unsigned char *re;

        if(!sec_id_searched){
            turncate_item(sec_id_searched, PROTECT_SECTION, needed_blks);
            re = addr_item(sec_id_searched + 1);
        }else{
            re = addr_item(sec_id_searched + 1);
            extern_item(sec_id_searched - 1, needed_blks);
        }
        reg2_ptr2size_list(re, needed_blks);
/**!!! args pointer in stack !!!
 * .
 * >>>now in kernel mem_pool
 */
        return re;
    }

    void MMgr::deallocate(
        void *ptr_in
    ){
        ptr2size *i = const_cast<ptr2size *>(ptr_list);
        for(i;i->ptr == ptr_in;i++);
        unsigned size = i->size;
        unsigned int free_blks = (size + Block_Size - 1) / Block_Size;
/**
 * need to be free
 */
        unsigned at_blk = static_cast<unsigned char *>(i->ptr) - Storage;
        unsigned sec_id = 0;
/**
 * |======|===>
 * ^      ^
 * start  here is the pointer
 * I need to change into blocks
 */
        while (at_blk - status_list[sec_id] >= 0){
            at_blk -= status_list[sec_id];
            sec_id ++;
        }
        
        if(at_blk + free_blks > status_list[sec_id]) {
            sign_1 = (char )0xFF;
            sys_warning((STXT )"memory deallocate error: beyound section length", SYS_ERROR);
            return;
        }

        if (at_blk) {
            if (!(sec_id & 1)){
                sign_1 = (char )0xFF;
                sys_warning((STXT )"memory deallocate error: deallocate null section", SYS_ERROR);
                return;
            };
            goto COMMON_LABLE;// common
        }else{
            goto NULL_LABLE;
/**
 * |======|======|======>
 * ^sec1  ^sec2  ^sec3
 *        ^at_blk
 * at_blk is just point at section edge
 */
        }
        ;
COMMON_LABLE:
        if (status_list[sec_id] == free_blks + at_blk) {
            compress_item(sec_id, free_blks);
            return;
        }
        turncate_item(sec_id, at_blk, at_blk + free_blks);
        ;
NULL_LABLE:
        if(status_list[sec_id] == free_blks){
            delete_item(sec_id);
            return;
        }
        extern_item(sec_id - 1, free_blks);
        return;
    }

    TailChain::TailChain(
        void *TailChain_Funclist_Ptr,
        unsigned size_init=192
    ): 
    list(static_cast<TailChain_FuncList *>(TailChain_Funclist_Ptr)),
    size(size_init){}

    TailChain::~TailChain(){
        for(TailChain_FuncList *i = list;i < list + size;i += 1){
            clean(i);
        };
        size = 0;
        sign__2 = 0;
        sign__1 = 0;
        sign_0 = 0;
        sign_1 = 0;
        sign_2 = 0;
        sign_3 = 0;
    }

    inline void *TailChain::search_for_struct_space(){
        for(TailChain_FuncList *i = list;i < list + size;i += 1){
            if(i->is_null)return i;
        };
/**
 * ======
 * maybe..
 * I need to add something for error
 * it will break the reg function
 * ======
 */
        return NULL_PTR;
    }

    void TailChain::handle_overflow(
        FuncPtr func_ptr_in, 
        void *args, 
        FuncPriority priority_in
    ){
        switch (priority_in)
        {
        case NULL_PRIORITY:
            /* rubish */
            break;
        case SELF_BLOCK:
            if(over_sign_tansiting){
                over_sign_0 ++;
                ;
            }else{
                over_sign_0 ++;
                over_sign_tansiting ++;
                func_ptr_in(args);
            }
            break;
        case NEXT_BLOCK:
            break;
        default:
            break;
        };
    }

    void TailChain::reg(
        FuncPtr func_ptr_in,
        void *args_in,
        FuncPriority priority_in = BACKGROUND
    ){
        TailChain_FuncList *struct_address = static_cast<TailChain_FuncList *>(search_for_struct_space());
        if(!struct_address){
            handle_overflow(func_ptr_in, args_in, priority_in);
            return;
        };
        struct_address->priority = priority_in;
/**
 * don't worry
 * struct_address->priority is not in stack 
 * so there's no nullptr or suspended_ptr
 * ===
 * struct_address->priority is in self section
 * but priority_in in on stack
 * so, input params using priority_in maybe better
 */
        switch (priority_in)
        {
        case NULL_PRIORITY:
            sign__1 = 1;
            return ;
        
        case SELF_BLOCK:
            sign_0 += 1;
            break;

        case NEXT_BLOCK:
            sign_1 += 1;
            break;
        
        case OPTIMIZABLE:
            sign_2 += 1;
            break;
        
        case BACKGROUND:
            sign_3 += 1;
            break;
        
        default:
            sign_3 += 1;
            sign__2 = 1;
            break;
        };

        struct_address->func_ptr = func_ptr_in;
        struct_address->args = args_in;
/**
 * I use new, so args struct 
 * is on kernel mem_pool
 */
        struct_address->is_null = 0;
    }

    void TailChain::clean(
        TailChain_FuncList *func
    ){
        func->args = NULL_PTR;
        func->func_ptr = NULL_PTR;
        func->priority = NULL_PRIORITY;
        func->is_null = 0;
        return;
    }

}