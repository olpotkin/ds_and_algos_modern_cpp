#ifndef CODEBASE_DUPLICATE_ZEROS_H
#define CODEBASE_DUPLICATE_ZEROS_H

#include <vector>


/// Time Complexity: O(N), where N is the number of elements in the array.
/// Space Complexity: O(1)
void DuplicateZero(std::vector<int>& arr) {
  // The number of zeros which would be duplicated.
  // The number of elements to be trimmed off the original array.
  int possibleDups = 0;

  int maxIdx = arr.size() - 1;

  // Count the zeros
  for (int lhsIdx = 0; lhsIdx <= maxIdx - possibleDups; ++lhsIdx) {
    if (arr[lhsIdx] == 0) {

      // Handle the edge case for a zero present on the boundary of the leftover elements
      if (lhsIdx == maxIdx - possibleDups) {
        // Just copy this zero
        arr[maxIdx] = 0;
        --maxIdx;
        break;
      }
      ++possibleDups;
    }
  }

  // Index of last element to be copied
  int leftValidIdx = maxIdx - possibleDups;

  // Iterate the array from the end and copy a non-zero element once and zero element twice
  // Start from the right side
  for (int i = leftValidIdx; i >= 0; --i) {
    if (arr[i] == 0) {
      arr[i + possibleDups] = 0;
      --possibleDups;
      arr[i + possibleDups] = 0;
    }
    else {
      arr[i + possibleDups] = arr[i];
    }
  }

}

#endif //CODEBASE_DUPLICATE_ZEROS_H
