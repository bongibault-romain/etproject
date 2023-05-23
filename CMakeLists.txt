cmake_minimum_required(VERSION 3.25)
project(etproject C)

set(CMAKE_C_STANDARD 23)

add_executable(etproject src/main.c src/array/carray/carray.c src/array/farray/farray.c src/string/string.c src/array/iarray/iarray.c)
