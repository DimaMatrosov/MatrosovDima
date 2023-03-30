cmake_minimum_required(VERSION 3.24)
project(labs C)

set(CMAKE_C_STANDARD 11)

add_executable(lab1 labs/lab1/main.c labs/lab1/ff.h labs/lab1/ff.c)
add_executable(lab2compress labs/lab2/lab2compress/main.clabs/lab2/lab2compress/hed.h labs/lab2/lab2compress/ff.c labs/lab2/lab2compress/compress.c)
