CC=i686-elf-gcc
CFLAGS=-m16 -ffreestanding -nostdlib -Wno-nonnull

UTIL_SRC := $(wildcard ../../modules/coreutils86/*.c)
UTIL_BIN := $(patsubst ../../modules/coreutils86/%.c, %.bin, $(UTIL_SRC))

BOOT86VERSION := 0.1.0

all: shell.bin $(UTIL_BIN) miniboot86-$(BOOT86VERSION).iso

%.bin: ../../modules/coreutils86/%.c
	$(CC) $(CFLAGS) -o $@ -Ttext=0x100000 -Wl,--oformat=elf32-i386 $<

shell.bin: shell.c
	$(CC) $(CFLAGS) -o shell.bin -Ttext=0x100000 -Wl,--oformat=elf32-i386 shell.c

miniboot86.iso: shell.bin $(UTIL_BIN)
	rm -rf iso
	mkdir -p iso/boot/grub
	cp shell.bin iso/boot/
	cp $(UTIL_BIN) iso/boot/
	echo 'set timeout=0' > iso/boot/grub/grub.cfg
	echo 'set default=0' >> iso/boot/grub/grub.cfg
	echo 'menuentry "Miniboot86 i686" {' >> iso/boot/grub/grub.cfg
	echo '  multiboot /boot/shell.bin' >> iso/boot/grub/grub.cfg
	echo '  boot' >> iso/boot/grub/grub.cfg
	echo '}' >> iso/boot/grub/grub.cfg
	grub-mkrescue -o miniboot86.iso iso

clean:
	rm -f *.bin shell.bin miniboot86.iso
	rm -rf iso
