add_executable(rdsconsole
               rdsconsole.cpp
               ../../inc/rdsnddslib.h
               ../../inc/rdsgenlib_EXPORTS.h
               ../../inc/rdsnddslib_EXPORTS.h)

find_library (rdsnddslib ../rdsnddslib)
find_library (rdsgenlib ../rdsgenlib)

target_link_libraries (rdsconsole rdsnddslib rdsgenlib)

install (TARGETS rdsconsole RUNTIME DESTINATION bin COMPONENT applications)
