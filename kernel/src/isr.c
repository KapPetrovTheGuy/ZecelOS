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
	"Alignment check"
	"Machine check",
	"Reserved"
};

void InstallIsr(void)
{
	// TODO - Finish ISR
	PutStr("Installed ISRs\n");
}

void CFaultHandler(uint8_t exN)
{
	if (exN < 32) {
		Clear(RED);
		PutStr("ISR Execption : ");
		PutStr(exceptionMsgs[exN]);
	}

	while (1)
		asm volatile("hlt");
}
