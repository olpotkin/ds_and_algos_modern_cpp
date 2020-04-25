#include <iostream>

#include "arrays/max_consecutive_ones.h"
#include "arrays/even_num_digits.h"


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
  std::cout << "arrays | 01 | findNumbers | res = " << ret_02 << std::endl;

  
  return 0;
}
