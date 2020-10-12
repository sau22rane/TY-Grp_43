[bits 16]
switch_to_protected_mode:
    cli                         ;disable interupts
    lgdt [gdt_descriptor]       ;load gdt

    mov eax, cr0                ;
    or eax, 0x1                 ;setting first bit of cr0 1
    mov cr0,eax                 ;

    jmp CODE_SEG:start_protected_mode

[bits 32]
start_protected_mode:
    mov ax, DATA_SEG
    mov ds, ax
    mov ss, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ebp, 0x90000
    mov esp, ebp

    call init_pm