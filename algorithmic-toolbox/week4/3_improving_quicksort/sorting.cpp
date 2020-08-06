#include <iostream>
#include <vector>
#include <cstdlib>
#include <cassert>


/// Intro: The goal in this problem is to redesign a given implementation of the randomized quick sort
///        algorithm so that it works fast even on sequences containing many equal elements.
///
/// Task: To force the given implementation of the quick sort algorithm to efficiently process sequences with
///       few unique elements, your goal is replace a 2-way partition with a 3-way partition. That is, your new
///       partition procedure should partition the array into three parts: < x part, = x part, and > x part.
///
/// Input Format: The first line of the input contains an integer n. The next line contains a sequence of n
///               integers a_0, a_1, ... , a_n−1.
///
/// Output Format: Output this sequence sorted in non-decreasing order.


std::pair<int, int> partition3(std::vector<int> &a, int l, int r) {
  int pivot = a[l];
  int gt = r;
  int lt = l;

  for (int i = l; i <= gt; ++i) {
    // case 1: a[i] == pivot -> ++i

    // case 2: a[i] < pivot
    if (a[i] < pivot) {
      std::swap(a[i], a[lt]);
      ++lt;
    }
    else if (a[i] > pivot) {
      // case 3: a[i] > pivot
      std::swap(a[i], a[gt]);
      --i;
      --gt;
    }
  }

  return std::make_pair(lt, gt);
}


int partition2(std::vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;

  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      std::swap(a[i], a[j]);
    }
  }

  std::swap(a[l], a[j]);

  return j;
}


void randomized_quick_sort(std::vector<int> &a, int l, int r) {
  if (l >= r)
    return;

  int k = l + rand() % (r - l + 1);
  std::swap(a[l], a[k]);

//  int m = partition2(a, l, r);
//  randomized_quick_sort(a, l, m - 1);
//  randomized_quick_sort(a, m + 1, r);

  auto m = partition3(a, l, r);
  randomized_quick_sort(a, l, m.first - 1);
  randomized_quick_sort(a, m.second + 1, r);
}


int main() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }

  randomized_quick_sort(a, 0, a.size() - 1);

  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
  std::cout << std::endl;

  return 0;
}
