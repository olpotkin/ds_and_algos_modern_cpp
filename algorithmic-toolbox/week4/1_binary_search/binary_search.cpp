#include <iostream>
#include <cassert>
#include <vector>


/// Intro: In this problem, you will implement the binary search algorithm that allows searching very
///        efficiently (even huge) lists, provided that the list is sorted.
///
/// Task: The goal in this code problem is to implement the binary search algorithm.
///
/// Input Format: The first line of the input contains an integer n and a sequence a_0 < a_1 < ... < a_n-1
///               of n pairwise distinct positive integers in increasing order. The next line contains an
///               integer k and k positive integers b_0, b_1, ... , b_k-1.
///
/// Output Format: For all i from 0 to k − 1, output an index 0 <= j <= n − 1 such that a_j = b_i or −1
///                if there is no such index.


int binary_search(const std::vector<long long> &a, long long x) {
  int left   = 0;
  int right  = static_cast<int>(a.size());
  int result = -1;

  while (left <= right) {
    int mid = (left + right) / 2;

    if (a[mid] < x) {
      // Ignore left part if x is greater than mid
      left = mid + 1;
    }
    else if (a[mid] > x) {
      // Ignore right part if x is smaller than mid
      right = mid - 1;
    }
    else {
      result = mid;
      break;
    }
  }

  return result;
}


int linear_search(const std::vector<long long> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}


void test_solution() {
  /// In this sample, we are given an increasing sequence a_0 = 1, a_1 = 5, a_2 = 8, a_3 = 12, a_4 = 13 of length
  /// five and five keys to search: 8, 1, 23, 1, 11. We see that a_2 = 8 and a_0 = 1, but the keys 23 and 11 do
  /// not appear in the sequence a. For this reason, we output a sequence 2, 0, −1, 0, −1.
  std::vector<long long> a_test_01 { 1, 5, 8, 12, 13 };
  std::vector<long long> b_test_01 { 8, 1, 23, 1, 11 };
  std::vector<long long> expected_test_01 { 2, 0, -1, 0, -1 };

  for (int i = 0; i < b_test_01.size(); ++i) {
    std::cout << "Test 01: searching for "
              << b_test_01[i] << " index is "
              << linear_search(a_test_01, b_test_01[i]) << std::endl;
    assert(linear_search(a_test_01, b_test_01[i]) == expected_test_01[i]);
    assert(linear_search(a_test_01, b_test_01[i]) == binary_search(a_test_01, b_test_01[i]));
  }
  std::cout << "Test 01 passed..." << std::endl;
}


int main() {
//  test_solution();

  int n = 0;
  std::cin >> n;

  std::vector<long long> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }

  int m = 0;
  std::cin >> m;

  std::vector<long long> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }

  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    std::cout << binary_search(a, b[i]) << ' ';
  }
  std::cout << std::endl;

  return 0;
}
