#include <cmath>
#include <iostream>
#include <vector>


/// Infer Energy Values of Ingredients
///
/// Intro: In this problem, you will apply Gaussian Elimination to infer the energy values of ingredients given a
///        restaurant menu with calorie counts and ingredient lists provided for each item.
///
/// Task: You’re looking into a restaurant menu which shows for each dish the list of ingredients with amounts
///       and the estimated total energy value in calories. You would like to find out the energy values of
///       individual ingredients (then you will be able to estimate the total energy values of your favorite dishes).
///
/// Input: The first line of the input contains an integer n — the number of dishes in the menu, and it happens so that
///        the number of different ingredients is the same. Each of the next n lines contains description a1, a2, ... ,
///        a_n, E of a single menu item. a_i is the amount of i-th ingredient in the dish, and E is the estimated total
///        energy value of the dish. If the ingredient is not used in the dish, the amount will be specified as a_i = 0;
///        beware that although the amount of any ingredient in any real menu would be positive, we will test that your
///        algorithm works even for negative amounts a_i < 0.
///
/// Output: Output n real numbers — for each ingredient, what is its energy value. These numbers can be non-integer,
///         so output them with at least 3 digits after the decimal point.


constexpr int PRECISION = 10;

using Column = std::vector<double>;
using Row    = std::vector<double>;
using Matrix = std::vector<Row>;

struct Equation {
  Matrix a;
  Column b;
};

struct Position {
  short column;
  short row;
};


Equation read_equation()
{
  int size;
  std::cin >> size;

  Matrix a(size, std::vector<double>(size, 0.0));
  Column b(size, 0.0);

  for (int row = 0; row < size; ++row) {
    for (int column = 0; column < size; ++column) {
      std::cin >> a[row][column];
    }
    std::cin >> b[row];
  }

  return Equation{ std::move(a), std::move(b) };
}


Position select_pivot(
  const Matrix& a,
  std::vector<bool>& used_rows,
  std::vector<bool>& used_columns)
{
  // First, select the first free element.
  Position pivot_element{ 0, 0 };
  while (used_rows[pivot_element.row]) {
    ++pivot_element.row;
  }
  while (used_columns[pivot_element.column]) {
    ++pivot_element.column;
  }

  // Amongs free elements, select a pivot with the largest absolute value
  double max = 0.0;
  for (int from = pivot_element.row, size = a.size(); from < size; ++from) {
    if (std::fabs(a[from][pivot_element.column]) > std::fabs(max)) {
      max = a[from][pivot_element.column];
      pivot_element.row = from;
    }
  }

  return pivot_element;
}


inline void swap_lines(
  Matrix& a,
  Column& b,
  std::vector<bool>& used_rows,
  Position& pivot_element)
{
  std::swap(a[pivot_element.column], a[pivot_element.row]);
  std::swap(b[pivot_element.column], b[pivot_element.row]);
  std::swap(used_rows[pivot_element.column], used_rows[pivot_element.row]);
  pivot_element.row = pivot_element.column;
}


void back_substitution(Matrix& a, Column& b) {
  for (int i = a.size() - 1; i; --i) {
    double v = b[i];
    for (int j = 0; j != i; ++j) {
      b[j] -= a[j][i] * v;
      a[j][i] = 0;
    }
  }
}


inline void scale_pivot(Matrix& a, Column& b, const Position& pivot_element) {
  const double divisor = a[pivot_element.row][pivot_element.column];
  const int size = a.size();

  for (int j = pivot_element.column; j < size; ++j) {
    a[pivot_element.row][j] /= divisor;
  }

  b[pivot_element.row] /= divisor;
}


void process_pivot(Matrix& a, Column& b, const Position& pivot_element) {
  const int size = a.size();
  double multiple{ 0.0 };

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
  const Position& pivot,
  std::vector<bool>& used_rows,
  std::vector<bool>& used_columns)
{
  used_rows[pivot.row] = true;
  used_columns[pivot.column] = true;
}


Column solve_equation(Equation equation) {
  Matrix& a = equation.a;
  Column& b = equation.b;

  std::vector<bool> used_columns(a.size(), false);
  std::vector<bool> used_rows(a.size(), false);

  for (int steps = a.size(); steps; --steps) {
    Position pivot_element = select_pivot(a, used_rows, used_columns);
    swap_lines(a, b, used_rows, pivot_element);
    process_pivot(a, b, pivot_element);
    mark_pivot_used(pivot_element, used_rows, used_columns);
  }

  back_substitution(a, b);

  return b;
}


void print_column(const Column& column) {
  std::cout.precision(PRECISION);

  for (const auto s : column) {
    std::cout << s << ' ';
  }

  std::cout << std::endl;
}


int main() {
  std::ios_base::sync_with_stdio(false);
  Equation equation = read_equation();

  if (equation.a.size()) {
    Column solution = solve_equation(equation);
    print_column(solution);
  }

  return 0;
}
