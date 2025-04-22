#include "graphics.h"
#include "input.h"
#include "settings.h"

void main() {
    // Inicializace obrazovky, klávesnice atd.
    clear_screen(0x4F); // Vymazání obrazovky
    draw_button(50, 50, "Nastaveni");

    while (1) {
        if (key_pressed(KEY_ENTER)) {
            open_settings();  // Spuštění aplikace nastavení při stisknutí Enter
        }
    }
}
