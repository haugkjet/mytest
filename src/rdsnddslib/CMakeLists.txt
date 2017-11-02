#rdsndds stuff

include (GenerateExportHeader)
add_library (rdsnddslib SHARED rdsnddslib.cpp ../../inc/rdsnddslib.h)
generate_export_header (rdsnddslib          # generates the export header shared_EXPORTS.h automatically
    BASE_NAME rdsnddslib
    EXPORT_MACRO_NAME shared_EXP
    EXPORT_FILE_NAME ${CMAKE_CURRENT_SOURCE_DIR}/../../inc/rdsnddslib_EXPORTS.h
    STATIC_DEFINE rdsnddslib_EXPORTS_BUILT_AS_STATIC)
install (TARGETS rdsnddslib LIBRARY DESTINATION bin RUNTIME DESTINATION bin COMPONENT libraries)


#NDDS stuff

if (NOT DEFINED NDDSHOME)
  if (DEFINED ENV{NDDSHOME})
    set(NDDSHOME $ENV{NDDSHOME})
  else()
    message(FATAL_ERROR "$NDDSHOME not specified. Please set -DNDDSHOME= to your RTI Connext DDS installation directory")
  endif()
endif()

#TODO: no hardcoding
IF (WIN32)
    find_library (NDDS_LIB1 NAMES nddsc PATHS ${NDDSHOME}/lib/x64Win64VS2015)
    find_library (NDDS_LIB2 NAMES nddscpp PATHS ${NDDSHOME}/lib/x64Win64VS2015)
    find_library (NDDS_LIB3 NAMES nddscore PATHS ${NDDSHOME}/lib/x64Win64VS2015)

    include_directories (${NDDSHOME}/include)
    include_directories (${NDDSHOME}/include/ndds)

    INSTALL(FILES ${NDDSHOME}/lib/x64Win64VS2015/nddsc.dll
                  ${NDDSHOME}/lib/x64Win64VS2015/nddscpp.dll
                  ${NDDSHOME}/lib/x64Win64VS2015/nddscore.dll
                 DESTINATION bin
                 COMPONENT libraries)
ELSE()

    find_library (NDDS_LIB1 NAMES nddsc PATHS ${NDDSHOME}/lib/x64Linux3gcc4.8.2)
    find_library (NDDS_LIB2 NAMES nddscpp PATHS ${NDDSHOME}/lib/x64Linux3gcc4.8.2)
    find_library (NDDS_LIB3 NAMES nddscore PATHS ${NDDSHOME}/lib/x64Linux3gcc4.8.2)


    include_directories (${NDDSHOME}/include)
    include_directories (${NDDSHOME}/include/ndds)

    INSTALL(FILES ${NDDSHOME}/lib/x64Linux3gcc4.8.2/libnddsc.so
                 ${NDDSHOME}/lib/x64Linux3gcc4.8.2/libnddscpp.so
                 ${NDDSHOME}/lib/x64Linux3gcc4.8.2/libnddscore.so
                 DESTINATION bin
                 COMPONENT libraries)
ENDIF()

if (NDDS_LIB1 AND NDDS_LIB2  AND NDDS_LIB3)

   target_link_libraries (rdsnddslib ${NDDS_LIB1} ${NDDS_LIB2} ${NDDS_LIB3})
   message ("NDDS found")
else ()
   message ("NDDS not found, aborting")
endif ()
