#
# ZecelOS Kernel Makefile
# Author(s) - amrix
#

KERNEL = kernel.elf
OBJ = \
	obj/entry.o obj/gdta.o obj/gdtc.o \
	obj/main.o obj/vga.o obj/ports.o \
	obj/string.o obj/ctype.o \
	obj/font.o obj/console.o obj/pmm.o

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
	$(CC) $(CFLAGS) -c src/font.c -o obj/font.o
	$(CC) $(CFLAGS) -c src/console.c -o obj/console.o
	$(CC) $(CFLAGS) -c src/ports.c -o obj/ports.o
	$(CC) $(CFLAGS) -c src/c/string.c -o obj/string.o
	$(CC) $(CFLAGS) -c src/c/ctype.c -o obj/ctype.o
	$(NASM) $(NASMFLAGS) src/gdt.asm -o obj/gdta.o
	$(CC) $(CFLAGS) -c src/gdt.c -o obj/gdtc.o
	$(CC) $(CFLAGS) -c src/pmm.c -o obj/pmm.o
	$(LD) $(LDFLAGS) -o $(KERNEL) $(OBJ)

clean:
	rm -f $(OBJ) $(KERNEL)
