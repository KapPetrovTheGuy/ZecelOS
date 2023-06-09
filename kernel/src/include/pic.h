/*
 * pic.h - 8259 Programmable Interrupt Controller Definitions & Functions
 * Author(s) - KapPetrov
 */

#pragma once

#include <stdint.h>
#include <ports.h>
#include <console.h>
#include <idt.h>
#include <c/string.h>
#include <stdbool.h>
#include <stddef.h>
#include <vga.h>

#define PIC_1_CMD								0x20
#define PIC_1_DATA								0x21

#define PIC_2_CMD								0xA0
#define PIC_2_DATA								0xA1

#define NEW_IRQ_0								0x20
#define NEW_IRQ_8								0x28

#define PIC_EOI									0x20

#define IRQ0_SLEEP_TIMER_TICKS_AREA				0x1700
#define RTC_DATETIME_AREA						0x1610

#define BUFFER_SIZE 10000
#define MAX_COLS 999

void SendPICEOI(uint8_t irq)
{
	if (irq >= 8) outb(PIC_2_CMD, PIC_EOI);

	outb(PIC_1_CMD, PIC_EOI);
}

void DisablePIC()
{
	outb(PIC_2_DATA, 0xFF);
	outb(PIC_1_DATA, 0xFF);
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
}

static volatile uint32_t ticks = 0;

void SleepMilliseconds(uint32_t milliseconds)
{
    uint32_t start_ticks = ticks;
    while ((ticks - start_ticks) < milliseconds)
    {
        __asm__ __volatile__ ("hlt");
    }
}

void SleepSeconds(uint16_t seconds)
{
    SleepMilliseconds(seconds * 1000);
}

__attribute__ ((interrupt)) void TimerIRQ0Handler(IntFrame32T *frame)
{
    ticks++;

	SendPICEOI(0);
}

void SetPITChannelModeFrequency(const uint8_t channel, const uint8_t operatingMode, const uint16_t freq)
{
	if (channel > 2 || operatingMode > 7) return;
	
	__asm__ __volatile__ ("cli");

	outb(0x43, (channel << 6) | (0x3 << 4) | (operatingMode << 1));

	outb(0x40 + channel, (uint8_t)freq);
	outb(0x40 + channel, (uint8_t)(freq >> 8));

	__asm__ __volatile__ ("sti");
}

uint8_t ReadCMOS(uint8_t reg)
{
    // Set the CMOS address register
    outb(0x70, reg);
    // Read the data from the CMOS data register
    return inb(0x71);
}

uint8_t BCDToDecimal(uint8_t bcd)
{
    return (bcd >> 4) * 10 + (bcd & 0x0F);
}

void ReadRTC(uint8_t* year, uint8_t* month, uint8_t* day, uint8_t* hour, uint8_t* minute, uint8_t* second)
{
    // Disable interrupts to prevent time inconsistency
    __asm__ __volatile__ ("cli");

    // Wait until the RTC is not updating
    while (ReadCMOS(0x0A) & 0x80);

    // Read the time values from the CMOS RTC registers
    uint8_t year_bcd = ReadCMOS(0x09);
    uint8_t month_bcd = ReadCMOS(0x08);
    uint8_t day_bcd = ReadCMOS(0x07);
    uint8_t hour_bcd = ReadCMOS(0x04);
    uint8_t minute_bcd = ReadCMOS(0x02);
    uint8_t second_bcd = ReadCMOS(0x00);

    // Convert BCD values to decimal
    *year = BCDToDecimal(year_bcd);
    *month = BCDToDecimal(month_bcd);
    *day = BCDToDecimal(day_bcd);
    *hour = BCDToDecimal(hour_bcd);
    *minute = BCDToDecimal(minute_bcd);
    *second = BCDToDecimal(second_bcd);

    // Enable interrupts
    __asm__ __volatile__ ("sti");
}