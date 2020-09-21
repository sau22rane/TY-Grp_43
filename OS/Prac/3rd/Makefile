all : run

run : os-image.bin
	qemu-system-x86_64 -fda $<
	clear	

os-image.bin : boot_sect.bin kernel.bin
	cat $^ > $@

kernel.bin : kernel_entry.o kernel.o
	ld -o kernel.bin -Ttext 0x1000 $^ --oformat binary

kernel.o : kernel.c
	gcc -ffreestanding -c $< -o $@

kernel_entry.o : kernel_entry.asm
	nasm $< -f elf64 -o $@

boot_sect.bin : boot_sector.asm
	 nasm $< -f bin -o $@

clean :
	rm -f -r *.bin *.o *.map