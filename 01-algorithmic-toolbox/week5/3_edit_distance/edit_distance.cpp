#include <iostream>
#include <string>
#include <vector>
#include <cassert>


/// Edit Distance
///
/// Intro: The edit distance between two strings is the minimum number of operations (insertions, deletions,
///        and substitutions of symbols) to transform one string into another. It is a measure of similarity
///        of two strings. Edit distance has applications, for example, in computational biology, natural
///        language processing, and spell checking.
///        Your goal in this problem is to compute the edit distance between two strings.
///
/// Task: The goal of this problem is to implement the algorithm for computing the edit distance between
///       two strings.
///
/// Input: Each of the two lines of the input contains a string consisting of lower case latin letters.
///
/// Output: Output the edit distance between the given two strings.


int edit_distance(const std::string &str1, const std::string &str2) {
  const int str1_len = str1.size();
  const int str2_len = str2.size();

  std::vector<std::vector<int>> dp(str1_len + 1, std::vector<int>(str2_len + 1, 0));

  for (int i = 0; i <= str1_len; ++i) {
    dp[i][0] = i;
  }
  for (int i = 0; i <= str2_len; ++i) {
    dp[0][i] = i;
  }

  int cost = 0;

  for (int i = 1; i <= str1_len; ++i) {
    for (int j = 1; j <= str2_len; ++j) {

      if (str1[i-1] == str2[j-1]) {
        cost = 0;
      }
      else {
        cost = 1;
      }
      dp[i][j] = std::min(std::min(dp[i-1][j], dp[i][j-1]) + 1,
                          dp[i-1][j-1] + cost);
    }
  }

  return dp[str1_len][str2_len];
}


void test_solution() {
  assert (edit_distance("ab", "ab") == 0);
  std::cout << "Test 01 passed..." << std::endl;

  /// An alignment of total cost 3
  assert (edit_distance("short", "ports") == 3);
  std::cout << "Test 02 passed..." << std::endl;

  /// An alignment of total cost 5
  assert (edit_distance("editing", "distance") == 5);
  std::cout << "Test 03 passed..." << std::endl;
}


int main() {
//  test_solution();

  std::string str1;
  std::string str2;
  std::cin >> str1 >> str2;

  std::cout << edit_distance(str1, str2) << std::endl;

  return 0;
}
