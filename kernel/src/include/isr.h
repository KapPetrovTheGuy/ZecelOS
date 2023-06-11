#ifndef ISR_H
#define ISR_H

#include <stdint.h>

typedef struct {
  uint32_t ds;
  uint32_t edi, esi, ebp, esp, ebx, edx, ecx, eax; 
  uint32_t intN, errN;
  uint32_t eip, cs, eflags, useresp, ss;
} Registers;

typedef void (*InterruptHandler)(void);

void InstallIsr(void);
void SetInterruptHandler(uint8_t interruptNumber, InterruptHandler handler);
void EnableInterrupt(uint8_t interruptNumber);


#endif
