cmake_minimum_required(VERSION 3.20)

project(test LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(test
    main.c
)

add_subdirectory(lib_a)
add_subdirectory(lib_b)
