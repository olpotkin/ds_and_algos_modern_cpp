#include <iostream>
#include <vector>
#include <cassert>


/// Squares of a Sorted Array
///
/// Task: Given an array of integers A sorted in non-decreasing order, return an array of the squares of each number,
///       also in sorted non-decreasing order.
///
/// Source: https://leetcode.com/explore/learn/card/fun-with-arrays/521/introduction/3240/


/// Time Complexity: O(N * log N), where N is the length of A.
/// Space Complexity: O(N).
std::vector<int> sortedSquaresNaive(std::vector<int>& A) {
  for (unsigned int i = 0; i < A.size(); ++i) {
    A[i] = A[i] * A[i];
  }

  std::sort(A.begin(), A.end());

  return A;
}


/// Time Complexity: O(N), where N is the length of A.
/// Space Complexity: O(N).
std::vector<int> sortedSquaresFast(std::vector<int>& A) {
  std::vector<int> result;
  result.reserve(A.size());

  int negIdx = 0;
  unsigned int posIdx = 0;

  // Find the index of negative/positive number
  while (posIdx < A.size() && A[posIdx] < 0) {
    ++posIdx;
  }
  negIdx = posIdx - 1;

  // Case 1: We have positive and negative numbers in A
  while (negIdx >= 0 && posIdx < A.size()) {
    if (A[negIdx] * A[negIdx] < A[posIdx] * A[posIdx]) {
      result.push_back(A[negIdx] * A[negIdx]);
      --negIdx;
    }
    else {
      result.push_back(A[posIdx] * A[posIdx]);
      ++posIdx;
    }
  }

  // Case 2: We have only negative numbers in A
  while (negIdx >= 0) {
    result.push_back(A[negIdx] * A[negIdx]);
    --negIdx;
  }

  // Case 3: We have only positive numbers in A
  while (posIdx < A.size()) {
    result.push_back(A[posIdx] * A[posIdx]);
    ++posIdx;
  }

  return result;
}


void test_solution() {
  std::vector<int> input_1 {-4, -1, 0, 3, 10};
  std::vector<int> expected_1 {0, 1, 9, 16, 100};
  assert(sortedSquaresFast(input_1) == expected_1);
  std::cout << "Test 1 passed..." << std::endl;

  std::vector<int> input_2 {-7, -3, 2, 3, 11};
  std::vector<int> expected_2 {4, 9, 9, 49, 121};
  assert(sortedSquaresFast(input_2) == expected_2);
  std::cout << "Test 2 passed..." << std::endl;
}


int main() {
  test_solution();

  return 0;
}
