cmake_minimum_required(VERSION 3.5)
project (rdsDemo)

set(EXECUTABLE_OUTPUT_PATH "../bin")
set(LIBRARY_OUTPUT_PATH "../bin")

add_subdirectory (src)

SET(CPACK_COMPONENTS_ALL applications libraries)
set(CPACK_PACKAGE_INSTALL_DIRECTORY "rdsDemo2")

IF (WIN32)
   SET(CPACK_GENERATOR NSIS)
ELSE()
   SET(CPACK_GENERATOR ZIP)
ENDIF()

SET(CPACK_PACKAGE_EXECUTABLES "rdsDemo3")

INCLUDE(CPack)

