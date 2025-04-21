[bits 16]
[org 0x7c00]

; Změna režimu na 320x200, 256 barev (BIOS interrupt 0x10, AH = 0x00 pro změnu režimu)
mov ah, 0x00
mov al, 0x13   ; Režim 0x13 - grafický režim
int 0x10

; Pokračujeme na kernel
mov ax, 0x0000
jmp 0x1000:0    ; Skáčeme do kernelu (adresy, kde je umístěn kernel)
times 510 - ($ - $$) db 0  ; Doplňte zbytek do 512 byte
dw 0xAA55        ; Boot sector signature
