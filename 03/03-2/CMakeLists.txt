cmake_minimum_required(VERSION 3.26)
project(03_2 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(03_2
        ArrayList.c
        ArrayList.h
        NameCard.c
        NameCard.h
        NameCardListMain.c)
