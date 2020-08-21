#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <climits>


/// Maximum Value of an Arithmetic Expression
///
/// Intro: In this problem, your goal is to add parentheses to a given arithmetic expression to maximize its value.
///        e.g., max(5−8+7×4−8+9)=?
///
/// Task: Find the maximum value of an arithmetic expression by specifying the order of applying its arithmetic
///       operations using additional parentheses.
///
/// Input: The only line of the input contains a string s of length 2n + 1 for some n, with symbols
///        s_0, s_1, ... , s_2n. Each symbol at an even position of s is a digit (that is, an integer
///        from 0 to 9) while each symbol at an odd position is one of three operations from {+, -, *}.
///
/// Output: Output the maximum possible value of the given arithmetic expression among different orders of
///         applying arithmetic operations.


long long eval(
  const long long a,
  const long long b,
  const char op)
{
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}


long long get_maximum_value(const std::string& exp) {
  int length = exp.size();
  int operands_count = (length + 1) / 2;

  std::vector<std::vector<long long>> minimum (operands_count, std::vector<long long> (operands_count, 0));
  std::vector<std::vector<long long>> maximum (operands_count, std::vector<long long> (operands_count, 0));

  // Fill the diagonal
  for (int i = 0; i < operands_count; ++i) {
    // Extract numbers from the expression
    minimum[i][i] = std::stoll(exp.substr(2*i, 1));
    maximum[i][i] = std::stoll(exp.substr(2*i, 1));
  }

  for (int z = 0; z < operands_count - 1; ++z) {
    for (int i = 0; i < operands_count - z - 1; ++i) {

      int j = i + z + 1;
      long long minValue = LLONG_MAX;
      long long maxValue = LLONG_MIN;

      for (int k = i; k < j; ++k) {
        long long a = eval(minimum[i][k], minimum[k+1][j], exp[2*k + 1]);
        long long b = eval(minimum[i][k], maximum[k+1][j], exp[2*k + 1]);
        long long c = eval(maximum[i][k], minimum[k+1][j], exp[2*k + 1]);
        long long d = eval(maximum[i][k], maximum[k+1][j], exp[2*k + 1]);

         minValue = std::min(minValue, std::min(a, std::min(b, std::min(c, d))));
         maxValue = std::max(maxValue, std::max(a, std::max(b, std::max(c, d))));
      }

      minimum[i][j] = minValue;
      maximum[i][j] = maxValue;
    }
  }

  return maximum[0][operands_count - 1];
}


void test_solution() {
  assert(get_maximum_value("1+5") == 6);
  std::cout << "Test 01 passed..." << std::endl;

  /// 200 = (5 − ((8 + 7) * (4 − (8 + 9))))
  assert(get_maximum_value("5-8+7*4-8+9") == 200);
  std::cout << "Test 02 passed..." << std::endl;
}


int main() {
//  test_solution();

  std::string s;
  std::cin >> s;

  std::cout << get_maximum_value(s) << std::endl;

  return 0;
}
