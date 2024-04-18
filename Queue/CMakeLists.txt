cmake_minimum_required(VERSION 3.10)
project(MP04-Student)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_COMPILER gcc)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(MP04 main.c Queue.c List.c)