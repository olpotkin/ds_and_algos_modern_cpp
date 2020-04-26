#ifndef CODEBASE_UTILS_H
#define CODEBASE_UTILS_H

#include <iostream>
#include <vector>


void PrintVector(const std::vector<int>& inVector) {
  std::cout << "{ ";

  for (const auto& element : inVector) {
    std::cout << element << " ";
  }
  std::cout << "}" << std::endl;
}

#endif //CODEBASE_UTILS_H
