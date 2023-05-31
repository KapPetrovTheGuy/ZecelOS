#ifndef VGA_H
#define VGA_H

#include <stdint.h>

#define TEXTMODE_WIDTH 80
#define TEXTMODE_HEIGHT 25

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

void SetColors(VgaColor fg, VgaColor bg);
void MoveCursor(uint8_t x, uint8_t y);
void EnableCursor(void);
void DisableCursor(void);
void BasicPutChar(char c, uint8_t x, uint8_t y);
void BasicPutStr(const char *str, uint8_t x, uint8_t y);
void PutChar(char c);
void PutStr(const char *str);

#endif
