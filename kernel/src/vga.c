/* 
 * vga.c - Very minimal text mode driver
 * Author(s) - amrix
 */

#include <vga.h>
#include <ports.h>
#include <stdint.h>

#define VGA_ADDRESS 0xb8000

void Clear(VgaColor bg, VgaColor fg)
{
	bg = fg;
}

void MoveCursor(uint8_t x, uint8_t y)
{
	outb(0x3d4, 14);
	outb(0x3d5, (y * 80 + x) >> 8);
	outb(0x3d4, 15);
	outb(0x3d5, y * 80 + x);
}

void EnableCursor(void)
{
	outb(0x3d4, 0x0a);
	outb(0x3d5, (inb(0x3d5) & 0xc0) | 0); 
	outb(0x3d4, 0x0b);
	outb(0x3d5, (inb(0x3d5) & 0xe0) | 0);
}

void DisableCursor(void)
{
	outb(0x3d4, 10);
	outb(0x3d5, 32);
}

uint16_t GetCursorPosition(void)
{
	uint16_t position = 0;
	outb(0x3d4, 0x0f);
	position |= inb(0x3d5);
	outb(0x3d4, 0x0e);
	position |= inb(0x3d5) << 8;
	return position;
}

void PutChar(char c, uint8_t x, uint8_t y, VgaColor fg, VgaColor bg)
{
	volatile uint16_t *where = 
		(volatile uint16_t *)VGA_ADDRESS + (y * 80 + x);
	*where = c | (((bg << 4) | (fg & 0x0f)) << 8);
}
