#include <iostream>
#include <string>
#include <stack>
#include <cassert>


/// Check brackets in the code
///
/// Task: Your friend is making a text editor for programmers. He is currently working on a feature that will find
///       errors in the usage of different types of brackets. Code can contain any brackets from the set []{}(),
///       where the opening brackets are [,{, and ( and the closing brackets corresponding to them are ], }, and ).
///
///       For convenience, the text editor should not only inform the user that there is an error in the usage of
///       brackets, but also point to the exact place in the code with the problematic bracket. First priority is to
///       find the first unmatched closing bracket which either doesn’t have an opening bracket before it, like ]
///       in ](), or closes the wrong opening bracket, like } in ()[}. If there are no such mistakes, then it should
///       find the first unmatched opening bracket without the corresponding closing bracket after it, like ( in {}([].
///       If there are no mistakes, text editor should inform the user that the usage of brackets is correct.
///
///       Apart from the brackets, code can contain big and small latin letters, digits and punctuation marks.
///
///       More formally, all brackets in the code should be divided into pairs of matching brackets, such that in each
///       pair the opening bracket goes before the closing bracket, and for any two pairs of brackets either one of
///       them is nested inside another one as in (foo[bar]) or they are separate as in f(a,b)-g[c]. The bracket [
///       corresponds to the bracket ], { corresponds to }, and ( corresponds to ).
///
/// Input: Input contains one string S which consists of big and small latin letters, digits, punctuation marks and
///        brackets from the set []{}().
///
/// Output: If the code in S uses brackets correctly, output “Success" (without the quotes). Otherwise, output the
///         1-based index of the first unmatched closing bracket, and if there are no unmatched closing brackets,
///         output the 1-based index of the first unmatched opening bracket.


struct Bracket {
  Bracket(char type, int position):
    type(type),
    position(position)
  {}

  bool Matchc(const char c) const {
    if (type == '[' && c == ']')
      return true;
    if (type == '{' && c == '}')
      return true;
    if (type == '(' && c == ')')
      return true;
    return false;
  }

  char type;
  int position;
};


int checkBrackets(const std::string& text) {
  std::stack <Bracket> opening_brackets_stack;
  int error_pos = 0;

  for (int position = 0; position < text.length(); ++position) {
    char next = text[position];

    if (next == '(' || next == '[' || next == '{') {
      // Process opening bracket
      opening_brackets_stack.emplace(Bracket{next, position + 1});
    }

    if (next == ')' || next == ']' || next == '}') {
      // Process closing bracket
      if (opening_brackets_stack.empty()) {
        error_pos = position + 1;
        break;
      }

      Bracket top = opening_brackets_stack.top();
      opening_brackets_stack.pop();
      if (!top.Matchc(next)) {
        error_pos = position + 1;
        break;
      }
    }
  }

  if (error_pos == 0 && opening_brackets_stack.empty()) {
    return 0;
  }
  else {
    if (error_pos == 0) {
      while (opening_brackets_stack.size() > 1) {
        opening_brackets_stack.pop();
      }
      error_pos = opening_brackets_stack.top().position;
    }
    return error_pos;
  }
}


void test_solution() {
  /// The brackets are used correctly: there is just one pair of brackets [ and ], they correspond to each
  /// other, the left bracket [ goes before the right bracket ], and no two pairs of brackets intersect, because
  /// there is just one pair of brackets.
  assert (checkBrackets("[]") == 0);
  std::cout << "Test 01 passed..." << std::endl;

  /// The brackets are used correctly: there are two pairs of brackets — first pair of { and }, and second pair
  /// of [ and ] — and these pairs do not intersect.
  assert (checkBrackets("{}[]") == 0);
  std::cout << "Test 02 passed..." << std::endl;

  /// The brackets are used correctly: there are two pairs of brackets — first pair of [ and ], and second pair
  /// of ( and ) — and the second pair is nested inside the first pair.
  assert (checkBrackets("[()]") == 0);
  std::cout << "Test 03 passed..." << std::endl;

  /// Pairs with the same types of brackets can also be nested.
  assert (checkBrackets("(())") == 0);
  std::cout << "Test 04 passed..." << std::endl;

  /// Here there are 3 pairs of brackets, one of them is nested into another one, and the third one is separate
  /// from the first two.
  assert (checkBrackets("{[]}()") == 0);
  std::cout << "Test 05 passed..." << std::endl;

  /// The code { doesn't use brackets correctly, because brackets cannot be divided into pairs (there is just
  /// one bracket). There are no closing brackets, and the first unmatched opening bracket is {, and its
  /// position is 1, so we output 1.
  assert (checkBrackets("{") == 1);
  std::cout << "Test 06 passed..." << std::endl;

  /// The bracket } is unmatched, because the last unmatched opening bracket before it is [ and not {. It
  /// is the first unmatched closing bracket, and our first priority is to output the first unmatched closing
  /// bracket, and its position is 3, so we output 3.
  assert (checkBrackets("{[}") == 3);
  std::cout << "Test 07 passed..." << std::endl;

  /// All the brackets are matching, and all the other symbols can be ignored.
  assert (checkBrackets("foo(bar);") == 0);
  std::cout << "Test 08 passed..." << std::endl;

  /// ) doesn't match [, so ) is the first unmatched closing bracket, so we output its position, which is 10.
  assert (checkBrackets("foo(bar[i);") == 10);
  std::cout << "Test 09 passed..." << std::endl;
}


int main() {
//  test_solution();

  std::string text;
  getline(std::cin, text);

  int res = checkBrackets(text);

  // Printing answer
  if (res == 0) {
    std::cout << "Success" << std::endl;
  }
  else {
    std::cout << res << std::endl;
  }

  return 0;
}
