; bootloader.asm — BIOS bootloader for miniboot86
org 0x7C00

start:
    cli                 ; disable interrupts
    xor ax, ax
    mov ds, ax
    mov es, ax
    mov ss, ax
    mov sp, 0x7C00      ; set stack

    ; Load 10 sectors from disk (adjust as needed)
    mov ah, 0x02        ; BIOS read function
    mov al, 10          ; num sectors
    mov ch, 0x00        ; cylinder
    mov cl, 0x02        ; sector (starts at 2 — 1 is boot sector)
    mov dh, 0x00        ; head
    mov dl, 0x00        ; drive (0 = floppy/hard)
    mov bx, 0x7E00      ; where to load userland
    int 0x13            ; BIOS disk read

    jc disk_error       ; jump if carry flag set (fail)
    
    ; Jump to userland
    jmp 0x0000:0x7E00

disk_error:
    mov si, error_msg
.print:
    lodsb
    or al, al
    jz .halt
    mov ah, 0x0E
    int 0x10
    jmp .print

.halt:
    cli
    hlt
    jmp .halt

error_msg db "Disk Read Error", 0

times 510-($-$$) db 0
dw 0xAA55               ; boot signature
