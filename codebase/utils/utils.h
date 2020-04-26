#ifndef CODEBASE_UTILS_H
#define CODEBASE_UTILS_H

#include <iostream>
#include <vector>


void PrintVector(const std::vector& inVector) const {
  for (const auto& element : inVector) {
    std::cout << element << " ";
  }
}

#endif //CODEBASE_UTILS_H
