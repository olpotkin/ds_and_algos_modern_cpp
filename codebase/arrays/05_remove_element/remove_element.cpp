#include <iostream>
#include <vector>
#include <cassert>


/// Remove Elements from Array (in-place)
///
/// Given an array nums and a value val, remove all instances of that
/// value in-place and return the new length.
///
/// Do not allocate extra space for another array, you must do this by modifying
/// the input array in-place with O(1) extra memory.
///
/// The order of elements can be changed. It doesn't matter what you leave beyond the new length.


int removeElement(std::vector<int>& nums, const int val) {
  int i = 0;

  for (int j = 0; j < nums.size(); ++j) {
    if (nums[j] != val) {
      nums[i] = nums[j];
      ++i;
    }
  }

  return i;
}


void test_solution() {
  /// Function should return length = 2, with the first two elements of nums being 2.
  std::vector<int> input_1 {3, 2, 2, 3};
  assert(removeElement(input_1, 3) == 2);
  std::cout << "Test 1 passed..." << std::endl;

  /// Function should return length = 5, with the first five elements of nums
  /// containing 0, 1, 3, 0, and 4.
  std::vector<int> input_2 {0, 1, 2, 2, 3, 0, 4, 2};
  assert(removeElement(input_2, 2) == 5);
  std::cout << "Test 2 passed..." << std::endl;
}


int main() {
  test_solution();

  return 0;
}
