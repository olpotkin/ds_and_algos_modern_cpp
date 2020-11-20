#include <iostream>
#include <vector>


/// Checking Consistency of CS Curriculum
///
/// Intro: A Computer Science curriculum specifies the prerequisites for each course as a list of courses that should be
///        taken before taking this course. You would like to perform a consistency check of the curriculum, that is,
///        to check that there are no cyclic dependencies. For this, you construct the following directed graph:
///        vertices correspond to courses, there is a directed edge (u, v) is the course u should be taken before the
///        course v. Then, it is enough to check whether the resulting graph contains a cycle.
///
/// Task: Check whether a given directed graph with n vertices and m edges contains a cycle.
///
/// Input: A graph is given in the standard format.
///
/// Output: Output 1 if the graph contains a cycle and 0 otherwise.


int dfs(std::vector<std::vector<int>>& adj,
        int x,
        std::vector<int>& visited,
        std::vector<int>& recStack) {
  // Mark the current node as visited and part of recursion stack
  visited[x]  = 1;
  recStack[x] = 1;

  // Recur for all the vertices adjacent to this vertex
  for (size_t i = 0; i < adj[x].size(); ++i) {
    if (!visited[adj[x][i]] && dfs(adj, adj[x][i], visited, recStack)) {
      return 1;
    }
    else if (recStack[adj[x][i]]) {
      return 1;
    }
  }

  // Remove the vertex from recursion stack
  recStack[x] = 0;

  return 0;
}


int acyclic(std::vector<std::vector<int>>& adj) {
  // Mark all the vertices as not visited and not part of recursion stack
  std::vector<int> visited(adj.size());
  std::vector<int> recStack(adj.size());

  for (size_t i = 0; i < adj.size(); ++i) {
    if (!visited[i]) {
      if (dfs(adj, i, visited, recStack)) {
        return 1;
      }
    }
  }

  return 0;
}


int main() {
  size_t n, m;
  std::cin >> n >> m;
  
  std::vector<std::vector<int>> adj(n, std::vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }

  std::cout << acyclic(adj) << std::endl;;

  return 0;
}
