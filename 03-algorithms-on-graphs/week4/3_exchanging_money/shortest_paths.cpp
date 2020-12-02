#include <iostream>
#include <limits>
#include <vector>
#include <queue>


/// Exchanging Money Optimally
///
/// Intro: Now, you would like to compute an optimal way of exchanging the given currency c_i into all other currencies.
///        For this, you find shortest paths from the vertex c_i to all the other vertices.
///
/// Task: Given an directed graph with possibly negative edge weights and with n vertices and m edges as well as its
///       vertex s, compute the length of shortest paths from s to all other vertices of the graph.
///
/// Input: A graph is given in the standard format.
///
/// Output: For all vertices i from 1 to n output the following on a separate line:
///         - “*”, if there is no path from s to u;
///         - “-”, if there is a path from s to u, but there is no shortest path from s to u
///              (that is, the distance from s to u is −Infinity);
///         - the length of a shortest path otherwise.


void shortest_paths(std::vector<std::vector<int>>& adj,
                    std::vector<std::vector<int>>& cost, int s,
                    std::vector<long long>& distance,
                    std::vector<int>& reachable,
                    std::vector<int>& shortest) {
  reachable[s] = 1;
  distance[s]  = 0;
  std::queue<int> q;

  for (int i = 0; i < adj.size(); ++i) {
    for (int u = 0; u < adj.size(); ++u) {
      for (int k = 0; k < adj[u].size(); ++k) {
        int v = adj[u][k];
        
        if (distance[u]!= std::numeric_limits<long long>::max() && distance[v] > distance[u] + cost[u][k]) {
          distance[v]  = distance[u] + cost[u][k];
          reachable[v] = 1;
          if (i == adj.size() - 1) {
            q.push(v);
          }	
        }
      }
    }
  }
  
  std::vector<int> visited(adj.size());
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    visited[u]  = 1;
    shortest[u] = 0;
    
    for (int i = 0; i < adj[u].size(); ++i) {
      int v = adj[u][i];
      if (!visited[v]) {
        q.push(v);
        visited[v]  = 1;
        shortest[v] = 0;
      }
    }
  }
  distance[s] = 0;
}


int main() {
  int n, m, s;
  std::cin >> n >> m;
  std::vector<std::vector<int>> adj(n, std::vector<int>());
  std::vector<std::vector<int>> cost(n, std::vector<int>());
  for (int i = 0; i < m; ++i) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }

  std::cin >> s;
  s--;
  std::vector<long long> distance(n, std::numeric_limits<long long>::max());
  std::vector<int> reachable(n, 0);
  std::vector<int> shortest(n, 1);
  shortest_paths(adj, cost, s, distance, reachable, shortest);

  for (int i = 0; i < n; ++i) {
    if (!reachable[i]) {
      std::cout << "*\n";
    } else if (!shortest[i]) {
      std::cout << "-\n";
    } else {
      std::cout << distance[i] << "\n";
    }
  }

  return 0;
}
