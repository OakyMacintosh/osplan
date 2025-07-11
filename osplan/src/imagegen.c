#include "osplan.h"
#include <stdio.h>

int generate_mountable_image(osplan_config_t config) {
    printf("[osplan] Generating image for target: %s\n", config.target_arch);
    // Stub: generate actual image here
    return 0;
}

int generate_install_script(osplan_config_t config) {
    printf("[osplan] Generating install script to: %s\n", config.output_path);
    // Stub: output shell script
    return 0;
}
