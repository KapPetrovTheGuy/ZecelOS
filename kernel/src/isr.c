/*
 * isr.c - Interrupt Service Routines
 * Author(s) - amrix
 */

#include <isr.h>
#include <idt.h>
#include <console.h>
#include <vga.h>

extern void Exception0();
extern void Exception1();
extern void Exception2();
extern void Exception3();
extern void Exception4();
extern void Exception5();
extern void Exception6();
extern void Exception7();
extern void Exception8();
extern void Exception9();
extern void Exception10();
extern void Exception11();
extern void Exception12();
extern void Exception13();
extern void Exception14();
extern void Exception15();
extern void Exception16();
extern void Exception17();
extern void Exception18();
extern void Exception19();

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
	SetIdtGate(0, (uint32_t)Exception0, 0x08, 0x8e);
	SetIdtGate(1, (uint32_t)Exception1, 0x08, 0x8e);
	SetIdtGate(2, (uint32_t)Exception2, 0x08, 0x8e);
	SetIdtGate(3, (uint32_t)Exception3, 0x08, 0x8e);
	SetIdtGate(4, (uint32_t)Exception4, 0x08, 0x8e);
	SetIdtGate(5, (uint32_t)Exception5, 0x08, 0x8e);
	SetIdtGate(6, (uint32_t)Exception6, 0x08, 0x8e);
    SetIdtGate(7, (uint32_t)Exception7, 0x08, 0x8e);
    SetIdtGate(8, (uint32_t)Exception8, 0x08, 0x8e);
    SetIdtGate(9, (uint32_t)Exception9, 0x08, 0x8e);
    SetIdtGate(10, (uint32_t)Exception10, 0x08, 0x8e);
    SetIdtGate(11, (uint32_t)Exception11, 0x08, 0x8e);
	SetIdtGate(12, (uint32_t)Exception12, 0x08, 0x8e);
    SetIdtGate(13, (uint32_t)Exception13, 0x08, 0x8e);
    SetIdtGate(14, (uint32_t)Exception14, 0x08, 0x8e);
    SetIdtGate(15, (uint32_t)Exception15, 0x08, 0x8e);
    SetIdtGate(16, (uint32_t)Exception16, 0x08, 0x8e);
    SetIdtGate(17, (uint32_t)Exception17, 0x08, 0x8e);
	SetIdtGate(18, (uint32_t)Exception18, 0x08, 0x8e);
    SetIdtGate(19, (uint32_t)Exception19, 0x08, 0x8e);
	
	PutStr("Installed ISRs\n");
}

void CFaultHandler(int exNo)
{
	if (exNo < 32) {
		Clear(RED);
		PutStr("ISR Execption : ");
		PutStr(exceptionMsgs[exNo]);
	}

	asm volatile("cli; hlt");
}
