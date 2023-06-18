/*
 * idt.h - Data types and setup for the Interrupt Descriptor Table or IDT
 * Author(s) - KapPetrov
 */

#pragma once

#include <stdint.h>
#include <console.h>
#include <c/string.h>

#define TRAP_GATE_FLAGS			0x8F
#define INT_GATE_FLAGS			0x8E
#define INT_GATE_USER_FLAGS		0xEE

typedef struct {
	uint16_t isrAddressLow;
	uint16_t kernelCs;
	uint8_t reserved;
	uint8_t attributes;
	uint16_t isrAddressHigh;
}__attribute__((packed)) IdtEntry32T;

typedef struct {
	uint16_t limit;
	uint32_t base;
}__attribute__((packed)) Idtr32T;

IdtEntry32T idt32[256];
Idtr32T idtr32;

typedef struct {
	uint32_t eip;
	uint32_t cs;
	uint32_t eflags;
	uint32_t esp;
	uint32_t sp;
	uint32_t ss;
}__attribute__((packed)) IntFrame32T;

__attribute__ ((interrupt)) void DefaultExcpHandler(IntFrame32T *intFrame32)
{
	PutStr("DEFAULT_EXCEPTION_HANDLER-NO ERROR CODE\r\n");
}

__attribute__ ((interrupt)) void DefaultExcpHandlerErrCode(IntFrame32T *IntFrame32, uint32_t errorcode)
{
	PutStr("DEFAULT_EXCEPTION_HANDLER - ERROR CODE: \r\n");

	uint32_t number = errorcode;
	char buffer[20]; // Make sure the buffer is large enough to hold the string representation

	uint32ToString(number, buffer, sizeof(buffer));

	PutStr(buffer);
	PutStr("\r\n");
}

__attribute__ ((interrupt)) void DefaultIntHandler(IntFrame32T *IntFrame32)
{
	
}

void SetIDTDescriptor32(uint8_t entryNumber, void *isr, uint8_t flags)
{
	IdtEntry32T *descriptor = &idt32[entryNumber];

	descriptor->isrAddressLow 			= (uint32_t)isr & 0xFFFF;
	descriptor->kernelCs				= 0x08;
	descriptor->reserved				= 0;
	descriptor->attributes				= flags;
	descriptor->isrAddressHigh			= ((uint32_t)isr >> 16) & 0xFFFF;
}

void InitIdt32(void)
{
	idtr32.limit = (uint16_t)(8*256);
	idtr32.base = (uint32_t)&idt32[0];

	for(uint8_t entry = 0; entry < 32; entry++) {

		// really basic way of doing this, not the best way. But it works for now.

		if(entry == 8 || entry == 10 || entry == 11 || entry == 12 || entry == 13 || entry == 14 || entry == 17 || entry == 21)
		{
			// Exception takes an error code
			SetIDTDescriptor32(entry, DefaultExcpHandlerErrCode, TRAP_GATE_FLAGS);
		} else
		{
			// Exception does not take an error code
			SetIDTDescriptor32(entry, DefaultExcpHandler, TRAP_GATE_FLAGS);
		}
		
	}

	for(uint16_t entry = 32; entry < 256; entry++) {
		SetIDTDescriptor32(entry, DefaultIntHandler, INT_GATE_FLAGS);
	}

	__asm__ volatile ("lidt %0" : : "memory"(idtr32));
    //__asm__ volatile ("sti");
}