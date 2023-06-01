/*
 * idt.c - Interrupt Descriptor Table
 * Author(s) - amrix, Bran's Kernel Dev
 */

#include <idt.h>
#include <console.h>

static IdtEntry idt[256];
static IdtPointer idtPointer;

void SetIdtGate(uint8_t n, uint32_t base, uint16_t sel, uint8_t flags)
{
	idt[n].baseLow = base & 0xffff;
	idt[n].baseHigh = (base >> 16) & 0xffff;
	idt[n].sel = sel;
	idt[n].always0 = 0;
	idt[n].flags = flags;
}

void InstallIdt(void)
{
	idtPointer.limit = (sizeof(IdtEntry) * 256) - 1;
	idtPointer.base = (uint32_t)&idt;

	asm volatile("lidt %0" : : "m"(idtPointer));

	PutStr("Installed IDT\n");
}
