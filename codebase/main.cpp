#include <iostream>

#include "arrays/max_consecutive_ones.h"


int main() {
  // 01: arrays
  // findMaxConsecutiveOnes
  std::vector<int> v_input_01 = {1, 0, 1, 1, 0, 1};
  auto ret_01 = findMaxConsecutiveOnes(v_input_01);
  std::cout << "01 | arrays | findMaxConsecutiveOnes | result = " << ret_01 << std::endl;


  return 0;
}
