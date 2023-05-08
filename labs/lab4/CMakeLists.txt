cmake_minimum_required(VERSION 3.23)
project(lab4n C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(lab4n
        func.c
        header.h
        main.c)
