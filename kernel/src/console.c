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

void SetCur(uint16_t x, uint16_t y)
{
	cursorX = x;
	cursorY = y;
}

void PutDec(uint32_t number)
{
    if (number == 0) {
        PutChar('0');
        return;
    }

    char buffer[10];  // Assuming maximum 10-digit number
    int i = 0;

    while (number > 0) {
        buffer[i++] = '0' + (number % 10);
        number /= 10;
    }

    while (i > 0) {
        PutChar(buffer[--i]);
    }
}

void ClearLine(uint16_t line)
{
    // Calculate the starting position of the line
    uint16_t startX = 0;
    uint16_t startY = line * FONT_DIM;

    // Clear each character on the line by printing spaces
    for (uint16_t x = startX; x < VGA_WIDTH; x += FONT_DIM)
    {
        // Set the cursor position
        SetCur(x, startY);
        
        // Print a space character to clear the position
        PutChar(' ');
    }
}

void PrintTime(uint8_t hour, uint8_t minute, uint8_t second, uint8_t day, uint8_t month, uint8_t year)
{
    // Determine if it is AM or PM based on the hour
    const char* ampm = (hour < 12) ? "AM" : "PM";

    // Convert hour to 12-hour format if necessary
    if (hour > 12)
        hour -= 12;

    // Print the formatted time with AM/PM indicator
    PutDec(hour);
    PutChar(':');
    if (minute < 10)
        PutChar('0');
    PutDec(minute);
    PutChar(':');
    if (second < 10)
        PutChar('0');
    PutDec(second);
    PutChar(' ');
    PutStr(ampm);
    PutChar('\n');

    // Print the formatted date
    PutStr("Date: ");
    PutDec(year);
    PutChar('-');
    PutDec(month);
    PutChar('-');
    PutDec(day);
    PutChar('\n');
}
