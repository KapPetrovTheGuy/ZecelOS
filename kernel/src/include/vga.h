#ifndef VGA_H
#define VGA_H

#include <stdint.h>

typedef enum {
	Black = 0,
	Blue,
	Green,
	Cyan,
	Red,
	Magenta, 
	Brown,
	LightGray,
	DarkGray,
	LightBlue,
	LightGreen,
	LightCyan,
	LightRed,
	LightMagenta,
	Yellow,
	White
} VgaColor;

static VgaColor fg = White, bg = Black;

void SetColors(VgaColor fg, VgaColor bg);
void MoveCursor(uint8_t x, uint8_t y);
void EnableCursor(void);
void DisableCursor(void);
uint16_t GetCursorPosition(void);
void VgaPutChar(char c, uint8_t x, uint8_t y);
void VgaPutStr(char *str, uint8_t x, uint8_t y);

#endif
