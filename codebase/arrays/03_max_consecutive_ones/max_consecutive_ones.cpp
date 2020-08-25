#include <iostream>
#include <vector>
#include <cassert>


/// Max Consecutive Ones
///
/// Intro: Given a binary array, find the maximum number of consecutive 1s in this array.
///
/// The input array will only contain 0 and 1.
/// The length of input array is a positive integer and will not exceed 10,000


void UpdateMax(const int currSequence, int& maxSequence) {
  if (currSequence > maxSequence){
    maxSequence = currSequence;
  }
}


int findMaxConsecutiveOnes(const std::vector<int> nums) {
  int currSequence = 0;
  int maxSequence  = 0;

  for (auto num : nums) {
    if (num == 1) {
      ++currSequence;
    }
    else {
      UpdateMax(currSequence, maxSequence);
      currSequence = 0;
    }
  }

  UpdateMax(currSequence, maxSequence);

  return maxSequence;
}


void test_solution() {
  std::cout << "Result 1: " << findMaxConsecutiveOnes(std::vector<int> {1, 1, 0, 1, 1, 1}) << std::endl;
  assert(findMaxConsecutiveOnes(std::vector<int> {1, 1, 0, 1, 1, 1}) == 3);
  std::cout << "Test 1 passed..." << std::endl;

  std::cout << "Result 2: " << findMaxConsecutiveOnes(std::vector<int> {1, 0, 1, 1, 0, 1}) << std::endl;
  assert(findMaxConsecutiveOnes(std::vector<int> {1, 0, 1, 1, 0, 1}) == 2);
  std::cout << "Test 2 passed..." << std::endl;
}


int main() {
  test_solution();

  return 0;
}
