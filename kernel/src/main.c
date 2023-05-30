/*
 * main.c - C entry point
 * Author(s) - Kap Petrov, amrix
 */

#include <vga.h>

void CEntry(void) 
{
	EnableCursor();

	PutStr("Test string!", 0, 0);

	while (1)
		asm volatile("hlt");
}
