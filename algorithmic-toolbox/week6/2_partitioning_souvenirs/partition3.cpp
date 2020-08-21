#include <iostream>
#include <vector>
#include <cassert>
#include <numeric>


/// Partitioning Souvenirs
///
/// Intro: You and two of your friends have just returned back home after visiting various countries.
///        Now you would like to evenly split all the souvenirs that all three of you bought.
///
/// Input: The first line contains an integer n. The second line contains integers v_1, v_2, ... , v_n
///        separated by spaces.
///
/// Output: Output 1, if it possible to partition v_1, v_2, ... , v_n into three subsets with equal sums,
///         and 0 otherwise.


int partition3(const std::vector<int>& A) {
  const int numParts = 3;
  int sum = std::accumulate(A.begin(), A.end(), 0);

  if (sum % numParts) return 0;

  // Descrete knapsack without repetitions
  int n = A.size();
  std::vector<std::vector<int>> value(sum / numParts + 1, std::vector<int>(n+1, 0));

  for (int i = 1; i <= n; ++i) {
    int w_i = A[i-1];

    // Smaller problems
    for (int w = 1; w <= sum / numParts; ++w) {
      value[w][i] = value[w][i-1];

      if (w >= w_i) {
        value[w][i] = std::max(value[w-w_i][i-1] + w_i, value[w][i-1]);
      }
    }
  }

  return (value[sum / numParts][n]) == (sum / numParts);
}


void test_solution() {
  assert(partition3(std::vector<int> {3, 3, 3, 3}) == 0);
  std::cout << "Test 01 passed..." << std::endl;

  assert(partition3(std::vector<int> {40}) == 0);
  std::cout << "Test 02 passed..." << std::endl;
  
  /// 34 + 67 + 17 = 23 + 59 + 1 + 17 + 18 = 59 + 2 + 57.
  assert(partition3(std::vector<int> {17, 59, 34, 57, 17, 23, 67, 1, 18, 2, 59}) == 1);
  std::cout << "Test 03 passed..." << std::endl;

  /// 1 + 3 + 7 + 25 = 2 + 4 + 5 + 7 + 8 + 10 = 5 + 12 + 19.
  assert(partition3(std::vector<int> {1, 2, 3, 4, 5, 5, 7, 7, 8, 10, 12, 19, 25}) == 1);
  std::cout << "Test 04 passed..." << std::endl;
}


int main() {
//  test_solution();

  int n;
  std::cin >> n;

  std::vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
  }

  std::cout << partition3(A) << std::endl;

  return 0;
}
