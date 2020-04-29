#ifndef CODEBASE_MERGE_SORTED_ARRAY_H
#define CODEBASE_MERGE_SORTED_ARRAY_H

#include <vector>


/// @brief https://leetcode.com/explore/learn/card/fun-with-arrays/525/inserting-items-into-an-array/3253/
/// Time complexity:  O(n + m)
/// Space complexity: O(1)
void mergeSortedArray(
  std::vector<int>& nums1,
  int               m,
  std::vector<int>& nums2,
  int               n) {

  int p1 = m - 1;     // Index of the last VALID element of the 1-st array
  int p2 = n - 1;     // Index of the last element of the 2-nd array
  int p  = m + n - 1; // Index of the last element of the 1-st (result) array

  while ((p1 >= 0) && (p2 >= 0)) {
    // Compare two elements from nums1 and nums2
    // and add the largest one in nums1
    if (nums1[p1] < nums2[p2]) {
      nums1[p--] = nums2[p2--];
    }
    else {
      nums1[p--] = nums1[p1--];
    }
  }

  // Add missing elements from nums2
  for (int i = 0; i < p2 + 1; ++i) {
    nums1[i] = nums2[i];
  }

}

#endif //CODEBASE_MERGE_SORTED_ARRAY_H
