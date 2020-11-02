#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>


/// Intro: You are given a primitive calculator that can perform the following three operations with the current
///        number x: multiply x by 2, multiply x by 3, or add 1 to x. Your goal is given a positive integer n,
///        find the minimum number of operations needed to obtain the number n starting from the number 1.
///
/// Task: Given an integer n, compute the minimum number of operations needed to obtain the number n starting
///       from the number 1.
///
/// Input: A single integer.
///
/// Output: In the first line, output the minimum number k of operations needed to get n from 1. In the second
///         line output a sequence of intermediate numbers. That is, the second line should contain positive
///         integers a_0, a_2, ... , a_k−1 such that a_0 = 1, a_k−1 = n and for all 0 <= i < k − 1,
///         a_i+1 is equal to either a_i + 1, 2*a_i, or 3*a_i. If there are many such sequences, output any one of them.


std::vector<int> dp_sequence(int n) {
  std::vector<int> sequence;
  std::vector<int> a(n+1);

  for (int i = 1; i < a.size(); ++i) {
    a[i] = a[i-1] + 1;

    if (i % 2 == 0) {
      a[i] = std::min(1 + a[i/2], a[i]);
    }
    if (i % 3 == 0) {
      a[i] = std::min(1 + a[i/3], a[i]);
    }
  }

  int i = n;

  while (i > 1) {
    sequence.push_back(i);
    
    if (a[i-1] == a[i] - 1) {
      i = i - 1;
    }
    else if (i % 2 == 0 && (a[i/2] == a[i] - 1)) {
      i = i / 2;
    }
    else if (i % 3 == 0 && (a[i/3] == a[i] - 1)) {
      i = i / 3;
    }
  }

  sequence.push_back(1);
  std::reverse(sequence.begin(), sequence.end());

  return sequence;
}


std::vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;

  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;
    }
  }

  std::reverse(sequence.begin(), sequence.end());

  return sequence;
}


void test_solution() {
  std::vector<int> sequence_test_1 = dp_sequence(1);
  std::vector<int> sequence_test_1_expected {1};
  assert((sequence_test_1.size() - 1) == 0);
  assert(sequence_test_1 == sequence_test_1_expected);
  std::cout << "Test 01 passed..." << std::endl;

  /// Here, we first multiply 1 by 2 two times and then add 1. Another possibility is to first multiply by 3
  /// and then add 1 two times. Hence “1 3 4 5” is also a valid output in this case.
  std::vector<int> sequence_test_2 = dp_sequence(5);
  std::vector<int> sequence_test_2_expected {1, 2, 4, 5};
  assert((sequence_test_2.size() - 1) == 3);
//  assert(sequence_test_2 == sequence_test_2_expected);
  std::cout << "Test 02 passed..." << std::endl;

  /// Again, another valid output in this case is “1 3 9 10 11 33 99 297 891 2673 8019 16038 16039 48117 96234”.
  std::vector<int> sequence_test_3 = dp_sequence(96234);
  std::vector<int> sequence_test_3_expected {1, 3, 9, 10, 11, 22, 66, 198, 594, 1782, 5346, 16038, 16039, 32078, 96234};
  assert((sequence_test_3.size() - 1) == 14);
//  assert(sequence_test_3 == sequence_test_3_expected);
  std::cout << "Test 03 passed..." << std::endl;
}


int main() {
//  test_solution();

  int n;
  std::cin >> n;

  std::vector<int> sequence = dp_sequence(n);

  std::cout << sequence.size() - 1 << std::endl;

  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }

  return 0;
}
