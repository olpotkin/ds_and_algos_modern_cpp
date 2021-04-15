#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>


/// Dataset Problem: Selecting the Optimal k-mer Size
///
/// Intro: Because we are not guaranteed to be given every possible read (i.e., the substring of Genome beginning at
///        every possible position), we cannot expect to use our reads directly and have our deBruijn graph have an
///        Eulerian Cycle. However, our way of combatting this is to choose some k < ReadLength to break our reads down,
///        and hopefully, for some value of 𝑘, the fragments will be small enough for there to exist an Eulerian Cycle
///        in the de Bruijn graph created from the fragments, but not so small that the de Bruijn graph becomes too convoluted.
///
/// Task: Given a list of error-free reads, return an integer k such that, when a de Bruijn graph is created from the
///       k-length fragments of the reads, the de Bruijn graph has a single possible Eulerian Cycle.
///
/// Dataset: The input consist of 400 reads of length 100, each on a separate line. The reads contain no sequencing errors.
///          Note that you are not given the 100-mer composition of the genome (i.e., some 100-mers may be missing).
///
/// Output: A single integer k on one line.


enum class result {
  no_cycle,
  one_cycle,
  multiple_cycles
};


result checkEulerCycle(const std::map<std::string, std::set<std::string>> graph) {
  for (auto& kv : graph) {
    if (kv.second.empty()) {
      return result::no_cycle;
    }

    if (kv.second.size() > 1) {
      return result::multiple_cycles;
    }
  }

  return result::one_cycle;
}


std::map<std::string, std::set<std::string>>
constructDeBruijnGraph(const std::vector<std::string>& reads,
                         const int k)
{
  std::map<std::string, std::set<std::string>> graph;

  for (const auto& read : reads) {
    for (size_t i = 0; i + k < read.size(); ++i) {
      graph[read.substr(i, k-1)].emplace(read.substr(i + 2, k - 1));

      if (i + k + 1 < read.size()) {
        graph[read.substr(i + 2, k - 1)];
      }
    }
  }

  return graph;
}


std::vector<std::string> read_input() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  std::vector<std::string> reads;
  std::string s;

  while(std::cin >> s) {
    reads.emplace_back(std::move(s));
  }

  return reads;
}


int binarySearch_k(const std::vector<std::string> reads,
                    int l,
                    int r) 
{ 
  while(r >= l) { 
    int mid = l + (r - l) / 2; 

    result res =  checkEulerCycle(constructDeBruijnGraph(reads, mid));
    switch(res) {
      case result::one_cycle: 
        return mid;
      case result::no_cycle:
        r = mid - 1;
        continue; 
      case result::multiple_cycles:
        l = mid + 1;
        continue;
    }
  } 

  throw std::logic_error{"Optimal k is not found"};
} 


int main () {
  const int mer_size = 100;
  std::cout << binarySearch_k(read_input(), 0, mer_size) << std::endl;

  return 0;
}
