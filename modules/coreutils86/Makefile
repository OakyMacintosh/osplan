CC=i686-elf-gcc
CFLAGS=CFLAGS = -m32 -ffreestanding -nostdlib

all: echo.bin ls.bin reboot.bin shell.bin

%.bin: %.c
	$(CC) $(CFLAGS) -o $*.bin -Ttext=0x7C00 -Wl,--oformat=binary $<

clean:
	rm -f *.bin