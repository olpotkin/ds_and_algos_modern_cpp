#include <iostream>
#include <vector>


/// Plan a Fun Party
///
/// Intro: In this problem, you will design and implement an efficient algorithm to plan invite the coolest people from
///        your company to a party in such a way that everybody is relaxed, because the direct boss of any invited
///        person is not invited.
///
/// Task: You're planning a company party. You'd like to invite the coolest people, and you've assigned each one of them
///       a fun factor — the more the fun factor, the cooler is the person. You want to maximize the total fun factor
///       (sum of the fun factors of all the invited people). However, you can't invite everyone, because if the direct
///       boss of some invited person is also invited, it will be awkward. Find out what is the maximum possible total
///       fun factor.
///
/// Input: The first line contains an integer n — the number of people in the company. The next line contains n numbers
///        f_i — the fun factors of each of the n people in the company. Each of the next n−1 lines describes the
///        subordination structure. Everyone but for the CEO of the company has exactly one direct boss. There are no
///        cycles: nobody can be a boss of a boss of a ... of a boss of himself. So, the subordination structure is a
///        regular tree. Each of the n − 1 lines contains two integers u and v, and you know that either u is the boss
///        of v or vice versa (you don't really need to know which one is the boss, but you can invite only one of them
///        or none of them).
///
/// Output: Output the maximum possible total fun factor of the party (the sum of fun factors of all the invited people).


struct vertex {
  int weight;
  std::vector<int> children;
};

using graph = std::vector<vertex>;
using sum   = std::vector<int>;


graph read_tree() noexcept {
  std::ios::sync_with_stdio(false);

  int vertices_count;
  std::cin >> vertices_count;

  graph tree(vertices_count);

  for (int i = 0; i < vertices_count; ++i) {
    std::cin >> tree[i].weight;
  }

  for (int i = 1, from, to; i < vertices_count; ++i) {
    std::cin >> from >> to;
    tree[from - 1].children.emplace_back(to - 1);
    tree[to - 1].children.emplace_back(from - 1);
  }

  return tree;
}


int compute_recursively(const graph& tree, const int vertex, sum& s, const int parent) noexcept {
  if (s[vertex] == -1) {
    if (tree[vertex].children.empty()) {
      s[vertex] = tree[vertex].weight;
    }
    else {
      auto m1 = tree[vertex].weight;
      for (auto u : tree[vertex].children) {
        if (u == parent)
        continue;

        for (auto w : tree[u].children) {
          if (w != vertex) {
            m1 += compute_recursively(tree, w, s, u);
          }
        }
      }

      auto m0 = 0;
      for (auto u : tree[vertex].children) {
        if (u != parent) {
          m0 += compute_recursively(tree, u, s, vertex);
        }
      }

      s[vertex] = std::max(m1, m0);
    }
  }

  return s[vertex];
}


int ComputeMaxIndependentSet(const graph& tree) noexcept {
  size_t size = tree.size();

  if (size == 0) {
    return 0;
  }

  auto s = sum(size, -1);

  return compute_recursively(tree, 0, s, -1);
}


int main()
{
  const graph tree = read_tree();
  std::cout << ComputeMaxIndependentSet(tree) << std::endl;

  return 0;
}
