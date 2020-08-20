#include <iostream>
#include <vector>
#include <cassert>


/// Longest Common Subsequence of Two Sequences
///
/// Intro: Compute the length of a longest common subsequence of two sequences.
///
/// Task: Given two sequences A = (a_1, a_2, ... , a_n) and B = (b_1, b_2, ... , b_m), find the length
///       of their longest common subsequence, i.e., the largest non-negative integer p such that there
///       exist indices 1 <= i_1 < i_2 < ... < i_p <= n 
///       and 1 <= j_1 < j_2 < ... < j_p <= m, such that a_i_1 = b_j_1 , ... , a_i_p = b_j_p.
///
/// Input: First line: n. Second line: a_1, a_2, ... , a_n. Third line: m. Fourth line: b_1, b_2, ... , b_m.
///
/// Output: Output p.


int lcs2(const std::vector<int>& a, const std::vector<int>& b) {
  int m = a.size();
  int n = b.size();

  std::vector<std::vector<int>> longest (m+1, std::vector<int>(n+1, 0));

  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (a[i-1] == b[j-1]) {
        longest[i][j] = longest[i-1][j-1] + 1;
      }
      else {
        longest[i][j] = std::max(longest[i-1][j], longest[i][j-1]);
      }
    }
  }

  return longest[m][n];
}


void test_solution() {
  /// A common subsequence of length 2 is (2, 5).
  assert(lcs2(std::vector<int> {2, 7, 5}, std::vector<int> {2, 5}) == 2);
  std::cout << "Test 01 passed..." << std::endl;

  /// The two sequences do not share elements.
  assert(lcs2(std::vector<int> {7}, std::vector<int> {1, 2, 3, 4}) == 0);
  std::cout << "Test 02 passed..." << std::endl;

  /// One common subsequence is (2, 7). Another one is (2, 8).
  assert(lcs2(std::vector<int> {2, 7, 8, 3}, std::vector<int> {5, 2, 8, 7}) == 2);
  std::cout << "Test 03 passed..." << std::endl;
}


int main() {
//  test_solution();

  size_t n;
  std::cin >> n;
  std::vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  std::vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;

  return 0;
}
