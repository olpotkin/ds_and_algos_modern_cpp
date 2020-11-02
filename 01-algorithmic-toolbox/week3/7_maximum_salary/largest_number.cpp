#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cassert>


/// Intro: As the last question of a successful interview, your boss gives you a few pieces of paper
///        with numbers on it and asks you to compose a largest number from these numbers. The resulting
///        number is going to be your salary, so you are very much interested in maximizing this number.
///
/// Task: Compose the largest number out of a set of integers.
///
/// Input Format: The first line of the input contains an integer n. The second line contains integers
///               a_1, a_2, ... , a_n.
///
/// Output Format: Output the largest number that can be composed out of a_1, a_2, ... , a_n.
///


std::string largest_number(std::vector<std::string>& a) {
  std::stringstream ret;

  /// Sort with custom comparator
  /// Example:
  /// Input: 2, 21
  /// Default sort: 21, 2
  /// Custom sort: 2, 21 (212 < 221)
  std::sort(a.begin(), a.end(), 
    [](const std::string& lhs, const std::string& rhs){ return ((lhs + rhs) > (rhs + lhs)); });

//  for (const auto& num : a)
//    std::cout << "sorted: " << num << std::endl;

  for (size_t i = 0; i < a.size(); i++) {
    ret << a[i];
  }

  std::string result;
  ret >> result;

  return result;
}


void test_solution() {
  std::vector<std::string> inputData_test_1 { "21", "2" };
  const std::string expectedResult_test_1 = "221";
  assert(largest_number(inputData_test_1) == expectedResult_test_1);
  std::cout << "Test 01 passed..." << std::endl;

  std::vector<std::string> inputData_test_2 { "9", "4", "6", "1", "9" };
  const std::string expectedResult_test_2 = "99641";
  assert(largest_number(inputData_test_2) == expectedResult_test_2);
  std::cout << "Test 02 passed..." << std::endl;

  std::vector<std::string> inputData_test_3 { "23", "39", "92"};
  const std::string expectedResult_test_3 = "923923";
  assert(largest_number(inputData_test_3) == expectedResult_test_3);
  std::cout << "Test 03 passed..." << std::endl;
}


int main() {
//  test_solution();

  int n;
  std::cin >> n;

  std::vector<std::string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }

  std::cout << largest_number(a) << std::endl;

  return 0;
}
