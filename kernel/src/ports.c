/*
 * ports.c - IO Ports
 * Author(s) - Kap Petrov, amrix
 */

#include <ports.h>
#include <stdint.h>

uint8_t inb(uint16_t port)
{
	uint8_t ret = 0;
	asm volatile("inb %1, %0" : "=a"(ret) : "Nd"(port));
	return ret;
}

void outb(uint16_t port, uint8_t data)
{
	asm volatile("outb %0, %1" : : "a"(data), "Nd"(port));
}

void ioWait(void)
{
	__asm__ __volatile__ ("outb %%al, $0x80" : : "a"(0) );
}