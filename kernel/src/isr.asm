;
; isr.asm - ISR exceptions
; Author(s) - amrix
;

global Exception0
global Exception1
global Exception2
global Exception3
global Exception4
global Exception5
global Exception6
global Exception7
global Exception8
global Exception9
global Exception10
global Exception11
global Exception12
global Exception13
global Exception14
global Exception15
global Exception16
global Exception17
global Exception18
global Exception19

Exception0:
	cli
	push 0
	push 0
	call CFaultHandler

Exception1:
    cli
    push 0
    push 1
    jmp CommonIsrStubHandler

Exception2:
    cli
    push 0
    push 2
    jmp CommonIsrStubHandler

Exception3:
    cli
    push 0
    push 3
    jmp CommonIsrStubHandler

Exception4:
    cli
    push 0
    push 4
    jmp CommonIsrStubHandler

Exception5:
    cli
    push 0
    push 5
    jmp CommonIsrStubHandler
    
Exception6:
    cli
    push 0
    push 6
    jmp CommonIsrStubHandler

Exception7:
    cli
    push 0
    push 7
    jmp CommonIsrStubHandler

Exception8:
    cli
    push 8
    jmp CommonIsrStubHandler

Exception9:
    cli
    push 0
    push 9
    jmp CommonIsrStubHandler

Exception10:
    cli
    push 10
    jmp CommonIsrStubHandler
    
Exception11:
    cli
    push 11
    jmp CommonIsrStubHandler

Exception12:
    cli
    push 12
    jmp CFaultHandler

Exception13:
    cli
    push 13
    jmp CFaultHandler

Exception14:
    cli
    push 14
    jmp CommonIsrStubHandler

Exception15:
    cli
    push 0
    push 15
    jmp CommonIsrStubHandler

Exception16:
    cli
    push 0
    push 16
    jmp CommonIsrStubHandler

Exception17:
    cli
    push 0
    push 17
    jmp CommonIsrStubHandler

Exception18:
    cli
    push 0
    push 18
    jmp CommonIsrStubHandler

Exception19:
    cli
    push 0
    push 19
    jmp CommonIsrStubHandler

extern CFaultHandler

CommonIsrStubHandler:
	pusha
	mov ds, eax
	push eax
	mov eax, 0x10
	mov ds, eax
	mov es, eax
	mov fs, eax
	mov gs, eax
	call CFaultHandler
	pop eax
	mov ds, eax
	mov es, eax
	mov fs, eax
	mov gs, eax
	popa
	add esp, 8
	sti
	iret
