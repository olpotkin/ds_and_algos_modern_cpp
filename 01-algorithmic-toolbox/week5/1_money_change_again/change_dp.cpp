#include <iostream>
#include <vector>
#include <cassert>
#include <climits>


/// Intro: As we already know, a natural greedy strategy for the change problem does not work correctly for any set of
///        denominations. For example, if the available denominations are 1, 3, and 4, the greedy algorithm will change
///        6 cents using three coins (4 + 1 + 1) while it can be changed using just two coins (3 + 3). Your goal now is
///        to apply dynamic programming for solving the Money Change Problem for denominations 1, 3, and 4.
///
/// Input Format: Integer [money]
///
/// Output Format: The minimum number of coins with denominations [1, 3, 4] that changes [money].
///


int get_change(const int m) {
  std::vector<int> coins {1, 3, 4};
  int minNumCoins[m+1];
  
  minNumCoins[0] = 0;
  int numCoins = 0;

  for (int i = 1; i <= m; ++i) {
    minNumCoins[i] = INT_MAX;

    for (int j = 0; j < coins.size(); ++j) {
      if (i >= coins[j]) {
        numCoins = minNumCoins[i - coins[j]] + 1;

        if (numCoins < minNumCoins[i]) {
          minNumCoins[i] = numCoins;
        }
      }
    }
  }

  return minNumCoins[m];
}


void test_solution() {
  /// 2 = 1 + 1
  assert(get_change(2) == 2);
  std::cout << "Test 01 passed..." << std::endl;

  /// 34 = 3 + 3 + 4 + 4 + 4 + 4 + 4 + 4 + 4
  assert(get_change(34) == 9);
  std::cout << "Test 02 passed..." << std::endl;
}


int main() {
//  test_solution();

  int m;
  std::cin >> m;

  std::cout << get_change(m) << std::endl;

  return 0;
}
