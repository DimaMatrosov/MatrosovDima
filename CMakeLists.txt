cmake_minimum_required(VERSION 3.24)
project(labs C)

set(CMAKE_C_STANDARD 11)

add_executable(lab1 labs/lab1/main.c labs/lab1/ff.h labs/lab1/ff.c)
add_executable(lab3 labs/lab3/main.c labs/lab3/hed.h labs/lab3/ff.c)
add_executable(lab4 labs/lab4/main.c labs/lab4/header.h labs/lab4/func.c)
