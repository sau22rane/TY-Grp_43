;GDT first null entry
gdt_start:
    dd 0x0
    dd 0x0

gdt_code:
    dw 0xffff       ;limit(0-15)
    dw 0x0          ;base(0-15)
    dw 0x9a00
    dw 0x00cf

    ;db 0x0          ;base(16-23)
    ;db 10011010b    ;1st flag, type
    ;db 11001111b    ;2nd flag, limit(16-19)
    ;db 0x0          ;base(24-31)

gdt_data:
    dw 0xffff       ;limit(0-15)
    dw 0x0          ;base(0-15)
    dw 0x9200
    dw 0x00cf
    ;db 0x0          ;base(16-23)
    ;db 10010010b    ;1st flag, type
    ;db 11001111b    ;2nd flag, limit(16-19)
    ;db 0x0          ;base(24-31)

gdt_end:

gdt_descriptor:
    dw gdt_end - gdt_start - 1
    dd gdt_start

CODE_SEG equ gdt_code - gdt_start
DATA_SEG equ gdt_data - gdt_start