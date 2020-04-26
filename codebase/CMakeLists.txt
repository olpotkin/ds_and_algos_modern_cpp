cmake_minimum_required(VERSION 3.16)
project(codebase)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        codebase
        main.cpp
        arrays/max_consecutive_ones.h
        arrays/even_num_digits.h
#        arrays/squares_sorted_array.h
        utils/utils.h)
