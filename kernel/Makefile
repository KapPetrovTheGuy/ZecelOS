#
# ZecelOS Kernel Makefile
# Author(s) - amrix
#

KERNEL = kernel.elf
OBJ = \
	obj/entry.o obj/main.o obj/vga.o \
	obj/ports.o obj/string.o obj/ctype.o \
	obj/idta.o obj/idtc.o obj/isr.o

NASM = nasm
CC = clang
LD = ld

NASMFLAGS = -f elf32
CFLAGS = \
	-Isrc/include \
	-m32 \
	-std=gnu11 \
	-ffreestanding \
	-Wall \
	-Wextra \
	-Werror \
	-O2
LDFLAGS = \
	-m elf_i386 \
	-T linker.ld \
	-nostdlib

build:
	mkdir -p obj/
	$(NASM) $(NASMFLAGS) src/entry.asm -o obj/entry.o
	$(CC) $(CFLAGS) -c src/main.c -o obj/main.o
	$(CC) $(CFLAGS) -c src/vga.c -o obj/vga.o
	$(CC) $(CFLAGS) -c src/ports.c -o obj/ports.o
	$(CC) $(CFLAGS) -c src/c/string.c -o obj/string.o
	$(CC) $(CFLAGS) -c src/c/ctype.c -o obj/ctype.o
	$(CC) $(CFLAGS) -c src/idt.c -o obj/idtc.o
	$(NASM) $(NASMFLAGS) src/idt.asm -o obj/idta.o
	$(CC) $(CFLAGS) -c src/isr.c -o obj/isr.o
	$(LD) $(LDFLAGS) -o $(KERNEL) $(OBJ)

clean:
	rm -f $(OBJ) $(KERNEL)
