; boot.asm - jednoduchý zaváděcí sektor pro náš OS

[bits 16]
[org 0x7C00]  ; Zaváděcí sektor musí začít na adrese 0x7C00

start:
    ; Zobrazení 'T' na obrazovce v textovém režimu, než přepneme do grafiky
    mov ah, 0x0E
    mov al, 'T'  ; T znamená Text, abys věděl, že se obrazovka přepnula do textového režimu
    int 0x10

    ; Přepnutí do grafického režimu 0x13 (320x200, 256 barev)
    mov ah, 0x00
    mov al, 0x13
    int 0x10

    ; Zavoláme kernel (předpokládáme, že je na začátku paměti)
    jmp 0x1000         ; Skok na začátek kernelu (adresa 0x1000)

times 510 - ($ - $$) db 0  ; Doplníme prázdné místo do 510 bytů
dw 0xAA55  ; Magické číslo pro zaváděcí sektor
