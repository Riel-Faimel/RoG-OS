OUTPUT_FORMAT("binary")
OUTPUT_ARCH(i386:x86-64)
ENTRY(_start)

SECTIONS
{
    //. = 0xffffffff80000000;
    . = 0x10000;

    .text : {
        E:/texmanim/cpp/07/build/boot/_start.o(.text)
    }
    
    .multiboot : {
        *(.multiboot)
        . = ALIGN(4096);
    }
    
    .kmalloc : {
        *(.kmalloc)
        *(.kmalloc.*)
        . = ALIGN(4096);
    }
    
    .text : {
        *(.text)
        *(.text.*)
        . = ALIGN(4096);
    }

    .ctors : {
        __CTOR_LIST__ = .;
        LONG(-1)
        *(.ctors)
        *(.ctors.*)
        LONG(0)
        __CTOR_END__ = .;
    } 
    
    .rodata : {
        *(.rodata)
        *(.rodata.*)
        . = ALIGN(4096);
    }
    
    .data : {
        *(.data)
        *(.data.*)
        . = ALIGN(4096);
    }
    
    .bss : {
        __bss_start = .;
        *(COMMON)
        *(.bss)
        *(.bss.*)
        . = ALIGN(4096);
        __bss_end = .;
    }
    
}