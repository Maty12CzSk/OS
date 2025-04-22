#include "graphics.h"

// Definice framebufferu
unsigned char framebuffer[SCREEN_WIDTH * SCREEN_HEIGHT];

// Funkce pro vymazání obrazovky
void clear_screen(unsigned char color) {
    for (int y = 0; y < SCREEN_HEIGHT; ++y) {
        for (int x = 0; x < SCREEN_WIDTH; ++x) {
            framebuffer[y * SCREEN_WIDTH + x] = color;  // Nastaví všechny pixely na zadanou barvu
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
    unsigned char font[256][8] = { /* Definice bitových map znaků */ };
    
    unsigned char* char_map = font[(unsigned char)c];  // Získej bitmapu znaku
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (char_map[i] & (1 << j)) {
                put_pixel(x + j, y + i, color);
            }
        }
    }
}

// Funkce pro vykreslení textu (řetězce)
void put_string(int x, int y, const char* str, unsigned char color) {
    while (*str) {
        put_char(x, y, *str, color);
        str++;
        x += 8;  // Posun na další znak
    }
}

// Funkce pro vykreslení desktopu
void draw_desktop() {
    for (int y = SCREEN_HEIGHT - 20; y < SCREEN_HEIGHT; y++) {
        for (int x = 0; x < SCREEN_WIDTH; x++) {
            put_pixel(x, y, 0x1F);  // Barva pozadí (modro-zelená)
        }
    }
}
