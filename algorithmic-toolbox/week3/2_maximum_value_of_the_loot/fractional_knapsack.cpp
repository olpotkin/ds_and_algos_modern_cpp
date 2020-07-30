#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>


/// Task: The goal of this code problem is to implement an algorithm for the fractional knapsack problem.
///
/// Input Format: The first line of the input contains the number n of items and the capacity W of a knapsack.
///               The next n lines define the values and weights of the items.
///               The i-th line contains integers v_i and w_i - the value and the weight of 𝑖-th item, respectively.
///
///
/// Output Format: Output the maximal value of fractions of items that fit into the knapsack. The absolute
///                value of the difference between the answer of your program and the optimal value should be
///                at most 10^(−3). To ensure this, output your answer with at least four digits after
///                the decimal point (otherwise an answer, while being computed correctly, can turn out to be
///                wrong because of rounding issues).
/// Useful links:
/// https://towardsdatascience.com/course-1-algorithmic-toolbox-part-2-big-o-and-greedy-6265d9065f05
/// https://codereview.stackexchange.com/questions/223657/determining-the-maximum-value-that-can-be-obtained-from-a-loot
/// https://www.geeksforgeeks.org/fractional-knapsack-problem/

// Structure to store value and weight for an Item (unit in knapsack)
struct Item {
  int value;
  int weight;

  // Constructor
  Item(int value, int weight)
    : value(value)
    , weight(weight) 
  {
  }
};


// Custom comparator for Item object
// Main idea - to make a comparison based on value/weight ratio
bool itemCmp(const Item& lhs, const Item& rhs) {
  double lhsRatio = static_cast<double>(lhs.value) / lhs.weight;
  double rhsRatio = static_cast<double>(rhs.value) / rhs.weight;
  
  return lhsRatio > rhsRatio;
}


double get_optimal_value(const int capacity,
                         const std::vector<int>& weights,
                         const std::vector<int>& values) {
  // Result (value in knapsack)
  double value = 0.0;

  // Move all the input items to the optimal struct
  std::vector<Item> items;
  for (int i = 0; i < weights.size(); ++ i) {
    items.emplace_back(Item(values[i], weights[i]));
  }

  // Descending order sort by ratio of value/weight
  std::sort(items.begin(), items.end(), itemCmp);

  // Sort verification
  //for (const Item& it : items) {
  //  std::cout << "value: " << it.value
  //            << " weight: " << it.weight << std::endl;
  //}
  
  // Current capacity of knapsack
  int curCapacity = 0;

  // Iterate through the all Items
  for (int i = 0; i < items.size(); ++i) {
    // If current Item will not overflow knapsack - add it completely:
    if (curCapacity + items[i].weight <= capacity) {
      curCapacity += items[i].weight;
      value       += items[i].value;
    }
    else {
      // If current item doesn't suit into knapsack - add fractional part of it:
      int remainingCapacity = capacity - curCapacity;
      value += items[i].value * (static_cast<double>(remainingCapacity) / items[i].weight);
      break;
    }
  }

//  std::cout.precision(10);
//  std::cout << "Final value: " << value << std::endl;
   
  return value;
}


void test_solution() {
  int capacity = 50;
  std::vector<int> values  = {60, 100, 120};
  std::vector<int> weights = {20, 50,  30};
  // To achieve the value 180, we take the first item and the third item into the bag.
  assert(get_optimal_value(capacity, weights, values) == 180.0);
  values.clear();
  weights.clear();

  capacity = 10;
  values   = {500};
  weights  = {30};
  // Here, we just take one third of the only available item.
  assert(get_optimal_value(capacity, weights, values) == 166.6667);
}


int main() {
  int n        = 0;
  int capacity = 0;

  std::cin >> n >> capacity;

  std::vector<int> values(n);
  std::vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

//  test_solution();
  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;

  return 0;
}
