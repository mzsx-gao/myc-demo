cmake_minimum_required(VERSION 3.17)
project(myc_demo)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(function)
include_directories(array)
include_directories(pointer)

add_executable(myc_demo
        pointer/pointer_001.c
        pointer/pointer_002.c
        function/function_001.c
        function/function_002.c
        array/array_001.c
        array/array_002.c
        array/array_003.c
        )
