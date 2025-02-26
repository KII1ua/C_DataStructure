cmake_minimum_required(VERSION 3.27)
project(c_datastructure C)

set(CMAKE_C_STANDARD 11)

add_executable(c_datastructure main.c
        stack_imple_linkedlist.c
)