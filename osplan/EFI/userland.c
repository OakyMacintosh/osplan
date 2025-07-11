// init.c — miniboot86 userland entrypoint (freestanding ELF)
// Built with i586-elf-gcc -ffreestanding -nostdlib

#include <stdint.h>

#define SH_ELF_ADDR ((void (*)(void))0x8000)

// BIOS TTY print via int 0x10
static void bios_print(const char *str) {
    while (*str) {
        __asm__ volatile (
            "movb $0x0E, %%ah\n\t"
            "movb %0, %%al\n\t"
            "int $0x10"
            :
            : "r"(*str)
            : "ah", "al"
        );
        str++;
    }
}

// Entry function — no runtime
void main() {
    bios_print("\r\n");
    bios_print("== MINIBOOT86 INIT ==\r\n");
    bios_print("Jumping to sh.elf at 0x8000...\r\n");

    // Jump to sh.elf (BusyBox ash shell)
    SH_ELF_ADDR();

    // Fallback halt loop
    bios_print("Shell exited. System halted.\r\n");
    for (;;) {
        __asm__ volatile ("hlt");
    }
}
