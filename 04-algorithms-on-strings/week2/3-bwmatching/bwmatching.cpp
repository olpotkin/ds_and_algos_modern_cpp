#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>


/// Implement BetterBWMatching
///
/// Task: Implement BetterBWMatching algorithm.
///
/// Input: A string BWT(Text), followed by an integer n and a collection of n strings
///        Patterns = {p_1, ... , p_n} (on one line separated by spaces).
///
/// Output: A list of integers, where the 𝑖-th integer corresponds to the number of substring matches
///         of the i-th member of Patterns in Text.


class BWMatching {
  const std::size_t  N;
  const std::string& bwt;
  std::vector<std::vector<int>> symbolsCounterByIndex;
  std::vector<int>              symbolsCounter;

  inline int getIndex(char s) noexcept {
    switch (s) {
      case 'A':
        return 0;
      case 'C':
        return 1;
      case 'G':
        return 2;
      case 'T':
        return 3;
      default:
        return 4;
    }
  }

  inline int getFirstPosition(char s) noexcept
  {
    switch (s) {
      case 'A':
        return 1;
      case 'C':
        return symbolsCounter[0] + 1;
      case 'G':
        return symbolsCounter[1] + symbolsCounter[0] + 1;
      case 'T':
        return symbolsCounter[2] + symbolsCounter[1] + symbolsCounter[0] + 1;
      default:
        return 0;
    }
  }

  inline int getSymbolsCountByIndex(int i, char s) noexcept {
    return symbolsCounterByIndex[getIndex(s)][i];
  }

  inline bool isSymbolInTopBottomRange(int top, int bottom, char s) noexcept {
    return symbolsCounterByIndex[getIndex(s)][bottom] > symbolsCounterByIndex[getIndex(s)][top];
  }

public:
  explicit BWMatching(const std::string& bwt)
  : N{ bwt.size() }
  , bwt{ bwt }
  , symbolsCounter{ std::vector<int>(5) }
  , symbolsCounterByIndex{ std::vector<std::vector<int> >(5, std::vector<int>(bwt.size() + 1)) }
  {
    for (int i = 1; i <= N; ++i) {
      for (auto& o : symbolsCounterByIndex) {
        o[i] = o[i - 1];
      }
      ++symbolsCounter[getIndex(bwt[i - 1])];
      ++symbolsCounterByIndex[getIndex(bwt[i - 1])][i];
    }
  }

  int getNumOfPatternOccurences(const std::string& pattern) {
    if (pattern.size() == 1) {
      return symbolsCounter[getIndex(pattern[0])];
    }

    int top = 0;
    int bottom = bwt.size() - 1;
    int k = pattern.size();

    while (top <= bottom) {
      if (k) {
        char s = pattern[--k];
        if (isSymbolInTopBottomRange(top, bottom + 1, s)) {
          top = getFirstPosition(s) + getSymbolsCountByIndex(top, s);
          bottom = getFirstPosition(s) + getSymbolsCountByIndex(bottom + 1, s) - 1;
        }
        else {
          return 0;
        }
      }
      else {
        return (bottom - top) + 1;
      }
    }
  }
};


int main()
{
  std::string bwt;
  std::cin >> bwt;

  BWMatching bwm(bwt);

  int s;
  std::cin >> s;

  while (s--) {
    std::string pattern;
    std::cin >> pattern;
    std::cout << bwm.getNumOfPatternOccurences(pattern) << '\n';
  }

  return 0;
}
