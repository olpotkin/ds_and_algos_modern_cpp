#include <algorithm>
#include <iostream>
#include <vector>
#include <cassert>

#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif


/// Compute tree height
///
/// Intro: Trees are used to manipulate hierarchical data such as hierarchy of categories of a retailer or the
///        directory structure on your computer. They are also used in data analysis and machine learning both
///        for hierarchical clustering and building complex predictive models, including some of the best-performing
///        in practice algorithms like Gradient Boosting over Decision Trees and Random Forests. In the later modules
///        of this course, we will introduce balanced binary search trees (BST) — a special kind of trees that allows
///        to very efficiently store, manipulate and retrieve data. Balanced BSTs are thus used in databases for
///        efficient storage and actually in virtually any non-trivial programs, typically via built-in data structures
///        of the programming language at hand.
///
///        In this problem, your goal is to get used to trees. You will need to read a description of a tree from the
///        input, implement the tree data structure, store the tree and compute its height.
///
/// Task: You are given a description of a rooted tree. Your task is to compute and output its height. Recall that the
///       height of a (rooted) tree is the maximum depth of a node, or the maximum distance from a leaf to the root.
///       You are given an arbitrary tree, not necessarily a binary tree.
///
/// Input: The first line contains the number of nodes n. The second line contains n integer numbers from -1 to n−1
///        - parents of nodes. If the i-th one of them (0 <= i <= n − 1) is −1, node i is the root, otherwise it's
///        0-based index of the parent of i-th node. It is guaranteed that there is exactly one root. It is guaranteed
///        that the input represents a tree.
///
/// Output: Output the height of the tree.
///
/// Input format example:
/// 5 (node 0-4)
/// Parent 4 -1 4 1 1 (-1: root node, 4: children of node 4)
/// Node   0  1 2 3 4 (node number)


class TreeHeight {
public:
  // Input from the keyboard
  inline void readInput() {
    std::cin >> n;
    parent.resize(n);
    depth.resize(n);

    for (int i = 0; i < n; ++i) {
      std::cin >> parent[i];
    }
  }

  // Method needed for testing (automatic input)
  inline void readInput(const int numElements, const std::vector<int>& data) {
    n = numElements;

    parent.resize(n);
    depth.resize(n);

    for (int i = 0; i < n; ++i) {
      parent[i] = data[i];
    }
  }

  void fillDepth(const int nodeNumber) {
    // Root node -> depth = 1
    if (parent[nodeNumber] == -1) {
      depth[nodeNumber] = 1;
      return;
    }

    // Depth of given node already calculated
    if (depth[nodeNumber]) return;

    // If depth of parent is not calculated -> put the parent node to recursive call to get the depth
    if (!depth[parent[nodeNumber]]) {
      fillDepth(parent[nodeNumber]);
    }

    // Depth of this node = depth of parent node + 1
    depth[nodeNumber] = depth[parent[nodeNumber]] + 1;
  }

  int computeMaxHeight() {
    int maxHeight = 0;

    // Empty tree
    if (n == 0) return n;

    // Fill depth of all nodes
    for (int i = 0; i < n; ++i) {
      fillDepth(i);
    }
    for (int i = 0; i < n; ++i) {
      int height = depth[i];
      maxHeight = std::max(maxHeight, height);
    }

    return maxHeight;
  }

private:

  int n;
  std::vector<int> parent;
  std::vector<int> depth;
};


void test_solution() {
  /// The input means that there are 5 nodes with numbers from 0 to 4, node 0 is a child of node 4, node 1 is the root,
  /// node 2 is a child of node 4, node 3 is a child of node 1 and node 4 is a child of node 1. To see this, let us
  /// write numbers of nodes from 0 to 4 in one line and the numbers given in the input in the second line underneath:
  ///   0  1 2 3 4
  ///   4 -1 4 1 1
  /// Now we can see that the node number 1 is the root, because −1 corresponds to it in the second line. Also, we know
  /// that the nodes number 3 and number 4 are children of the root node 1. Also, we know that the nodes number 0 and
  /// number 2 are children of the node 4.
  ///
  /// The height of this tree is 3, because the number of vertices on the path from root 1 to leaf 2 is 3.
  TreeHeight tree_test_01;
  tree_test_01.readInput(5, std::vector<int> {4, -1, 4, 1, 1});
  assert(tree_test_01.computeMaxHeight() == 3);
  std::cout << "Test 01 passed..." << std::endl;

  /// The input means that there are 5 nodes with numbers from 0 to 4, node 0 is the root, node 1 is a child of node 0,
  /// node 2 is a child of node 4, node 3 is a child of node 0 and node 4 is a child of node 3. The height of this
  /// tree is 4, because the number of nodes on the path from root 0 to leaf 2 is 4.
  TreeHeight tree_test_02;
  tree_test_02.readInput(5, std::vector<int> {-1, 0, 4, 0, 3});
  assert(tree_test_02.computeMaxHeight() == 4);
  std::cout << "Test 02 passed..." << std::endl;
}


// Entry point
int main_with_large_stack_space() {
//  test_solution();

  std::ios_base::sync_with_stdio(0);
  TreeHeight tree;
  tree.readInput();
  std::cout << tree.computeMaxHeight() << std::endl;

  return 0;
}


int main (int argc, char** argv)
{
#if defined(__unix__) || defined(__APPLE__)
  // Allow larger stack space
  const  rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
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
