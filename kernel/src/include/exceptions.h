/*
 * exceptions.h - Functions/ISRS For Exceptions (interrupts 0-31 in the IDT)
 * Author(s) - KapPetrov
 */

#pragma once

#include <idt.h>
#include <console.h>
#include <vga.h>

__attribute__ ((interrupt)) void DivBy0Handler(IntFrame32T *frame)
{
    Clear(4);
	//PutISRExceptionStr("DIVIDE BY 0 ERROR - EXCEPTION HANDLED\r\n", 4);

    asm volatile("hlt");

    frame->eip++;
}