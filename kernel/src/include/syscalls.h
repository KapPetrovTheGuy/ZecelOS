/*
 * syscalls.h - Syscall handler/dispatcher and system call functions
 * Author(s) - KapPetrov
 */

#pragma once

#include <console.h>
#include <stdint.h>

#define MAX_SYSCALLS        3
#define IRQ0_SLEEP_TIMER_TICKS_AREA				0x1700



// Test syscall 0
void SyscallTest0(void)
{
    PutStr("SYSCALL TEST 0\r\n");
}
// Test syscall 1
void SyscallTest1(void)
{
    PutStr("SYSCALL TEST 1\r\n");
}

// INPUTS:
// EBX = NUMBER OF MILLISECONDS TO SLEEP

void SyscallSleep(void)
{
     uint32_t *sleepTimerTicks = (uint32_t *)IRQ0_SLEEP_TIMER_TICKS_AREA;

     __asm__ __volatile__ ("movl %%ebx, %0" : "=r"(*sleepTimerTicks) );

     while (*sleepTimerTicks > 0) __asm__ __volatile__ ("sti;hlt;cli");
     
}

// Syscalls table

void *syscalls[MAX_SYSCALLS] = {
    SyscallTest0,
    SyscallTest1,
    SyscallSleep
};

__attribute__ ((naked)) void SyscallDispatcher(void)
{
     __asm__ __volatile__ (".intel_syntax noprefix\n"

                          ".equ MAX_SYSCALLS, 3\n"

                          "cmp eax, MAX_SYSCALLS-1\n"  
                          "ja invalid_syscall\n"        

                          "push eax\n"
                          "push gs\n"
                          "push fs\n"
                          "push es\n"
                          "push ds\n"
                          "push ebp\n"
                          "push edi\n"
                          "push esi\n"
                          "push edx\n"
                          "push ecx\n"
                          "push ebx\n"
                          "push esp\n"
                          "call [syscalls+eax*4]\n"
                          "add esp, 4\n"
                          "pop ebx\n"
                          "pop ecx\n"
                          "pop edx\n"
                          "pop esi\n"
                          "pop edi\n"
                          "pop ebp\n"
                          "pop ds\n"
                          "pop es\n"
                          "pop fs\n"
                          "pop gs\n"
                          "add esp, 4\n"    
                          "iretd\n"         

                          "invalid_syscall:\n"
                          "iretd\n"

                          ".att_syntax");
}