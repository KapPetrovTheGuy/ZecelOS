/*
 * pc_speaker.h - A Simple PC Speaker Driver
 * Author(s) - KapPetrov
 */

#pragma once

#include <ports.h>

#include <stdint.h>
#include <stdbool.h>

#define SPEAKER_PORT 0x61 // Port address for PC speaker control

void PlaySound(uint32_t frequency)
{
    uint32_t divisor = 1193180 / frequency;
    
    // Set the PIT (Programmable Interval Timer) to the desired frequency
    outb(0x43, 0xB6); // Command port: Channel 2, High/Low bytes, Square wave
    outb(0x42, divisor & 0xFF); // Data port: Low byte
    outb(0x42, (divisor >> 8) & 0xFF); // Data port: High byte
    
    // Enable the PC speaker by setting the corresponding bit in the control port
    uint8_t speakerControl = inb(SPEAKER_PORT);
    speakerControl |= 0x03; // Set bits 0 and 1
    outb(SPEAKER_PORT, speakerControl);
}

void StopSound()
{
    // Disable the PC speaker by clearing the corresponding bit in the control port
    uint8_t speakerControl = inb(SPEAKER_PORT);
    speakerControl &= 0xFC; // Clear bits 0 and 1
    outb(SPEAKER_PORT, speakerControl);
}