;
; idt.asm - To load the IDT pointer
; Author(s) - amrix, Bran's Kernel Dev
;

extern idtPointer

global IdtLoad
IdtLoad:
	lidt [idtPointer]
	ret
