/* 
 * vga.c - Very minimal text mode driver
 * Author(s) - amrix
 */

#include <vga.h>
#include <ports.h>
#include <c/string.h>
#include <stdint.h>

uint16_t *vgaAddress = (uint16_t *)0xb8000;

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

void Clear(void)
{
	for (int i = 0; i < 0xF9FF; i++)
		vgaAddress[i] = bg;
}

void BasicPutChar(char c, uint8_t x, uint8_t y)
{
	volatile uint16_t *where = 
		(volatile uint16_t *)vgaAddress + (y * 80 + x);
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
			if (cursorY > 25)
				Clear();
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
            if (cursorX == 80) {
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
