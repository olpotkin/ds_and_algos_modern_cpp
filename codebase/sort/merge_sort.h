#ifndef CODEBASE_MERGE_SORT_H
#define CODEBASE_MERGE_SORT_H


#include <utility>


/// Declare helper method 1
template<typename T>
void Merge2Subarrays(T& a, T& aux, const int& low, const int& mid, const int& hi);


/// BASIC PLAN:
/// 1. Divide array into 2 halves
/// 2. Recursively (or in the cycle) sort each half
/// 3. Merge 2 halves
///
/// GOAL:
/// Given 2 sorted sub-arrays a[low] to a[mid] and a[mid+1] to a[hi],
/// replace it with sorted sub-array a[low] to a[hi].

template <typename T>
void MergeSort(T& a) {
  int N = a.size();

  // Create helper container with the same size as original (a)
  T aux(N, -1);

  // sz - size of sub-array: 1, 2, 4, 8, ...
  for (int sz = 1; sz < N; sz = sz+sz) {
    // low - starting index of each sub-array: 0, 2, 4, 8, ...
    for (int low = 0; low < N - sz; low += sz+sz) {
      int mid = low + sz - 1;
      int hi = std::min(low + sz + sz - 1, N - 1);

      Merge2Subarrays(a, aux, low, mid, hi);
    }
  }
}


/// @brief Merge 2 sorted sub-arrays
///
/// @tparam T - container type (vector, array, string, etc.)
/// @param a - container (array/vector with 2 sorted sub-arrays)
/// @param aux - container to store data sequence before sorting
/// @param low - start of first sub-array
/// @param mid - tail of first sub-array and start of second
/// @param hi - tail of second sub-array
template<typename T>
void Merge2Subarrays(T& a, T& aux, const int& low, const int& mid, const int& hi) {
  // Copy sequence to aux[]
  for (int k = low; k <= hi; ++k) {
    aux[k] = a[k];
  }

  int i = low;
  int j = mid + 1;

  for (int k = low; k <= hi; ++k) {
    if      (i > mid)         { a[k] = aux[j++]; }
    else if (j > hi)          { a[k] = aux[i++]; }
    else if (aux[j] < aux[i]) { a[k] = aux[j++]; }
    else                      { a[k] = aux[i++]; }
  }
}

#endif //CODEBASE_MERGE_SORT_H
