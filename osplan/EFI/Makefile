# === CONFIG ===
ARCH       := i586
CROSS      := $(ARCH)-elf-
CC         := $(CROSS)gcc
LD         := $(CROSS)ld
AS         := nasm
OBJCOPY    := $(CROSS)objcopy
QEMU       := qemu-system-i386

BOOTLOADER := miniboot86.asm
INIT_SRC   := userland.c
LINKER     := userland.ld
INIT_BIN   := init.elf
IMG        := miniboot86.img

BUSYBOX_DIR   := components/busybox
BUSYBOX_BUILD := build/busybox
BUSYBOX_ELF   := sh.elf

MODULES_ADDR := 0x8000

# === DEFAULT ===
all: $(IMG)

# === BOOTLOADER ===
bootloader.bin: $(BOOTLOADER)
	$(AS) -f bin $< -o $@

# === INIT ELF (userland.c) ===
$(INIT_BIN): $(INIT_SRC) $(LINKER)
	$(CC) -m32 -ffreestanding -nostdlib -Wl,-T,$(LINKER) -o $@ $<

# === BUSYBOX SHELL (sh.elf) ===
$(BUSYBOX_ELF):
	mkdir -p $(BUSYBOX_BUILD)
	cp $(BUSYBOX_DIR)/.config $(BUSYBOX_BUILD)/.config || true
	cd $(BUSYBOX_DIR) && \
		make O=$(abspath $(BUSYBOX_BUILD)) \
		CROSS_COMPILE=$(CROSS) \
		CC=$(CC) \
		defconfig
	cd $(BUSYBOX_BUILD) && make -j4
	cp $(BUSYBOX_BUILD)/busybox $@

# === FINAL BOOTABLE IMAGE ===
$(IMG): bootloader.bin $(INIT_BIN) $(BUSYBOX_ELF)
	cat bootloader.bin > $(IMG)
	cat $(INIT_BIN) >> $(IMG)
	dd if=$(BUSYBOX_ELF) of=$(IMG) bs=512 seek=20 conv=notrunc status=none
	truncate -s 1474560 $(IMG)

# === TEST IN QEMU ===
run: $(IMG)
	$(QEMU) -fda $(IMG) -boot a

# === CLEAN ===
clean:
	rm -f *.bin *.elf *.img
	rm -rf $(BUSYBOX_BUILD)
