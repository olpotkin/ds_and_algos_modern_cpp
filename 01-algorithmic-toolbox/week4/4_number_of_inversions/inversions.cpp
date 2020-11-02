#include <iostream>
#include <vector>
#include <cassert>


/// Intro: An inversion of a sequence a_0, a_1, ... , a_n−1 is a pair of indices 0 <= i < j < n such that a_i > a_j.
///        The number of inversions of a sequence in some sense measures how close the sequence is to being sorted.
///        For example, a sorted (in non-descending order) sequence contains no inversions at all, while in a
///        sequence sorted in descending order any two elements constitute an inversion
///        (for a total of n(n − 1)/2 inversions).
///
/// Task: The goal in this problem is to count the number of inversions of a given sequence.
///
/// Input Format: The first line contains an integer n, the next one contains a sequence of
///               integers a_0, a_1, ... , a_n−1.
///
/// Output Format: Output the number of inversions in the sequence.
///
/// References:
/// https://www.geeksforgeeks.org/counting-inversions/
/// https://www.cp.eng.chula.ac.th/~prabhas//teaching/algo/algo2008/count-inv.htm
///
/// Algorithm:
/// 1. The idea is similar to merge sort, divide the array into two equal or almost equal halves in each step
///    until the base case is reached.
/// 2. Create a function merge that counts the number of inversions when two halves of the array are merged,
///    create two indices i and j, i is the index for first half and j is an index of the second half.
///    if a[i] is greater than a[j], then there are (mid – i) inversions. Because left and right subarrays are
///    sorted, so all the remaining elements in left-subarray (a[i+1], a[i+2] ... a[mid]) will be greater than a[j].
/// 3. Create a recursive function to divide the array into halves and find the answer by summing the number of
///    inversions is the first half, number of inversion in the second half and the number of inversions by merging the two.
/// 4. The base case of recursion is when there is only one element in the given half.
/// 5. Print the answer
///


long long merge_and_count_split_inversions(
  std::vector<int>& arr,
  std::vector<int>& aux,
  size_t            left,
  size_t            mid,
  size_t            right)
{
  int i = left;
  int j = mid;
  int k = left;

  int inversion_count = 0;

  // Step 1: While there are elements in the left and in the right runs
  while (i <= mid - 1 && j <= right) {
    if (arr[i] <= arr[j]) {
      aux[k++] = arr[i++];
    }
    else {
      aux[k++] = arr[j++];
      inversion_count += (mid - i);
    }
  }

  // Step 2: Copy remaining elements
  // Left side
  while (i <= mid - 1) {
    aux[k++] = arr[i++];
  }
  // Right side
  while (j <= right) {
    aux[k++] = arr[j++];
  }

  // Step 3: Copy back to the original array to reflect sorted order
  for (i = left; i <= right; ++i) {
    arr[i] = aux[i];
  }

  return inversion_count;
}


long long get_number_of_inversions(
  std::vector<int>& a,
  std::vector<int>& b,
  size_t            left,
  size_t            right)
{
  long long number_of_inversions = 0;

  if (right <= left) {
    return number_of_inversions;
  }

  size_t mid = left + (right - left) / 2;

  number_of_inversions += get_number_of_inversions(a, b, left, mid);
  number_of_inversions += get_number_of_inversions(a, b, mid + 1, right);

  number_of_inversions += merge_and_count_split_inversions(a, b, left, mid + 1, right);

  return number_of_inversions;
}


void test_solution() {
  /// The two inversions here are (1, 3) (a_1 = 3 > 2 = a_3) and (2, 3) (a_2 = 9 > 2 = a_3).
  std::vector<int> a_test_01 {2, 3, 9, 2, 9};
  std::vector<int> b_test_01(a_test_01.size());
  long long res_test_01 = get_number_of_inversions(a_test_01, b_test_01, 0, a_test_01.size() - 1);

  std::cout << "Inversions: " << res_test_01 << std::endl;

  assert(res_test_01 == 2);
  std::cout << "Test 01 passed..." << std::endl;
}


int main() {
//  test_solution();

  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }

  std::vector<int> b(a.size());
  std::cout << get_number_of_inversions(a, b, 0, a.size() - 1) << std::endl;

  return 0;
}
