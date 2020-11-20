#include <iostream>
#include <algorithm>
#include <vector>


/// Determining an Order of Courses
///
/// Intro: Now, when you are sure that there are no cyclic dependencies in the given CS curriculum, you would like to
///        find an order of all courses that is consistent with all dependencies. For this, you find a topological
///        ordering of the corresponding directed graph.
///
/// Task: Compute a topological ordering of a given directed acyclic graph (DAG) with n vertices and m edges.
///
/// Input: A graph is given in the standard format.
///
/// Output: Output any topological ordering of its vertices. (Many DAGs have more than just one topological ordering.
///         You may output any of them.)


void dfs(std::vector<std::vector<int>>& adj,
         std::vector<int>& used,
         std::vector<int>& order,
         int x) {
  used[x] = 1;

  for (size_t i = 0; i < adj[x].size(); ++i) {
    if(!used[adj[x][i]]) {
      dfs(adj, used, order, adj[x][i]);
    }
  }

  order.insert(order.begin(), x);
}     


std::vector<int> toposort(std::vector<std::vector<int>> adj) {
  std::vector<int> used(adj.size(), 0);
  std::vector<int> order;

  for (size_t i = 0; i < adj.size(); ++i) {
    if (!used[i]) {
      dfs(adj, used, order, i);
    }
  }

  return order;
}


int main() {
  size_t n, m;
  std::cin >> n >> m;

  std::vector<std::vector<int>> adj(n, std::vector<int>());
  for (size_t i = 0; i < m; ++i) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }

  std::vector<int> order = toposort(adj);
  for (size_t i = 0; i < order.size(); ++i) {
    std::cout << order[i] + 1 << " ";
  }

  return 0;
}
