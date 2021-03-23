#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cmath>
#include <vector>
#include <iomanip>
#include <iostream>
#include <limits>
#include <numeric>


/// Optimal Diet Problem
///
/// Intro: In this problem, you will implement an algorithm for solving linear programming with only a few inequalities
///        and apply it to determine the optimal diet.
///
/// Task: You want to optimize your diet: that is, make sure that your diet satisfies all the recommendations of nutrition
///       experts, but you also get maximum pleasure from your food and drinks. For each dish and drink you know all the
///       nutrition facts, cost of one item, and an estimation of how much you like it. Your budget is limited, of course.
///       The recommendations are of the form “total amount of calories consumed each day should be at least 1000” or
///       “the amount of water you drink in liters should be at least twice the amount of food you eat in kilograms”, and
///       so on. You optimize the total pleasure which is the sum of pleasure you get from consuming each particular dish
///       or drink, and that is proportional to the amount amount𝑖 of that dish or drink consumed.
///
/// More details:
/// https://github.com/olpotkin/ds_and_algos_modern_cpp/blob/master/05-advanced-algorithms-and-complexity/week2/Programming-Assignment-2.pdf


const long double EPS = 1e-3;
const long double INF = 1.0e+9;

using Column = std::vector<long double>;
using Row    = std::vector<long double>;
using Matrix = std::vector<Row>;

struct Equation {
  Matrix a;
  Column b;
};

struct Position {
  short column;
  short row;
};


Position select_pivot(
  const Matrix&      a,
  std::vector<bool>& used_rows,
  std::vector<bool>& used_columns)
{
  // Select the first free element.
  Position pivot_element{ 0, 0 };
  while (used_rows[pivot_element.row]) {
    ++pivot_element.row;
  }
  while (used_columns[pivot_element.column]) {
    ++pivot_element.column;
  }

  // Amongs free elements, select a pivot with the largest absolute value
  long double max = 0.0;
  for (int from = pivot_element.row, size = a.size(); from < size; ++from) {
    if (std::fabs(max) - std::fabs(a[from][pivot_element.column]) < EPS) {
      max = a[from][pivot_element.column];
      pivot_element.row = from;
    }
  }

  return pivot_element;
}


inline void swap_lines(
  Matrix&            a,
  Column&            b,
  std::vector<bool>& used_rows,
  Position&          pivot_element)
{
  std::swap(a[pivot_element.column], a[pivot_element.row]);
  std::swap(b[pivot_element.column], b[pivot_element.row]);
  std::swap(used_rows[pivot_element.column], used_rows[pivot_element.row]);
  pivot_element.row = pivot_element.column;
}


int back_substitution(
  Matrix& a,
  Column& b)
{
  for (int i = a.size() - 1; i; --i) {
    long double v = b[i];
    for (int j = 0; j != i; ++j) {
      b[j] -= a[j][i] * v;
    }
  }

  return 0;
}


inline void scale_pivot(
  Matrix&         a,
  Column&         b,
  const Position& pivot_element)
{
  const long double divisor = a[pivot_element.row][pivot_element.column];
  const int size = a.size();

  for (int j = pivot_element.column; j < size; ++j) {
    a[pivot_element.row][j] /= divisor;
  }

  b[pivot_element.row] /= divisor;
}


void process_pivot(
  Matrix&         a,
  Column&         b,
  const Position& pivot_element)
{
  const int size = a.size();
  long double multiple{ 0.0 };

  scale_pivot(a, b, pivot_element);

  for (int i = pivot_element.row + 1; i < size; ++i) {
    multiple = a[i][pivot_element.column];

    for (int j = pivot_element.column; j < size; ++j) {
      a[i][j] -= (a[pivot_element.row][j] * multiple);
    }

    b[i] -= (b[pivot_element.row] * multiple);
  }
}


inline void mark_pivot_used(
  const Position&    pivot,
  std::vector<bool>& used_rows,
  std::vector<bool>& used_columns)
{
  used_rows[pivot.row] = true;
  used_columns[pivot.column] = true;
}


std::pair<int, Column> solve_equation(Equation equation)
{
  Matrix& a = equation.a;
  Column& b = equation.b;

  if (a.empty()) {
    return {};
  }

  std::vector<bool> used_columns(a.size(), false);
  std::vector<bool> used_rows(a.size(), false);

  for (int steps = a.size(); steps; --steps) {
    Position pivot_element = select_pivot(a, used_rows, used_columns);

    if (a[pivot_element.row][pivot_element.column] == 0) {
      break;
    }

    swap_lines(a, b, used_rows, pivot_element);
    process_pivot(a, b, pivot_element);
    mark_pivot_used(pivot_element, used_rows, used_columns);
  }

  int code = back_substitution(a, b);

  return { code, std::move(b) };
}


std::vector<std::vector<int> > get_subsets(const std::vector<int>& set, int m)
{
  const int n = pow(2, set.size());
  std::vector<std::vector<int> > subsets;
  std::bitset<32> bset;

  for (int i = 0; i < n; ++i) {
    bset = bset.to_ulong() + 1l;
    std::vector<int> subset;

    int cnt = 0;

    for (int j = 0; j < set.size(); ++j) {
      if (bset[set.size() - 1 - j]) {
        subset.push_back(set[j]);
        if (++cnt > m) {
          break;
        }
      }
    }

    if (cnt == m) {
      subsets.emplace_back(std::move(subset));
    }
  }

  return subsets;
}


std::vector<Column> solve_all_equations(
  int                             m,
  const Matrix&                   A,
  const std::vector<long double>& b)
{
  std::vector<Column> solutions;
  std::vector<int> nums(A.size());

  int s { 0 };
  generate(nums.begin(), nums.end(), [&s] { return s++; });
  auto subsets = get_subsets(nums, m);

  if (A.size() == 1) {
    subsets.emplace_back(0);
  }

  for (const auto& sub : subsets) {
    Matrix mat;
    Column col;

    for (auto j : sub) {
      mat.push_back(A[j]);
      col.push_back(b[j]);
    }

    Equation eq { std::move(mat), std::move(col) };
    auto code_and_sol = solve_equation(eq);

    if (code_and_sol.first == 0 && !code_and_sol.second.empty()) {
      solutions.emplace_back(std::move(code_and_sol.second));
    }
  }

  return solutions;
}


inline void prepare(
  int&                      n,
  const int                 m,
  Matrix&                   A,
  std::vector<long double>& b)
{
  // Enusre matrix MxM
  while (n < m) {
    A.emplace_back(m, 0);
    b.emplace_back(0);
    ++n;
  }

  // Add equation to check for infnity
  A.emplace_back(std::vector<long double>(m, 1));
  b.emplace_back(1.0e+9);
  ++n;

  // Add equations to check that amount are positive
  for (int k = 0; k < m; ++k) {
    std::vector<long double> vec(m, 0.0);
    vec[k] = -1;
    A.emplace_back(std::move(vec));
    b.emplace_back(-0.0);
    ++n;
  }
}


std::pair<int, std::vector<long double> >
solve_diet_problem(
  int n,
  int m,
  Matrix A,
  std::vector<long double> b,
  std::vector<long double> c)
{
  prepare(n, m, A, b);
  std::vector<Column> solutions = solve_all_equations(m, A, b);

  if (solutions.size() == 0) {
    // No solution
    return { -1, {} };
  }

  int sol_index = -1;
  long double largest_pleasure = -(std::numeric_limits<long double>::max() / 2);

  // Check solutions
  for (int i = 0; i < solutions.size(); ++i) {
    auto& sol = solutions[i];
    bool satisfied{ true };

    for (int j = 0; j < n; ++j) {
      long double constraint = b[j];
      long double sum{ 0.0 };

      for (int k = 0; k < m; ++k) {
        sum += A[j][k] * sol[k];
      }

      if (sum - constraint > EPS) {
        satisfied = false;
        break;
      }
    }

    long double pleasure{ 0.0 };
    for (int k = 0; k < m; ++k) {
      pleasure += sol[k] * c[k];
    }

    if (satisfied && pleasure > largest_pleasure) {
      largest_pleasure = pleasure;
      sol_index = i;
    }
  }

  if (sol_index == -1) {
    // No solution
    return { -1, {} };
  }

  auto& sol = solutions[sol_index];
  if (std::accumulate(sol.begin(), sol.end(), (long double)0.0) + EPS >= INF) {
    // Infinity
    return { 1, {} };
  }

  return { 0, std::move(sol) };
}


int main()
{
  std::ios_base::sync_with_stdio(false);

  int n, m;
  std::cin >> n >> m;
  Matrix A(n, std::vector<long double>(m));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cin >> A[i][j];
    }
  }

  std::vector<long double> b(n);
  for (int i = 0; i < n; i++) {
    std::cin >> b[i];
  }

  std::vector<long double> c(m);
  for (int i = 0; i < m; i++) {
    std::cin >> c[i];
  }

  std::pair<int, std::vector<long double> > ans = solve_diet_problem(n, m, std::move(A), std::move(b), std::move(c));

  switch (ans.first) {
  case -1:
    printf("No solution\n");
    break;
  case 0:
    printf("Bounded solution\n");
    for (int i = 0; i < m; i++) {
      printf("%.18Lf%c", ans.second[i], " \n"[i + 1 == m]);
    }
    break;
  case 1:
    printf("Infinity\n");
    break;
  }
  
  return 0;
}
