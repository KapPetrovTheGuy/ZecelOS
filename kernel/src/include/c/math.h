#ifndef MATH_H
#define MATH_H

#include <stdint.h>

#define M_PI 3.14159265358979323846

double sin(double x) {
    double result = 0.0;
    double term = x;
    double sign = 1.0;
    double fact = 1.0;
    
    for (int i = 1; i <= 10; i++) {
        result += sign * term;
        term = term * x * x / ((2 * i) * (2 * i + 1));
        sign = -sign;
    }
    
    return result;
}

static unsigned int next = 1;

int randomint(int start, int end) {
    next = next * 1103515245 + 12345;
    unsigned int rand_num = (unsigned int)(next / 65536) % 32768;
    return start + rand_num % (end - start + 1);
}


#endif