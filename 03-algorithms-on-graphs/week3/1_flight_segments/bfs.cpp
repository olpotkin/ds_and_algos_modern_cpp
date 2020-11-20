#include <iostream>
#include <vector>
#include <queue>
#include <limits>


/// Computing the Minimum Number of Flight Segments
/// Breadth first search (minimum number of flight segments)
///
/// Intro: You would like to compute the minimum number of flight segments to get from one city to another one. For
///        this, you construct the following undirected graph: vertices represent cities, there is an edge between two
///        vertices whenever there is a flight between the corresponding two cities. Then, it suffices to find
///        a shortest path from one of the given cities to the other one.
///
/// Task: Given an undirected graph with n vertices and m edges and two vertices u and v, compute the length of
///       a shortest path between u and v (that is, the minimum number of edges in a path from u to v).
///
/// Input: A graph is given in the standard format. The next line contains two vertices u and v.
///
/// Output: Output the minimum number of edges in a path from u to v, or −1 if there is no path.


int distance(std::vector<std::vector<int>>& adj,
             int s,
             int t) {
  if (s == t) {
    return 0;
  }
  
  std::vector<int> dist(adj.size());
  for (size_t i = 0; i < dist.size(); ++i) {
    dist[i] = std::numeric_limits<int>::max();
  }
  
  dist[s] = 0;

  // Create a queue for BFS
  std::queue<int> queue;
  
  // Enqueue the current node
  queue.push(s);
  
  while(!queue.empty()) {
    // Dequeue a vertex from queue
    int u = queue.front();
    queue.pop();
	  
    // Get all adjacent vertices of the dequeued vertex u
    // If an adjacent has not been discovered, then enqueue it
    for (size_t i = 0; i < adj[u].size(); ++i) {
      int v = adj[u][i];

      if (dist[v] == std::numeric_limits<int>::max()) {
        queue.push(v);
        dist[v] = dist[u] + 1;
      }
    }
  }
  
  if (dist[t] != std::numeric_limits<int>::max()) {
    return dist[t];
  }

  return -1;
}


int main() {
  int n, m;
  std::cin >> n >> m;

  std::vector<std::vector<int>> adj(n, std::vector<int>());
  for (size_t i = 0; i < m; ++i) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }

  int s, t;
  std::cin >> s >> t;
  s--, t--;

  std::cout << distance(adj, s, t);

  return 0;
}
