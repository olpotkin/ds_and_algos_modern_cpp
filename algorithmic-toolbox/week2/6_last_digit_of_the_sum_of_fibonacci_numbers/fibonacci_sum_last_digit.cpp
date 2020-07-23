#include <iostream>
#include <cassert>


/// The goal in this problem is to find the last digit of a sum of the first n Fibonacci numbers.
/// Task. Given an integer n, find the last digit of the sum F0 + F1 + ... + Fn.

int fibonacci_sum_naive(long long n) {
  if (n <= 1)
    return n;

  long long previous = 0;
  long long current  = 1;
  long long sum      = 1;

  for (long long i = 0; i < n - 1; ++i) {
    long long tmp_previous = previous;
    previous = current;
    current = tmp_previous + current;
    sum += current;
  }

  return sum % 10;
}


int fibonacci_sum_fast(long long n) {
  /// NOTE: Last digit of Fibonacci sum repeats after 60 elements
  /// Why? because Pisano Series for m = 10 (we need last digit, so SUM % 10) is 60.
  long long last_d_fib_60[60] = {0};

  last_d_fib_60[0] = 0;
  last_d_fib_60[1] = 1;

  for (int i = 2; i < 60; ++i)
    last_d_fib_60[i] = (last_d_fib_60[i-1] + last_d_fib_60[i-2]) % 10;

  long long sum = 0;
  long long len_last_period = n % 60;

  for (int i = 0; i <= len_last_period; ++i)
    sum += last_d_fib_60[i];

  return sum % 10;
}


void test_solution() {
  assert(fibonacci_sum_fast(3) == 4);
  assert(fibonacci_sum_fast(100) == 5);

  for (int n = 0; n < 100; ++n) {
    std::cout << "n: " << n
              << " naive: " << fibonacci_sum_naive(n)
              << " fast: " << fibonacci_sum_fast(n) << std::endl;
    assert(fibonacci_sum_fast(n) == fibonacci_sum_naive(n));
  }
}


int main() {
  long long n = 0;
  std::cin >> n;

//  std::cout << fibonacci_sum_naive(n) << std::endl;
//  test_solution();
  std::cout << fibonacci_sum_fast(n) << std::endl;

  return 0;
}
