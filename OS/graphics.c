#include "graphics.h"
#include <stddef.h>

// Definice framebufferu
unsigned char framebuffer[SCREEN_WIDTH * SCREEN_HEIGHT];

// Jednoduchý 8x8 bitmapový font (přidány znaky: 'A', 'B', 'C', ' ')
static const unsigned char font[256][8] = {
    ['A'] = {0x18, 0x24, 0x42, 0x7E, 0x42, 0x42, 0x42, 0x00},
    ['B'] = {0x7C, 0x42, 0x42, 0x7C, 0x42, 0x42, 0x7C, 0x00},
    ['C'] = {0x3C, 0x42, 0x40, 0x40, 0x40, 0x42, 0x3C, 0x00},
    [' '] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    // Přidej další znaky podle potřeby
};

// Vlastní implementace funkce strlen
size_t strlen(const char *str) {
    size_t len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

// Funkce pro vymazání obrazovky
void clear_screen(unsigned char color) {
    for (int y = 0; y < SCREEN_HEIGHT; ++y) {
        for (int x = 0; x < SCREEN_WIDTH; ++x) {
            framebuffer[y * SCREEN_WIDTH + x] = color;
        }
    }
}

// Funkce pro vykreslení jednoho pixelu
void put_pixel(int x, int y, unsigned char color) {
    if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT) {
        framebuffer[y * SCREEN_WIDTH + x] = color;
    }
}

// Funkce pro vykreslení jednoho znaku
void put_char(int x, int y, char c, unsigned char color) {
    const unsigned char* char_map = font[(unsigned char)c];
    for (int row = 0; row < 8; row++) {
        unsigned char bits = char_map[row];
        for (int col = 0; col < 8; col++) {
            if (bits & (1 << (7 - col))) {
                put_pixel(x + col, y + row, color);
            }
        }
    }
}

// Funkce pro vykreslení textu (řetězce)
void put_string(int x, int y, const char* str, unsigned char color) {
    while (*str) {
        put_char(x, y, *str, color);
        x += 8;
        str++;
    }
}

// Funkce pro vykreslení desktopu
void draw_desktop() {
    for (int y = SCREEN_HEIGHT - 20; y < SCREEN_HEIGHT; y++) {
        for (int x = 0; x < SCREEN_WIDTH; x++) {
            put_pixel(x, y, 0x1F);
        }
    }
}

// Funkce pro vykreslení tlačítka
void draw_button(int x, int y, const char* label) {
    int width = 100;
    int height = 20;
    unsigned char bg_color = 0x17;   // Světle modrá
    unsigned char border_color = 0x1F; // Modro-zelená
    unsigned char text_color = 0x0F; // Bílá

    // Vykreslení pozadí tlačítka
    for (int dy = 0; dy < height; dy++) {
        for (int dx = 0; dx < width; dx++) {
            put_pixel(x + dx, y + dy, bg_color);
        }
    }

    // Vykreslení okraje tlačítka
    for (int dx = 0; dx < width; dx++) {
        put_pixel(x + dx, y, border_color);
        put_pixel(x + dx, y + height - 1, border_color);
    }
    for (int dy = 0; dy < height; dy++) {
        put_pixel(x, y + dy, border_color);
        put_pixel(x + width - 1, y + dy, border_color);
    }

    // Vykreslení textu doprostřed
    int text_x = x + (width - 8 * strlen(label)) / 2;
    int text_y = y + (height - 8) / 2;
    put_string(text_x, text_y, label, text_color);
}
