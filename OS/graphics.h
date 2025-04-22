#ifndef GRAPHICS_H
#define GRAPHICS_H

// Definice šířky a výšky obrazovky
#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 200

// Deklarace framebufferu
extern unsigned char framebuffer[SCREEN_WIDTH * SCREEN_HEIGHT];

// Funkce pro vymazání obrazovky
void clear_screen(unsigned char color);

// Funkce pro vykreslení jednoho pixelu
void put_pixel(int x, int y, unsigned char color);

// Funkce pro vykreslení textu
void put_char(int x, int y, char c, unsigned char color);

// Funkce pro vykreslení desktopu
void draw_desktop();

// Deklarace pro vykreslení textu
void put_string(int x, int y, const char* str, unsigned char color);


#endif // GRAPHICS_H
