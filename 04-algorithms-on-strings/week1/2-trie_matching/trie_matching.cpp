#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>


/// Implement TrieMatching
///
/// Intro: Given a string Text and Trie(Patterns), we can quickly check whether any string from Patterns matches a
///        prefix of Text. To do so, we start reading symbols from the beginning of Text and see what string these
///        symbols “spell” as we proceed along the path downward from the root of the trie, as illustrated in the
///        pseudocode below. For each new symbol in Text, if we encounter this symbol along an edge leading down
///        from the present node, then we continue along this edge; otherwise, we stop and conclude that no string in
///        Patterns matches a prefix of Text. If we make it all the way to a leaf, then the pattern spelled out by this
///        path matches a prefix of Text.
///
/// Task: Implement TrieMatching algorithm.
///
/// Input: The first line of the input contains a string Text, the second line contains an integer n, each of the following
///        n lines contains a pattern from Patterns = {p_1, . . . , p_n}.
///
/// Output: All starting positions in Text where a string from Patterns appears as a substring in increasing order
///         (assuming that Text is a 0-based array of symbols).


int const Letters =    4;
int const NA      =   -1;


struct Node
{
  int next [Letters];
  
  Node () {
    std::fill (next, next + Letters, NA);
  }
  
  bool isLeaf () const {
    return (next[0] == NA && next[1] == NA && next[2] == NA && next[3] == NA);
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


void build_trie (const std::vector <std::string>& patterns, std::vector<Node>& t)
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
  }
}


std::vector <int> solve (const std::string& text, int n, const std::vector <std::string>& patterns)
{
  std::vector <int> result;

  std::vector<Node> t;
  build_trie(patterns, t);

  for (int i = 0; i < text.size(); i++) {
    int index = letterToIndex(text[i]);
    int x = 0;

    if (t[x].next[index] != -1) {
      bool found = true;
      for (int j = i; !t[x].isLeaf(); j++) {
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

  std::vector <std::string> patterns (n);
  for (int i = 0; i < n; i++) {
    std::cin >> patterns[i];
  }

  std::vector <int> ans;
  ans = solve (t, n, patterns);

  for (int i = 0; i < (int) ans.size (); i++) {
    std::cout << ans[i];
    if (i + 1 < (int) ans.size ()) {
      std::cout << " ";
    }
    else {
      std::cout << std::endl;
    }
  }

  return 0;
}
