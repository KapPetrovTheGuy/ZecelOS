#ifndef IDT_H
#define IDT_H

#include <stdint.h>

typedef struct {
	uint16_t baseLow;
	uint16_t sel;
	uint8_t always0;
	uint8_t flags;
	uint16_t baseHigh;
} IdtEntry;

typedef struct {
	uint16_t limit;
	uint32_t base;
} IdtPointer;

extern IdtEntry idt[256];

void SetIdtGate(uint8_t n, uint32_t base, uint16_t sel, uint8_t flags);
void InstallIdt(void);

#endif
