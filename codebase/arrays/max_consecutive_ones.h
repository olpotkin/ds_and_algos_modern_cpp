#ifndef CODEBASE_MAX_CONSECUTIVE_ONES_H
#define CODEBASE_MAX_CONSECUTIVE_ONES_H

#include <vector>


void UpdateMax(const int& currSequence, int& maxSequence) {
  if (currSequence > maxSequence){
    maxSequence = currSequence;
  }
}


int findMaxConsecutiveOnes(std::vector<int>& nums) {
  int currSequence = 0;
  int maxSequence  = 0;

  for (auto num : nums) {
    if (num == 1) {
      ++currSequence;
    }
    else {
      UpdateMax(currSequence, maxSequence);
      currSequence = 0;
    }
  }

  UpdateMax(currSequence, maxSequence);

  return maxSequence;
}

#endif //CODEBASE_MAX_CONSECUTIVE_ONES_H
