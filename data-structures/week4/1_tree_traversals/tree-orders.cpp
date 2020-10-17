#include <iostream>
#include <vector>
#include <algorithm>

#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif


/// Binary tree traversals
///
/// Intro: In this problem you will implement in-order, pre-order and post-order traversals of a binary tree.
///
/// Task: You are given a rooted binary tree. Build and output its in-order, pre-order and post-order traversals.
///
/// Input: The first line contains the number of vertices n. The vertices of the tree are numbered from 0 to n − 1.
///        Vertex 0 is the root.
///        The next n lines contain information about vertices 0, 1, ..., n−1 in order. Each of these lines contains
///        three integers key_i, left_i and right_i — key_i is the key of the i-th vertex, left_i is the index of the left
///        child of the i-th vertex, and right_i is the index of the right child of the i-th vertex. If i doesn’t have
///        left or right child (or both), the corresponding left_i or right_i (or both) will be equal to −1.
///
/// Output: Print three lines. The first line should contain the keys of the vertices in the in-order traversal of the tree.
///         The second line should contain the keys of the vertices in the pre-order traversal of the tree. The third
///         line should contain the keys of the vertices in the post-order traversal of the tree.


class TreeOrders {
  int n;
  std::vector <int> key;
  std::vector <int> left;
  std::vector <int> right;

public:
  void read() {
    std::cin >> n;
    key.resize(n);
    left.resize(n);
    right.resize(n);

    for (int i = 0; i < n; i++) {
      std::cin >> key[i] >> left[i] >> right[i];
    }
  }

  struct Node {
    int key;
    int left;
    int right;
  };

  void inorder_traversal(std::vector<int>& result, int nodeIdx) {
    if (nodeIdx == -1) {
      return;
    }
    int k = key[nodeIdx];
    int l = left[nodeIdx];
    int r = right[nodeIdx];

    inorder_traversal(result, l);
    result.push_back(k);
    inorder_traversal(result, r);
  }

  std::vector<int> in_order() {
    if (key.empty()) {
      return std::vector<int>();
    }

    std::vector<int> result;
    inorder_traversal(result, 0);
    return result;
  }

  void preorder_traversal(std::vector<int>& result, int nodeIdx) {
    if (nodeIdx == -1) {
      return;
    }

    result.push_back(key[nodeIdx]);
    preorder_traversal(result, left[nodeIdx]);
    preorder_traversal(result, right[nodeIdx]);
  }

  std::vector<int> pre_order() {
    if (key.empty()) {
      return std::vector<int>();
    }

    std::vector<int> result;
    preorder_traversal(result, 0);
    return result;
  }

  void postorder_traversal(std::vector<int>& result, int nodeIdx) {
    if (nodeIdx == -1) {
      return;
    }

    postorder_traversal(result, left[nodeIdx]);
    postorder_traversal(result, right[nodeIdx]);
    result.push_back(key[nodeIdx]);
  }

  std::vector<int> post_order() {
    if (key.empty()) {
      return std::vector<int>();
    }

    std::vector<int> result;
    postorder_traversal(result, 0);
    return result;
  }
};


void print(std::vector<int> a) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (i > 0) {
      std::cout << ' ';
    }
    std::cout << a[i];
  }

  std::cout << '\n';
}


int main_with_large_stack_space() {
  std::ios_base::sync_with_stdio(0);
  TreeOrders t;
  t.read();
  print(t.in_order());
  print(t.pre_order());
  print(t.post_order());
  return 0;
}


int main (int argc, char **argv) {
#if defined(__unix__) || defined(__APPLE__)
  // Allow larger stack space
  const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  
  if (result == 0) {
    if (rl.rlim_cur < kStackSize) {
      rl.rlim_cur = kStackSize;
      result = setrlimit(RLIMIT_STACK, &rl);

      if (result != 0) {
        std::cerr << "setrlimit returned result = " << result << std::endl;
      }
    }
  }
#endif

  return main_with_large_stack_space();
}