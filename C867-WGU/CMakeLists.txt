cmake_minimum_required(VERSION 3.17)
project(C867)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(C867
        degree.h
        main.cpp
        roster.cpp
        roster.h
        student.cpp
        student.h)
