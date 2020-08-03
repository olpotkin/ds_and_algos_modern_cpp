#include <iostream>
#include <vector>
#include <cassert>


/// Intro: You are organizing a funny competition for children. As a prize fund you have n candies.
///        You would like to use these candies for top k places in a competition with a natural restriction
///        that a higher place gets a larger number of candies. To make as many children happy as possible,
///        you are going to find the largest value of k for which it is possible.
///
/// Task: The goal of this problem is to represent a given positive integer n as a sum of as many pairwise
///       distinct positive integers as possible. That is, to find the maximum k such that n can be written as
///       a_1 + a_2 + ... + a_k where a_1, ... , a_k are positive integers and a_i != a_j for all 1 <= i < j <= k.
///
/// Input Format: The input consists of a single integer n.
///
/// Output Format: In the first line, output the maximum number k such that n can be represented as a sum
///                of k pairwise distinct positive integers. In the second line, output k pairwise distinct
///                positive integers that sum up to n (if there are many such representations, output any of them).
///

std::vector<int> optimal_summands(const int n) {
  std::vector<int> summands;
  int prizeBudget = n;

  int curPlacePrize = 1;
  int nextPrize     = curPlacePrize + 1;
  int nextNextPrize = nextPrize + 1;

  // While we have enough budget to increase next prize
  while ((prizeBudget - nextNextPrize > nextPrize)) {
    summands.push_back(curPlacePrize);
    prizeBudget -= curPlacePrize;

    curPlacePrize = nextPrize;
    ++nextPrize;
    ++nextNextPrize;
  }

  // Check if we can add current prize (next prize is still higher)
  if (prizeBudget - curPlacePrize > curPlacePrize) {
    summands.push_back(curPlacePrize);
    prizeBudget -= curPlacePrize;
  }
  // In all other cases - rest of the budget is final prize
  if (prizeBudget != 0) {
    summands.push_back(prizeBudget);
  }

  return summands;
}


void test_solution() {
  const std::vector<int> expectedResult_test_1 { 1, 2, 3 };
  assert(optimal_summands(6) == expectedResult_test_1);
  std::cout << "Test 01 passed..." << std::endl;

  const std::vector<int> expectedResult_test_2 { 1, 2, 5 };
  assert(optimal_summands(8) == expectedResult_test_2);
  std::cout << "Test 02 passed..." << std::endl;

  const std::vector<int> expectedResult_test_3 { 2 };
  assert(optimal_summands(2) == expectedResult_test_3);
  std::cout << "Test 03 passed..." << std::endl;
}


int main() {
//  test_solution();

  int n;
  std::cin >> n;

  std::vector<int> summands = optimal_summands(n);

  std::cout << summands.size() << std::endl;
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }

  return 0;
}
