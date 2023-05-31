;
; gdt.asm - Load the GDT
; Author(s) - KapPetrov, amrix
;

[bits 32]

global GdtLoad
GdtLoad:
    push ebp
    mov ebp, esp

    mov eax, [ebp + 8]
    lgdt [eax]

    mov eax, [ebp + 12]
    push eax
    push .ReloadCS
	retf

.ReloadCS:
    mov ax, [ebp + 16]
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax

    mov esp, ebp
    pop ebp
    ret
