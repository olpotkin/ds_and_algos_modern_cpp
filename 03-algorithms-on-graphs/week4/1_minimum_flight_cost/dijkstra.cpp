#include <iostream>
#include <vector>
#include <limits>
#include <queue>


/// Computing the Minimum Cost of a Flight
///
/// Intro: Now, you are interested in minimizing not the number of segments, but the total cost of a flight. For this
///        you construct a weighted graph: the weight of an edge from one city to another one is the cost of the
///        corresponding flight.
/// Task: Given an directed graph with positive edge weights and with n vertices and 𝑚 edges as well as two vertices
///       u and v, compute the weight of a shortest path between u and v (that is, the minimum total weight of a path
///       from u to v).
/// Input: A graph is given in the standard format. The next line contains two vertices u and v.
/// Output: Output the minimum weight of a path from u to v, or −1 if there is no path.


const int inf = std::numeric_limits<int>::max();

struct Node {
  int index;
  int distance;

  Node(int a = 0, int b = 0)
  : index(a)
  , distance(b) {}
};


struct cmp {
	bool operator()(const Node& a, const Node& b) {
		return a.distance > b.distance;
	}
};


long long distance(std::vector<std::vector<int>>& adj,
                   std::vector<std::vector<int>>& cost,
                   int s, int t) {
  std::vector<int> dist(adj.size(), inf);
  dist[s] = 0;
  
  std::priority_queue<Node, std::vector<Node>, cmp> pq;
  pq.push(Node(s, dist[s]));

  while(!pq.empty()) {
    Node u = pq.top();
    pq.pop();
    int u_index = u.index;
    
    for (int i = 0; i < adj[u_index].size(); ++i) {
      int v = adj[u_index][i];
      if (dist[v] > dist[u_index] + cost[u_index][i]) {
        dist[v] = dist[u_index] + cost[u_index][i];
        pq.push(Node(v, dist[v]));
      }
    }
  }

  if (dist[t] == inf) return -1;

  return dist[t];
}


int main() {
  int n, m;
  std::cin >> n >> m;

  std::vector<std::vector<int>> adj(n, std::vector<int>());
  std::vector<std::vector<int>> cost(n, std::vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }

  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, cost, s, t);

  return 0;
}
