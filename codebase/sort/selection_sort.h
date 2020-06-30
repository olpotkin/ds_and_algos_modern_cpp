#ifndef CODEBASE_SELECTION_SORT_H
#define CODEBASE_SELECTION_SORT_H

#include <utility>


/// 1. In iteration i, find index min of smallest remaining entry
/// 2. Swap a[i] and a[min]
///
/// Note: Even if array sorted - doing all the steps.


template <typename T>
void SelectionSort(T& a) {
  int N = a.size();   // N - size of the sorted container

  for (int i = 0; i < N; ++i) {
    int min = i;

    for (int j = i + 1; j < N; ++j) {
      if (a[j] < a[min]) {
        min = j;
      }
    }

    std::swap(a[i], a[min]);
  }
}

#endif //CODEBASE_SELECTION_SORT_H
