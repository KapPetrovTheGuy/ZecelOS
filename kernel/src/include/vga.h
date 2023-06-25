#ifndef VGA_H
#define VGA_H

#include <stdint.h>

#define VGA_MAX    0xf9ff
#define VGA_WIDTH  320
#define VGA_HEIGHT 200

// Attribute Controller Registers
#define	VGA_AC_INDEX 0x3c0
#define	VGA_AC_READ  0x3c1
#define	VGA_AC_WRITE 0x3c0

// Miscellaneous Output
#define	VGA_MISC_READ  0x3cc
#define	VGA_MISC_WRITE 0x3c2

// Sequencer Registers
#define VGA_SEQ_INDEX 0x3c4
#define VGA_SEQ_DATA  0x3c5

// VGA Color Palette Registers
#define	VGA_DAC_READ_INDEX  0x3c7
#define	VGA_DAC_WRITE_INDEX 0x3c8
#define	VGA_DAC_DATA        0x3c9

// Graphics Controller Registers
#define VGA_GC_INDEX 0x3ce
#define VGA_GC_DATA  0x3cf

// CRT Controller Registers
#define VGA_CRTC_INDEX 0x3d4
#define VGA_CRTC_DATA  0x3d5

// General Control and Status Registers
#define	VGA_INSTAT_READ 0x3da

void PutPixel(uint8_t color, uint16_t x, uint16_t y);
void Clear(uint8_t color);
void InitVga(void);

#endif