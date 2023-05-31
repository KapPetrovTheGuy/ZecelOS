#include "hal.h"
#include <gdt.h>

void HAL_Initialize()
{
    i686_GDT_Initialize();
}