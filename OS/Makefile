# Kompilátor a NASM
CC = gcc
NASM = nasm

# Parametry pro kompilaci a linkování
CFLAGS = -ffreestanding -O2 -Wall -Wextra -m32
LDFLAGS = -T linker.ld -nostdlib -m elf_i386

# Cíl pro kernel binární soubor
TARGET = kernel.bin
BOOTLOADER = boot.bin
FINAL_IMAGE = os_image.bin

# Zdrojové soubory
OBJS = kernel.o graphics.o

# Cíl pro bootovací obraz
$(FINAL_IMAGE): $(BOOTLOADER) $(TARGET)
	cat $(BOOTLOADER) $(TARGET) > $(FINAL_IMAGE)

# Linkování a sestavení kernelu
$(TARGET): $(OBJS)
	ld $(LDFLAGS) -o $(TARGET) $(OBJS)

# Kompilace C souborů
kernel.o: kernel.c
	$(CC) $(CFLAGS) -c kernel.c -o kernel.o

graphics.o: graphics.c
	$(CC) $(CFLAGS) -c graphics.c -o graphics.o

# Kompilace NASM souborů (bootloader)
$(BOOTLOADER): boot.asm
	$(NASM) -f bin boot.asm -o $(BOOTLOADER)

# Čistící příkaz pro odstranění dočasných souborů
clean:
	rm -f *.o *.bin $(TARGET) $(BOOTLOADER) $(FINAL_IMAGE)

# Spuštění v QEMU
run: $(FINAL_IMAGE)
	qemu-system-i386 -drive format=raw,file=$(FINAL_IMAGE)
