#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

/// Construct the Burrows–Wheeler Transform of a String
///
/// Intro: Our goal is to further improve on the memory requirements of the suffix array. Given a string Text, form
///        all possible cyclic rotations of Text; a cyclic rotation is defined by chopping off a suffix from the end
///        of Text and appending this suffix to the beginning of Text.
///        Next — similarly to suffix arrays — order all the cyclic rotations of Text lexicographically to form
///        a |Text| * |Text| matrix of symbols that we call the Burrows–Wheeler matrix and denote by M(Text).
///        Note that the first column of M(Text) contains the symbols of Text ordered lexicographically.
///        In turn, the second column of M(Text) contains the second symbols of all cyclic rotations of Text, and so it too
///        represents a (different) rearrangement of symbols from Text. The same reasoning applies to show that any
///        column of M(Text) is some rearrangement of the symbols of Text. We are interested in the last column of
//         M(Text), called the Burrows–Wheeler transform of Text, or BWT(Text).
///
/// Task: Construct the Burrows–Wheeler transform of a string.
///
/// Input: A string Text ending with a "$" symbol.
///
/// Output: BWT(Text)


std::string BWT(const std::string& text) {
  std::string result = "";

  std::vector<std::string> m(text.size());
  for (int i = 0; i < m.size(); ++i) {
  	m[i] = text.substr(i) + text.substr(0, i);
  }

  std::sort(m.begin(), m.end());

  for (int i = 0; i < m.size(); ++i) {
  	result += m[i][m.size() - 1];
  }

  return result;
}


int main() {
  std::string text;
  std::cin >> text;
  std::cout << BWT(text) << std::endl;

  return 0;
}
