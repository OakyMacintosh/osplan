__attribute__((section(".text")))
void print(const char *msg) {
    while (*msg) {
        asm volatile (
            "mov $0x0E, %%ah\n"
            "movb %0, %%al\n"
            "int $0x10"
            : : "r"(*msg++) : "ah", "al"
        );
    }
}

__attribute__((section(".text")))
char getchar() {
    char c;
    asm volatile (
        "xor %%ah, %%ah\n"
        "int $0x16\n"
        "mov %%al, %0\n"
        : "=r"(c) : : "ah", "al"
    );
    return c;
}

__attribute__((section(".text")))
void read_line(char *buf, int maxlen) {
    int i = 0;
    while (i < maxlen - 1) {
        char c = getchar();
        if (c == '\r') {
            print("\r\n");
            break;
        } else if (c == '\b' && i > 0) {
            --i;
            print("\b \b");
        } else {
            buf[i++] = c;
            char s[2] = {c, 0};
            print(s);
        }
    }
    buf[i] = 0;
}

__attribute__((section(".text")))
void _start(void) {
    char buf[80];
    print("miniboot86> [shell starting...]\r\n");

    while (1) {
        print("0 > ");
        read_line(buf, sizeof(buf));

        if (buf[0] == '\0') continue;
        else if (!__builtin_strcmp(buf, "echo")) {
            print("Hello from shell echo!\r\n");
        } else if (!__builtin_strcmp(buf, "reboot")) {
            asm volatile (
                "cli\n"
                "mov al, 0xFE\n"
                "out 0x64, al\n"
                "hlt\n"
            );
        } else {
            print("Unknown command\r\n");
        }
    }
}
