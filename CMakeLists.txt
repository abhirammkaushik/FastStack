cmake_minimum_required(VERSION 3.17)
project(FastStack)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")

add_executable(FastStack main.cpp Stack.cpp Stack.h FastStack.cpp FastStack.h)