/*
 * main.c - C entry point
 * Author(s) - Kap Petrov, amrix
 */

#include <vga.h>
#include <console.h>
#include <idt.h>
#include <isr.h>
#include "hal/hal.h"

void CEntry(void) 
{
	InitVga();

	HAL_Initialize();
	InstallIdt();
	InstallIsr();

	while (1)
		asm volatile("hlt");
}
