/*
 * main.c - C entry point
 * Author(s) - Kap Petrov, amrix
 */

#include <vga.h>
#include <idt.h>
#include <isr.h>

void CEntry(void) 
{
	InitVga();
	
EnableCursor();
	PutStr("ZecelOS Kernel\n\n");

	InstallIdt();
	InstallIsr();

	while (1)
		asm volatile("hlt");
}
