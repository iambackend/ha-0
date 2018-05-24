cmake_minimum_required(VERSION 3.9)
project(ha_0 C)

set(CMAKE_C_STANDARD 99)

add_executable(ha_0 test-binarize.c binarize.c binarize.h)