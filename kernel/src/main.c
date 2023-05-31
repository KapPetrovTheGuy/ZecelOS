/*
 * main.c - C entry point
 * Author(s) - Kap Petrov, amrix
 */

#include <vga.h>

void CEntry(void) 
{
	EnableCursor();
	PutStr("ZecelOS Kernel\n\n");

	while (1)
		asm volatile("hlt");
}
