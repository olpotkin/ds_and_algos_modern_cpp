cmake_minimum_required(VERSION 3.16)
project(codebase)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        codebase
        main.cpp
        utils/utils.h
        arrays/max_consecutive_ones.h
        arrays/even_num_digits.h
        arrays/squares_sorted_array.h
        arrays/duplicate_zeros.h
        arrays/merge_sorted_array.h
        arrays/remove_element.h
        sort/selection_sort.h
        sort/insertion_sort.h
        sort/shell_sort.h
        sort/merge_sort.h
        sort/quick_sort.h
        sort/n-smallest-item.h)
