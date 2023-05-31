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

	//InstallGdt();	
	InstallIdt();
	InstallIsr();
	
	while (1)
		asm volatile("hlt");
}
