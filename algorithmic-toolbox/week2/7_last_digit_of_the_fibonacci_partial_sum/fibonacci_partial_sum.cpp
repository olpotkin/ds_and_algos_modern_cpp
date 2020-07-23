#include <iostream>
#include <cassert>


/// Find the last digit of a partial sum of Fibonacci numbers: Fm + Fm+1 + ... + Fn.
///
/// TASK: Given two non-negative integers m and n, where m ≤ n, find the last digit of the sum Fm + Fm+1 + ... + Fn.
/// Input Format: The input consists of two non-negative integers m and n separated by a space.


long long get_fibonacci_partial_sum_naive(long long from, long long to) {
  long long sum     = 0;
  long long current = 0;
  long long next    = 1;

  for (long long i = 0; i <= to; ++i) {
    if (i >= from) {
      sum += current;
    }

    long long new_current = next;
    next = next + current;
    current = new_current;
  }

  return sum % 10;
}


long long get_fibonacci_partial_sum_fast(const long long& from, const long long& to) {
  /// NOTE: Last digit of Fibonacci sum repeats after 60 elements
  /// Why? because Pisano Series for m = 10 (we need last digit, so SUM % 10) is 60.

  // Reduce very large numbers
  int rem_from_60 = from % 60;
  int rem_to_60   = to % 60;

  // After reduction (rem_to_60) "to" could be less than "from" (rem_to_60). It will produce error.
  // In this case add 60 to "rem_to_60"
  if (rem_to_60 < rem_from_60)
    rem_to_60 += 60;

  // Calculate Fibonacci sums (only last digits used!)
  int current = 0;
  int next    = 1;
  int sum     = 0;

  for (int i = 0; i <= rem_to_60; ++i) {
      if (i >= rem_from_60)
        sum += current;

      int new_current = next;
      next    = (next + current) % 10;
      current = new_current;
  }

  return sum % 10;
}


void test_solution() {
  // F3 + F4 + F5 + F6 + F7 = 2 + 3 + 5 + 8 + 13 = 31.
  assert(get_fibonacci_partial_sum_fast(3, 7) == 1);
  // F10 = 55.
  assert(get_fibonacci_partial_sum_fast(10, 10) == 5);
  // F10 + F11 + ... + F200 = 734 544 867 157 818 093 234 908 902 110 449 296 423 262
  assert(get_fibonacci_partial_sum_fast(10, 200) == 2);

  for (int from = 0; from <= 10; ++from) {
    for (int to = 10; to < 20; ++to) {
      std::cout << "from: " << from << " to: " << to
                << " naive: " << get_fibonacci_partial_sum_naive(from, to)
                << " fast: " << get_fibonacci_partial_sum_fast(from, to) << std::endl;

      assert(get_fibonacci_partial_sum_fast(from, to) == get_fibonacci_partial_sum_naive(from, to));
    }
  }
}


int main() {
  long long from, to;
  std::cin >> from >> to;

//  std::cout << get_fibonacci_partial_sum_naive(from, to) << std::endl;
//  test_solution();
  std::cout << get_fibonacci_partial_sum_fast(from, to) << std::endl;

  return 0;
}
