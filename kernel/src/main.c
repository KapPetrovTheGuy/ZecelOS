/*
 * main.c - C entry point
 * Author(s) - Kap Petrov, amrix
 */

#include <vga.h>

// This is just for fun lol
static void Flags(void)
{
	for (int i = 0; i < 8; i++)
		PutChar(' ', i, 0, White, White);
	for (int i = 0; i < 8; i++)
		PutChar(' ', i, 1, Blue, Blue);
	for (int i = 0; i < 8; i++)
		PutChar(' ', i, 2, Red, Red);
	
	for (int i = 8; i < 11; i++)
		PutChar(' ', i, 0, White, White);
	PutChar(' ', 11, 0, Red, Red);
	PutChar(' ', 12, 0, Red, Red);
	for (int i = 13; i < 16; i++)
		PutChar(' ', i, 0, White, White);
	for (int i = 8; i < 16; i++)
		PutChar(' ', i, 1, Red, Red);
	for (int i = 8; i < 11; i++)
        PutChar(' ', i, 2, White, White);
    PutChar(' ', 11, 2, Red, Red);
	PutChar(' ', 12, 2, Red, Red);
    for (int i = 13; i < 16; i++)
        PutChar(' ', i, 2, White, White);
}

void CEntry(void) 
{
	EnableCursor();
	Flags();
	
	while (1)
		asm volatile("hlt");
}
