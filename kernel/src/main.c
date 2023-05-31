/*
 * main.c - C entry point
 * Author(s) - Kap Petrov, amrix
 */

#include <vga.h>
#include <graphics.h>

void CEntry(void) 
{
	EnableCursor();

	VgaPutStr("Test string!", 10, 10);

	while (1)
		asm volatile("hlt");
}
