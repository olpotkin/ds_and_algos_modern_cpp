#include <iostream>
#include <vector>
#include <cassert>


/// Intro: Compute the length of a longest common subsequence of three sequences.
///
/// Task: Given three sequences A = (a_1, a_2, ... , a_n), B = (b_1, b_2, ... , b_m),
///       and C = (c_1, c_2, ... , c_l), find the length of their longest common subsequence,
///       i.e., the largest non-negative integer p such that there exist indices
///         1 <= i_1 < i_2 < ... < i_p <= n,
///         1 <= j_1 < j_2 < ... < j_p <= m,
///         1 <= k_1 < k_2 < ... < k_p <= l
///       such that a_i_1 = b_j_1 = c_k_1 , ... , a_i_p = b_j_p = c_k_p
///
/// Input: First line: n. Second line: a_1, a_2, ... , a_n. Third line: m.
///        Fourth line: b_1, b_2, ... , b_m. Fifth line: l. Sixth line: c_1, c_2, ... , c_l.
///
/// Output: Output p.


int lcs3(
  const std::vector<int> &a,
  const std::vector<int> &b,
  const std::vector<int> &c)
{
  int m = a.size();
  int n = b.size();
  int p = c.size();

  std::vector<std::vector<std::vector<int>>> longest (m+1, std::vector<std::vector<int>>(n+1, std::vector<int>(p+1, 0)));

  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      for (int k = 1; k <= p; ++k) {

        if (a[i-1] == b[j-1] && b[j-1] == c[k-1]) {
          longest[i][j][k] = longest[i-1][j-1][k-1] + 1;
        }
        else {
          longest[i][j][k] = std::max(std::max(longest[i-1][j][k], longest[i][j-1][k]), longest[i][j][k-1]);
        }

      }
    }
  }

  return longest[m][n][p];
}


void test_solution() {
  /// A common subsequence of length 2 is (1, 3).
  assert(lcs3(std::vector<int> {1, 2, 3},
              std::vector<int> {2, 1, 3},
              std::vector<int> {1, 3, 5}) == 2);
  std::cout << "Test 01 passed..." << std::endl;

  /// One common subsequence of length 3 in this case is (8, 3, 7). Another one is (8, 1, 7).
  assert(lcs3(std::vector<int> {8, 3, 2, 1, 7},
              std::vector<int> {8, 2, 1, 3, 8, 10, 7},
              std::vector<int> {6, 8, 3, 1, 4, 7}) == 3);
  std::cout << "Test 02 passed..." << std::endl;
}


int main() {
//  test_solution();

  size_t an;
  std::cin >> an;
  std::vector<int> a(an);
  for (size_t i = 0; i < an; i++) {
    std::cin >> a[i];
  }

  size_t bn;
  std::cin >> bn;
  std::vector<int> b(bn);
  for (size_t i = 0; i < bn; i++) {
    std::cin >> b[i];
  }

  size_t cn;
  std::cin >> cn;
  std::vector<int> c(cn);
  for (size_t i = 0; i < cn; i++) {
    std::cin >> c[i];
  }

  std::cout << lcs3(a, b, c) << std::endl;

  return 0;
}
