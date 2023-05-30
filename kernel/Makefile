#
# ZecelOS Kernel Makefile
# Author(s) - amrix
#

KERNEL = kernel.elf
OBJ = \
	obj/entry.o obj/main.o obj/vga.o \
	obj/ports.o #obj/string.o obj/console.o

NASM = nasm
CC = clang
LD = ld

NASMFLAGS = -f elf32
CFLAGS = \
	-Isrc/include \
	-m32 \
	-std=gnu99 \
	-ffreestanding \
	-Wall \
	-Wextra \
	-Werror
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
	#$(CC) $(CFLAGS) -c src/string.c -o obj/string.o
	#$(CC) $(CFLAGS) -c src/console.c -o obj/console.o
	$(LD) $(LDFLAGS) -o $(KERNEL) $(OBJ)

clean:
	rm -f $(OBJ) $(KERNEL)
