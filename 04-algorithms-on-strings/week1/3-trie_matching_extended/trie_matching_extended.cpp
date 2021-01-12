#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


/// Extend TrieMatching
///
/// Intro: The goal in this problem is to extend the algorithm from the previous problem such that it will be able to
///        handle cases when one of the patterns is a prefix of another pattern. In this case, some patterns are spelled
///        in a trie by traversing a path from the root to an internal vertex, but not to a leaf.
///
/// Task: Extend TrieMatching algorithm so that it handles correctly cases when one of the patterns is a prefix of
///       another one.
///
/// Input: The first line of the input contains a string Text, the second line contains an integer n, each of the
///        following n lines contains a pattern from Patterns = {p_1, . . . , p_n}.
///
/// Output: All starting positions in Text where a string from Patterns appears as a substring in increasing order
///         (assuming that Text is a 0-based array of symbols). If more than one pattern appears starting at
///         position i, output i once.

int const Letters = 4;
int const NA      = -1;

struct Node
{
  int next [Letters];
  bool patternEnd;

  Node () {
    std::fill (next, next + Letters, NA);
	patternEnd = false;
  }
};


int letterToIndex (char letter)
{
  switch (letter) {
    case 'A': return 0; break;
    case 'C': return 1; break;
    case 'G': return 2; break;
    case 'T': return 3; break;
    default: assert (false); return -1;
  }
}


void build_trie (const std::vector<std::string>& patterns, std::vector<Node>& t)
{
  for (int i = 0; i < patterns.size(); i++) {
    int x = 0;
    for (int j = 0; j < patterns[i].size(); j++) {
      int index = letterToIndex(patterns[i][j]);
      if (x >= t.size()) {
        t.resize(x + 1);
      }
      if (t[x].next[index] != -1) {
        x = t[x].next[index];
      }
      else {
        t[x].next[index] = t.size();
        x = t[x].next[index];
        t.resize(x + 1);
      }
    }
    t[x].patternEnd = true;
  }
}


std::vector<int> solve (std::string text, int n, std::vector <std::string> patterns)
{
  std::vector<int> result;

  std::vector<Node> t;
  build_trie(patterns, t);

  for (int i = 0; i < text.size(); i++) {
    int index = letterToIndex(text[i]);
    int x = 0;

    if (t[x].next[index] != -1) {
      bool found = true;

      for (int j = i; !t[x].patternEnd; j++) {
        if (j >= text.size()) {
          found = false;
          break;
        }
        index = letterToIndex(text[j]);
        if (t[x].next[index] != -1) {
          x = t[x].next[index];
        }
        else {
          found = false;
          break;
        }
      }

      if (found) {
        result.push_back(i);
      }
    }
  }

  return result;
}


int main (void)
{
  std::string t;
  std::cin >> t;

  int n;
  std::cin >> n;

  std::vector<std::string> patterns (n);
  for (int i = 0; i < n; i++) {
    cin >> patterns[i];
  }

  std::vector <int> ans;
  ans = solve (t, n, patterns);

  for (int i = 0; i < (int) ans.size (); i++) {
    std::cout << ans[i];
    if (i + 1 < (int) ans.size ()) {
      std::cout << " ";
    }
    else {
      std::cout << endl;
    }
  }

  return 0;
}
