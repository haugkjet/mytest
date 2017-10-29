include (GenerateExportHeader)

add_library (hellolib SHARED hellolib.cpp ../../inc/hellolib.h)

generate_export_header (hellolib          # generates the export header shared_EXPORTS.h automatically
    BASE_NAME hellolib
    EXPORT_MACRO_NAME shared_EXP
    EXPORT_FILE_NAME ${CMAKE_CURRENT_SOURCE_DIR}/../../inc/shared_EXPORTS.h
    STATIC_DEFINE hellolib_EXPORTS_BUILT_AS_STATIC)

install (TARGETS hellolib RUNTIME DESTINATION bin COMPONENT libraries)
