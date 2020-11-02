#include <iostream>
#include <vector>
#include <string>
#include <map>


/// Phone book
///
/// Intro: In this problem you will implement a simple phone book manager.
///
/// Task: In this task your goal is to implement a simple phone book manager. It should be able to process the
///       following types of user’s queries:
///       - add number name. It means that the user adds a person with name name and phone number number to the phone
///         book. If there exists a user with such number already, then your manager has to overwrite the corresponding name.
///       - del number. It means that the manager should erase a person with number number from the phone book. If there
///       is no such person, then it should just ignore the query.
///       - find number. It means that the user looks for a person with phone number number. The manager should reply
///       with the appropriate name, or with string “not found" (without quotes) if there is no such person in the book.
///
/// Input: There is a single integer 𝑁 in the first line — the number of queries. It’s followed by N lines, each of
///        them contains one query in the format described above.
///
/// Output: Print the result of each find query — the name corresponding to the phone number or “not found" (without
///         quotes) if there is no person in the phone book with such phone number. Output one result per line in the
///         same order as the find queries are given in the input.


struct Query {
  std::string type;
  std::string name;
  int number;
};


std::vector<Query> read_queries() {
  int n;
  std::cin >> n;
  std::vector<Query> queries(n);

  for (int i = 0; i < n; ++i) {
    std::cin >> queries[i].type;
    if (queries[i].type == "add") {
      std::cin >> queries[i].number >> queries[i].name;
    }
    else {
      std::cin >> queries[i].number;
    }
  }
  
  return queries;
}


void write_responses(const std::vector<std::string>& result) {
  for (size_t i = 0; i < result.size(); ++i) {
    std::cout << result[i] << std::endl;
  }
}


std::vector<std::string> process_queries(const std::vector<Query>& queries) {
  std::vector<std::string> result;

  // STL map (hash table)
  std::map<int, std::string>           mapPhonebook;
  std::map<int, std::string>::iterator it;

  // Traverse every query
  for (int i = 0; i < queries.size(); i++) {
    it = mapPhonebook.find(queries[i].number);
    if (queries[i].type == "add") {
      mapPhonebook[queries[i].number] = queries[i].name;
    }
    else if (queries[i].type == "del") {
      if (it != mapPhonebook.end()) {
        mapPhonebook.erase(it);
      }
    }
    else if(queries[i].type == "find"){
      std::string response = "not found";
      if (it != mapPhonebook.end()){
        response = it->second;
      }
      result.push_back(response);
    }
  }

  return result;
}


int main() {
  write_responses(process_queries(read_queries()));

  return 0;
}
