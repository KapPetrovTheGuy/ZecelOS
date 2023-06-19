/*
 * keyboard.h - Basic Keyboard Driver
 * Author(s) - KapPetrov
 */

#include <stdint.h>
#include <stdbool.h>
#include <pic.h>
#include <console.h>
#include <vga.h>

uint16_t cX = 0;
uint16_t cY = 0;

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

__attribute__ ((interrupt)) void KeyboardIRQ1Handler(IntFrame32T *frame)
{
    uint8_t scancode = inb(0x60); // Read the scancode from the keyboard controller

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
    }

    else if (scancode == 0x48) // Up arrow key
    {
        cY -= 10;
    }

    else if (scancode == 0x50) // Down arrow key
    {
        cY += 10;
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
        }
    }

    SendPICEOI(1);
}