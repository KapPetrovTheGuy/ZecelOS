/*
 * isr.c - Interrupt Service Routines
 * Author(s) - amrix
 */

#include <isr.h>
#include <idt.h>
#include <console.h>
#include <vga.h>

const char *exceptionMsgs[] = {
	"Division by zero",
	"Debug",
	"Non maskable interrupt",
	"Breakpoint",
	"Overflow",
	"Invalid opcode",
	"No coprocessor",
	"Double fault",
	"Coprocessor segment overrun",
	"Bad TSS",
	"Segment not present",
	"Stack fault",
	"General protection fault",
	"Page fault",
	"Unknown interrupt",
	"Coprocessor fault",
	"Alignment check",
	"Machine check",
	"Reserved"
};

void InstallIsr(void)
{
	PutStr("Installed ISRs\n");
}

void CFaultHandler(int interrupt)
{
	if (interrupt < 32) {
		Clear(1);
		PutStr("ISR Execption : ");
		PutStr(exceptionMsgs[interrupt]);
	}

	while (1)
		asm volatile("cli; hlt");
}
