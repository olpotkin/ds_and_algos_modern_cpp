#include <iostream>
#include <cassert>
#include <vector>     //std::vector
#include <algorithm>  //std::sort


/// Problem: You have n ads to place on a popular Internet page. For each ad, you know how much is
///          the advertiser willing to pay for one click on this ad. You have set up n slots on your
///          page and estimated the expected number of clicks per day for each slot. Now, your goal
///          is to distribute the ads among the slots to maximize the total revenue.
///
/// Task: Given two sequences a_1, a_2, ... , a_n (a_i is the profit per click of the i-th ad)
///       and b_1, b_2, ... , b_n (b_i is the average number of clicks per day of the i-th slot),
///       we need to partition them into n pairs (a_i, b_j) such that the sum of their products is maximized.
///
/// Input: The first line contains an integer n, the second one contains a sequence of integers 
///        a_1, a_2, ... , a_n, the third one contains a sequence of integers b_1, b_2, ... , b_n.
///
///Output Format. Output the maximum value of sum(1->n): a_i * c_i, where c_1, c_2, ... , c_n is a
///               permutation of b_1, b_2, ... , b_n.


long long max_dot_product(std::vector<int> a, std::vector<int> b) {
  long long result = 0;

  std::sort(a.begin(), a.end(), std::greater<int>());
  std::sort(b.begin(), b.end(), std::greater<int>());

  for (size_t i = 0; i < a.size(); i++) {
    result += static_cast<long long>(a[i]) * b[i];
  }

  return result;
}


void test_solution() {
  /// 897 = 23 * 39
  assert(max_dot_product(std::vector<int> {23}, std::vector<int> {39}) == 897);
  std::cout << "Test 01 passed..." << std::endl;

  /// 23 = 3 · 4 + 1 · 1 + (−5) · (−2)
  assert(max_dot_product(std::vector<int> {1, 3, -5}, std::vector<int> {-2, 4, 1}) == 23);
  std::cout << "Test 02 passed..." << std::endl;
}


int main() {
//  test_solution();

  size_t n;
  std::cin >> n;

  std::vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  std::vector<int> b(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }

  std::cout << max_dot_product(a, b) << std::endl;

  return 0;
}
