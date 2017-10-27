cmake_minimum_required(VERSION 3.5)
project (mytest)

add_executable(mytest src/hello.cpp src/hellolib.cpp inc/hellolib.h)

# install(TARGETS mytest DESTINATION bin)
# SET(CPACK_SET_DESTDIR "on")
# SET(CPACK_PACKAGING_INSTALL_PREFIX "/tmp")
# SET(CPACK_GENERATOR "DEB")
# SET(CPACK_DEBIAN_PACKAGE_MAINTAINER "Kjetil Haugland") #required

# SET(CPACK_COMPONENTS_ALL Libraries ApplicationData)

# INCLUDE(CPack)
