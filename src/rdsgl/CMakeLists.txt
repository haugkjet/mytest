project(rdsgltest)
cmake_minimum_required(VERSION 2.8.12)
IF (WIN32)
   set(CMAKE_PREFIX_PATH "C:/Qt/Qt5.9.2/5.9.2/msvc2015_64")
ELSE()
   set(CMAKE_PREFIX_PATH "/home/kh/Qt5.9/5.9.1/gcc_64")
ENDIF()



# Qt library
find_package(Qt5Widgets)
find_package(Qt5OpenGL)
set(CMAKE_AUTOMOC ON)

# OpenGL & GLEW library
find_package(OpenGL)

# executable
add_executable(rdsgltest main.cpp)
qt5_use_modules(rdsgltest Widgets OpenGL)
target_link_libraries(rdsgltest ${QT_LIBRARIES} ${OPENGL_LIBRARIES})
