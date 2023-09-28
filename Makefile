#
# ZecelOS ISO+Run Makfile
# Author(s) - amrix, Vincent392
#

ISO = ZecelOS.iso

VM = qemu-system-x86_64
VMFLAGS = -rtc base=localtime,clock=vm,driftfix=slew -monitor stdio -m 16M

all: iso run clean

iso:
	make -C kernel build
	mkdir -p iso_tmp/boot/grub
	cp kernel/kernel.elf iso_tmp/boot/
        cp kernel/Flopkern.elf iso_tmp/boot/CelOS
	cp cfg/grub.cfg iso_tmp/boot/grub/ 
	grub-mkrescue -o $(ISO) iso_tmp

run: iso
	$(VM) -cdrom $(ISO) $(VMFLAGS)

clean:
	make -C kernel clean
	rm -r iso_tmp $(ISO)
