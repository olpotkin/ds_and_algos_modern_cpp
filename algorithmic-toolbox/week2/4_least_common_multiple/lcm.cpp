#include <iostream>
#include <cassert>


long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l) {
    if (l % a == 0 && l % b == 0)
      return l;
  }

  return (long long) a * b;
}


// We will need GCD to compute LCM efficiently
long long gcdEuclid(const int& a, const int& b) {
  if (b == 0)
    return a;

  return gcdEuclid(b, a % b);
}

long long lcm_fast(const int& a, const int& b) {
  // The formula is:
  // lcm = (a * b) / gcd(a, b)
  long long lcm = (static_cast<long long>(a) * b) / gcdEuclid(a, b);

  return lcm;
}


void test_solution() {
  assert(lcm_fast(1, 1) == 1);
  assert(lcm_fast(10, 2) == 10);

  for (int a = 1; a < 100; ++a) {
    for (int b = 1; b < 20; ++b)
      assert(lcm_fast(a, b) == lcm_naive(a, b));
  }
}


int main() {
  int a, b;
  std::cin >> a >> b;

//  std::cout << lcm_naive(a, b) << std::endl;
//  test_solution();
  std::cout << lcm_fast(a, b) << std::endl;

  return 0;
}
