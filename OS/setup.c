// setup.c

#include "setup.h"
#include "graphics.h"

void change_background_color(unsigned short color) {
    clear_screen(color);  // Vyčistí obrazovku danou barvou
}
