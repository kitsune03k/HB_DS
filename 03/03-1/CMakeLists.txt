cmake_minimum_required(VERSION 3.25)
project(03_1 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(03_1
        ArrayList.c
        ArrayList.h
        ListMain.c)
