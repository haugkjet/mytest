#hellolib stuff
include (GenerateExportHeader)

add_library (hellolib SHARED hellolib.cpp ../../inc/hellolib.h)
generate_export_header (hellolib          # generates the export header shared_EXPORTS.h automatically
    BASE_NAME hellolib
    EXPORT_MACRO_NAME shared_EXP
    EXPORT_FILE_NAME ${CMAKE_CURRENT_SOURCE_DIR}/../../inc/shared_EXPORTS.h
    STATIC_DEFINE hellolib_EXPORTS_BUILT_AS_STATIC)
install (TARGETS hellolib LIBRARY DESTINATION bin RUNTIME DESTINATION bin COMPONENT libraries)

#NDDS stuff

#TODO: no hardcoding
IF (WIN32)
    find_library (NDDS_LIB1 NAMES nddsc PATHS "C:/Program\ Files/rti_connext_dds-5.2.3/lib/x64Win64VS2015")
    find_library (NDDS_LIB2 NAMES nddscpp PATHS "C:/Program\ Files/rti_connext_dds-5.2.3/lib/x64Win64VS2015")
    find_library (NDDS_LIB3 NAMES nddscore PATHS "C:/Program\ Files/rti_connext_dds-5.2.3/lib/x64Win64VS2015")

    include_directories ("C:/Program\ Files/rti_connext_dds-5.2.3/include")
    include_directories ("C:/Program\ Files/rti_connext_dds-5.2.3/include/ndds")

    INSTALL(FILES "C:/Program\ Files/rti_connext_dds-5.2.3/lib/x64Win64VS2015/nddsc.dll"
                  "C:/Program\ Files/rti_connext_dds-5.2.3/lib/x64Win64VS2015/nddscpp.dll"
                  "C:/Program\ Files/rti_connext_dds-5.2.3/lib/x64Win64VS2015/nddscore.dll"
                 DESTINATION bin
                 COMPONENT libraries)
ELSE()

    find_library (NDDS_LIB1 NAMES nddsc PATHS "/home/kh/rti_connext_dds-5.2.3/lib/x64Linux3gcc4.8.2/")
    find_library (NDDS_LIB2 NAMES nddscpp PATHS "/home/kh/rti_connext_dds-5.2.3/lib/x64Linux3gcc4.8.2/")
    find_library (NDDS_LIB3 NAMES nddscore PATHS "/home/kh/rti_connext_dds-5.2.3/lib/x64Linux3gcc4.8.2/")

    include_directories ("/home/kh/rti_connext_dds-5.2.3/include")
    include_directories ("/home/kh/rti_connext_dds-5.2.3/include/ndds")

    INSTALL(FILES /home/kh/rti_connext_dds-5.2.3/lib/x64Linux3gcc4.8.2/libnddsc.so
                 /home/kh/rti_connext_dds-5.2.3/lib/x64Linux3gcc4.8.2/libnddscpp.so
                 /home/kh/rti_connext_dds-5.2.3/lib/x64Linux3gcc4.8.2/libnddscore.so
                 DESTINATION bin
                 COMPONENT libraries)
ENDIF()

if (NDDS_LIB1 AND NDDS_LIB2  AND NDDS_LIB3)
   target_link_libraries (hellolib ${NDDS_LIB1} ${NDDS_LIB2} ${NDDS_LIB3})
   message ("NDDS found")
else ()
   message ("NDDS not found, aborting")
endif ()


