#include <iostream>
#include <vector>


/// Finding an Exit from a Maze
///
/// Intro: A maze is a rectangular grid of cells with walls between some of adjacent cells. You would like to check
///        whether there is a path from a given cell to a given exit from a maze where an exit is also a cell that
///        lies on the border of the maze (in the example shown to the right there are two exits: one on the left
///        border and one on the right border). For this, you represent the maze as an undirected graph: vertices of
///        the graph are cells of the maze, two vertices are connected by an undirected edge if they are adjacent and
///        there is no wall between them. Then, to check whether there is a path between two given cells in the maze,
///        it suffices to check that there is a path between the corresponding two vertices in the graph.
///
/// Task: Given an undirected graph and two distinct vertices u and v, check if there is a path between u and v.
///
/// Input: An undirected graph with n vertices and m edges. The next line contains two vertices u and v of the graph.
///
/// Output: Output 1 if there is a path between u and v and 0 otherwise.


int explore(std::vector<std::vector<int>>& adj, int x, int y, std::vector<int>& visited) {
  if (x == y) return 1;

  visited[x] = 1;

  for(int i = 0; i < adj[x].size(); i++) {
    if (!visited[adj[x][i]]) {
      if (explore(adj, adj[x][i], y, visited)) {
        return 1;
      }
    }
  }
  return 0;
}


int reach(std::vector<std::vector<int>>& adj, int x, int y) {
  std::vector<int> visited(adj.size());

  return explore(adj, x, y, visited);
}


int main() {
  size_t n, m;
  
  // Input
  std::cin >> n >> m;
  std::vector<std::vector<int>> adj(n, std::vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }

  int x, y;
  std::cin >> x >> y;

  // Output
  std::cout << reach(adj, x - 1, y - 1);

  return 0;
}
