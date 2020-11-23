# CMake 最低版本号要求
cmake_minimum_required(VERSION 3.17)
# 项目信息
project(myc-demo C)

set(CMAKE_C_STANDARD 99)

# 查找当前目录下的所有源文件，并将名称保存到 DIR_SRCS 变量
aux_source_directory(. DIR_SRCS)

# 指定生成目标，将DIR_SRCS中 的源文件编译成一个名称为 pointer 的可执行文件
add_executable(pointer ${DIR_SRCS})