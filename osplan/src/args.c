#include "osplan.h"
#include <string.h>

osplan_config_t parse_osplan_args(int argc, char **argv) {
    osplan_config_t config = {0};

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--xgcc=interactive") == 0) {
            config.xgcc_mode = XGCC_INTERACTIVE;
        } else if (strcmp(argv[i], "--output") == 0 && i+1 < argc) {
            config.output_path = argv[++i];
            config.output_type = OUTPUT_IMAGE;
        } else if (strcmp(argv[i], "--default-filesystem") == 0 && i+1 < argc) {
            config.filesystem = argv[++i];
        }
        // ...add more options here
    }

    return config;
}
