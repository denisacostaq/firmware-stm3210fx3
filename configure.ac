#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([firmware-stm3210fx3], [0.0.0], [denisacostaq@gmail.com])

AM_INIT_AUTOMAKE([1.13.2 filename-length-max=256 tar-ustar -Wall])

AC_CONFIG_SRCDIR([config.h.in])
AC_CONFIG_HEADERS([config.h])

AC_CANONICAL_HOST
AC_CANONICAL_BUILD

# Checks for programs.
AC_PROG_AWK
AC_PROG_CC([arm-none-eabi-gcc])
AC_PROG_MAKE_SET
AM_PROG_CC_C_O

# Checks for libraries.

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([Makefile
                 src/Makefile
                 doc/Makefile])
AC_OUTPUT
