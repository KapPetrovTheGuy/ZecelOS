/*
 * console.c - A simple console
 * Author(s) - amrix
 */

#include <console.h>
#include <font.h>
#include <vga.h>
#include <c/string.h>

static uint16_t cursorX = 0, cursorY = 0;
static uint8_t fg = 63, bg = 0;

void PutChar(char c)
{
	switch (c) {
		case '\n':
			if (cursorY > VGA_HEIGHT)
				Clear(bg);
			else {
				cursorY += FONT_DIM;
				cursorX = 0;
			}
			break;
		case '\r':
			cursorX = 0;
			break;
		default:
			if (cursorX > VGA_WIDTH) {
				cursorY += FONT_DIM;
				cursorX = 0;
			}

			BasicPutChar(c, cursorX, cursorY, fg, bg);
			cursorX += FONT_DIM;
			break;
	}
}

void PutStr(const char *str)
{
	for (int i = 0; i < StrLength(str); i++)
		PutChar(str[i]);
}
