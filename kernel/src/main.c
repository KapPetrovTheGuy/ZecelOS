/*
 * main.c - C entry point
 * Author(s) - Kap Petrov, amrix
 */

#include <vga.h>
#include <font.h>
#include <idt.h>
#include <isr.h>

void CEntry(void) 
{
	InitVga();
	
	InstallIdt();
	InstallIsr();

	PutChar('T', 10, 10, Red, Black);

	while (1)
		asm volatile("hlt");
}
