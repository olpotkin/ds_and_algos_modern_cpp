#include <algorithm>
#include <iostream>
#include <string>
#include <vector>


/// Reconstruct a String from its Burrows–Wheeler Transform
///
/// Intro: In the previous problem, we introduced the Burrows–Wheeler transform of a string Text. In this problem,
///        we give you the opportunity to reverse this transform.
///
/// Task: Reconstruct a string from its Burrows–Wheeler transform.
///
/// Input: A string Transform with a single “$” sign.
///
/// Output: The string Text such that BWT(Text) = Transform. (There exists a unique such string.)


std::string InverseBWT(const std::string& bwt) {
  std::string text = "";

  std::vector<std::pair<char, int> > col1(bwt.size());
  for (int i = 0; i < bwt.size(); ++i) {
    col1[i] = std::make_pair(bwt[i], i);
  }

  std::sort(col1.begin(), col1.end());

  std::pair<char, int> symbol = col1[0];
  for (int i = 0; i < bwt.size(); ++i) {
    symbol = col1[symbol.second];
    text += symbol.first;
  }

  return text;
}


int main() {
  std::string bwt;
  std::cin >> bwt;
  std::cout << InverseBWT(bwt) << std::endl;

  return 0;
}
