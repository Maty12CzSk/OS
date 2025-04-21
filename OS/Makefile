CC = gcc
AS = nasm
LD = ld
QEMU = qemu-system-x86_64
CFLAGS = -ffreestanding -O2 -Wall -Wextra
LDFLAGS = -T linker.ld -nostdlib

all: kernel.bin

kernel.bin: boot.asm kernel.o graphics.o input.o setup.o
	$(AS) -f bin boot.asm -o boot.bin
	$(LD) $(LDFLAGS) -o kernel.bin kernel.o graphics.o input.o setup.o
	cat boot.bin kernel.bin > os-image.bin

kernel.o: kernel.c
	$(CC) $(CFLAGS) -c kernel.c -o kernel.o

graphics.o: graphics.c
	$(CC) $(CFLAGS) -c graphics.c -o graphics.o

input.o: input.c
	$(CC) $(CFLAGS) -c input.c -o input.o

setup.o: setup.c
	$(CC) $(CFLAGS) -c setup.c -o setup.o

run: kernel.bin
	$(QEMU) -drive format=raw,file=os-image.bin

clean:
	rm -f *.o *.bin *.bin
