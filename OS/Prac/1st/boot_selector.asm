[org 0x7c00]
mov [DRIVE_NUMBER], dl  ;BIOS stores our boot drive in DL

mov dh, 10  ; row
mov dl, 5   ; col
mov bh, 0   ; page
mov ah, 2   ; set cursor
int 0x10
mov ah, 0x0e ; tty mode

mov bx, msg1
call print

call print_nl

msg1:
    db 'Welcome!! Rane Saurabh', 0

;load from drive
DRIVE_NUMBER:
    db 0x00
mov dh, 0x05
mov bx, 0x9000
mov dl, [DRIVE_NUMBER]

call disk_load



jmp $ ; jump to current address = infinite loop


%include "disk_load.asm"
%include "print_string.asm"
%include "print_hex.asm"
; padding and magic number
times 510 - ($-$$) db 0
dw 0xaa55 