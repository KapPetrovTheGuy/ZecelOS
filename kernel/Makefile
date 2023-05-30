#
# ZecelOS Kernel Makefile
# Author(s) - amrix
#

KERNEL = kernel.elf
OBJ = \
       	obj/asm/entry.o obj/kernel.o obj/io_ports.o \
	obj/vga.o obj/string.o obj/console.o

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
	mkdir -p obj/asm
	$(NASM) $(NASMFLAGS) src/asm/entry.asm -o obj/asm/entry.o
	$(CC) $(CFLAGS) -c src/kernel.c -o obj/kernel.o
	$(CC) $(CFLAGS) -c src/io_ports.c -o obj/io_ports.o
	$(CC) $(CFLAGS) -c src/vga.c -o obj/vga.o
	$(CC) $(CFLAGS) -c src/string.c -o obj/string.o
	$(CC) $(CFLAGS) -c src/console.c -o obj/console.o
	$(LD) $(LDFLAGS) -o $(KERNEL) $(OBJS)

clean:
	rm -f $(OBJ) $(KERNEL)
