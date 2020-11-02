#include <iostream>
#include <cassert>


/// Task: Given two integers n and m,
/// output F(n) mod m (that is, the remainder of F(n) when divided by m)
///
/// Helpful articles:
/// https://medium.com/competitive/huge-fibonacci-number-modulo-m-6b4926a5c836
/// https://mathoverflow.net/questions/144308/calculating-pisano-periods-for-any-integer


long long get_fibonacci_huge_naive(long long n, long long m) {
  if (n <= 1)
    return n;

  long long previous = 0;
  long long current  = 1;

  for (long long i = 0; i < n - 1; ++i) {
    long long tmp_previous = previous;
    previous = current;
    current = tmp_previous + current;
  }

  return current % m;
}


// Find the length of Pisano period for m
long long get_pisano_period(const long long& m) {
  long long a = 0;
  long long b = 1;
  long long c = a + b;

  // 1. Find the remainder of (F(0) mod m) to (F(m*m) mod m)
  // 2. Stop as soon as you encounter 01, as they indicate that the next iteration is being started
  // 3. Return the length up to that point
  for (long long i = 0; i < m * m; ++i) {
    c = (a + b) % m;
    a = b;
    b = c;

    if (a == 0 && b == 1)
      return i + 1;
  }
}


long long get_fibonacci_huge_fast(const long long& n, const long long& m) {
  // Find the remainder of F(n) divided by the length of Paisano period given m
  long long reminder = n % get_pisano_period(m);

  // n+1 because indexing starts from 0
  long long fibStor[reminder+1];

  fibStor[0] = 0;
  fibStor[1] = 1;

  for (long long i = 2; i <= reminder; ++i) {
    // We need reminder after dividing by m
    fibStor[i] = (fibStor[i-1] + fibStor[i-2]) % m;
  }

  return fibStor[reminder] % m;
}


void test_solution() {
  for (int i = 2; i < 100; ++i) {
    std::cout << i << " : " << get_pisano_period(i) << std::endl;
  }

  assert(get_fibonacci_huge_fast(23, 23) == 22);

  for (int n = 2; n < 30; ++n) {
    for (int m = 1; m < 100; ++m) {
      std::cout << "n = " << n << "| m = " << m << std::endl;
      assert(get_fibonacci_huge_fast(n, m) == get_fibonacci_huge_naive(n, m));
    }
  }
}

int main() {
  long long n, m;
  std::cin >> n >> m;

//  std::cout << get_fibonacci_huge_naive(n, m) << std::endl;
//  test_solution();
  std::cout << get_fibonacci_huge_fast(n, m) << std::endl;

  return 0;
}
