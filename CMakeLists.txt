cmake_minimum_required(VERSION 3.6)
project(2048)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Block.cpp
        Block.h
        Board.cpp
        Board.h
        main.cpp GameWindow.cpp GameWindow.h)

include_directories(FLTK)
link_directories(usr/local/lib)

add_executable(2048 ${SOURCE_FILES})
target_link_libraries(2048 fltk_images fltk X11 Xext pthread Xfixes dl m)