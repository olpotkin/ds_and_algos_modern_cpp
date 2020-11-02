#include <algorithm>
#include <iostream>
#include <vector>


/// Is it a binary search tree?
///
/// Intro: In this problem you are going to test whether a binary search tree data structure from some programming
///        language library was implemented correctly. There is already a program that plays with this data structure
///        by inserting, removing, searching integers in the data structure and outputs the state of the internal binary
///        tree after each operation. Now you need to test whether the given binary tree is indeed a correct binary
///        search tree. In other words, you want to ensure that you can search for integers in this binary tree using
///        binary search through the tree, and you will always get correct result: if the integer is in the tree, you will
///        find it, otherwise you will not.
///
/// Task: You are given a binary tree with integers as its keys. You need to test whether it is a correct binary search
///       tree. The definition of the binary search tree is the following: for any node of the tree, if its key is x,
///       then for any node in its left subtree its key must be strictly less than x, and for any node in its right
///       subtree its key must be strictly greater than x. In other words, smaller elements are to the left, and bigger
///       elements are to the right. You need to check whether the given binary tree structure satisfies this condition.
///       You are guaranteed that the input contains a valid binary tree. That is, it is a tree, and each node has at most
///       two children.
///
/// Input: The first line contains the number of vertices n. The vertices of the tree are numbered from 0 to n − 1.
///        Vertex 0 is the root.
///        The next n lines contain information about vertices 0, 1, ..., n−1 in order. Each of these lines contains
///        three integers key_i, left_i and right_i — key_i is the key of the i-th vertex, left_i is the index of the left
///        child of the i-th vertex, and right_i is the index of the right child of the i-th vertex. If i doesn’t have
///        left or right child (or both), the corresponding left_i or right_i (or both) will be equal to −1.
///
/// Output: If the given binary tree is a correct binary search tree (see the definition in the problem description),
///         output one word “CORRECT” (without quotes). Otherwise, output one word “INCORRECT” (without quotes).


struct Node {
  int key;
  int left;
  int right;

  Node()
  : key(0)
  , left(-1)
  , right(-1)
  {}

  Node(int key_, int left_, int right_)
  : key(key_)
  , left(left_)
  , right(right_)
  {}
};


std::vector<Node> tree;


void inorder_traversal(std::vector<int>& result, int root) {
  if (root == -1) {
    return;
  }

  inorder_traversal(result, tree[root].left);
  result.push_back(tree[root].key);
  inorder_traversal(result, tree[root].right);
}


std::vector <int> in_order(const std::vector<Node>& tree) {
  std::vector<int> result;
  inorder_traversal(result, 0);

  return result;
}


bool IsBinarySearchTree(const std::vector<Node>& tree) {
  // Implement correct algorithm
  if (tree.size() > 1) {
    std::vector <int> v = in_order(tree);
    for (int i = 1; i < v.size(); i++) {
      if (v[i] < v[i - 1]) {
        return false;
      }
    }
  }

  return true;
}


int main() {
  int nodes;
  std::cin >> nodes;

  for (int i = 0; i < nodes; ++i) {
    int key, left, right;
    std::cin >> key >> left >> right;
    tree.push_back(Node(key, left, right));
  }

  if (IsBinarySearchTree(tree)) {
    std::cout << "CORRECT" << std::endl;
  }
  else {
    std::cout << "INCORRECT" << std::endl;
  }

  return 0;
}
