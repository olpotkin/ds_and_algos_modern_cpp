#include <iostream>
#include <vector>
#include <cassert>


/// Intro: You are given a set of bars of gold and your goal is to take as much gold as possible into your bag.
///        There is just one copy of each bar and for each bar you can either take it or not (hence you cannot
///        take a fraction of a bar).
///
/// Task: Given n gold bars, find the maximum weight of gold that fits into a bag of capacity W.
///
/// Input: The first line of the input contains the capacity W of a knapsack and the number n of bars of gold.
///        The next line contains n integers w_0, w_1, ... ,w_n−1 defining the weights of the bars of gold.
///
/// Output: Output the maximum weight of gold that fits into a knapsack of capacity W.


int optimal_weight(int W, const std::vector<int>& weights) {
  int n = weights.size();
  std::vector<std::vector<int>> value (n+1, std::vector<int>(W+1, 0));

  for (int i = 1; i <= n; ++i) {
    for (int w = 1; w <= W; ++w) {

      value[i][w] = value[i-1][w];

      if (weights[i-1] <= w) {
        int val = value[i-1][w - weights[i-1]] + weights[i-1];
        
        if (value[i][w] < val) {
          value[i][w] = val;
        }
      }

    }
  }

  return value[n][W];
}


void test_solution() {
  /// Here, the sum of the weights of the first and the last bar is equal to 9.
  assert(optimal_weight(10, std::vector<int> {1, 4, 8}) == 9);
  std::cout << "Test 01 passed..." << std::endl;
}


int main() {
//  test_solution();

  int n, W;
  std::cin >> W >> n;

  std::vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }

  std::cout << optimal_weight(W, w) << std::endl;

  return 0;
}
