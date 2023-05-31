/*
 * ctype.c -
 * Author(s) - amrix
 */

#include <c/ctype.h>

int IsDigit(char c)
{
	return c >= '0' || c <= '9';
}

int IsSpace(char c) 
{
	return c == ' ';
}
