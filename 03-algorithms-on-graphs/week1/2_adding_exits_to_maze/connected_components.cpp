#include <iostream>
#include <vector>


/// Adding Exits to a Maze
///
/// Intro: Now you decide to make sure that there are no dead zones in a maze, that is, that at least one exit is
///        reachable from each cell. For this, you find connected components of the corresponding undirected graph
///        and ensure that each component contains an exit cell.
///
/// Task: Given an undirected graph with n vertices and m edges, compute the number of connected components in it.
///
/// Input: A graph is given in the standard format.
///
/// Output: Output the number of connected components.


void explore(std::vector<std::vector<int>>& adj,
             int x,
             std::vector<int>& visited) {
  visited[x] = 1;

  for (size_t i = 0; i < adj[x].size(); ++i) {
    if (!visited[adj[x][i]]) {
      explore(adj, adj[x][i], visited);
    }
  }
}


int number_of_components(std::vector<std::vector<int>>& adj) {
  int res = 0;

  std::vector<int> visited(adj.size());
  for (size_t i = 0; i < adj.size(); i++) {
    if (!visited[i]) {
      explore(adj, i, visited);
      ++res;
    }
  }
  return res;
}


int main() {
  size_t n, m;
  std::cin >> n >> m;

  std::vector<std::vector<int>> adj(n, std::vector<int>());
  for (size_t i = 0; i < m; ++i) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }

  std::cout << number_of_components(adj);

  return 0;
}
