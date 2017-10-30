set(CMAKE_PREFIX_PATH "/home/kh/Qt5.9/5.9.1/gcc_64")

find_package(Qt5Widgets)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_executable(mytest hello.cpp ../../inc/hellolib.h ../../inc/shared_EXPORTS.h)

find_library (hellolib ../mytestlib)
target_link_libraries (mytest hellolib Qt5::Widgets)

install (TARGETS mytest RUNTIME DESTINATION bin COMPONENT applications)
