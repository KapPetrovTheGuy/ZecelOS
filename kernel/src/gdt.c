/*
 * gdt.c - Global Descriptor Table
 * Author(s) - KapPetrov, amrix
 */

#include <gdt.h>
#include <console.h>
#include <stdint.h>

#define GDT_LIMIT_LOW(limit) (limit & 0xFFFF)
#define GDT_BASE_LOW(base) (base & 0xFFFF)
#define GDT_BASE_MIDDLE(base) ((base >> 16) & 0xFF)
#define GDT_FLAG_LIMITS_HI(limit, flags) (((limit >> 16) & 0xF) | (flags & 0xF0))
#define GDT_BASE_HIGH(base) ((base >> 24) & 0xFF)

#define GDT_ENTRY(base, limit, access, flags) { \
    GDT_LIMIT_LOW(limit), \
    GDT_BASE_LOW(base), \
    GDT_BASE_MIDDLE(base), \
    access, \
    GDT_FLAG_LIMITS_HI(limit, flags), \
    GDT_BASE_HIGH(base) \
}

typedef struct {
    uint16_t limitLow;
    uint16_t baseLow;
    uint8_t baseMiddle;
    uint8_t access;
    uint8_t flagsLimitHi;
    uint8_t baseHigh;
} __attribute__((packed)) GdtEntry;

typedef struct {
    uint16_t limit;
    GdtEntry* ptr;
} __attribute__((packed)) GdtDescriptor;

typedef enum {
    GDT_ACCESS_CODE_READABLE = 0x02,
    GDT_ACCESS_DATA_WRITEABLE = 0x02,
    GDT_ACCESS_CODE_CONFORMING = 0x04,
    GDT_ACCESS_DATA_DIRECTION_NORMAL = 0x00,
    GDT_ACCESS_DATA_DIRECTION_DOWN = 0x04,
    GDT_ACCESS_DATA_SEGMENT	= 0x10,
    GDT_ACCESS_CODE_SEGMENT	= 0x18,
    GDT_ACCESS_DESCRIPTOR_TSS = 0x00,
    GDT_ACCESS_RING0 = 0x00,
    GDT_ACCESS_RING1 = 0x20,
    GDT_ACCESS_RING2 = 0x40,
    GDT_ACCESS_RING3 = 0x60,
	GDT_ACCESS_PRESENT = 0x80,
} GdtAccess;

typedef enum {
	GDT_FLAG_64_BIT = 0x20,
	GDT_FLAG_32BIT = 0x40,
	GDT_FLAG_16BIT = 0x00,
	GDT_FLAG_GRANULARITY_1B = 0x00,
	GDT_FLAG_GRANULARITY_4K	= 0x80,
} GdtFlags;

GdtEntry gdt[] = {
	// Null descriptor
	GDT_ENTRY(0, 0, 0, 0),
	// Kernel 32-Bit code segment
	GDT_ENTRY(
		0, 
		0xFFFFF, 
		GDT_ACCESS_PRESENT | 
		GDT_ACCESS_RING0 | 
		GDT_ACCESS_CODE_SEGMENT | 
		GDT_ACCESS_CODE_READABLE, 
		GDT_FLAG_32BIT | 
		GDT_FLAG_GRANULARITY_4K
	),
	// Kernel 32-Bit data segment
	GDT_ENTRY(
		0, 
		0xFFFFF, 
		GDT_ACCESS_PRESENT | 
		GDT_ACCESS_RING0 | 
		GDT_ACCESS_DATA_SEGMENT | 
		GDT_ACCESS_DATA_WRITEABLE, 
		GDT_FLAG_32BIT | 
		GDT_FLAG_GRANULARITY_4K
	)
};

GdtDescriptor gdtDescriptor = {sizeof(gdt) - 1, gdt};

void __attribute__((cdecl)) GdtLoad(GdtDescriptor* descriptor, uint16_t codeSegment, uint16_t dataSegment);

void InstallGdt(void)
{
    GdtLoad(&gdtDescriptor, i686_GDT_CODE_SEGMENT, i686_GDT_DATA_SEGMENT);
}
