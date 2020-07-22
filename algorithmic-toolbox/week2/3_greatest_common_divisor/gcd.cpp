#include <iostream>
#include <cassert>


int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}


int gcdEuclid(const int& a, const int& b) {
  if (b == 0)
    return a;

  int reminder = a % b;
  
  return gcdEuclid(b, reminder);
}


void test_solution() {
  assert(gcdEuclid(10, 2) == 2);
  assert(gcdEuclid(10, 0) == 10);
  assert(gcdEuclid(100, 30) == 10);

  for (int a = 1; a < 100; ++a) {
    for (int b = 1; b < 20; ++b)
      assert(gcdEuclid(a, b) == gcd_naive(a, b));
  }
}


int main() {
  int a, b;
  std::cin >> a >> b;

//  std::cout << gcd_naive(a, b) << std::endl;
//  test_solution();
  std::cout << gcdEuclid(a, b) << std::endl;

  return 0;
}
