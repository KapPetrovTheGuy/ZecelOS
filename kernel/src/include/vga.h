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

void InitVga(void);

#endif
