project(qt5test)
cmake_minimum_required(VERSION 2.8.12)
set(CMAKE_PREFIX_PATH "/home/kh/Qt5.9/5.9.1/gcc_64")

# Qt library
find_package(Qt5Widgets)
find_package(Qt5OpenGL)
set(CMAKE_AUTOMOC ON)

# OpenGL & GLEW library
find_package(OpenGL)

# executable
add_executable(qt5test main.cpp)
qt5_use_modules(qt5test Widgets OpenGL)
target_link_libraries(qt5test ${QT_LIBRARIES} ${OPENGL_LIBRARIES})
