#ifndef CODEBASE_INSERTION_SORT_H
#define CODEBASE_INSERTION_SORT_H


#include <utility>


/// 1. In iteration i, swap a[i] with each larger entry to its left.
///
/// Note: If array sorted - only validates it.
/// Note: Reverse order is the worst case -> very slow


template <typename T>
void InsertionSort(T& a) {
  int N = a.size();

  for (int i = 0; i < N; ++i) {

    for (int j = i; j > 0; --j) {
      if (a[j] < a[j-1]) {
        std::swap(a[j], a[j-1]);
      }
      else { break; }
    }
  }
}

#endif //CODEBASE_INSERTION_SORT_H
