AC_INIT([pgfs], [0.0.1], [ma.munoz.araya@gmail.com])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])

# C compiler and c99 suport
AC_PROG_CC
AC_PROG_CC_C99
if test x"$ac_cv_prog_cc_c99" = x"no"; then
  AC_MSG_FAILURE([C99 support is mandatory, your compiler not suport this])
fi


AC_HEADER_DIRENT

PKG_CHECK_MODULES([libpq], [libpq])
PKG_CHECK_MODULES([libfuse], [fuse])


AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([
 Makefile
 src/Makefile
])


AC_OUTPUT
