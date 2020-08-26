#include <iostream>
#include <vector>
#include <cassert>


/// Merge Sorted Array
///
/// Intro: Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
///
/// The number of elements initialized in nums1 and nums2 are m and n respectively.
/// You may assume that nums1 has enough space (size that is equal to m + n) to hold additional elements from nums2.
///
/// Source: https://leetcode.com/explore/learn/card/fun-with-arrays/525/inserting-items-into-an-array/3253/
///
/// Time complexity:  O(n + m)
/// Space complexity: O(1)


void mergeSortedArray(
  std::vector<int>&       nums1,
  int                     m,
  const std::vector<int>& nums2,
  int                     n)
{
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


void test_solution() {
  std::vector<int> expected_1 {1, 2, 2, 3, 5, 6};
  std::vector<int> nums_1 {1, 2, 3, 0, 0, 0};
  mergeSortedArray(nums_1, 3, std::vector<int> {2, 5, 6}, 3);
  assert(nums_1 == expected_1);
  std::cout << "Test 1 passed..." << std::endl;
}


int main() {
  test_solution();

  return 0;
}
