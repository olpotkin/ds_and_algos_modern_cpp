#include <iostream>
#include <vector>
#include <algorithm>


/// Convert array into heap
///
/// Intro: In this problem you will convert an array of integers into a heap. This is the crucial step of the sorting
///        algorithm called HeapSort. It has guaranteed worst-case running time of 𝑂(n log n) as opposed to QuickSort’s
///        average running time of 𝑂(n log n). QuickSort is usually used in practice, because typically it is faster, but
///        HeapSort is used for external sort when you need to sort huge files that don’t fit into memory of your computer.
///
/// Task: The first step of the HeapSort algorithm is to create a heap from the array you want to sort. By the way,
///       did you know that algorithms based on Heaps are widely used for external sort, when you need to sort huge
///       files that don’t fit into memory of a computer?
///       Your task is to implement this first step and convert a given array of integers into a heap. You will do that
///       by applying a certain number of swaps to the array. Swap is an operation which exchanges elements a_i and a_j
///       of the array a for some i and j. You will need to convert the array into a heap using only 𝑂(n) swaps, as was
///       described in the lectures. Note that you will need to use a min-heap instead of a max-heap in this problem.
///
/// Input: The first line of the input contains single integer n. The next line contains n space-separated integers a_i.
///
/// Output: The first line of the output should contain single integer m — the total number of swaps. m must satisfy
///         conditions 0 <= m <= 4n. The next m lines should contain the swap operations used to convert the array 'a'
///         into a heap. Each swap is described by a pair of integers i, j — the 0-based indices of the elements to be
///         swapped. After applying all the swaps in the specified order the array must become a heap, that is, for
///         each i where 0 <= i <= 𝑛 − 1 the following conditions must be true:
///           1. If 2i + 1 <= n − 1, then a_i < a_2i+1.
///           2. If 2i + 2 <= n − 1, then a_i < a_2i+2.
///         Note that all the elements of the input array are distinct. Note that any sequence of swaps that has length
///         at most 4n and after which your initial array becomes a correct heap will be graded as correct.


class HeapBuilder {
 private:
  std::vector<int> data_;
  std::vector<std::pair<int, int> > swaps_;

  void WriteResponse() const {
    std::cout << swaps_.size() << "\n";
    for (int i = 0; i < swaps_.size(); ++i) {
      std::cout << swaps_[i].first << " " << swaps_[i].second << "\n";
    }
  }

  void ReadData() {
    int n;
    std::cin >> n;
    data_.resize(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> data_[i];
    }
  }

  /// New Algo Implementation
  int getLeftChild(const int i) {
    if (i == 0) return i + 1;

    return 2*i + 1;
  }

  /// New Algo Implementation
  int getRightChild(const int i) {
    if (i == 0) return i + 2;
    
    return 2*i + 2;
  }

  /// New Algo Implementation
  void SiftDown(const int i) {
    int minIdx = i;

    int left = getLeftChild(i);
    if (left < data_.size() && data_[left] < data_[minIdx]) {
      minIdx = left;
    }

    int right = getRightChild(i);
    if (right < data_.size() && data_[right] < data_[minIdx]) {
      minIdx = right;
    }

    if (i != minIdx) {
      std::swap(data_[i], data_[minIdx]);
      swaps_.push_back(std::make_pair(i, minIdx));
      SiftDown(minIdx);
    }
  }

  void GenerateSwaps() {
    swaps_.clear();
    // The following naive implementation just sorts the given sequence using selection sort algorithm
    // and saves the resulting sequence of swaps. This turns the given array into a heap, 
    // but in the worst case gives a quadratic number of swaps.
    //

    // TODO: replace by a more efficient implementation
    /*
    for (int i = 0; i < data_.size(); ++i)
      for (int j = i + 1; j < data_.size(); ++j) {
        if (data_[i] > data_[j]) {
          std::swap(data_[i], data_[j]);
          swaps_.push_back(std::make_pair(i, j));
        }
      }
    */

    // Change BuildHeap to min-heap
    int n = data_.size();
    for (int i = n/2; i >= 0; --i) {
      SiftDown(i);
    }
  }

 public:
  void Solve() {
    ReadData();
    GenerateSwaps();
    WriteResponse();
  }
};


int main() {
  std::ios_base::sync_with_stdio(false);

  HeapBuilder heap_builder;
  heap_builder.Solve();

  return 0;
}
