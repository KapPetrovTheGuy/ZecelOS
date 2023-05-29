#ifndef CONSOLE_H
#define CONSOLE_H

#include "vga.h" //including our vga.

#define MAXIMUM_PAGES   16

#define SCROLL_UP       1
#define SCROLL_DOWN     2

//clearing the console (cls/clear)
void console_clear(VGA_COLOR_TYPE fore_color, VGA_COLOR_TYPE back_color);

//init the console
void console_init(VGA_COLOR_TYPE fore_color, VGA_COLOR_TYPE back_color);
void console_scroll(int line_count);
void console_putchar(char ch);

//revert back the printed character and add 0 to it
void console_ungetchar();
//revert back the printed character untill n characters
void console_ungetchar_bound(uint8 n);

void console_gotoxy(uint16 x, uint16 y);

//output a string
void console_putstr(const char *str);
//our lovely printf :)
void printf(const char *format, ...);

#endif
