#ifndef VGA_H
#define VGA_H

#include <stdint.h>

#define VGA_MAX 0xf9ff
#define VGA_WIDTH 320
#define VGA_HEIGHT 200

// Attribute Controller Registers
#define	VGA_AC_INDEX 0x3C0
#define	VGA_AC_READ 0x3C1
#define	VGA_AC_WRITE 0x3C0

// Miscellaneous Output
#define	VGA_MISC_READ 0x3CC
#define	VGA_MISC_WRITE 0x3C2

// Sequencer Registers
#define VGA_SEQ_INDEX 0x3C4
#define VGA_SEQ_DATA 0x3C5

// VGA Color Palette Registers
#define	VGA_DAC_READ_INDEX 0x3C7
#define	VGA_DAC_WRITE_INDEX 0x3C8
#define	VGA_DAC_DATA 0x3C9

// Graphics Controller Registers
#define VGA_GC_INDEX 0x3CE
#define VGA_GC_DATA 0x3CF

// CRT Controller Registers
#define VGA_CRTC_INDEX 0x3D4
#define VGA_CRTC_DATA 0x3D5

// General Control and Status Registers
#define	VGA_INSTAT_READ 0x3DA

typedef enum {
    Black = 0,
    Blue,
    Green,
    Cyan,
    Red,
    Magenta,
    Brown,
    LightGray,
    DarkGray,
    LightBlue,
    LightGreen,
    LightCyan,
    LightRed,
    LightMagenta,
    Yellow,
    White
} VgaColor;

void InitVga(void);
void PutPixel(VgaColor color, uint16_t x, uint16_t y);

#endif
