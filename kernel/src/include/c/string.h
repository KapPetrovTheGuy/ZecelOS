#ifndef STRING_H
#define STRING_H

#include <stdint.h>

void *MemSet(void *dst, char c, uint32_t n);
void *MemCopy(void *dst, const void *src, uint32_t n);
int MemCompare(uint8_t *s1, uint8_t *s2, uint32_t n);
int StrLength(const char *s);
int StrCompare(const char *s1, char *s2);
int StrCopy(char *dst, const char *src);
void StrConcat(char *dest, const char *src);
void uint32ToString(uint32_t number, char* buffer, unsigned int bufferSize);

#endif
