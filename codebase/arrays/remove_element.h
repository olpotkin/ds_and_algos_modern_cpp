#ifndef CODEBASE_REMOVE_ELEMENT_H
#define CODEBASE_REMOVE_ELEMENT_H

#include <vector>

/// Given an array nums and a value val, remove all instances of that
/// value in-place and return the new length.
///
/// Do not allocate extra space for another array, you must do this by modifying
/// the input array in-place with O(1) extra memory.
///
/// The order of elements can be changed. It doesn't matter what you leave beyond the new length.


int removeElement(std::vector<int>& nums, const int& val) {
  int i = 0;

  for (int j = 0; j < nums.size(); ++j) {
    if (nums[j] != val) {
      nums[i] = nums[j];
      ++i;
    }
  }

  return i;
}

#endif //CODEBASE_REMOVE_ELEMENT_H
