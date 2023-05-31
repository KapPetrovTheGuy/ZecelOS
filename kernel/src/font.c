/*
 * font.c - Write text using bitmap font
 * Author(s) - amrix, spacerace(provided the font)
 */

#include <font.h>
#include <vga.h>
#include <stdint.h>

void PutChar(char c, uint16_t x, uint16_t y, VgaColor fg, VgaColor bg)
{
	int mask[8] = {1, 2, 4, 8, 16, 32, 64, 128};
	uint8_t *glyph = (uint8_t *)(fontData + (int)c * 8);

	for (uint16_t fx = 0; fx < 8; fx++)
		for (uint32_t fy = 0; fy < 8; fy++) {
			PutPixel(glyph[fy] & mask[fx] ? fg : bg, x + fx, y + fy);
		}
}
