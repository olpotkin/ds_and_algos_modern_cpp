#ifndef CODEBASE_SQUARES_SORTED_ARRAY_H
#define CODEBASE_SQUARES_SORTED_ARRAY_H

#include <vector>


/// Time Complexity: O(N * log N), where N is the length of A.
/// Space Complexity: O(N).
std::vector<int> sortedSquares(std::vector<int>& A) {
  for (unsigned int i = 0; i < A.size(); ++i) {
    A[i] = A[i] * A[i];
  }

  std::sort(A.begin(), A.end());

  return A;
}


/// Time Complexity: O(N), where N is the length of A.
/// Space Complexity: O(N).
std::vector<int> sortedSquares2Pointers(std::vector<int>& A) {
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

#endif //CODEBASE_SQUARES_SORTED_ARRAY_H
