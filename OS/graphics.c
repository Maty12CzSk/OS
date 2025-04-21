#include "graphics.h"

#define SCREEN_WIDTH  320
#define SCREEN_HEIGHT 200

// Fiktivní framebuffer (nahraď podle svého výstupu)
unsigned char* framebuffer = (unsigned char*) 0xA0000;

void put_pixel(int x, int y, unsigned char color) {
    if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT) {
        framebuffer[y * SCREEN_WIDTH + x] = color;
    }
}

void clear_screen(unsigned char color) {
    for (int y = 0; y < SCREEN_HEIGHT; ++y) {
        for (int x = 0; x < SCREEN_WIDTH; ++x) {
            put_pixel(x, y, color);
        }
    }
}

void draw_button(int x, int y, const char* text) {
    for (int i = 0; i < 50; ++i) {
        for (int j = 0; j < 20; ++j) {
            put_pixel(x + i, y + j, 0x0F); // bílé tlačítko
        }
    }
    // Text ignorujeme (zatím) — jen placeholder
}
