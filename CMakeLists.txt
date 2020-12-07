cmake_minimum_required(VERSION 3.17)
project(myc_demo)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(base_function)
include_directories(base_array)
include_directories(base_pointer)
include_directories(base_scope)
include_directories(base_struct)
include_directories(base_string)

add_executable(myc_demo
        base_pointer/pointer_001.c
        base_pointer/pointer_002.c
        base_pointer/pointer_003.c
        base_pointer/pointer_004.c
        base_pointer/pointer_005.c
        base_function/function_001.c
        base_function/function_002.c
        base_array/array_001.c
        base_array/array_002.c
        base_array/array_003.c
        base_string/string_001.c
        base_string/string_002.c
        base_string/string_003.c
        base_string/string_004.c
        base_string/string_005.c
        base_scope/scope_001.c
        base_scope/memory_001.c
        base_scope/memory_002.c
        base_scope/memory_003.c
        base_scope/memory_004.c
        base_struct/struct_001.c
        base_struct/struct_002.c
        base_struct/struct_003.c
        base_struct/struct_004.c
        base_struct/struct_005.c
        base_struct/struct_006.c
        base_struct/struct_007.c
        base_file/file_001.c
        base_file/file_002.c
        base_file/file_003.c
        base_file/file_004.c
        base_file/file_005.c
        )
