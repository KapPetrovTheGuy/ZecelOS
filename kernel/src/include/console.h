#ifndef CONSOLE_H
#define CONSOLE_H

#include <stdint.h>

static const uint8_t mColor = 10;

static uint8_t fg = 63, bg;

void PutChar(char c);
void PutCharXY(char c, uint16_t x, uint16_t y);
void PutStrXY(const char *str, uint16_t x, uint16_t y);
void PutStr(const char *str);
void PutISRExceptionStr(const char* str, uint8_t isrcolor);
void ISRPutChar(char c, uint8_t isrcolor);
void ResetCur(void);
void SetCur(uint16_t x, uint16_t y);
void SetCurX(uint16_t x);
void ClearLine(uint16_t line);

void intToStr(int num, char *str, int size);

void PutDec(uint32_t number);
void PutHex(uint32_t value);

#endif