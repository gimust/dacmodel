#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([dacmodel], [0.1], [jonathan.rosser@gmail.com])
AC_CONFIG_HEADERS([config.h])

AM_INIT_AUTOMAKE([1.11 silent-rules])
AM_SILENT_RULES([yes])

LT_PREREQ([2.2.6])
LT_INIT

# Checks for programs.
AC_PROG_CXX
AM_PROG_CC_C_O

# Checks for libraries.
PKG_CHECK_MODULES(FFTW3, fftw3, HAVE_FFTW3=yes, HAVE_FFTW3=no)

# Checks for header files.
AC_CHECK_HEADERS([float.h stdint.h stdlib.h string.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL
AC_C_INLINE
AC_TYPE_INT64_T

# Checks for library functions.
AC_CHECK_FUNCS([floor memset pow])

DACMODEL_CFLAGS="$DACMODEL_CFLAGS -I\$(top_srcdir)"
AC_SUBST(DACMODEL)

AC_CONFIG_FILES([
Makefile
first/Makefile
dsp/Makefile
])
AC_OUTPUT
