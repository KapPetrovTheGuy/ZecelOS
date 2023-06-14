/*
 * console.c - A simple console
 * Author(s) - amrix
 */

#include <console.h>
#include <font.h>
#include <vga.h>
#include <c/string.h>
#include <stdbool.h>


static uint16_t cursorX = 0, cursorY = 0;

void InitBgColor() {
	bg = mColor;
}

void reverseStr(char *str, int length)
{
    int start = 0;
    int end = length - 1;
    
    while (start < end)
    {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

void intToStr(int num, char *str, int size)
{
    int i = 0;
    int isNegative = 0;
    
    // Handle negative numbers
    if (num < 0)
    {
        isNegative = 1;
        num = -num;
    }
    
    // Convert each digit to a character in reverse order
    do
    {
        str[i++] = num % 10 + '0';
        num /= 10;
    } while (num > 0 && i < size - 1);
    
    // Add the negative sign if necessary
    if (isNegative)
    {
        str[i++] = '-';
    }
    
    // Reverse the string
    reverseStr(str, i);
    
    // Null-terminate the string
    str[i] = '\0';
}

void PutChar(char c)
{
	InitBgColor();

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

void PutISRExceptionStr(const char* str, uint8_t isrcolor)
{
	for (int i = 0; i < StrLength(str); i++)
		ISRPutChar(str[i], isrcolor);
}

void ISRPutChar(char c, uint8_t isrcolor)
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

			BasicPutChar(c, cursorX, cursorY, fg, isrcolor);
			cursorX += FONT_DIM;
			break;
	}
}

void BootPutChar(char c, uint8_t isrcolor, uint16_t x, uint16_t y)
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

			BasicPutChar(c, cursorX, cursorY, fg, isrcolor);
			cursorX += FONT_DIM;
			cursorY = 0;
			break;
	}
}

void ResetCur(void)
{
	cursorX = 0;
	cursorY = 0;
}

void BootString(const char* str, uint16_t x, uint16_t y)
{
	for (int i = 0; i < StrLength(str); i++)
		BootPutChar(str[i], 0, x, y);
	
}