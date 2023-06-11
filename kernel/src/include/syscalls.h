/*
 * syscalls.h - Syscall handler/dispatcher and system call functions
 * Author(s) - KapPetrov
 */

#pragma once

#include <console.h>

#define MAX_SYSCALLS        2



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

// Syscalls table

void *syscalls[MAX_SYSCALLS] = {
    SyscallTest0,
    SyscallTest1
};

__attribute__ ((naked)) void SyscallDispatcher(void)
{
     __asm__ __volatile__ (".intel_syntax noprefix\n"

                          ".equ MAX_SYSCALLS, 2\n"

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