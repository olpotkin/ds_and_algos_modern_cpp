#include <iostream>
#include <cstring>
#include <vector>


/// Dataset Problem: Assembling the phi X174 Genome from Error-Prone Reads Using Overlap Graphs
///
/// Intro: In this challenge, the task of performing Genome Assembly on a simulated error-prone sequencing dataset
///        will be given.
///
/// Task: Given a list of error-prone reads, perform the task of Genome Assembly and return the circular genome from
///       which they came.
///
/// Dataset: Each of 1 618 lines of the input contains a single read. The reads are given to you in alphabetical
///          order because their true order is hidden from you. Each read is 100 nucleotides long and contains a
///          single sequencing error (i.e., one mismatch per read) in order to simulate the 1% error rate of Illumina
///          sequencing machines. Note that you are not given the 100-mer composition of the genome (i.e., some
///          100-mers may be missing).
///
/// Output: Output the assembled genome on a single line.


int calculateOverlap(const std::string& a,
                     const std::string& b,
                     const int mer) noexcept
{
  for (int i = 0, n = 1 + a.size() - mer; i < n; ++i) {
    if (strncmp(b.c_str(), a.c_str() + i, a.size() - i) == 0) {
      return a.size() - i;
    }
  }
  return 0;
}


std::string assembleGenome(std::vector<std::string> reads,
                           const int mer) noexcept
{    
  std::string genome;
  genome.reserve(1000);
  genome += reads.front();

  std::string first_read = reads.front(), cur_read = "";
  int cur_index = 0;

  while (reads.size() > 1) {
    cur_read = std::move(reads[cur_index]);
    reads.erase(reads.begin() + cur_index);
        
    int max_overlap = -1;

    for (int j = 0; j < reads.size(); ++j) {
      int overlap = calculateOverlap(cur_read, reads[j], mer);
      if (overlap > max_overlap) max_overlap = overlap, cur_index = j;
    }

    genome += reads[cur_index].substr(max_overlap);
  }

  genome.erase(0, calculateOverlap(reads[0], first_read, mer));

  return genome;
}


int main ()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  std::vector<std::string> reads;
  reads.reserve(1618);
  std::string s;

  while (std::cin >> s) {
    if (reads.back() != s) {
      reads.emplace_back(std::move(s));
    }
  }

  std::cout << assembleGenome(std::move(reads), 12) << std::endl;   

  return 0;
}
