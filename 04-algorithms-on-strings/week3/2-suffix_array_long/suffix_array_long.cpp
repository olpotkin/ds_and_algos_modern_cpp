#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <utility>


/// Construct the Suffix Array of a Long String
///
/// Intro: The goal in this problem is to construct the suffix array of a given string again, but this time for
///        a longer string. This will require you to implement an efficient algorithm.
///
/// Task: Construct the suffix array of a string.
///
/// Input: A string Text ending with a “$” symbol.
///
/// Outpu: SuffixArray(Text), that is, the list of starting positions of sorted suffixes separated by spaces.


void print_int_v(std::vector<int>& v) {
  for (int i = 0; i < v.size(); ++i) {
    std::cout << v[i] << " ";
  }
  std::cout << std::endl;
}


int char_to_idx(char x) {
  switch (x) {
    case '$':
      return 0;
    case 'A':
      return 1;
    case 'C':
      return 2;
    case 'G':
      return 3;
    case 'T':
      return 4;
  }
}


void counting_sort_char(const std::string& text, std::vector<int>& order) {
  std::vector<int> c_f(5, 0);
  for (int i = 0; i < text.size(); ++i) {
    c_f[char_to_idx(text[i])]++;
  }
  for (int i = 1; i < c_f.size(); ++i) {
    c_f[i] += c_f[i - 1];
  }
  for (int i = text.size() - 1; i >= 0; --i) {
    order[--c_f[char_to_idx(text[i])]] = i;
  }
}


void compute_class(const std::string& text,
                   std::vector<int>&  order,
                   std::vector<int>&  sort_class) {
  int count = 0;
  sort_class[order[0]] = count;

  for (int i = 1; i < order.size(); ++i) {
    if (text[order[i]] == text[order[i - 1]])
      sort_class[order[i]] = count;
    else
      sort_class[order[i]] = ++count;
  }
}


std::vector<int> sort_double(const std::string& text,
                             int l,
                             std::vector<int>& order,
                             std::vector<int>& sort_class) {
  std::vector<int> new_order(text.size());
  std::vector<int> c_f(text.size(), 0);

  for (int i = 0; i < order.size(); ++i) {
    c_f[sort_class[i]]++;
  }
  for (int i = 1; i < c_f.size(); ++i) {
    c_f[i] += c_f[i - 1];
  }
  for (int i = order.size() - 1; i >= 0; --i) {
    int start = (order[i] - l + order.size()) % order.size();
    new_order[--c_f[sort_class[start]]] = start;
  }
  order.clear();

  return new_order;
}


std::vector<int> update_class(std::vector<int>& order,
                              std::vector<int>& sort_class,
                              int l) {
  std::vector<int> new_sort_class(order.size());
  int count = 0;
  new_sort_class[order[0]] = count;

  for (int i = 1; i < order.size(); ++i) {
    int cur = order[i];
    int cur_mid = (order[i] + l) % order.size();
    int prev = order[i - 1];
    int prev_mid = (order[i - 1] + l) % order.size();
    if (sort_class[cur]!= sort_class[prev] || sort_class[cur_mid] != sort_class[prev_mid]) {
      new_sort_class[order[i]] = ++count;
    }
    else {
      new_sort_class[order[i]] = count;
    }
  }
  sort_class.clear();

  return new_sort_class;
}


// Build suffix array of the string text and return a vector result of the same length as the text
// such that the value result[i] is the index (0-based) in text where the i-th lexicographically smallest
// suffix of text starts.
std::vector<int> BuildSuffixArray(const std::string& text) {
  std::vector<int> order(text.size());
  counting_sort_char(text, order);

  std::vector<int> sort_class(text.size());
  compute_class(text, order, sort_class);

  for (int l = 1; l <= text.size(); l *= 2) {
    order = sort_double(text, l, order, sort_class);
    sort_class = update_class(order, sort_class, l);
  }

  return order;
}


int main() {
  std::string text;
  std::cin >> text;
  std::vector<int> suffix_array = BuildSuffixArray(text);

  for (int i = 0; i < suffix_array.size(); ++i) {
    std::cout << suffix_array[i] << ' ';
  }
  std::cout << std::endl;

  return 0;
}
