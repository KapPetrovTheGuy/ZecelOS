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

	PutISRExceptionStr(" __________\r\n", 0);
	PutISRExceptionStr("         _ \r\n", 0);
	PutISRExceptionStr("        _\r\n", 0);
	PutISRExceptionStr("       _\r\n", 0);
	PutISRExceptionStr("      _\r\n", 0);
	PutISRExceptionStr("     ________\r\n", 0);

	ResetCur();

	InstallGdt();
	InitIdt32();

	SetIDTDescriptor32(0, DivBy0Handler, TRAP_GATE_FLAGS);
	SetIDTDescriptor32(0x80, SyscallDispatcher, INT_GATE_USER_FLAGS);

	// tests, uncomment these lines if you want to test.
	//__asm__ __volatile__ ("movl $0, %eax; int $0x80"); //syscall 0
	//__asm__ __volatile__ ("movl $1, %eax; int $0x80"); // syscall 1

	RemapPIC();

	SetIDTDescriptor32(0x20, TimerIRQ0Handler, INT_GATE_FLAGS);
	SetIDTDescriptor32(0x21, KeyboardIRQ1Handler, INT_GATE_FLAGS);

	ClearIRQMask(0);

	__asm__ __volatile__ ("sti");

	SetPITChannelModeFrequency(0, 2, 1193);

	SleepSeconds(0);

	Clear(mColor);

	// PutStr("Welcome To ZecelOS!\n");

	// int a = 85;

	// char str[4];

	// intToStr(a, str, sizeof(str));

	// PutStr("Commit Version: ");
	// PutStr(str);
	// PutStr("\n");

	while (1) {
		uint8_t year, month, day, hour, minute, second;
		ReadRTC(&year, &month, &day, &hour, &minute, &second);

		ClearLine(5); // Clear the line where the date and time are displayed
		PutStr(" ");
		PrintTime(hour, minute, second, day, month, year);

		SleepMilliseconds(1000);
	}

}
