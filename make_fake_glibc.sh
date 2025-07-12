#!/bin/bash

set -e

GLIBC_LITE_DIR="./glibc-lite"

echo "[+] Creating fake glibc include directory at $GLIBC_LITE_DIR"
mkdir -p "$GLIBC_LITE_DIR"

# Create endian.h
cat > "$GLIBC_LITE_DIR/endian.h" <<EOF
#ifndef _FAKE_ENDIAN_H
#define _FAKE_ENDIAN_H

#define __LITTLE_ENDIAN 1234
#define __BIG_ENDIAN    4321
#define __PDP_ENDIAN    3412

#define __BYTE_ORDER __LITTLE_ENDIAN

#endif
EOF

# Create byteswap.h
cat > "$GLIBC_LITE_DIR/byteswap.h" <<EOF
#ifndef _FAKE_BYTESWAP_H
#define _FAKE_BYTESWAP_H

#define bswap_16(x) __builtin_bswap16(x)
#define bswap_32(x) __builtin_bswap32(x)
#define bswap_64(x) __builtin_bswap64(x)

#endif
EOF

# Create sys/endian.h (some systems use this instead)
mkdir -p "$GLIBC_LITE_DIR/sys"
cat > "$GLIBC_LITE_DIR/sys/endian.h" <<EOF
#ifndef _FAKE_SYS_ENDIAN_H
#define _FAKE_SYS_ENDIAN_H

#include "../endian.h"

#endif
EOF

cat > glibc-lite/stdint.h <<EOF
#ifndef _FAKE_STDINT_H
#define _FAKE_STDINT_H

typedef signed char int8_t;
typedef unsigned char uint8_t;

typedef short int16_t;
typedef unsigned short uint16_t;

typedef int int32_t;
typedef unsigned int uint32_t;

typedef long long int64_t;
typedef unsigned long long uint64_t;

typedef int32_t intptr_t;
typedef uint32_t uintptr_t;

#define INT8_MAX 127
#define INT16_MAX 32767
#define INT32_MAX 2147483647
#define INT64_MAX 9223372036854775807LL

#define UINT8_MAX 255
#define UINT16_MAX 65535
#define UINT32_MAX 4294967295U
#define UINT64_MAX 18446744073709551615ULL

#endif
EOF


echo "[+] Done. Add the following flag to your build:"
echo ""
echo "   CFLAGS=\"-I$GLIBC_LITE_DIR\""
echo ""
echo "[+] You can now compile BusyBox or miniboot86 with fake glibc headers."
