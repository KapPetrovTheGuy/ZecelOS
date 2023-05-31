/*
 * font.c - Write text using bitmap font
 * Author(s) - amrix, spacerace(provided the font)
 */

#include <font.h>
#include <vga.h>
#include <stdint.h>

void BasicPutChar(char c, uint16_t x, uint16_t y, VgaColor fg, VgaColor bg)
{
	int mask[8] = {1, 2, 4, 8, 16, 32, 64, 128};
	uint8_t *glyph = (uint8_t *)(fontData + (int)c * FONT_DIM);

	for (uint16_t fx = 0; fx < FONT_DIM; fx++)
		for (uint32_t fy = 0; fy < FONT_DIM; fy++) {
			PutPixel(glyph[fy] & mask[fx] ? fg : bg, x - fx + FONT_DIM, y + fy);
		}
}
