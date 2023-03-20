cmake_minimum_required(VERSION 3.23)
project(oaip_labs2 C)

set(CMAKE_C_STANDARD 99)

add_executable(compress lab2/main.compressor.c
        lab2/hed.h lab2/compress.c lab2/ff.c)

add_executable(decompress lab2/main.decompressor.c
        lab2/hed.h lab2/decompress.c lab2/compress.c lab2/ff.c)