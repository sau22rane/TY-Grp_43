[org 0x7c00]
    mov bp, 0x9000
    mov sp, bp

    mov bx, REAL_MODE_MSG
    call print
    call print_nl

    call switch_to_protected_mode
    jmp $

%include "print_string.asm"
%include "32bit_print.asm"
%include "32bit_gdt.asm"
%include "32bit_switch.asm"

[bits 32]
init_pm:
    mov ebx, PROTETED_MODE_MSG
    call print_string32
    jmp $

PROTETED_MODE_MSG:
    db "PROTECTED MODE STARTED!!!", 0

REAL_MODE_MSG:
    db "REAL MODE STARTED!!!!", 0

times 510-($-$$) db 0x00
dw 0xaa55