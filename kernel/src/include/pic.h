/*
 * pic.h - 8259 Programmable Interrupt Controller Definitions & Functions
 * Author(s) - KapPetrov
 */

#pragma once

#include <stdint.h>
#include <ports.h>
#include <console.h>

#define PIC_1_CMD			0x20
#define PIC_1_DATA			0x21

#define PIC_2_CMD			0xA0
#define PIC_2_DATA			0xA1

#define NEW_IRQ_0			0x20
#define NEW_IRQ_8			0x28

#define PIC_EOI				0x20

void SendPICEOI(uint8_t irq)
{
	if (irq >= 8)
		outb(PIC_2_CMD, PIC_EOI);
	outb(PIC_1_CMD, PIC_EOI);
}

void DisablePIC()
{
	outb(PIC_2_DATA, 0xFF);
	outb(PIC_1_DATA, 0xFF);

	PutStr("PIC Disabled\r\n");
}

void SetIRQMask(uint8_t irq)
{
	uint16_t port;
	uint8_t value;

	if (irq < 8)
		port = PIC_1_DATA;
	else
		irq -= 8;
		port = PIC_2_DATA;

	value = inb(port) | (1 << irq);
	outb(port, value);
	
}

void ClearIRQMask(uint8_t irq)
{
	uint16_t port;
	uint8_t value;

	if (irq < 8)
		port = PIC_1_DATA;
	else
		irq -= 8;
		port = PIC_2_DATA;

	value = inb(port) | ~(1 << irq);
	outb(port, value);
	
}

void RemapPIC(void)
{
	uint8_t PIC1Mask, PIC2Mask;

	PIC1Mask = inb(PIC_1_DATA);
	PIC2Mask = inb(PIC_2_DATA);

	outb(PIC_1_CMD, 0x11);
	ioWait();
	outb(PIC_2_CMD, 0x11);
	ioWait();

	outb(PIC_1_DATA, NEW_IRQ_0);
	ioWait();
	outb(PIC_2_DATA, NEW_IRQ_8);
	ioWait();

	outb(PIC_1_DATA, 0x4);
	ioWait();
	outb(PIC_2_DATA, 0x2);
	ioWait();

	outb(PIC_1_DATA, 0x1);
	ioWait();
	outb(PIC_2_DATA, 0x1);
	ioWait();

	outb(PIC_1_DATA, PIC1Mask);
	outb(PIC_2_DATA, PIC2Mask);

	PutStr("PIC Remapped\r\n");
}