; load DH sectors to ES:BX from drive DL
; dl must have the drive number to read from
; ES:BX must be pointing to buffer section
disk_load:
    pusha
    push dx
    mov ah, 0x02    ;read mode
    mov al, dh      ;no. sector
    mov ch, 0x00    ;cylinder number
    mov dh, 0x00    ;head number
    mov cl, 0x02    ;start sector number

    int 0x13
    jc disk_error

    pop dx
    cmp dh, al
    jne disk_error

    ret

disk_error:
    mov bx, DISK_ERROR
    call print_nl
    call print
    call print_nl
    jmp $

DISK_ERROR:
    db 'DISK READ ERROR!!!', 0