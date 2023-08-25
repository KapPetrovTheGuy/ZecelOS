/*
 * graphics.h - Basic Graphics Tests
 * Author(s) - KapPetrov
 */

#include <stdint.h>
#include <vga.h>
#include <console.h>

void Line(uint32_t color, uint32_t x, uint32_t y, uint32_t width, uint32_t height)
{
    for(uint32_t i = 0; i < width; i++)
    {
    	PutPixel(color, x, y);
        x++;
    }
}

void Rectangle(uint32_t color, uint32_t x, uint32_t y, uint32_t width, uint32_t height)
{

    for(uint32_t i = 0; i < height; i++)
    {
    	Line(color, x, y, width, height);
        x++;
        y++;
        x--;
    }
}

void BoredFace()
{
        PutPixel(63, 2, 0);
		PutPixel(63, 3, 0);
		PutPixel(63, 28, 0);
		PutPixel(63, 29, 0);
		PutPixel(63, 10, 10);
		PutPixel(63, 11, 10);
		PutPixel(63, 12, 10);
		PutPixel(63, 13, 10);
		PutPixel(63, 14, 10);
		PutPixel(63, 15, 10);
		PutPixel(63, 16, 10);
		PutPixel(63, 17, 10);
		PutPixel(63, 18, 10);
		PutPixel(63, 19, 10);
}