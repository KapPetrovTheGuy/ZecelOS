#ifndef FONT_H
#define FONT_H

#include <vga.h>
#include <stdint.h>

#define FONT_DIM 8

// Toshiba 8x8 font
static const uint8_t fontData[2048] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x7e, 0x81, 0xa5, 0x81, 0xbd, 0x99, 0x81, 0x7e,
	0x7e, 0xff, 0xdb, 0xff, 0xc3, 0xe7, 0xff, 0x7e,
	0x44, 0xee, 0xfe, 0xfe, 0x7c, 0x7c, 0x38, 0x10,
	0x10, 0x38, 0x7c, 0xfe, 0xfe, 0x7c, 0x38, 0x10,
	0x38, 0x38, 0x10, 0xd6, 0xfe, 0xd6, 0x10, 0x38,
	0x10, 0x38, 0x7c, 0xfe, 0xfe, 0xd6, 0x10, 0x38,
	0x00, 0x00, 0x18, 0x3c, 0x3c, 0x18, 0x00, 0x00,
	0xff, 0xff, 0xe7, 0xc3, 0xc3, 0xe7, 0xff, 0xff,
	0x00, 0x3c, 0x66, 0x42, 0x42, 0x66, 0x3c, 0x00,
	0xff, 0xc3, 0x99, 0xbd, 0xbd, 0x99, 0xc3, 0xff,
	0x1e, 0x06, 0x0a, 0x72, 0x88, 0x88, 0x88, 0x70,
	0x38, 0x44, 0x44, 0x44, 0x38, 0x10, 0x7c, 0x10,
	0x18, 0x1c, 0x16, 0x12, 0x12, 0x74, 0xf0, 0xe0,
	0x30, 0x2e, 0x32, 0x2e, 0x62, 0xe6, 0xce, 0x0c,
	0x92, 0x54, 0x38, 0xc6, 0x44, 0x38, 0x54, 0x92,
	0x80, 0xe0, 0xf8, 0xfe, 0xf8, 0xe0, 0x80, 0x00,
	0x02, 0x0e, 0x3e, 0xfe, 0x3e, 0x0e, 0x02, 0x00,
	0x10, 0x38, 0x54, 0x10, 0x10, 0x54, 0x38, 0x10,
	0x24, 0x24, 0x24, 0x24, 0x24, 0x00, 0x24, 0x00,
	0x7f, 0x92, 0x92, 0x72, 0x12, 0x12, 0x12, 0x00,
	0x38, 0x44, 0x70, 0x8e, 0xe2, 0x1c, 0x44, 0x38,
	0x00, 0x00, 0x00, 0x00, 0x7e, 0x7e, 0x7e, 0x00,
	0x10, 0x38, 0x54, 0x10, 0x54, 0x38, 0x10, 0xff,
	0x10, 0x38, 0x54, 0x10, 0x10, 0x10, 0x10, 0x00,
	0x10, 0x10, 0x10, 0x10, 0x54, 0x38, 0x10, 0x00,
	0x00, 0x08, 0x04, 0xfe, 0x04, 0x08, 0x00, 0x00,
	0x00, 0x20, 0x40, 0xfe, 0x40, 0x20, 0x00, 0x00,
	0x00, 0x00, 0x40, 0x40, 0x40, 0x7e, 0x00, 0x00,
	0x00, 0x24, 0x42, 0xff, 0x42, 0x24, 0x00, 0x00,
	0x10, 0x10, 0x38, 0x38, 0x7c, 0x7c, 0xfe, 0x00,
	0xfe, 0x7c, 0x7c, 0x38, 0x38, 0x10, 0x10, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x10, 0x38, 0x38, 0x10, 0x10, 0x00, 0x10, 0x00,
	0x24, 0x24, 0x24, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x24, 0x7e, 0x24, 0x24, 0x7e, 0x24, 0x24, 0x00,
	0x10, 0x7e, 0x82, 0x70, 0x0c, 0x82, 0xfc, 0x10,
	0x61, 0x92, 0x94, 0x68, 0x16, 0x29, 0x49, 0x86,
	0x30, 0x48, 0x28, 0x52, 0x8a, 0x84, 0x7a, 0x00,
	0x10, 0x10, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x08, 0x10, 0x20, 0x20, 0x20, 0x10, 0x08, 0x00,
	0x20, 0x10, 0x08, 0x08, 0x08, 0x10, 0x20, 0x00,
	0x00, 0x66, 0x3c, 0xff, 0x3c, 0x66, 0x00, 0x00,
	0x00, 0x10, 0x10, 0x7c, 0x10, 0x10, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x10, 0x20,
	0x00, 0x00, 0x00, 0x7e, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x10, 0x00,
	0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x00,
	0x3c, 0x46, 0x4a, 0x52, 0x62, 0x42, 0x3c, 0x00,
	0x18, 0x28, 0x48, 0x08, 0x08, 0x08, 0x7e, 0x00,
	0x3c, 0x42, 0x02, 0x0c, 0x30, 0x42, 0x7e, 0x00,
	0x3c, 0x42, 0x02, 0x1c, 0x02, 0x42, 0x3c, 0x00,
	0x18, 0x28, 0x48, 0x88, 0xfe, 0x08, 0x1c, 0x00,
	0x7e, 0x40, 0x40, 0x7c, 0x02, 0x42, 0x3c, 0x00,
	0x1c, 0x22, 0x40, 0x7c, 0x42, 0x42, 0x3c, 0x00,
	0x7e, 0x02, 0x04, 0x08, 0x08, 0x10, 0x10, 0x00,
	0x3c, 0x42, 0x42, 0x3c, 0x42, 0x42, 0x3c, 0x00,
	0x3c, 0x42, 0x42, 0x3e, 0x02, 0x44, 0x38, 0x00,
	0x00, 0x10, 0x10, 0x00, 0x00, 0x10, 0x10, 0x00,
	0x00, 0x10, 0x10, 0x00, 0x00, 0x10, 0x10, 0x20,
	0x04, 0x08, 0x10, 0x20, 0x10, 0x08, 0x04, 0x00,
	0x00, 0x00, 0x7e, 0x00, 0x7e, 0x00, 0x00, 0x00,
	0x40, 0x20, 0x10, 0x08, 0x10, 0x20, 0x40, 0x00,
	0x78, 0x84, 0x04, 0x18, 0x20, 0x00, 0x20, 0x00,
	0x3c, 0x42, 0x9e, 0xa2, 0xa2, 0x9e, 0x40, 0x3c,
	0x70, 0x28, 0x28, 0x44, 0x7c, 0x82, 0xc6, 0x00,
	0xfc, 0x42, 0x42, 0x7c, 0x42, 0x42, 0xfc, 0x00,
	0x3e, 0x42, 0x80, 0x80, 0x82, 0x44, 0x38, 0x00,
	0xf8, 0x44, 0x42, 0x42, 0x42, 0x44, 0xf8, 0x00,
	0x7e, 0x22, 0x20, 0x3c, 0x20, 0x22, 0x7e, 0x00,
	0xfe, 0x42, 0x40, 0x7c, 0x40, 0x40, 0xf0, 0x00,
	0x3e, 0x42, 0x80, 0x9e, 0x82, 0x42, 0x3e, 0x00,
	0xe6, 0x42, 0x42, 0x7e, 0x42, 0x42, 0xe6, 0x00,
	0x7c, 0x10, 0x10, 0x10, 0x10, 0x10, 0x7c, 0x00,
	0x1e, 0x04, 0x04, 0x04, 0x84, 0x88, 0x70, 0x00,
	0xee, 0x44, 0x48, 0x70, 0x48, 0x44, 0xee, 0x00,
	0xf0, 0x40, 0x40, 0x40, 0x42, 0x42, 0xfe, 0x00,
	0x82, 0xc6, 0xaa, 0xaa, 0x92, 0x82, 0xc6, 0x00,
	0xc6, 0x62, 0x52, 0x4a, 0x4a, 0x46, 0xe2, 0x00,
	0x38, 0x44, 0x82, 0x82, 0x82, 0x44, 0x38, 0x00,
	0xfc, 0x42, 0x42, 0x7c, 0x40, 0x40, 0xf0, 0x00,
	0x38, 0x44, 0x82, 0x82, 0xa2, 0x94, 0x78, 0x06,
	0xfc, 0x42, 0x42, 0x7c, 0x44, 0x42, 0xe6, 0x00,
	0x3e, 0x42, 0x40, 0x3c, 0x02, 0x42, 0x7c, 0x00,
	0xfe, 0x92, 0x92, 0x10, 0x10, 0x10, 0x7c, 0x00,
	0xe6, 0x42, 0x42, 0x42, 0x42, 0x44, 0x38, 0x00,
	0xc6, 0x82, 0x44, 0x44, 0x28, 0x28, 0x10, 0x00,
	0xc6, 0x82, 0x92, 0x92, 0x54, 0x6c, 0x44, 0x00,
	0xc6, 0x44, 0x28, 0x10, 0x28, 0x44, 0xc6, 0x00,
	0xc6, 0x82, 0x44, 0x28, 0x10, 0x10, 0x38, 0x00,
	0x7e, 0x44, 0x08, 0x10, 0x20, 0x42, 0x7e, 0x00,
	0x3c, 0x20, 0x20, 0x20, 0x20, 0x20, 0x3c, 0x00,
	0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x00,
	0x78, 0x08, 0x08, 0x08, 0x08, 0x08, 0x78, 0x00,
	0x10, 0x28, 0x44, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff,
	0x10, 0x10, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0xf8, 0x04, 0x7c, 0x84, 0xfa, 0x00,
	0xc0, 0x40, 0x5c, 0x62, 0x42, 0x42, 0xbc, 0x00,
	0x00, 0x00, 0x7e, 0x82, 0x80, 0x82, 0x7c, 0x00,
	0x0c, 0x04, 0x74, 0x8c, 0x84, 0x84, 0x7a, 0x00,
	0x00, 0x00, 0x7c, 0x82, 0xfe, 0x80, 0x7c, 0x00,
	0x0e, 0x10, 0x7e, 0x10, 0x10, 0x10, 0x7c, 0x00,
	0x00, 0x00, 0x7a, 0x84, 0x8c, 0x74, 0x04, 0x78,
	0xc0, 0x40, 0x5c, 0x62, 0x42, 0x42, 0xc6, 0x00,
	0x18, 0x00, 0x38, 0x08, 0x08, 0x08, 0x7e, 0x00,
	0x0c, 0x00, 0x1c, 0x04, 0x04, 0x84, 0x88, 0x70,
	0xc0, 0x40, 0x46, 0x48, 0x70, 0x48, 0xc6, 0x00,
	0x38, 0x08, 0x08, 0x08, 0x08, 0x08, 0x7e, 0x00,
	0x00, 0x00, 0xac, 0xd2, 0x92, 0x92, 0xd6, 0x00,
	0x00, 0x00, 0xdc, 0x62, 0x42, 0x42, 0xe6, 0x00,
	0x00, 0x00, 0x7c, 0x82, 0x82, 0x82, 0x7c, 0x00,
	0x00, 0x00, 0xbc, 0x42, 0x62, 0x5c, 0x40, 0xf0,
	0x00, 0x00, 0x7a, 0x84, 0x8c, 0x74, 0x04, 0x1e,
	0x00, 0x00, 0x6e, 0x32, 0x20, 0x20, 0x78, 0x00,
	0x00, 0x00, 0x7c, 0x80, 0x7c, 0x02, 0xfc, 0x00,
	0x20, 0x20, 0xfc, 0x20, 0x20, 0x20, 0x1c, 0x00,
	0x00, 0x00, 0xc6, 0x42, 0x42, 0x46, 0x3a, 0x00,
	0x00, 0x00, 0xc6, 0x82, 0x44, 0x28, 0x10, 0x00,
	0x00, 0x00, 0xc6, 0x92, 0x92, 0xaa, 0x44, 0x00,
	0x00, 0x00, 0xc6, 0x28, 0x10, 0x28, 0xc6, 0x00,
	0x00, 0x00, 0xc6, 0x42, 0x24, 0x14, 0x08, 0x30,
	0x00, 0x00, 0x7e, 0x44, 0x18, 0x22, 0x7e, 0x00,
	0x0c, 0x10, 0x10, 0x60, 0x10, 0x10, 0x0c, 0x00,
	0x10, 0x10, 0x10, 0x00, 0x10, 0x10, 0x10, 0x00,
	0x60, 0x10, 0x10, 0x0c, 0x10, 0x10, 0x60, 0x00,
	0x32, 0x4c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x10, 0x28, 0x28, 0x44, 0x82, 0xfe, 0x00,
	0x7e, 0x82, 0x80, 0x80, 0x82, 0x7c, 0x08, 0x70,
	0x6c, 0x00, 0xc6, 0x42, 0x42, 0x46, 0x3a, 0x00,
	0x18, 0x60, 0x00, 0x7c, 0x82, 0xfe, 0x80, 0x7c,
	0x10, 0x6c, 0x00, 0xf8, 0x04, 0x7c, 0x84, 0xfa,
	0x6c, 0x00, 0xf8, 0x04, 0x7c, 0x84, 0xfa, 0x00,
	0x60, 0x18, 0x00, 0xf8, 0x04, 0x7c, 0x84, 0xfa,
	0x30, 0x48, 0x30, 0xf8, 0x04, 0x7c, 0x84, 0xfa,
	0x00, 0x7e, 0x82, 0x80, 0x82, 0x7c, 0x08, 0x70,
	0x10, 0x6c, 0x00, 0x7c, 0x82, 0xfe, 0x80, 0x7c,
	0x6c, 0x00, 0x7c, 0x82, 0xfe, 0x80, 0x7c, 0x00,
	0x60, 0x18, 0x00, 0x7c, 0x82, 0xfe, 0x80, 0x7c,
	0x6c, 0x00, 0x38, 0x08, 0x08, 0x08, 0x7e, 0x00,
	0x10, 0x6c, 0x00, 0x38, 0x08, 0x08, 0x7e, 0x00,
	0x30, 0x0c, 0x00, 0x38, 0x08, 0x08, 0x7e, 0x00,
	0x6c, 0x00, 0x38, 0x28, 0x44, 0x7c, 0x82, 0xc6,
	0x30, 0x48, 0x30, 0x28, 0x44, 0x7c, 0x82, 0xc6,
	0x0c, 0x30, 0x00, 0xfe, 0x42, 0x78, 0x42, 0xfe,
	0x00, 0x00, 0xec, 0x12, 0x7e, 0x90, 0xee, 0x00,
	0x1e, 0x2a, 0x28, 0x4e, 0x78, 0x8a, 0xce, 0x00,
	0x10, 0x6c, 0x00, 0x7c, 0x82, 0x82, 0x7c, 0x00,
	0x6c, 0x00, 0x7c, 0x82, 0x82, 0x82, 0x7c, 0x00,
	0x60, 0x18, 0x00, 0x7c, 0x82, 0x82, 0x7c, 0x00,
	0x10, 0x6c, 0x00, 0xc6, 0x42, 0x46, 0x3a, 0x00,
	0x30, 0x0c, 0x00, 0xc6, 0x42, 0x46, 0x3a, 0x00,
	0x6c, 0x00, 0x00, 0xc6, 0x42, 0x34, 0x08, 0x30,
	0x6c, 0x00, 0x7c, 0x82, 0x82, 0x82, 0x82, 0x7c,
	0x6c, 0x00, 0xe6, 0x42, 0x42, 0x42, 0x44, 0x38,
	0x00, 0x10, 0x7e, 0x82, 0x80, 0x82, 0x7c, 0x10,
	0x38, 0x44, 0x40, 0xf8, 0x40, 0x42, 0xbc, 0x00,
	0xc6, 0x44, 0x28, 0xee, 0x10, 0xfe, 0x10, 0x00,
	0xe0, 0x94, 0x9e, 0x94, 0xe4, 0x84, 0x86, 0x00,
	0x0e, 0x12, 0x10, 0x7e, 0x10, 0x10, 0x90, 0xe0,
	0x18, 0x60, 0x00, 0xf8, 0x04, 0x7c, 0x84, 0xfa,
	0x18, 0x60, 0x00, 0x38, 0x08, 0x08, 0x7e, 0x00,
	0x18, 0x60, 0x00, 0x7c, 0x82, 0x82, 0x7c, 0x00,
	0x18, 0x60, 0x00, 0xc6, 0x42, 0x46, 0x3a, 0x00,
	0x32, 0x4c, 0x00, 0xbc, 0x42, 0x42, 0xe6, 0x00,
	0x32, 0x4c, 0x00, 0xe6, 0x52, 0x4a, 0x46, 0xe2,
	0x00, 0xf8, 0x04, 0x7c, 0x84, 0xfa, 0x00, 0xfe,
	0x00, 0x00, 0x7c, 0x82, 0x82, 0x7c, 0x00, 0xfe,
	0x00, 0x30, 0x00, 0x10, 0x60, 0x82, 0x82, 0x7c,
	0x00, 0x00, 0x7e, 0x40, 0x40, 0x40, 0x00, 0x00,
	0x00, 0x00, 0xfc, 0x04, 0x04, 0x04, 0x00, 0x00,
	0xc2, 0x44, 0x48, 0x56, 0x29, 0x42, 0x84, 0x0f,
	0xc2, 0x44, 0x48, 0x56, 0x2a, 0x52, 0x9f, 0x02,
	0x00, 0x10, 0x00, 0x10, 0x10, 0x38, 0x38, 0x10,
	0x00, 0x12, 0x24, 0x48, 0x24, 0x12, 0x00, 0x00,
	0x00, 0x48, 0x24, 0x12, 0x24, 0x48, 0x00, 0x00,
	0x22, 0x88, 0x22, 0x88, 0x22, 0x88, 0x22, 0x88,
	0x55, 0xaa, 0x55, 0xaa, 0x55, 0xaa, 0x55, 0xaa,
	0xdb, 0x77, 0xdb, 0xee, 0xdb, 0x77, 0xdb, 0xee,
	0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
	0x10, 0x10, 0x10, 0x10, 0xf0, 0x10, 0x10, 0x10,
	0x10, 0x10, 0xf0, 0x10, 0xf0, 0x10, 0x10, 0x10,
	0x14, 0x14, 0x14, 0x14, 0xf4, 0x14, 0x14, 0x14,
	0x00, 0x00, 0x00, 0x00, 0xfc, 0x14, 0x14, 0x14,
	0x00, 0x00, 0xf0, 0x10, 0xf0, 0x10, 0x10, 0x10,
	0x14, 0x14, 0xf4, 0x04, 0xf4, 0x14, 0x14, 0x14,
	0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14,
	0x00, 0x00, 0xfc, 0x04, 0xf4, 0x14, 0x14, 0x14,
	0x14, 0x14, 0xf4, 0x04, 0xfc, 0x00, 0x00, 0x00,
	0x14, 0x14, 0x14, 0x14, 0xfc, 0x00, 0x00, 0x00,
	0x10, 0x10, 0xf0, 0x10, 0xf0, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0xf0, 0x10, 0x10, 0x10,
	0x10, 0x10, 0x10, 0x10, 0x1f, 0x00, 0x00, 0x00,
	0x10, 0x10, 0x10, 0x10, 0xff, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0xff, 0x10, 0x10, 0x10,
	0x10, 0x10, 0x10, 0x10, 0x1f, 0x10, 0x10, 0x10,
	0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00,
	0x10, 0x10, 0x10, 0x10, 0xff, 0x10, 0x10, 0x10,
	0x10, 0x10, 0x1f, 0x10, 0x1f, 0x10, 0x10, 0x10,
	0x14, 0x14, 0x14, 0x14, 0x17, 0x14, 0x14, 0x14,
	0x14, 0x14, 0x17, 0x10, 0x1f, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x1f, 0x10, 0x17, 0x14, 0x14, 0x14,
	0x14, 0x14, 0xf7, 0x00, 0xff, 0x00, 0x00, 0x00,
	0x00, 0x00, 0xff, 0x00, 0xf7, 0x14, 0x14, 0x14,
	0x14, 0x14, 0x17, 0x10, 0x17, 0x14, 0x14, 0x14,
	0x00, 0x00, 0xff, 0x00, 0xff, 0x00, 0x00, 0x00,
	0x14, 0x14, 0xf7, 0x00, 0xf7, 0x14, 0x14, 0x14,
	0x10, 0x10, 0xff, 0x00, 0xff, 0x00, 0x00, 0x00,
	0x14, 0x14, 0x14, 0x14, 0xff, 0x00, 0x00, 0x00,
	0x00, 0x00, 0xff, 0x00, 0xff, 0x10, 0x10, 0x10,
	0x00, 0x00, 0x00, 0x00, 0xff, 0x14, 0x14, 0x14,
	0x14, 0x14, 0x14, 0x14, 0x1f, 0x00, 0x00, 0x00,
	0x10, 0x10, 0x1f, 0x10, 0x1f, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x1f, 0x10, 0x1f, 0x10, 0x10, 0x10,
	0x00, 0x00, 0x00, 0x00, 0x1f, 0x14, 0x14, 0x14,
	0x14, 0x14, 0x14, 0x14, 0xff, 0x14, 0x14, 0x14,
	0x10, 0x10, 0xff, 0x10, 0xff, 0x10, 0x10, 0x10,
	0x10, 0x10, 0x10, 0x10, 0xf0, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x1f, 0x10, 0x10, 0x10,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
	0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0,
	0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,
	0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x62, 0x94, 0x88, 0x94, 0x62, 0x00,
	0x3c, 0x42, 0x42, 0x5c, 0x42, 0x42, 0x5c, 0x40,
	0xfe, 0x42, 0x42, 0x40, 0x40, 0x40, 0xf0, 0x00,
	0x00, 0x00, 0x7e, 0xa4, 0x24, 0x24, 0x46, 0x00,
	0xfe, 0x42, 0x20, 0x10, 0x20, 0x42, 0xfe, 0x00,
	0x00, 0x00, 0x7e, 0x88, 0x84, 0x84, 0x78, 0x00,
	0x00, 0xcc, 0x44, 0x44, 0x64, 0x5a, 0x40, 0x00,
	0x00, 0x00, 0x66, 0x98, 0x10, 0x10, 0x10, 0x10,
	0x7c, 0x10, 0x38, 0x44, 0x44, 0x38, 0x10, 0x7c,
	0x3c, 0x42, 0x42, 0x7e, 0x42, 0x42, 0x3c, 0x00,
	0x38, 0x44, 0x82, 0x82, 0x44, 0x28, 0xee, 0x00,
	0x1c, 0x20, 0x10, 0x3c, 0x42, 0x42, 0x3c, 0x00,
	0x00, 0x44, 0xaa, 0x92, 0xaa, 0x44, 0x00, 0x00,
	0x00, 0x02, 0x7c, 0x8a, 0x92, 0xa2, 0x7c, 0x80,
	0x1e, 0x20, 0x40, 0x7e, 0x40, 0x20, 0x1e, 0x00,
	0x18, 0x24, 0x42, 0x42, 0x42, 0x42, 0x42, 0x00,
	0x00, 0x7e, 0x00, 0x7e, 0x00, 0x7e, 0x00, 0x00,
	0x10, 0x10, 0x7c, 0x10, 0x10, 0x00, 0x7c, 0x00,
	0x60, 0x18, 0x06, 0x18, 0x60, 0x00, 0x7e, 0x00,
	0x06, 0x18, 0x60, 0x18, 0x06, 0x00, 0x7e, 0x00,
	0x06, 0x0a, 0x08, 0x10, 0x10, 0x10, 0x10, 0x10,
	0x10, 0x10, 0x10, 0x10, 0x10, 0x20, 0xa0, 0xc0,
	0x18, 0x00, 0x00, 0x7e, 0x00, 0x00, 0x18, 0x00,
	0x00, 0x32, 0x4c, 0x00, 0x32, 0x4c, 0x00, 0x00,
	0x18, 0x24, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00,
	0x0f, 0x08, 0x08, 0x10, 0x90, 0x50, 0x20, 0x00,
	0x50, 0x68, 0x48, 0x48, 0x48, 0x00, 0x00, 0x00,
	0x30, 0x48, 0x10, 0x20, 0x78, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x3c, 0x3c, 0x3c, 0x3c, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

void BasicPutChar(char c, uint16_t x, uint16_t y, VgaColor fg, VgaColor bg);

#endif
