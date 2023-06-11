/*
 * irq.h - Interrupt Request Handler
 * Author(s) - KapPetrov
 */

#ifndef IRQ_H
#define IRQ_H

#include <stdint.h>
#include <pic.h>

#define IRQ1        0x21
#define IRQ2        0x22

// IRQ 1 Handler (Keyboard)

void KeyboardIrqHandler(uint32_t interruptNumber);

// IRQ 2 Handler (Cascade)

void CascadeIrqHandler();

void IrqHandler(uint32_t interruptNumber);

#endif