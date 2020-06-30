#ifndef CODEBASE_SHELL_SORT_H
#define CODEBASE_SHELL_SORT_H


#include <utility>


/// Idea: Move entries more than one position at a time by h-sorting the array.
/// Which increment sequence to use? (opened question)
/// h = (3x + 1) is good.
/// 1, 4, 13, 40, 121, ...
///
/// Note: Based on Insertion Sort.
/// Note: Used in embedded systems.


template <typename T>
void ShellSort(T& a) {
  int N = a.size();
  int h = 1;

  while (h < N/3) {
    h = 3*h + 1;  // 1, 4, 13, 40, 121, ...
  }

  // h-sort the array
  while (h >= 1) {
    // Insertion sort
    for (int i = h; i < N; ++i) {
      for (int j = i; (j >= h) && (a[j] < a[j-h]); j -= h) {
        std::swap(a[j], a[j-h]);
      }
    }
    h = h/3; // Move to the next increment
  }
}

#endif //CODEBASE_SHELL_SORT_H
