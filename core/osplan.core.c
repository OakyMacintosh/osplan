#include <stdio.h>
#include <stdlib.h>
#include "parse_yml.h"
#include "vrg.h"

#define MAX_COMMAND_LENGHT 1024

void CommandParser(int argc, char *argv) {
    #define VRGCLI

    vrgcli("OSPLAN Version 0.1.0 (c)2025 OakyMacintosh",argc,argv); {
        vrg_argn("-f [filename]\tPath to Planfile.yml"); {
            // TODO: Implement file parsing
            printf("Not implemented.\n");
         //   return 1;
        }
        vrg_argn("-v\tPrint version + System info and quit"); {
            printf("OSPLAN v0.1.0");
            // print OS Info + Architecture
            #ifdef __x86_64__
                printf(" (x86_64)\n");
            #elif defined(__i386__)
                printf(" (i386)\n");
            #elif defined(__aarch64__)
                printf(" (aarch64)\n");
            #elif defined(__arm__)
                printf(" (arm)\n");
            #elif defined(__riscv)
                printf(" (riscv)\n");
            #else   
                printf(" (Unknown Architecture)\n");
            #endif
            #ifdef __linux__
                printf(" (Linux)\n");
            #elif defined(_WIN32)
                printf(" (Windows)\n");
            #elif defined(__APPLE__)
                printf(" (macOS)\n");
            #else
                printf(" (Unknown OS)\n");
            #endif
  //          return 0;
        }
    }
}

int main() {
    // nah...
}