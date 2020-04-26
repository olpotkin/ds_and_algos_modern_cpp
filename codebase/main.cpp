#include <iostream>

#include "utils/utils.h"
#include "arrays/max_consecutive_ones.h"
#include "arrays/even_num_digits.h"
#include "arrays/squares_sorted_array.h"
#include "arrays/duplicate_zeros.h"


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

  ///  05: arrays
  /// Duplicate Zeros (in-place)
  std::vector<int> v_input_05 = {3, 1, 2, 0, 0, 0, 0, 3};
  DuplicateZero(v_input_05);
  std::cout << "arrays | 05 | Duplicate Zeros | res = ";
  PrintVector(v_input_05);


  return 0;
}
