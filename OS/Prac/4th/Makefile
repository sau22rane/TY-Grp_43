C_SOURCES = $(wildcard kernel/*.c drivers/*.c)
HEADERS = $(wildcard kernel/*.h drivers/*.h)

all : run

OBJ = ${C_SOURCES .c=.o}

run : os-image.bin	
	qemu-system-x86_64 -fda $<
	rm -f -r boot/*.bin boot/*.o kernel.bin kernel.o
	clear	

os-image.bin : boot/boot_sector.bin kernel.bin
	cat $^ > $@

kernel.bin : boot/kernel_entry.o kernel.o
	ld -o $@ -Ttext 0x1000 $^ --oformat binary

kernel.o : kernel/kernel.c
	gcc -ffreestanding -c $< -o $@

%.o : %.c ${HEADERS}
	gcc -ffreestanding -c $< -o $@

%.o : %.asm
	nasm $< -f elf64 -o $@

%.bin : %.asm
	 nasm $< -f bin -o $@

clean :
	rm -f -r *.bin *.o *.map

load:os-image.bin	
	qemu-system-x86_64 -fda $<
	clear

build:os-image.bin
	rm -f -r boot/*.bin kernel.bin kernel.o boot/*.o
	clear