// graphics.h

#ifndef GRAPHICS_H
#define GRAPHICS_H

#define SCREEN_WIDTH  320
#define SCREEN_HEIGHT 200

void put_pixel(int x, int y, unsigned char color);
void draw_button(int x, int y, const char* text);
void clear_screen(unsigned char color); // ← Přidáno

#endif
