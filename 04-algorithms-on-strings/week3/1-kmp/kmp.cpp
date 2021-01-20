#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

/// Find All Occurrences of a Pattern in a String
///
/// Intro: In this problem, we ask a simple question: how many times one string occurs as a substring of another?
///        Recall that different occurrences of a substring can overlap with each other. For example, ATA occurs three
///        times in CGATATATCCATAG.
///
/// Task: Find all occurrences of a pattern in a string.
///
/// Input: Strings 'Pattern' and 'Genome'.
///
/// Output: All starting positions in 𝐺𝑒𝑛𝑜𝑚𝑒 where 𝑃𝑎𝑡𝑡𝑒𝑟𝑛 appears as a substring (using 0-based indexing as usual).


void compute_prefix(std::string& p_t,
                    std::vector<int>& s) {
  int border = 0;

  for (int i = 1; i < p_t.size(); ++i) {
    while (border > 0 && p_t[i] != p_t[border]) {
      border = s[border - 1];
    }
    if (p_t[i] == p_t[border]) {
      ++border;
      s[i] = border;
    }
    if (border == 0) {
      s[i] = 0;
    }
  }
}


// Find all occurrences of the pattern in the text and return a vector with all positions in the text (starting from 0)
// where the pattern starts in the text.
std::vector<int> find_pattern(const std::string& pattern,
                              const std::string& text) {
  std::vector<int> result;

  std::string p_t = pattern + '$' + text;
  std::vector<int> s(p_t.size());
  compute_prefix(p_t, s);

  for (int i = pattern.size() + 1; i < p_t.size(); ++i) {
    if (s[i] == pattern.size()) {
      result.push_back(i - 2 * pattern.size());
    }
  }

  return result;
}


int main() {
  std::string pattern;
  std::string text;
  std::cin >> pattern;
  std::cin >> text;

  std::vector<int> result = find_pattern(pattern, text);
  for (int i = 0; i < result.size(); ++i) {
    printf("%d ", result[i]);
  }
  printf("\n");

  return 0;
}
