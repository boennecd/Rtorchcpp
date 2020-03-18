AC_INIT([Rtorchcpp],[0.1.0])

# Find the compiler and compiler flags used by R.
: ${R_HOME=`R RHOME`}
if test -z "${R_HOME}"; then
  echo "could not determine R_HOME"
  exit 1
fi
CC=`"${R_HOME}/bin/R" CMD config CC`
CFLAGS=`"${R_HOME}/bin/R" CMD config CFLAGS`
CPPFLAGS=`"${R_HOME}/bin/R" CMD config CPPFLAGS`
AC_LANG(C++)
AC_PROG_CPP

# Find needed libtorch files. See
#   https://github.com/pytorch/pytorch/blob/6aecfd1e804f2be68df6557c43adbe1f2234fe91/cmake/TorchConfig.cmake.in
if test -z "${TORCH_INSTALL_PREFIX}"; then
  echo "could not determine TORCH_INSTALL_PREFIX"
  exit 1
fi

TORCH_INCLUDE_ONE="-I${TORCH_INSTALL_PREFIX}/include"
TORCH_INCLUDE_TWO="-I${TORCH_INSTALL_PREFIX}/include/torch/csrc/api/include"
TORCH_LIBRARIES="${TORCH_INSTALL_PREFIX}/lib"

# Write the flags into the src/Makevars file and to the README
AC_SUBST([PKG_CPPFLAGS], ["${PKG_CPPFLAGS} ${TORCH_INCLUDE_ONE} ${TORCH_INCLUDE_TWO}"])
AC_SUBST([PKG_LIBS], ["${LIBS} ${PKG_LIBS} -L${TORCH_LIBRARIES} -ltorch"])
AC_CONFIG_FILES([src/Makevars])
AC_CHECK_FILE([README.md.in], AC_CONFIG_FILES([README.md]), [])
AC_CHECK_FILE([DESCRIPTION.in], AC_CONFIG_FILES([DESCRIPTION]), [])
AC_OUTPUT

echo "
  --------------------------------------------------
  Configuration for ${PACKAGE_NAME} ${PACKAGE_VERSION}

    cppflags:        ${CPPFLAGS} ${PKG_CPPFLAGS}
    libs:            ${PKG_LIBS}

  --------------------------------------------------

  Please, add this line to your .Rprofile (e.g. in your home directory)

    local({
      stopifnot(dir.exists(
        torch_lib <-
          '${TORCH_LIBRARIES}'))
      Sys.setenv('LD_LIBRARY_PATH' = paste0(
        Sys.getenv('LD_LIBRARY_PATH'), ':', torch_lib))
      dyn.load(file.path(torch_lib, 'libtorch.so'))
    })

  Add the following line to your .Rprofile to make development more smooth

    local({
      stopifnot(dir.exists(
        torch_inst_pre <-
          '${TORCH_INSTALL_PREFIX}'))
      Sys.setenv('TORCH_INSTALL_PREFIX' = torch_inst_pre)
    })

"
