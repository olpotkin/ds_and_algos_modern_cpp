#include <iostream>
#include <cassert>


/// Intro: Design and implement an elementary greedy algorithm used by cashiers
///        all over the world millions of times per day.
///
/// Task: The goal in this problem is to find the minimum number of coins needed to change the input value
///       (an integer) into coins with denominations 1, 5, and 10.
///
/// Input Format: The input consists of a single integer m.
///
/// Constraints: 1 <= m <= 10^3.
///
/// Output Format: Output the minimum number of coins with denominations 1, 5, 10 that changes m.


int get_change(int m) {
  // In this case coins nominals are sorted in decreasing order (to apply greedy strategy)
  int coins [3] = {10, 5, 1};
  int totalCoins = 0;

  for (const int& c : coins) {
    while (m >= c) {
      m -= c;
      ++totalCoins;
    }
  }

  return totalCoins;
}


void test_solution() {
  // 2 = 1 + 1
  assert(get_change(2) == 2);
  // 28 = 10 + 10 + 5 + 1 + 1 + 1
  assert(get_change(28) == 6);

  for (int n = 0; n < 40; ++n) {
    std::cout << "n: " << n
              << " result: " << get_change(n) << std::endl;
  }
}


int main() {
  int m;
  std::cin >> m;

//  test_solution();
  std::cout << get_change(m) << std::endl;

  return 0;
}
