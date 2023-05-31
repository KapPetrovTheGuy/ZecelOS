#include "hal.h"
#include <gdt.h>
#include <console.h>

void HAL_Initialize()
{
    i686_GDT_Initialize();
    PutStr("Installed GDT \n");
}