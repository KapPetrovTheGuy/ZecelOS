/* 
 * vga.c - Simple VGA graphics driver
 * Author(s) - amrix, pritamzope
 * Based on manuals and available source
 */

#include <vga.h>
#include <ports.h>
#include <stdint.h>

uint8_t *vgaBuffer = (uint8_t *)0xa0000;

static uint8_t seqData[5] = {
	0x03, 0x01, 0x0f, 0x00, 0x0e
};
static uint8_t crtcData[25] = {
	0x5F, 0x4F, 0x50, 0x82, 0x54, 
	0x80, 0xBF, 0x1F, 0x00, 0x41, 
	0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x9C, 0x0E, 0x8F, 0x28,
	0x40, 0x96, 0xB9, 0xA3, 0xFF
};
static uint8_t gcData[9] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 
	0x40, 0x05, 0x0F, 0xFF
};
static uint8_t acData[21] = {
	0x00, 0x01, 0x02, 0x03, 0x04, 
	0x05, 0x06, 0x07, 0x08, 0x09, 
	0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 
	0x0F, 0x41, 0x00, 0x0F, 0x00,
	0x00	
};

void Clear(VgaColor color)
{
	for(uint32_t i = 0; i < VGA_MAX; i++)
    	vgaBuffer[i] = color;
}

void PutPixel(VgaColor color, uint16_t x, uint16_t y)
{
	vgaBuffer[VGA_WIDTH * y + x] = color;
}

void InitVga(void)
{
	outb(VGA_MISC_WRITE, 0x63);

	// Sequencer
	for (uint8_t i = 0; i < 5; i++) {
		outb(VGA_SEQ_INDEX, i);
		outb(VGA_SEQ_DATA, seqData[i]);
	}

	// CRT Controller
	for (uint8_t i = 0; i < 25; i++) {
		outb(VGA_CRTC_INDEX, i);
		outb(VGA_CRTC_DATA, crtcData[i]);
	}

	// Set Graphics Controller
	for (uint8_t i = 0; i < 9; i++) {
		outb(VGA_GC_INDEX, i);
		outb(VGA_GC_DATA, gcData[i]);
	}

	// Set Attribute Controller
	for (uint8_t i = 0; i < 21; i++) {
		outb(VGA_AC_INDEX, i);
		outb(VGA_AC_WRITE, acData[i]);
	}

	outb(VGA_AC_INDEX, inb(VGA_INSTAT_READ) | 0x20);

	Clear(BLACK);
}
