AC_INIT([osplan], [0.1], [you@example.com])
AC_CONFIG_SRCDIR([src/main.c])
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE([foreign subdir-objects])
AC_PROG_CC
AC_PROG_CPP
AC_PROG_MAKE_SET

# Check basic UNIX tools
AC_CHECK_PROG([AR], [ar], [ar], [missing])
AC_CHECK_PROG([RANLIB], [ranlib], [ranlib], [missing])
AC_CHECK_PROG([STRIP], [strip], [strip], [missing])
AC_CHECK_PROG([SH], [sh], [/bin/sh])
AC_CHECK_PROG([BASH], [bash], [/bin/bash], [no])

# Optional: Check if we're using GCC
AC_MSG_CHECKING([if compiler is GCC])
if test "$GCC" = "yes"; then
  AC_MSG_RESULT([yes])
else
  AC_MSG_RESULT([no])
  AC_MSG_WARN([You should compile OSPLAN with GCC for best compatibility.])
fi

# Add build option for internal xgcc shell
AC_ARG_ENABLE([xgcc],
  [AS_HELP_STRING([--enable-xgcc], [Include internal xgcc shell])],
  [enable_xgcc=$enableval],
  [enable_xgcc=no]
)

# Add option to embed prebuilt xgcc binary
AC_ARG_WITH([xgcc-bin],
  [AS_HELP_STRING([--with-xgcc-bin=PATH], [Path to prebuilt xgcc binary to embed])],
  [with_xgcc_bin=$withval],
  [with_xgcc_bin=none]
)

# Add target architecture and system type
AC_ARG_WITH([target],
  [AS_HELP_STRING([--with-target=ARCH], [Target triplet (e.g. x86_64-elf)])],
  [with_target=$withval],
  [with_target=x86_64-unknown-elf]
)

# Set variables for Makefile
AM_CONDITIONAL([USE_XGCC], [test "x$enable_xgcc" = "xyes"])
AC_SUBST([XGCC_BIN], [$with_xgcc_bin])
AC_SUBST([TARGET_TRIPLET], [$with_target])

# Output
AC_CONFIG_FILES([Makefile src/Makefile])
AC_OUTPUT
