#rdsndds stuff

include (GenerateExportHeader)
add_library (rdsgenlib SHARED rdsgenlib.cpp ../../inc/rdsgenlib.h)
generate_export_header (rdsgenlib          # generates the export header shared_EXPORTS.h automatically
    BASE_NAME rdsgenlib
    EXPORT_MACRO_NAME shared_EXP
    EXPORT_FILE_NAME ${CMAKE_CURRENT_SOURCE_DIR}/../../inc/rdsgenlib_EXPORTS.h
    STATIC_DEFINE rdsgenlib_EXPORTS_BUILT_AS_STATIC)
install (TARGETS rdsgenlib LIBRARY DESTINATION bin RUNTIME DESTINATION bin COMPONENT libraries)

