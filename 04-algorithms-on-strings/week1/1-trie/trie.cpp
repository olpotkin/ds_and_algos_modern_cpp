#include <string>
#include <iostream>
#include <vector>
#include <map>


/// Construct a Trie from a Collection of Patterns
///
/// Intro: Reads will form a collection of strings Patterns that we wish to match against a reference genome Text. For
///        each string in Patterns, we will first find all its exact matches as a substring of Text (or conclude that it
///        does not appear in Text). When hunting for the cause of a genetic disorder, we can immediately eliminate
///        from consideration areas of the reference genome where exact matches occur.
///
/// Problem: Find all occurrences of a collection of patterns in a text.
///
/// Input: A string Text and a collection Patterns containing (shorter) strings.
///
/// Output: All starting positions in Text where a string from Patterns appears as a substring.
///
/// To solve this problem, we will consolidate Patterns into a directed tree called a trie (pronounced “try”), which is
/// written Trie(Patterns) and has the following properties.
/// - The trie has a single root node with indegree 0, denoted root.
/// - Each edge of Trie(Patterns) is labeled with a letter of the alphabet.
/// - Edges leading out of a given node have distinct labels.
/// - Every string in Patterns is spelled out by concatenating the letters along some path from the root downward.
/// - Every path from the root to a leaf, or node with outdegree 0, spells a string from Patterns.

typedef std::map<char, int> edges;
typedef std::vector<edges> trie;


trie build_trie(std::vector<std::string>& patterns) {

  if (patterns.empty()) {
    return trie{};
  }
  
  trie t{ edges{} };
  
  int root{ 0 };
  int cnt{ 0 };

  for (auto& p : patterns) {
    int current = root;
    
    for (auto s : p) {
      if (t[current].find(s) != t[current].end()) {
        current = t[current][s];
      }
      else {
        t.emplace_back(edges{});
        t[current][s] = ++cnt;
        current = cnt;
      }
    }
  }

  return t;
}


int main() {
  size_t n;
  std::cin >> n;
  std::vector<std::string> patterns;

  for (size_t i = 0; i < n; ++i) {
    std::string s;
    std::cin >> s;
    patterns.push_back(s);
  }

  trie t = build_trie(patterns);
  for (size_t i = 0; i < t.size(); ++i) {
    for (const auto& j : t[i]) {
      std::cout << i << "->" << j.second << ":" << j.first << "\n";
    }
  }

  return 0;
}
