AC_INIT([pgfs], [0.0.1], [ma.munoz.araya@gmail.com])

AC_CONFIG_AUX_DIR(build-aux)

AM_INIT_AUTOMAKE([-Wall -Werror foreign])

AC_PROG_CC
AC_HEADER_DIRENT

PKG_CHECK_MODULES([libpq], [libpq])
PKG_CHECK_MODULES([libfuse], [fuse])

AC_CONFIG_HEADERS([config.h])

AC_CONFIG_FILES([
 Makefile
 src/Makefile
])


AC_OUTPUT
