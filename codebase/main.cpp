#include <iostream>

#include "utils/utils.h"

#include "arrays/max_consecutive_ones.h"
#include "arrays/even_num_digits.h"
#include "arrays/squares_sorted_array.h"
#include "arrays/duplicate_zeros.h"
#include "arrays/merge_sorted_array.h"
#include "arrays/remove_element.h"

#include "sort/selection_sort.h"
#include "sort/insertion_sort.h"
#include "sort/shell_sort.h"
#include "sort/merge_sort.h"
#include "sort/quick_sort.h"


int main() {
  /// 01: arrays
  /// Max Consecutive Ones
  std::vector<int> v_input_01 = {1, 0, 1, 1, 0, 1};
  auto ret_01 = findMaxConsecutiveOnes(v_input_01);
  std::cout << "arrays | 01 | findMaxConsecutiveOnes | res = " << ret_01 << std::endl;

  /// 02: arrays
  /// Find Numbers with Even Number of Digits
  std::vector<int> v_input_02 = {10, 123, 1, 1234, 12345, 123456};
  auto ret_02 = findNumbers(v_input_02);
  std::cout << "arrays | 02 | findNumbers | res = " << ret_02 << std::endl;

  /// 03: arrays
  /// Squares of a Sorted Array: N*log(N)
  std::vector<int> v_input_03 = {-5, -3, -1, 0, 2, 3, 7};
  auto ret_03 = sortedSquares(v_input_03);
  std::cout << "arrays | 03 | sortedSquares | res = ";
  PrintVector(ret_03);

  /// 04: arrays
  /// Squares of a Sorted Array with 2 pointers: N
  std::vector<int> v_input_04 = {-3, -2, 0, 1, 2};
  auto ret_04 = sortedSquares2Pointers(v_input_04);
  std::cout << "arrays | 04 | sortedSquares2Pointers | res = ";
  PrintVector(ret_04);

  /// 05: arrays
  /// Duplicate Zeros (in-place)
  std::vector<int> v_input_05 = {3, 1, 2, 0, 0, 0, 0, 3};
  DuplicateZero(v_input_05);
  std::cout << "arrays | 05 | Duplicate Zeros | res = ";
  PrintVector(v_input_05);

  /// 06: arrays
  /// Merge Sorted Arrays (in-place)
  std::vector<int> v_input_06_1 = {4, 14, 0, 0};
  std::vector<int> v_input_06_2 = {1, 2};
  mergeSortedArray(v_input_06_1, 1, v_input_06_2, 0);
  std::cout << "arrays | 06 | MergeSortedArray | res = ";
  PrintVector(v_input_06_1);

  /// 07: arrays
  /// Remove Elements from Array (in-place)
  std::vector<int> v_input_07 = {1, 2, 2, 1};
  const int num_to_remove_07 = 2;
  auto ret_07 = removeElement(v_input_07, num_to_remove_07);
  std::cout << "arrays | 07 | removeElements (new size of vector) | res = " << ret_07 << std::endl;

  /// 08: sort
  /// Selection Sort
  std::vector<int> v_input_08 = {6, 5, 4, 3, 8, 9, 123, 0, 12, 6, 1, 3, 7};
  SelectionSort(v_input_08);
  std::cout << "sort | 08 | Selection Sort | res = ";
  PrintVector(v_input_08);

  /// 09: sort
  /// Insertion Sort
  std::vector<int> v_input_09 = {6, 5, 4, 3, 8, 9, 123, 0, 12, 6, 1, 3, 7};
  InsertionSort(v_input_09);
  std::cout << "sort | 09 | Insertion Sort | res = ";
  PrintVector(v_input_09);

  /// 10: sort
  /// Shell Sort
  std::vector<int> v_input_10 = {6, 5, 4, 3, 8, 9, 123, 0, 12, 6, 1, 3, 7};
  ShellSort(v_input_10);
  std::cout << "sort | 10 | Shell Sort | res = ";
  PrintVector(v_input_10);

  /// 11: sort
  /// Merge Sort
  std::vector<int> v_input_11 = {6, 5, 4, 3, 8, 9, 123, 0, 12, 6, 1, 3, 7};
  MergeSort(v_input_11);
  std::cout << "sort | 11 | Merge Sort | res = ";
  PrintVector(v_input_11);

  /// 12: sort
  /// Quick Sort
  std::vector<int> v_input_12 = {6, 5, 4, 3, 8, 9, 123, 0, 12, 6, 1, 3, 7};
  QuickSort(v_input_12);
  std::cout << "sort | 12 | Quick Sort | res = ";
  PrintVector(v_input_12);

  return 0;
}
