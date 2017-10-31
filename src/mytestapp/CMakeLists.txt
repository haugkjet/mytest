
#TODO: no hardcoding

IF (WIN32)
   set(CMAKE_PREFIX_PATH "C:/Qt/Qt5.9.2/5.9.2/msvc2015_64")
ELSE()
   set(CMAKE_PREFIX_PATH "/home/kh/Qt5.9/5.9.1/gcc_64")
ENDIF()


find_package(Qt5Widgets)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_executable(mytest hello.cpp ../../inc/hellolib.h ../../inc/shared_EXPORTS.h)

find_library (hellolib ../mytestlib)
target_link_libraries (mytest hellolib Qt5::Widgets)

install (TARGETS mytest RUNTIME DESTINATION bin COMPONENT applications)

#TODO: no hardcoding
IF (WIN32)
   INSTALL(FILES C:/Qt/Qt5.9.2/5.9.2/msvc2015_64/bin/Qt5Cored.dll
                 C:/Qt/Qt5.9.2/5.9.2/msvc2015_64/bin/Qt5Widgetsd.dll
                 C:/Qt/Qt5.9.2/5.9.2/msvc2015_64/bin/Qt5Guid.dll
                 DESTINATION bin
                 COMPONENT libraries)
ELSE()
   INSTALL(FILES /home/kh/Qt5.9/5.9.1/gcc64/lib/libQt5Widgets.so
                 /home/kh/Qt5.9/5.9.1/gcc64/lib/libQt5Core.so
                 /home/kh/Qt5.9/5.9.1/gcc64/lib/libQt5Gui.so
                 DESTINATION bin
                 COMPONENT libraries)
ENDIF()
