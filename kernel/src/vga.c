/* 
 * vga.c - Very minimal text mode driver
 * Author(s) - amrix
 */

#include <vga.h>
#include <ports.h>
#include <c/string.h>
#include <stdint.h>

#define VGA_ADDRESS 0xb8000

static VgaColor bg = Black, fg = White;
static uint8_t cursorX = 0, cursorY = 0;

void SetColors(VgaColor _bg, VgaColor _fg)
{
	fg = _fg;
	bg = _bg;
}

void MoveCursor(uint8_t x, uint8_t y)
{
	outb(0x3d4, 14);
	outb(0x3d5, (y * 80 + x) >> 8);
	outb(0x3d4, 15);
	outb(0x3d5, y * 80 + x);

	cursorX = x;
	cursorY = y;
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

void BasicPutChar(char c, uint8_t x, uint8_t y)
{
	volatile uint16_t *where = 
		(volatile uint16_t *)VGA_ADDRESS + (y * 80 + x);
	*where = c | (((bg << 4) | (fg & 0x0f)) << 8);
}

void BasicPutStr(const char *str, uint8_t x, uint8_t y)
{
	for (int i = 0; i < StrLength(str); i++)
		BasicPutChar(str[i], x + i, y);
}

void PutChar(char c)
{
	switch (c) {
		case '\n':
			if (cursorY > TEXTMODE_HEIGHT)
				; // TODO
			else {
				cursorY++;
				cursorX = 0;
			}
			break;
		case '\r':
			cursorX = 0;	
			break;
		case '\t':
			cursorX += 4;
			break;
		default:
            if (cursorX == TEXTMODE_WIDTH) {
				cursorY++;
				cursorX = 0;
			}

			BasicPutChar(c, cursorX++, cursorY);
    		break;
	}

	MoveCursor(cursorX, cursorY);
}

void PutStr(const char *str)
{
	for (int i = 0; i < StrLength(str); i++)
		PutChar(str[i]);
}
