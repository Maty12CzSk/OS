// input.h

#ifndef INPUT_H
#define INPUT_H

extern int cursor_x;
extern int cursor_y;

void move_cursor(int dx, int dy);
int key_pressed(char key);

#endif
