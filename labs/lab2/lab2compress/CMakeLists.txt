cmake_minimum_required(VERSION 3.23)
project(lab2compress C)

set(CMAKE_C_STANDARD 99)

add_executable(lab2compress main.c compress.c hed.h ff.c)
