#ifndef PARSE_YML_H
#define PARSE_YML_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>

#define MAX_YML_ENTRIES 128
#define MAX_YML_KEY_LEN 64
#define MAX_YML_VAL_LEN 256

typedef struct {
    char key[MAX_YML_KEY_LEN];
    char value[MAX_YML_VAL_LEN];
    int indent;  // nesting level
} yml_entry_t;

typedef struct {
    yml_entry_t entries[MAX_YML_ENTRIES];
    size_t count;
} yml_doc_t;

/**
 * Parses a raw YAML buffer into a yml_doc_t structure.
 * Supports key: value and nested indentation.
 */
int yml_parse(const char* buffer, yml_doc_t* doc);

/**
 * Finds a value in the parsed document by key and indent level.
 */
const char* yml_get(const yml_doc_t* doc, const char* key, int indent);

/**
 * Prints all parsed entries (for debug).
 */
void yml_debug(const yml_doc_t* doc);

#ifdef __cplusplus
}
#endif

#endif // PARSE_YML_H
