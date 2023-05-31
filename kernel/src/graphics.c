#include <graphics.h>

/*
 * graphics.c - Graphics For GUI
 * Author(s) - KapPetrov
 */

void Pixel(VgaColor color, int x, int y)
{
    SetColors(color, bg);
    VgaPutChar(' ', x, y);
}
