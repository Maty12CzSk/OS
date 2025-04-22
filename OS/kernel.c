#include "graphics.h"  // Zahrnutí grafických funkcí

// Hlavní funkce kernelu
void kernel_main() {
    // Vymazání obrazovky na červenou
    clear_screen(0x4F);  // Červená barva

    // Vykreslení plochy (spodní lišta + pozadí)
    draw_desktop();

    // Vykreslení textu na pozici (10, 10) s bílou barvou (0x0F)
    put_string(10, 10, "Hello, World!", 0x0F);  // Bílý text
}

// Funkce _start volá kernel_main
void _start() {
    kernel_main();  // Zavolání kernel_main
    while (1);  // Nekonečná smyčka
}
