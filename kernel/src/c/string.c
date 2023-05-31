/*
 * string.c -
 * Author(s) - OSDev Wiki, Kap Petrov, amrix
 */

#include <c/string.h>
#include <stdint.h>

void *MemSet(void *dst, char c, uint32_t n) 
{
	char *temp = dst;
	for (; n != 0; n--) *temp++ = c;
	return dst;
}

void *MemCopy(void *dst, const void *src, uint32_t n) 
{
	char *ret = dst;
	char *p = dst;
	const char *q = src;

	while (n--)
		*p++ = *q++;
    
	return ret;
}

int MemCompare(uint8_t *s1, uint8_t *s2, uint32_t n) 
{
    while (n--) {
    	if (*s1 != *s2)
			return 0;
		s1++;
		s2++;
	}

	return 1;
}

int StrLength(const char *s) 
{
	int len = 0;
    
	while (*s++)
		len++;
    
	return len;
}

int StrCompare(const char *s1, char *s2) 
{
	int i = 0;

	while ((s1[i] == s2[i]))
		if (s2[i++] == 0)
			return 0;

	return 1;
}

int StrCopy(char *dst, const char *src) 
{
	int i = 0;
    
	while ((*dst++ = *src++) != 0)
		i++;
    
	return i;
}

void StrConcat(char *dest, const char *src) 
{
	char *end = (char *)dest + StrLength(dest);
	MemCopy((void *)end, (void *)src, StrLength(src));
	end = end + StrLength(src);
	*end = '\0';
}

/* Better implementations could be found

int isspace(char c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r';
}

void itoa(char *buf, int base, int d) {
    char *p = buf;
    char *p1, *p2;
    unsigned long ud = d;
    int divisor = 10;

    if (base == 'd' && d < 0) {
        *p++ = '-';
        buf++;
        ud = -d;
    } else if (base == 'x')
        divisor = 16;
    do {
        int remainder = ud % divisor;
        *p++ = (remainder < 10) ? remainder + '0' : remainder + 'a' - 10;
    } while (ud /= divisor);

    *p = 0;

    p1 = buf;
    p2 = p - 1;
    while (p1 < p2) {
        char tmp = *p1;
        *p1 = *p2;
        *p2 = tmp;
        p1++;
        p2--;
    }
}*/
