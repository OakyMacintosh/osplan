#include "osplan.h"
#include <stdio.h>
#include <string.h>

int run_xgcc_shell(osplan_config_t config) {
    printf("$(osinfo)\n");
    printf("(gcc) ");
    char input[256];
    while (fgets(input, sizeof(input), stdin)) {
        if (strncmp(input, "exit", 4) == 0) {
            break;
        }
        // Remove trailing newline
        input[strcspn(input, "\n")] = 0;

        // Build gcc command
        char cmd[512];
        snprintf(cmd, sizeof(cmd), "gcc %s", input);

        // Execute gcc and print output
        FILE *fp = popen(cmd, "r");
        if (fp) {
            char output[256];
            while (fgets(output, sizeof(output), fp)) {
                fputs(output, stdout);
            }
            pclose(fp);
        } else {
            printf("Failed to run gcc\n");
        }
        printf("(gcc) ");
    }
    printf("PROCESS EXITED WITH CODE 0\n");
    return 0;
}
