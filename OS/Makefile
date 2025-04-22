# Kompilátor a NASM
CC = gcc
NASM = nasm

# Parametry pro kompilaci a linkování
CFLAGS = -ffreestanding -O2 -Wall -Wextra -m32
LDFLAGS = -T linker.ld -nostdlib -m elf_i386

# Cíle
TARGET = kernel.bin
BOOTLOADER = boot.bin
FINAL_IMAGE = os_image.bin

# Zdrojové soubory
OBJS = kernel.o graphics.o input.o setup.o settings.o main.o

# Výchozí cíl
all: $(FINAL_IMAGE)

# Výsledný binární obraz OS
$(FINAL_IMAGE): $(BOOTLOADER) $(TARGET)
	cat $(BOOTLOADER) $(TARGET) > $(FINAL_IMAGE)

# Linkování kernelu
$(TARGET): $(OBJS)
	ld $(LDFLAGS) -o $(TARGET) $(OBJS)

# Kompilace jednotlivých souborů
kernel.o: kernel.c
	$(CC) $(CFLAGS) -c kernel.c -o kernel.o

graphics.o: graphics.c
	$(CC) $(CFLAGS) -c graphics.c -o graphics.o

input.o: input.c
	$(CC) $(CFLAGS) -c input.c -o input.o

setup.o: setup.c
	$(CC) $(CFLAGS) -c setup.c -o setup.o

settings.o: settings.c
	$(CC) $(CFLAGS) -c settings.c -o settings.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o

# Kompilace NASM (bootloader)
$(BOOTLOADER): boot.asm
	$(NASM) -f bin boot.asm -o $(BOOTLOADER)

# Čistící cíl
clean:
	rm -f *.o *.bin *.img $(FINAL_IMAGE) $(TARGET) $(BOOTLOADER)

# Spuštění v QEMU
run: $(FINAL_IMAGE)
	qemu-system-i386 -drive format=raw,file=$(FINAL_IMAGE)
