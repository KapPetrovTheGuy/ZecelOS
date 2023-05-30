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

void MoveCursor(uint8_t x, uint8_t y);
void EnableCursor(void);
void DisableCursor(void);
uint16_t GetCursorPosition(void);
void PutChar(char c, uint8_t x, uint8_t y, VgaColor fg, VgaColor bg);

#endif
