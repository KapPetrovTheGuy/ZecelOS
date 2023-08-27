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
#include <keyboard.h>
#include <pc_speaker.h>

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

	PutStr("\n");

	PutISRExceptionStr("STARTING ZECEL OS... \n", 0);

	PutISRExceptionStr("STARTING ZECEL\r", 63);

	InstallGdt();
	InitIdt32();

	SetIDTDescriptor32(0, DivBy0Handler, TRAP_GATE_FLAGS);
	SetIDTDescriptor32(0x80, SyscallDispatcher, INT_GATE_USER_FLAGS);

	// tests, uncomment these lines if you want to test.
	//__asm__ __volatile__ ("movl $0, %eax; int $0x80"); //syscall 0
	//__asm__ __volatile__ ("movl $1, %eax; int $0x80"); // syscall 1

	RemapPIC();

	SetIDTDescriptor32(0x20, TimerIRQ0Handler, INT_GATE_FLAGS);

	__asm__ __volatile__ ("sti");

	SetPITChannelModeFrequency(0, 2, 1193);

	SleepSeconds(2.5);

	PutISRExceptionStr("STARTING ZECEL.\r", 63);

	SleepSeconds(2.5);

	PutISRExceptionStr("STARTING ZECEL..\r", 63);

	SleepSeconds(2.5);

	PutISRExceptionStr("STARTING ZECEL...\r", 63);

	SleepSeconds(2.5);

	PutISRExceptionStr("STARTING ZECEL....\r", 63);

	SleepSeconds(2.5);

	PutISRExceptionStr("STARTING ZECEL.....\r", 63);

	SleepSeconds(2.5);

	PutISRExceptionStr("STARTING ZECEL.....\r", 63);

	SleepSeconds(2.5);

	PutISRExceptionStr("STARTING ZECEL......\r", 63);

	SleepSeconds(2.5);

	PutISRExceptionStr("                      \r", 10);

	SleepSeconds(2.5);

	PutISRExceptionStr("                        \r", 1);

	SleepSeconds(2.5);

	PutISRExceptionStr("                        \r", 5);

	SleepSeconds(2.5);

	PutISRExceptionStr("                     ", 7);

	SleepSeconds(0);

	ResetCur();

	SetIDTDescriptor32(0x21, KeyboardIRQ1Handler, INT_GATE_FLAGS);

	ClearIRQMask(0);
	ClearIRQMask(1);

	Clear(mColor);

	PutStr("Welcome To ZecelOS!\n");

	int a = 93;

	char str[4];

	intToStr(a, str, sizeof(str));

	PutStr("Commit Version: ");
	PutStr(str);
	PutStr("\n");

	PutStr(" Type a command");
	cY += 10;
	PutStr("(press");
	cY += 10;
	PutStr(" backspace after a  new line):");

	cX = 0;
	cY = 45;

	PlaySound(493.883);
	SleepSeconds(1);
	PlaySound(440);
	SleepSeconds(1);
	PlaySound(391.995);
	SleepSeconds(1);
	PlaySound(349.228); 
	SleepSeconds(1);
	StopSound();

	while (1) {
		uint8_t year, month, day, hour, minute, second;
		ReadRTC(&year, &month, &day, &hour, &minute, &second);

		ClearLine(900); // Clear the line where the date and time are displayed
		PutStr(" ");

		PrintTime(hour, minute, second, day, month, year);

		SleepMilliseconds(1000);
	}

}
