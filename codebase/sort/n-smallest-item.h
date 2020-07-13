#ifndef CODEBASE_N_SMALLEST_ITEM_H
#define CODEBASE_N_SMALLEST_ITEM_H


#include <random>


///----------------------------------------------
/// GOAL
/// Given an array on N elements, find K-th smallest item
///
/// Possible just sort and iterate to K (O(N*logN)), but Goal is O(N)
///----------------------------------------------

// Partition from QuickSort algo will be used
template<typename T>
int Partitioning(T& a, int low, int hi);


template<typename T>
int Selection(T& a, const int& k) {
  // NOTE: Shuffle needs performance guarantee
  std::random_device rd;
  std::mt19937 g(rd());
  std::shuffle(a.begin(), a.end(), g);

  int low = 0;
  int hi = a.size() - 1;

  while (hi > low) {
    int j = Partitioning(a, low, hi);

    if      (j < k) low = j + 1;
    else if (j > k) hi = j - 1;
    else {
      return a[k];
    }
    }
  return a[k];
}


template<typename T>
int Partitioning(T& a, int low, int hi) {
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

#endif //CODEBASE_N_SMALLEST_ITEM_H
