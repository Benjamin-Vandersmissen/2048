cmake_minimum_required(VERSION 3.6)
project(2048)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Block.cpp
        Block.h
        Board.cpp
        Board.h
        main.cpp)

add_executable(2048 ${SOURCE_FILES})