.PHONY: all

all: build grub_image

grub_image: build
	grub-mkrescue -o damos.iso isodir

build: build_boot build_kernel linker.ld
	./i686-elf/bin/i686-elf-gcc -T linker.ld -o ./isodir/boot/damos.bin -ffreestanding -O2 -nostdlib boot.o kernel.o -lgcc

build_boot: boot.S
	./i686-elf/bin/i686-elf-as boot.S -o boot.o

build_kernel: kernel.c
	./i686-elf/bin/i686-elf-gcc -c kernel.c -o kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra

clean:
	rm -f *.o ./isodir/boot/*.bin *.iso
