#include <iostream>
#include <vector>
#include <cstdlib>


long long MaxPairwiseProduct(const std::vector<int>& numbers) {
  long long max_product = 0;
  int n = numbers.size();

  for (int first = 0; first < n; ++first) {
    for (int second = first + 1; second < n; ++second) {
      max_product = std::max(max_product,
                             static_cast<long long>(numbers[first]) * numbers[second]);
    }
  }

  return max_product;
}


long long MaxPairwiseProductImproved(const std::vector<int>& numbers) {
  int n = numbers.size();

  int maxIdx1 = -1;
  for (int i = 0; i < n; ++i) {
    if ((maxIdx1 == -1) || (numbers[i] > numbers[maxIdx1])) {
      maxIdx1 = i;
    }
  }

  int maxIdx2 = -1;
  for (int i = 0; i < n; ++i) {
    if ((i != maxIdx1) &&
        (maxIdx2 == -1 || numbers[i] > numbers[maxIdx2])) {
      maxIdx2 = i;
    }
  }

  return static_cast<long long>(numbers[maxIdx1]) * numbers[maxIdx2];
}


int main() {

// Stress testing
/*
  while (true) {
    int n = rand() % 3 + 2;
    std::cout << n << "\n";

    std::vector<int> a;
    for (int i = 0; i < n; ++i) {
      a.push_back(rand() % 10);
    }
    for (int i = 0; i < n; ++i) {
      std::cout << a[i] << " ";
    }
    std::cout << "\n";

    long long res1 = MaxPairwiseProduct(a);
    long long res2 = MaxPairwiseProductImproved(a);

    if (res1 != res2) {
      std::cout << "Wrong answer " << res1 << " != " << res2 << "\n";
      break;
    }
    else {
      std::cout << "OK\n";
    }
  }
*/

  int n;
  std::cin >> n;
  
  std::vector<int> numbers(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> numbers[i];
  }

  //std::cout << MaxPairwiseProduct(numbers) << "\n";
  std::cout << MaxPairwiseProductImproved(numbers) << "\n";

  return 0;
}
