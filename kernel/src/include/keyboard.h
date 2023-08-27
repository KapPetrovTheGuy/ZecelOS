/*
 * keyboard.h - Basic Keyboard Driver
 * Author(s) - KapPetrov
 */

#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <stdint.h>
#include <stdbool.h>
#include <pic.h>
#include <console.h>
#include <vga.h>
#include <c/string.h>
#include <graphics.h>
#include <programs/TextEditor.h>
#include <c/math.h>

#define MAX_COMMAND_LENGTH       100

static uint16_t cX = 0;
static uint16_t cY = 0;

bool cmd = true;

char scancodeToChar[] = {
    '\0', '\0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', '\0',
    '\t', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n', '\0',
    'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`', '\0', '\\', 'z',
    'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', '\0', '\0', '\0', ' ', '\0', '\0',
    '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0',
    '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0',
    '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0',
    '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0',

	[0x1B] = '!',
    [0x29] = '`'
};

bool shiftPressed = false;

char displayBuffer[BUFFER_SIZE];
uint16_t bufferIndex = 0;

char commandBuffer[MAX_COMMAND_LENGTH];
uint16_t commandIndex = 0;

static uint8_t scancode;

void execCmd(const char* command)
{
    // Print the contents of the display buffer
    PutStrXY(displayBuffer, cX, cY);

    // Clear the display buffer and reset the buffer index
    MemSet(displayBuffer, 0, sizeof(displayBuffer));
    bufferIndex = 0;

    if(StrCompare(command, "help") == 0)
    {
        PutStrXY("Commands:", cX, cY);

		cX = 0;
		cY += 10;

		PutStrXY("shutdown-Turns off the computer", cX, cY);

        cX = 0;
        cY += 10;

		PutStrXY("reboot - Restarts the computer.", cX, cY);

		cX = 0;
        cY += 10;

        cX = 0;
        cY += 10;
        cX = 0;
    }

    else if(StrCompare(command, "eg") == 0)
    {
        PutStrXY("YOU FOUND AN EASTER EGG!!!!!!!! BALLLER!!!!", cX, cY);

        cX = 0;
        cY += 10;

        cX = 0;
        cY += 10;
        cX = 0;
    }

	else if (StrCompare(command, "shutdown") == 0)
    {
        outb(0x604, 0x2000); // QEMU's default I/O port for ACPI shutdown

		while (true)
		{
			Clear(0);
			asm("hlt");
		}
    }

	else if (StrCompare(command, "reboot") == 0)
    {
        // Send the ACPI reboot signal to QEMU
        outb(0x64, 0xfe);
    }

    else if (StrCompare(command, "bored") == 0)
    {
        cmd = false;

        Clear(mColor);
        Rectangle(1, 0, 0, 100, 100);
        Rectangle(2, 100, 0, 100, 100);
        Rectangle(4, 200, 0, 100, 100);

        BoredFace();

        Rectangle(0, 0, 190, 10, 10);

        Rectangle(0, 0, 100, 10, 10);

    }

	// else if (StrCompare(command, "texteditor") == 0)
    // {
    //     TextEditor(scancode, cX, cY, shiftPressed, scancodeToChar, commandIndex, commandBuffer, cmd);
    // }

	else {
		PutStrXY("Invalid command!", cX, cY);
		cX = 0;
        cY += 10;

        cX = 0;
        cY += 10;
        cX = 0;
	}
}

__attribute__ ((interrupt)) void KeyboardIRQ1Handler(IntFrame32T *frame)
{
    if(cmd)
    {
		scancode = inb(0x60);

        if (scancode == 0x2A) // Shift pressed
        {
            shiftPressed = true;
        }
        else if (scancode == 0xAA) // Shift released
        {
            shiftPressed = false;
        }

        else if (scancode == 0x1C) // Enter key
        {
            cX = 0;
            cY += 10;
            cX = 0;

            // Null-terminate the command buffer
            commandBuffer[commandIndex] = '\0';

            // Execute the command
            execCmd(commandBuffer);

            // Clear the command buffer
            MemSet(commandBuffer, 0, sizeof(commandBuffer));
            commandIndex = 0;
        }

        else if (scancode == 0x4D) // Right arrow key
        {
            cX += 10;
        }

        else if (scancode == 0x4B) // Left arrow key
        {
            cX -= 10;
        }

        else if (scancode == 0x0E) // Backspace key
        {
            if (cX > 0)
            {
                cX -= 10; // Move cursor back 10 columns
                PutCharXY(' ', cX, cY); // Print a space to erase the previous character
            }
            else if (cY > 0)
            {
                cY -= 10; // Move cursor up to the previous line
                cX = MAX_COLS - 1; // Set cursor to the last column of the previous line
            }

            if (commandIndex > 0)
            {
                commandIndex--;
                commandBuffer[commandIndex] = '\0';
            }
        }

        if (scancode < sizeof(scancodeToChar))
        {
            char character = scancodeToChar[scancode];

            if (shiftPressed)
            {
                // Handle Shifted characters
                switch (character)
                {
                    case '1':
                        character = '!';
                        break;

                    case '/':
                        character = '?';
                        break;

                    case 'a':
                        character = 'A';
                        break;

                    case 'b':
                        character = 'B';
                        break;

                    case 'c':
                        character = 'C';
                        break;

                    case 'd':
                        character = 'D';
                        break;

                    case 'e':
                        character = 'E';
                        break;

                    case 'f':
                        character = 'F';
                        break;

                    case 'g':
                        character = 'G';
                        break;

                    case 'h':
                        character = 'H';
                        break;

                    case 'i':
                        character = 'I';
                        break;

                    case 'j':
                        character = 'J';
                        break;

                    case 'k':
                        character = 'K';
                        break;

                    case 'l':
                        character = 'L';
                        break;

                    case 'm':
                        character = 'M';
                        break;

                    case 'n':
                        character = 'N';
                        break;

                    case 'o':
                        character = 'O';
                        break;

                    case 'p':
                        character = 'P';
                        break;

                    case 'q':
                        character = 'Q';
                        break;

                    case 'r':
                        character = 'R';
                        break;

                    case 's':
                        character = 'S';
                        break;

                    case 'v':
                        character = 'V';
                        break;

                    case 'w':
                        character = 'W';
                        break;

                    case 'x':
                        character = 'X';
                        break;

                    case 'y':
                        character = 'Y';
                        break;

                    case 'z':
                        character = 'Z';
                        break;

                    case 't':
                        character = 'T';
                        break;

                    case 'u':
                        character = 'U';
                        break;

                    case ';':
                        character = ':';
                        break;

                    case '2':
                        character = '@';
                        break;

                    case '3':
                        character = '#';
                        break;

                    case '4':
                        character = '$';
                        break;

                    case '5':
                        character = '%';
                        break;

                    case '6':
                        character = '^';
                        break;

                    case '7':
                        character = '&';
                        break;

                    case '8':
                        character = '*';
                        break;

                    case '9':
                        character = '(';
                        break;

                    case '0':
                        character = ')';
                        break;

                    case '`':
                        character = '~';
                        break;

                    case ',':
                        character = '<';
                        break;

                    case '.':
                        character = '>';
                        break;

                    case '=':
                        character = '+';
                        break;

                    case '-':
                        character = '_';
                        break;
                }
            }

            if (character != '\0')
            {
                // Handle line wrapping
                if (cX >= MAX_COLS)
                {
                    cX = 0;
                    cY += 10;
                }

                // Output the character to the display
                PutCharXY(character, cX, cY);

                // Update cursor position
                cX+= 10;

                if (commandIndex < MAX_COMMAND_LENGTH - 1)
                {
                    commandBuffer[commandIndex] = character;
                    commandIndex++;
                }
            }
        }
    }

    SendPICEOI(1);
}

#endif