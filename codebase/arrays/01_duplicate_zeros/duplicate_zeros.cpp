#include <iostream>
#include <vector>
#include <cassert>


/// Intro: Given a fixed length array arr of integers, duplicate each occurrence of zero, shifting
///        the remaining elements to the right. Note that elements beyond the length of the original
///        array are not written. Do the above modifications to the input array in place, do not return
///        anything from your function.
///
/// Time Complexity: O(N), where N is the number of elements in the array.
///
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


void test_solution() {
  std::vector<int> expected_1 {3, 1, 2, 0, 0, 0, 0, 0};
  std::vector<int> input_1 {3, 1, 2, 0, 0, 0, 0, 3};
  DuplicateZero(input_1);
  assert(input_1 == expected_1);
  std::cout << "Test 01 passed..." << std::endl;

  std::vector<int> expected_2 {1, 2, 3};
  std::vector<int> input_2 {1, 2,3 };
  DuplicateZero(input_2);
  assert(input_2 == expected_2);
  std::cout << "Test 02 passed..." << std::endl;
}


int main() {
  test_solution();

  return 0;
}
