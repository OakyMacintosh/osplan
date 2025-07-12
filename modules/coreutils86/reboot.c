__attribute__((section(".text")))
void _start(void) {
    asm volatile (
        "cli\n"
        "movb $0xFE, %%al\n"
        "out %%al, $0x64\n"
        "hlt\n"
        :
        :
        : "al"
    );

    for (;;);
}
