#ifndef CONSOLE_H
#define CONSOLE_H

#include <stdint.h>

static const uint8_t mColor = 1;

static uint8_t fg = 63, bg;

void PutChar(char c);
void PutStr(const char *str);
void PutISRExceptionStr(const char* str, uint8_t isrcolor);
void ISRPutChar(char c, uint8_t isrcolor);

#endif
