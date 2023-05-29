#ifndef VGA_H
#define VGA_H

#include "types.h"

#define VGA_ADDRESS 0xB8000
#define VGA_TOTAL_ITEMS 2200

#define VGA_WIDTH 800
#define VGA_HEIGHT 600

typedef enum {
    COLOR_BLACK,
    COLOR_BLUE,
    COLOR_GREEN,
    COLOR_CYAN,
    COLOR_RED,
    COLOR_MAGENTA,
    COLOR_BROWN,
    COLOR_GREY,
    COLOR_DARK_GREY,
    COLOR_BRIGHT_BLUE,
    COLOR_BRIGHT_GREEN,
    COLOR_BRIGHT_CYAN,
    COLOR_BRIGHT_RED,
    COLOR_BRIGHT_MAGENTA,
    COLOR_YELLOW,
    COLOR_WHITE,
} VGA_COLOR_TYPE;

//printing a char.
uint16 vga_item_entry(uint8 ch, VGA_COLOR_TYPE fore_color, VGA_COLOR_TYPE back_color);

//setting the position of the cursor on the screen
void vga_set_cursor_pos(uint8 x, uint8 y);

//disabling the cursor
void vga_disable_cursor();

#endif
