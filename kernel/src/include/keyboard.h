/*
 * keyboard.h - Variables And Functions For A Simple Keyboard Driver
 * Author(s) - KapPetrov
 */

#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <stdint.h>

#define KEYBOARD_BUFFER_SIZE 32

void KeyboardIrqHandler(uint32_t interruptNumber);

uint8_t ReadKeyboardData(void);

int IsBufferFull(void);

int IsBufferEmpty(void);
char GetCharFromKeyboardBuffer(void);

char GetCharFromScancode(uint8_t scancode);

#endif