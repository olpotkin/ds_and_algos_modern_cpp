
# Solutions for the [Algorithmic Toolbox](https://www.coursera.org/learn/algorithmic-toolbox) course

## Contents

### Section 1: Intro

* [Sum of Two Digits](https://github.com/olpotkin/ds_and_algos_modern_cpp/blob/master/01-algorithmic-toolbox/week1/1_sum_of_two_digits/APlusB.cpp):
   Compute the sum of two single digit numbers.

* [Maximum Pairwise Product](https://github.com/olpotkin/ds_and_algos_modern_cpp/blob/master/01-algorithmic-toolbox/week1/2_maximum_pairwise_product/max_pairwise_product.cpp):
   Find the maximum product of two distinct numbers in a sequence of non-negative integers.

### Section 2: Algorithmic Warm-up

* [Fibonacci Number](https://github.com/olpotkin/ds_and_algos_modern_cpp/blob/master/01-algorithmic-toolbox/week2/1_fibonacci_number/fibonacci.cpp):
   Given an integer `n`, find the n-th Fibonacci number `F_n`.

* [Last Digit of a Large Fibonacci Number](https://github.com/olpotkin/ds_and_algos_modern_cpp/blob/master/01-algorithmic-toolbox/week2/2_last_digit_of_fibonacci_number/fibonacci_last_digit.cpp):
   Find the last digit of n-th Fibonacci number.

* [Greatest Common Divisor](https://github.com/olpotkin/ds_and_algos_modern_cpp/blob/master/01-algorithmic-toolbox/week2/3_greatest_common_divisor/gcd.cpp):
   The **greatest common divisor** GCD(a, b) of two non-negative integers a and b (which are not both equal to 0) is the greatest integer d that divides both a and b.

* [Least Common Multiple](https://github.com/olpotkin/ds_and_algos_modern_cpp/blob/master/01-algorithmic-toolbox/week2/4_least_common_multiple/lcm.cpp):
   The **least common multiple** of two positive integers a and b is the least positive integer m that is divisible by both a and b.

* [Fibonacci huge](https://github.com/olpotkin/ds_and_algos_modern_cpp/blob/master/01-algorithmic-toolbox/week2/5_fibonacci_number_again/fibonacci_huge.cpp):
   Given two integers `n` and `m`, output `F(n) mod m` (that is, the remainder of F(n) when divided by m).

* [Last Digit of the Sum of Fibonacci Numbers](https://github.com/olpotkin/ds_and_algos_modern_cpp/blob/master/01-algorithmic-toolbox/week2/6_last_digit_of_the_sum_of_fibonacci_numbers/fibonacci_sum_last_digit.cpp)

* [Last digit of a Partial Sum of Fibonacci Numbers](https://github.com/olpotkin/ds_and_algos_modern_cpp/blob/master/01-algorithmic-toolbox/week2/7_last_digit_of_the_fibonacci_partial_sum/fibonacci_partial_sum.cpp):
   Given two non-negative integers `m` and `n`, where `m <= n`, find the last digit of the sum F_m + F_m+1 + ... + F_n.

* [Last Digit of the Sum of Squares of Fibonacci Numbers](https://github.com/olpotkin/ds_and_algos_modern_cpp/blob/master/01-algorithmic-toolbox/week2/8_last_digit_of_the_sum_of_squares_of_fibonacci_numbers/fibonacci_sum_squares.cpp)

### Section 3: Greedy algorithms

* [Money Change](https://github.com/olpotkin/ds_and_algos_modern_cpp/blob/master/01-algorithmic-toolbox/week3/1_money_change/change.cpp):
   Find the minimum number of coins needed to change the input value (an integer) into coins with denominations `1, 5, and 10`.

* [Maximum Value of the Loot](https://github.com/olpotkin/ds_and_algos_modern_cpp/blob/master/01-algorithmic-toolbox/week3/2_maximum_value_of_the_loot/fractional_knapsack.cpp):
   Fractional knapsack problem.

* [Car Fueling](https://github.com/olpotkin/ds_and_algos_modern_cpp/blob/master/01-algorithmic-toolbox/week3/3_car_fueling/car_fueling.cpp):
   Calculate the minimum number of refills needed to reach destination with given capacity of the fuel tank and list of fuel stations.

* [Maximum Advertisement Revenue](https://github.com/olpotkin/ds_and_algos_modern_cpp/blob/master/01-algorithmic-toolbox/week3/4_maximum_advertisement_revenue/dot_product.cpp):
   Maximal sum of dot products.

* [Collecting Signatures](https://github.com/olpotkin/ds_and_algos_modern_cpp/blob/master/01-algorithmic-toolbox/week3/5_collecting_signatures/covering_segments.cpp):
   Covering Segments by Points.

* [Maximum Number of Prizes](https://github.com/olpotkin/ds_and_algos_modern_cpp/blob/master/01-algorithmic-toolbox/week3/6_maximum_number_of_prizes/different_summands.cpp):
   Different Summands.

* [Maximum Salary](https://github.com/olpotkin/ds_and_algos_modern_cpp/blob/master/01-algorithmic-toolbox/week3/7_maximum_salary/largest_number.cpp):
   Compose a largest number from given numbers (1+ digit possible).

### Section 4: Divide-and-Conquer

* [Binary Search](https://github.com/olpotkin/ds_and_algos_modern_cpp/blob/master/01-algorithmic-toolbox/week4/1_binary_search/binary_search.cpp)

* [Majority Element](https://github.com/olpotkin/ds_and_algos_modern_cpp/blob/master/01-algorithmic-toolbox/week4/2_majority_element/majority_element.cpp):
   Check whether an input sequence contains a majority element (element that appears strictly more than n/2 times).

* [Improving Quick Sort](https://github.com/olpotkin/ds_and_algos_modern_cpp/blob/master/01-algorithmic-toolbox/week4/3_improving_quicksort/sorting.cpp):
   Replace a 2-way partition with a 3-way partition, so that it works fast even on sequences containing many equal elements

* [Number of Inversions](https://github.com/olpotkin/ds_and_algos_modern_cpp/blob/master/01-algorithmic-toolbox/week4/4_number_of_inversions/inversions.cpp):
   Count the number of inversions of a given sequence.

* [Points and Segments](https://github.com/olpotkin/ds_and_algos_modern_cpp/blob/master/01-algorithmic-toolbox/week4/5_organizing_a_lottery/points_and_segments.cpp):
   Compute, for each point, the number of segments that contain this point.

### Section 5: Dynamic Programming I

* Theory:
  * [Dynamic Programming](https://www.dropbox.com/s/qxzh146jd72188d/dynprog.pdf) slides;
  * [Making Change Visualisation](https://www.cs.usfca.edu/~galles/visualization/DPChange.html);
  * [Edit distance calculator](http://www.let.rug.nl/kleiweg/lev/) by Peter Kleiweg;
  * [Longest common subsequence](https://www.cs.usfca.edu/~galles/visualization/DPLCS.html) by David Galles (note the longest common subsequence problem is a special case of the edit distance problem where we allow insertions and deletions only).

* [Money Change](https://github.com/olpotkin/ds_and_algos_modern_cpp/blob/master/01-algorithmic-toolbox/week5/1_money_change_again/change_dp.cpp):
   Dynamic Programming Approach: Provide hhe minimum number of coins with denominations `1, 3, 4` that changes money.

* [Primitive Calculator](https://github.com/olpotkin/ds_and_algos_modern_cpp/blob/master/01-algorithmic-toolbox/week5/2_primitive_calculator/primitive_calculator.cpp):
   Given a positive integer `n`, find the minimum number of operations needed to obtain the number `n` starting from the number 1.

* [Edit Distance](https://github.com/olpotkin/ds_and_algos_modern_cpp/blob/master/01-algorithmic-toolbox/week5/3_edit_distance/edit_distance.cpp):
   The edit distance between two strings is the minimum number of operations (insertions, deletions, and substitutions of symbols) to transform one string into another.

* [Longest Common Subsequence of Two Sequences](https://github.com/olpotkin/ds_and_algos_modern_cpp/blob/master/01-algorithmic-toolbox/week5/4_longest_common_subsequence_of_two_sequences/lcs2.cpp):
   Compute the length of a longest common subsequence of two sequences.

* [Longest Common Subsequence of Three Sequences](https://github.com/olpotkin/ds_and_algos_modern_cpp/blob/master/01-algorithmic-toolbox/week5/5_longest_common_subsequence_of_three_sequences/lcs3.cpp):
   Compute the length of a longest common subsequence of three sequences.

### Section 6: Dynamic Programming II

* [Maximum Amount of Gold](https://github.com/olpotkin/ds_and_algos_modern_cpp/blob/master/01-algorithmic-toolbox/week6/1_maximum_amount_of_gold/knapsack.cpp):
   Given `n` gold bars, find the maximum weight of gold that fits into a bag of capacity `W`.

* [Partitioning Souvenirs](https://github.com/olpotkin/ds_and_algos_modern_cpp/blob/master/01-algorithmic-toolbox/week6/2_partitioning_souvenirs/partition3.cpp):
   Output 1, if it possible to partition v_1, v_2, ... , v_n into `three` subsets with equal sums, and 0 otherwise.

* [Maximum Value of an Arithmetic Expression](https://github.com/olpotkin/ds_and_algos_modern_cpp/blob/master/01-algorithmic-toolbox/week6/3_maximum_value_of_an_arithmetic_expression/placing_parentheses.cpp):
   Output the maximum possible value of the given arithmetic expression among different orders of applying arithmetic operations.

## Build instructions

* clang

```bash
clang++ -std=c++11 -stdlib=libc++ -Weverything file_name.cpp
```

* g++

```bash
g++ -pipe -O2 -std=c ++14 file_name.cpp -lm
```
