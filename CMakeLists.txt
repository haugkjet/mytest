cmake_minimum_required(VERSION 3.5)
project (mytest)

set(EXECUTABLE_OUTPUT_PATH "../bin")
set(LIBRARY_OUTPUT_PATH "../bin")

add_subdirectory (src)

SET(CPACK_COMPONENTS_ALL applications libraries)
set(CPACK_PACKAGE_INSTALL_DIRECTORY "CPackExample")

IF (WIN32)
   SET(CPACK_GENERATOR NSIS)
ELSE()
   SET(CPACK_GENERATOR ZIP)
   #SET(CPACK_DEBIAN_PACKAGE_MAINTAINER "Kjetil Haugland") #required
ENDIF()

SET(CPACK_PACKAGE_EXECUTABLES "mytest" "mytest2")

INCLUDE(CPack)

