
#TODO: no hardcoding

IF (WIN32)
   set(CMAKE_PREFIX_PATH "C:/Qt/Qt5.9.2/5.9.2/msvc2015_64")
ELSE()
   set(CMAKE_PREFIX_PATH "/home/kh/Qt5.9/5.9.1/gcc_64")
ENDIF()


find_package(Qt5Widgets)
find_package(Qt5Qml)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

qt5_wrap_ui(UI_HEADERS mainwindow.ui)
qt5_add_resources(UI_RESOURCES rdsqtwidget.qrc)

add_executable(rdsqtwidget
               rdsqtwidget.cpp
               mainwindow.cpp
               mainwindow.h
               ../../inc/rdsnddslib.h
               ../../inc/rdsnddslib_EXPORTS.h
               ../../inc/rdsgenlib_EXPORTS.h
               ${UI_HEADERS} ${UI_RESOURCES})

find_library (rdsnddslib ../rdsnddslib)
find_library (rdsgenlib ../rdsgenlib)

target_link_libraries (rdsqtwidget rdsnddslib rdsgenlib Qt5::Widgets Qt5::Qml)

install (TARGETS rdsqtwidget RUNTIME DESTINATION bin COMPONENT applications)


#TODO: no hardcoding
IF (WIN32)
   INSTALL(FILES C:/Qt/Qt5.9.2/5.9.2/msvc2015_64/bin/Qt5Core.dll
                 C:/Qt/Qt5.9.2/5.9.2/msvc2015_64/bin/Qt5Widgets.dll
                 C:/Qt/Qt5.9.2/5.9.2/msvc2015_64/bin/Qt5Gui.dll
                 C:/Qt/Qt5.9.2/5.9.2/msvc2015_64/bin/Qt5Qml.dll
                 DESTINATION bin
                 COMPONENT libraries)
ELSE()
   INSTALL(FILES /home/kh/Qt5.9/5.9.1/gcc64/lib/libQt5Widgets.so
                 /home/kh/Qt5.9/5.9.1/gcc64/lib/libQt5Core.so
                 /home/kh/Qt5.9/5.9.1/gcc64/lib/libQt5Gui.so
                 /home/kh/Qt5.9/5.9.1/gcc64/lib/libQt5Qml.so
                 DESTINATION bin
                 COMPONENT libraries)
ENDIF()
