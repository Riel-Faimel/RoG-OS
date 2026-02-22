[org 0x7C00]
[bits 16]

boot:
    cli
    xor ax, ax
    mov ds, ax
    mov es, ax
    mov ss, ax
    mov sp, 0x7c00
    sti

    mov ax, 0x0003
    int 0x10

    mov bx, 0x1000
    mov es, bx
    xor bx, bx

    mov ah, 0x02
    mov al, 20
    mov ch, 0
    mov cl, 2
    mov dh, 0
    int 0x13

    lgdt [gdt_]

    mov eax, cr0
    or eax, 1
    mov cr0, eax

    jmp 0x08:pro_mode

gdt:
    dq 0x0000000000000000
    dq 0x00cf9a000000ffff
    dq 0x00cf92000000ffff
gdt_:
    dw $ - gdt - 1
    dd gdt

idtp:
    limit dw 256*8-1
    base dd 0x8000

[bits 32]
pro_mode:
    lidt [idtp]

    jmp 0x10000

times 510-($-$$) db 0
dw 0xAA55
