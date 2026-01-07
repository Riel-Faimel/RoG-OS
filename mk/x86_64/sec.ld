/* sec.ld - 正确的x86_64链接脚本 */
OUTPUT_FORMAT("elf64-x86-64")
OUTPUT_ARCH(i386:x86-64)

SECTIONS
{
    /* 内核从1MB开始 */
    . = 1M;

    /* 多引导头必须在前面 */
    .multiboot : {
        *(.multiboot)
    }

    /* 你的kmalloc段 */
    .kmalloc : {
        *(.kmalloc)
        *(.kmalloc.*)
        . = ALIGN(16);
    }

    /* 代码段 */
    .text : {
        *(.text)
        *(.text.*)
    }

    /* 只读数据段 */
    .rodata : {
        *(.rodata)
        *(.rodata.*)
    }

    /* 数据段 */
    .data : {
        *(.data)
        *(.data.*)
    }

    /* BSS段 */
    .bss : {
        *(COMMON)
        *(.bss)
        *(.bss.*)
    }
}