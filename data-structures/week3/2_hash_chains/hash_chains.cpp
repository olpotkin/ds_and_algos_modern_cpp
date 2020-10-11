#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>


/// Hashing with chains
///
/// Intro: In this problem you will implement a hash table using the chaining scheme. Chaining is one of the most popular
///        ways of implementing hash tables in practice. The hash table you will implement can be used to implement a
///        phone book on your phone or to store the password table of your computer or web service (but don’t forget to
///        store hashes of passwords instead of the passwords themselves, or you will get hacked!).
///
/// Task: In this task your goal is to implement a hash table with lists chaining. You are already given the number of
///       buckets m and the hash function. It is a polynomial hash function.
///       Your program should support the following kinds of queries:
///       - add string — insert string into the table. If there is already such string in the hash table, then just ignore the query.
///       - del string — remove string from the table. If there is no such string in the hash table, then just ignore the query.
///       - find string — output “yes" or “no" (without quotes) depending on whether the table contains string or not.
///       - check i — output the content of the 𝑖-th list in the table. Use spaces to separate the elements of the list.
///         If i-th list is empty, output a blank line.
///       When inserting a new string into a hash chain, you must insert it in the beginning of the chain.
///
/// Input: There is a single integer 𝑚 in the first line — the number of buckets you should have. The next line contains
///        the number of queries N. It’s followed by N lines, each of them contains one query in the format described above.
///
/// Output: Print the result of each of the find and check queries, one result per line, in the same order as these
///         queries are given in the input.


struct Query {
  std::string type;
  std::string s;
  size_t ind;
};


class QueryProcessor {
  int bucket_count;

  // Store all strings in one vector
  std::vector< std::list<std::string> > buckets;
  
  size_t hash_func(const std::string& s) const {
    static const size_t multiplier = 263;
    static const size_t prime = 1000000007;
    unsigned long long hash = 0;
  
    for (int i = static_cast<int> (s.size()) - 1; i >= 0; --i) {
      hash = (hash * multiplier + s[i]) % prime;
    }

    return hash % bucket_count;
  }

public:
  explicit QueryProcessor(int bucket_count)
    : bucket_count(bucket_count)
  {}

  Query readQuery() const {
    Query query;
    std::cin >> query.type;
    if (query.type != "check") {
      std::cin >> query.s;
    }
    else {
      std::cin >> query.ind;
    }
    return query;
  }

  void writeSearchResult(bool was_found) const {
    std::cout << (was_found ? "yes\n" : "no\n");
  }

  void processQuery(const Query& query) {
    buckets.resize(bucket_count);

    // Declare an iterator
    std::vector< std::list<std::string> >::iterator itRow; // For Rows
    std::list<std::string>::iterator                itCol; // For Cols

    if (query.type == "check") {
      // Pointer to a single bucket
      std::list<std::string>& bucket = buckets[query.ind];
      for (itCol = bucket.begin(); itCol != bucket.end(); ++itCol){
        std::cout << *itCol << " ";
      }
      std::cout << "\n";
    }
    else
    {
      int hashValue = hash_func(query.s);
      std::list<std::string>& bucket = buckets[hashValue];
      
      for (itCol = bucket.begin(); itCol != bucket.end(); ++itCol){
        if (*itCol == query.s) {
          break;
        }
      }
    
      if (query.type == "find") {
        writeSearchResult(itCol != bucket.end()); // if it != .end() is true -> found
      }
      else if (query.type == "add") {
        if (itCol == bucket.end()) {
          bucket.push_front(query.s);
        }
      }
      else if (query.type == "del") {
        if (itCol != bucket.end()) {
          bucket.erase(itCol);
        }
      }
    }
  }

  void processQueries() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
      processQuery(readQuery());
    }
  }

};


int main() {
  std::ios_base::sync_with_stdio(false);

  int bucket_count;
  std::cin >> bucket_count;
  QueryProcessor proc(bucket_count);
  proc.processQueries();

  return 0;
}
