[org 0x7c00]
KERNEL_OFFSET equ 0x1000         ;kernel offset
    mov [BOOT_DRIVE], dl         ;BIOS stores our boot drive in DL
    mov bp, 0x9000               ;set-up stack
    mov sp,bp
    mov bx, REAL_MODE_MSG        ;Starting in 16bit real mode
    call print
    call print_nl

    call load_kernel             ;load the kernel from the disk

    call switch_to_protected_mode

    jmp $                        ;will never be executed

%include "print/print_string.asm"
%include "pm/32bit_gdt.asm"
%include "pm/32bit_switch.asm"
%include "disk/disk_load.asm"
%include "print/32bit_print.asm"

[bits 16]
load_kernel:
    mov bx, LOAD_KERNEL_MSG
    call print
    call print_nl

    mov bx, KERNEL_OFFSET
    mov dl, [BOOT_DRIVE]
    mov dh, 0xf
    call disk_load

    mov bx, LOADED_KERNEL_MSG
    call print
    call print_nl

    ret

[bits 32]
init_pm:
    mov ebx, PROTECTED_MODE_MSG
    call print_string32

    call KERNEL_OFFSET

    jmp $

PROTECTED_MODE_MSG:
    db "PROTECTED MODE STARTED!!!", 0

REAL_MODE_MSG:
    db "REAL MODE STARTED!!!!", 0

LOAD_KERNEL_MSG:
    db "LOADING KERNEL!!!",0

LOADED_KERNEL_MSG:
    db "KERNEL LOADED!!!",0

BOOT_DRIVE:
    db 0x0

times 510-($-$$) db 0x0
dw 0xaa55


