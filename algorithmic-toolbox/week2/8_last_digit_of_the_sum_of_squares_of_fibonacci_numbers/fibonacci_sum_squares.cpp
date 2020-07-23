#include <iostream>
#include <cassert>


/// Last Digit of the Sum of Squares of Fibonacci Numbers
///
/// Task. Compute the last digit of F0^2 + F1^2 + ... Fn^2.
/// Input Format. Integer n.

int fibonacci_sum_squares_naive(long long n) {
  if (n <= 1)
    return n;

  long long previous = 0;
  long long current  = 1;
  long long sum      = 1;

  for (long long i = 0; i < n - 1; ++i) {
    long long tmp_previous = previous;
    previous = current;
    current  = tmp_previous + current;
    sum += current * current;
  }

  return sum % 10;
}

//---

int get_fibonacci_last_digit_helper(const long long& n) {
  if (n <= 1)
    return n;

  int prev = 0;
  int curr = 1;

  for (long long i = 2; i <= n; ++i) {
    int tmp_prev = prev;
    prev = curr;
    curr = (curr + tmp_prev) % 10;
  }

  return curr % 10;
}

int fibonacci_sum_squares_fast(const long long& n) {
  // Hint 1: (F0)^2 + (F1)^2 + ... + (Fn)^2 = (Fn)*(Fn+1)
  // Hint 2: Concept https://math.stackexchange.com/a/2613653/373910
  const int pisano_mod_10 = 60;
  
  int vertical_side   = get_fibonacci_last_digit_helper(n % pisano_mod_10);
  int horizontal_side = get_fibonacci_last_digit_helper((n + 1) % pisano_mod_10);
  int sum_squares = vertical_side * horizontal_side;

  return sum_squares % 10;
}

//---

void test_solution() {
  // (F0)^2 + (F1)^2 + ... + (F7)^2 = 0 + 1 + 1 + 4 + 9 + 25 + 64 + 169 = 273.
  assert(fibonacci_sum_squares_fast(7) == 3);
  // (F0)^2 + ... + (F73)^2 = 1 052 478 208 141 359 608 061 842 155 201.
  assert(fibonacci_sum_squares_fast(73) == 1);
  assert(fibonacci_sum_squares_fast(1234567890) == 0);

  for (int n = 0; n < 40; ++n) {
    std::cout << "n: " << n
              << " naive: " << fibonacci_sum_squares_naive(n)
              << " fast: " << fibonacci_sum_squares_fast(n) << std::endl;
    assert(fibonacci_sum_squares_fast(n) == fibonacci_sum_squares_naive(n));
  }
}


int main() {
  long long n = 0;
  std::cin >> n;

//  std::cout << fibonacci_sum_squares_naive(n) << std::endl;
//  test_solution();
  std::cout << fibonacci_sum_squares_fast(n) << std::endl;

  return 0;
}
