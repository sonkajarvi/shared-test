cmake_minimum_required(VERSION 3.20)

project(b LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(b SHARED
    b_print_number.c
)
