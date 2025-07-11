#ifndef OSPLAN_H
#define OSPLAN_H

typedef enum {
    OUTPUT_NONE,
    OUTPUT_SCRIPT,
    OUTPUT_IMAGE
} osplan_output_type;

typedef enum {
    XGCC_NONE,
    XGCC_INTERACTIVE
} xgcc_mode_t;

typedef struct {
    char *target_arch;
    char *filesystem;
    char *system_type;
    char *media_type;
    char *volume_label;
    char *output_path;
    int include_self;
    osplan_output_type output_type;
    xgcc_mode_t xgcc_mode;
} osplan_config_t;

#endif
