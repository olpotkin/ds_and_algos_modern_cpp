#ifndef CODEBASE_QUICK_SORT_H
#define CODEBASE_QUICK_SORT_H


#include <random>
#include <stack>


///----------------------------------------------
/// BASIC PLAN
/// 1. Shuffle the Array.
/// 2. Partition so that, for some j:
///    - entry a[j] is in place;
///    - no larger entry to the left of j;
///    - no smaller entry to the right of j.
/// 3. Sort each piece recursively.
///----------------------------------------------
/// Phase I: Repeat until i and j pointers cross:
///    - Scan i from left to right so long as a[i] < a[low];
///    - Scan j from right to left so long as a[j] > a[low];
///    - Exchange a[i] with a[j].
/// Phase II: When pointers cross:
///    - Exchange a[low] with a[j]
///----------------------------------------------
template<typename T>
int Partition(T& a, int low, int hi);

template<typename T>
void QuickSortRecursive(T& a, int low, int hi);

template<typename T>
void QuickSortIterative(T& a, int low, int hi);


template<typename T>
void QuickSort(T& a) {
  // NOTE: Shuffle needs performance guarantee
  std::random_device rd;
  std::mt19937 g(rd());
  std::shuffle(a.begin(), a.end(), g);

  // QuickSortRecursive(a, 0, a.size() - 1);
  QuickSortIterative(a, 0, a.size() - 1);
}


/// @brief Recursive approach
template<typename T>
void QuickSortRecursive(T& a, int low, int hi) {
  if (hi <= low) return;

  int j = Partition(a, low, hi);
  QuickSortRecursive(a, low, j - 1);
  QuickSortRecursive(a, j + 1, hi);
}


/// @brief Iterative approach
template<typename T>
void QuickSortIterative(T& a, int low, int hi) {
  std::stack<std::pair<int, int>> stk;
  stk.push(std::make_pair(low, hi));

  // Run till stack is not empty
  while (!stk.empty()) {
    // Pop top pair from the stack
    // and get subarray starting and ending indices
    low = stk.top().first;
    hi = stk.top().second;
    stk.pop();

    int j = Partition(a, low, hi);

    // Push sub-array indices containing elements
    // that are less than current j (pivot)
    if (j - 1 > low) {
      stk.push(std::make_pair(low, j -1));
    }

    // Push sub-array indices containing elements
    // that are higher than current j (pivot)
    if (j + 1 < hi) {
      stk.push(std::make_pair(j + 1, hi));
    }
  }
}


template<typename T>
int Partition(T& a, int low, int hi) {
  int i = low;
  int j = hi + 1;

  while (true) {
    // Find item on left to swap
    while (a[++i] < a[low]) {
      if (i == hi) break;
    }

    // Find item on right to swap
    while (a[low] < a[--j]) {
      if (j == low) break;
    }

    // Check if pointers cross
    if (i >= j) break;

    std::swap(a[i], a[j]);
  }

  // Swap with partitioning item
  std::swap(a[low], a[j]);

  // Return index of item now known to be in place
  return j;
}

#endif //CODEBASE_QUICK_SORT_H
