/*
 * main.c - C entry point
 * Author(s) - Kap Petrov, amrix
 */

#include <vga.h>
#include <console.h>
#include <gdt.h>
#include <idt.h>
#include <isr.h>

void CEntry(void) 
{
	InitVga();

	InstallGdt();	
	InstallIdt();
	InstallIsr();

	//char *a = 0;
	//*a = 10;

	while (1)
		asm volatile("hlt");
}
