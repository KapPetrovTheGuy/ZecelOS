/* 
 * vga.c - Simple VGA graphics driver
 * Author(s) - amrix
 */

#include <vga.h>
#include <ports.h>
#include <stdint.h>

uint8_t *vgaBuffer = (uint8_t *)0xa0000;

void InitVga(void)
{

}
