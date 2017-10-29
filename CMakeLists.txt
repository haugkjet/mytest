cmake_minimum_required(VERSION 3.5)
project (mytest)

set(EXECUTABLE_OUTPUT_PATH "../bin")
set(LIBRARY_OUTPUT_PATH "../bin")

add_subdirectory (src)

SET(CPACK_COMPONENTS_ALL applications libraries)
set(CPACK_PACKAGE_INSTALL_DIRECTORY "CPackExample")
SET(CPACK_GENERATOR NSIS)
SET(CPACK_PACKAGE_EXECUTABLES "mytest" "mytest2")

INCLUDE(CPack)

