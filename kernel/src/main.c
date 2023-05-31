/*
 * main.c - C entry point
 * Author(s) - Kap Petrov, amrix
 */

#include <vga.h>
#include <idt.h>

void CEntry(void) 
{
	EnableCursor();
	PutStr("ZecelOS Kernel\n\n");

	InstallIdt();

	while (1)
		asm volatile("hlt");
}
