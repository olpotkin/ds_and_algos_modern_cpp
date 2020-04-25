#ifndef CODEBASE_EVEN_NUM_DIGITS_H
#define CODEBASE_EVEN_NUM_DIGITS_H

#include <vector>


/// @brief HELPER: Count the number of digits in given number
///
/// @param[in] inNumber - input integer
/// @param[out] numDigits - number of digits in the given integer
int CountDigitsInInt(int inNumber) {
  int numDigits = 0;

  while (inNumber > 0)
  {
    inNumber = inNumber / 10;
    ++numDigits;
  }

  return numDigits;
}


/// @brief HELPER: Check if number is Even
///
/// @param[in] inNumber - input integer
/// @param[out] boolean flag that tells whether the given Integer is Even number
bool IsEven(const int& inNumber) {
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

#endif //CODEBASE_EVEN_NUM_DIGITS_H
