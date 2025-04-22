// input.h

#ifndef INPUT_H
#define INPUT_H
#define KEY_ENTER 0x1C  // typický scan code pro Enter (můžeš upravit podle svých potřeb)

extern int cursor_x;
extern int cursor_y;

void move_cursor(int dx, int dy);
int key_pressed(char key);

#endif
