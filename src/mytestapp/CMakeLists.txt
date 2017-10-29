add_executable(mytest hello.cpp ../../inc/hellolib.h ../../inc/shared_EXPORTS.h)

find_library (hellolib ../mytestlib)
target_link_libraries (mytest hellolib)

install (TARGETS mytest RUNTIME DESTINATION bin COMPONENT applications)
