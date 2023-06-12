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

	Clear(mColor);

	InstallGdt();
	InitIdt32();

    //  int quotient;
    //  int remainder;
    //  int dividend = 10;
    //  int divisor = 3;

	SetIDTDescriptor32(0, DivBy0Handler, TRAP_GATE_FLAGS);
	SetIDTDescriptor32(0x80, SyscallDispatcher, INT_GATE_USER_FLAGS);
	//asm volatile("divl %0, %2" : "=a" (quotient), "=d" (remainder) : "r" (dividend), "r" (divisor));

	// tests, uncomment these lines if you want to test.
	__asm__ __volatile__ ("movl $0, %eax; int $0x80"); //syscall 0
	__asm__ __volatile__ ("movl $1, %eax; int $0x80"); // syscall 1

	__asm__ __volatile__ ("movl $2, %eax; int $0x80"); // Should do nothing at all lmao.

	DisablePIC();

	RemapPIC();

	// ClearIRQMask(0);
	// ClearIRQMask(1);

	//SetIDTDescriptor32(0x20, <TimerIRQHandler>, INT_GATE_FLAGS);
	//SetIDTDescriptor32(0x21, <KeyboardIRQHandler>, INT_GATE_FLAGS);

	__asm__ __volatile__ ("sti");

	while (1)
		asm volatile("hlt");
}
