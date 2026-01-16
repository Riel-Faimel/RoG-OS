OUTPUT_FORMAT("elf64-x86-64")
OUTPUT_ARCH(i386:x86-64)
ENTRY(_start)

SECTIONS
{
    . = 0xffffffff80000000;
    
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
        *(COMMON)
        *(.bss)
        *(.bss.*)
        . = ALIGN(4096);
    }
    
}