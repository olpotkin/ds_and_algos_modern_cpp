#include <iostream>
#include <vector>
#include <cassert>


/// Given an array nums of integers, return how many of them contain an even number of digits.


/// @brief HELPER: Count the number of digits in given number
///
/// @param[in] inNumber - input integer
/// @param[out] numDigits - number of digits in the given integer
int CountDigitsInInt(int inNumber) {
  int numDigits = 0;

  while (inNumber > 0) {
    inNumber = inNumber / 10;
    ++numDigits;
  }

  return numDigits;
}


/// @brief HELPER: Check if number is Even
///
/// @param[in] inNumber - input integer
/// @param[out] boolean flag that tells whether the given Integer is Even number
bool IsEven(const int inNumber) {
  return (inNumber % 2 == 0);
}


/// @brief Main entry
int findNumbers(std::vector<int>& nums) {
  int num_even          = 0;
  int num_digits_in_int = 0;

  for (auto num : nums) {
    num_digits_in_int = CountDigitsInInt(num);

    if (IsEven(num_digits_in_int)) {
      ++num_even;
    }
  }

  return num_even;
}


void test_solution() {
  std::vector<int> input_1 = {10, 123, 1, 1234, 12345, 123456};
  assert(findNumbers(input_1) == 3);
  std::cout << "Test 01 passed..." << std::endl;

  std::vector<int> input_2 = {12, 345, 2, 6, 7896};
  assert(findNumbers(input_2) == 2);
  std::cout << "Test 02 passed..." << std::endl;

  std::vector<int> input_3 = {555, 901, 482, 1771};
  assert(findNumbers(input_3) == 1);
  std::cout << "Test 03 passed..." << std::endl;
}


int main() {
  test_solution();

  return 0;
}
