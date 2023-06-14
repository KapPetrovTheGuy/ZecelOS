/*
 * main.c - C entry point
 * Author(s) - Kap Petrov, amrix
 */

#include <vga.h>
#include <console.h>
#include <gdt.h>
#include <idt.h>
#include <exceptions.h>
#include <syscalls.h>
#include <pic.h>

void CEntry(void) 
{
	InitVga();

	Clear(0);

	PutISRExceptionStr("Booting ZecelOS... \n", 0);

	InstallGdt();
	InitIdt32();

	SetIDTDescriptor32(0, DivBy0Handler, TRAP_GATE_FLAGS);
	SetIDTDescriptor32(0x80, SyscallDispatcher, INT_GATE_USER_FLAGS);

	// tests, uncomment these lines if you want to test.
	//__asm__ __volatile__ ("movl $0, %eax; int $0x80"); //syscall 0
	//__asm__ __volatile__ ("movl $1, %eax; int $0x80"); // syscall 1

	RemapPIC();

	SetIDTDescriptor32(0x20, TimerIRQ0Handler, INT_GATE_FLAGS);
	//SetIDTDescriptor32(0x21, <KeyboardIRQHandler>, INT_GATE_FLAGS);
	//SetIDTDescriptor32(0x28, <CmosRtcIRQ8Handler>, INT_GATE_FLAGS);

	ClearIRQMask(0);
	// ClearIRQMask(1);

	SetPITChannelModeFrequency(0, 2, 1193);

	SleepSeconds(5);

	Clear(mColor);

	PutStr("Welcome To ZecelOS!\n");

	__asm__ __volatile__ ("sti");

	while (1)
		asm volatile("hlt");
}
