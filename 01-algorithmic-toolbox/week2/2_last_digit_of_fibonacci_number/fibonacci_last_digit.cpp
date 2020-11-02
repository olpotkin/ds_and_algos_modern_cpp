#include <iostream>
#include <cassert>


int get_fibonacci_last_digit_naive(int n) {
  if (n <= 1)
    return n;

  long long previous = 0;
  long long current  = 1;

  for (int i = 0; i < n - 1; ++i) {
    long long tmp_previous = previous;
    previous = current;
    current = tmp_previous + current;
  }

  return current % 10;
}


int get_fibonacci_last_digit_fast(int n) {
  // We need to precompute first 60 Fibonacci numbers because
  // the series of final digits repeats with a cycle length of 60.
  long long fib[60] = {0};

  fib[0] = 0;
  fib[1] = 1;

  for (int i = 2; i <= 60; ++i) {
      fib[i] = fib[i-1] + fib[i-2];
  }

  return fib[n%60] % 10;
}


void test_solution() {
  assert(get_fibonacci_last_digit_fast(3) == 2);
  assert(get_fibonacci_last_digit_fast(61) == 1);
  assert(get_fibonacci_last_digit_fast(67) == 3);

  for (int n = 0; n < 20; ++n)
    assert(get_fibonacci_last_digit_fast(n) == get_fibonacci_last_digit_naive(n));
}


int main() {
  int n;
  std::cin >> n;

//  std::cout << get_fibonacci_last_digit_naive(n) << '\n';
//  test_solution();
  std::cout << get_fibonacci_last_digit_fast(n) << '\n';

  return 0;
}
