#include <algorithm>
#include <iostream>
#include <vector>
#include <cassert>


/// Intro: Majority rule is a decision rule that selects the alternative which has a majority,
///        that is, more than half the votes. Given a sequence of elements a_1, a_2, ... , a_n,
///        you would like to check whether it contains an element that appears more than n/2 times.
///        The running time of naive algorithm is quadratic. Your goal is to use the
///        divide-and-conquer technique to design an O(n*log n) algorithm.
///
/// Task: The goal in this code problem is to check whether an input sequence contains a majority element.
///
/// Input Format: The first line contains an integer n, the next one contains a sequence of n non-negative
///       integers a_0, a_1, ... , a_n−1.
///
/// Output Format: Output 1 if the sequence contains an element that appears strictly more than n/2 times,
///                and 0 otherwise.


int get_majority_element(std::vector<int> &a, int left, int right) {
  if (left == right)
    return -1;

  if (left + 1 == right)
    return a[left];

  std::sort(a.begin(), a.end());

  int mid      = left + (right - left) / 2;
  int major_el = a[mid];
  int counter  = 0;

  for (int i = 0; i < a.size(); ++i) {
    if (a[i] == major_el) {
      ++counter;
    }
  }

  if (counter > a.size() / 2) {
    return 1;
  }

  return -1;
}


void test_solution() {
  /// 2 is the majority element.
  std::vector<int> a_test_01 {2, 3, 9, 2, 2};
  std::cout << "RES 01: " << (get_majority_element(a_test_01, 0, a_test_01.size()) != -1) << std::endl;
  assert(get_majority_element(a_test_01, 0, a_test_01.size()) == 1);
  std::cout << "Test 01 completed..." << std::endl;

  /// There is no majority element in this sequence.
  std::vector<int> a_test_02 {1, 2, 3, 4};
  std::cout << "RES 02: " << (get_majority_element(a_test_02, 0, a_test_02.size()) != -1) << std::endl;
  assert(get_majority_element(a_test_02, 0, a_test_02.size()) == -1);
  std::cout << "Test 02 completed..." << std::endl;
}


int main() {
//  test_solution();

  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }

  std::cout << (get_majority_element(a, 0, a.size()) != -1) << std::endl;

  return 0;
}
