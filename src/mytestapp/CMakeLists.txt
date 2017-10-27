add_executable(mytest hello.cpp ../../inc/hellolib.h)
target_link_libraries (mytest LINK_PUBLIC hellolib)


