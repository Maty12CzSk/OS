#include "graphics.h"
#include "input.h"

void open_settings() {
    // Kód pro zobrazení "Nastavení"
    clear_screen(0x00); // Vymazání obrazovky, barva pozadí 0x00 (černá)
    put_string(10, 10, "Nastaveni je otevreno", 0x0F); // Text na obrazovce
}
