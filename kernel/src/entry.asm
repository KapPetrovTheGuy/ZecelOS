;;
;; entry.asm - Main entry from bootloader
;; Author(s) - Kap Petrov
;;

MBALIGN equ 1<<0
MEMINFO equ 1<<1
FLAGS equ MBALIGN | MEMINFO
MAGIC equ 0x1BADB002
CHECKSUM equ -(MAGIC + FLAGS)

section .multiboot
    align 4
    dd MAGIC
    dd FLAGS
    dd CHECKSUM

section .data
    align 4096

section .initial_stack, nobits
    align 4

stack_bottom:
    resb 104856
stack_top:

section .text
    global _start

	_start:
    	mov esp, stack_top
    	extern CEntry
    	push ebx
    	call CEntry
