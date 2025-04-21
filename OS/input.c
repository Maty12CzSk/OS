// input.c

#include "input.h"
#include "graphics.h"

int cursor_x = 0;
int cursor_y = 0;

void move_cursor(int dx, int dy) {
    cursor_x += dx;
    cursor_y += dy;

    if (cursor_x < 0) cursor_x = 0;
    if (cursor_y < 0) cursor_y = 0;
    if (cursor_x >= SCREEN_WIDTH)  cursor_x = SCREEN_WIDTH - 1;
    if (cursor_y >= SCREEN_HEIGHT) cursor_y = SCREEN_HEIGHT - 1;
}

int key_pressed(char key) {
    (void)key; // Zamezí warningu
    return 0;
}
