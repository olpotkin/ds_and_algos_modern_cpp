#include <iostream>
#include <vector>
#include <queue>
#include <limits>


/// Evacuating People
///
/// Intro: In this problem, you will apply an algorithm for finding maximum flow in a network to determine how fast
///        people can be evacuated from the given city.
///
/// Task: A tornado is approaching the city, and we need to evacuate the people quickly. There are several roads
///       outgoing from the city to the nearest cities and other roads going further. The goal is to evacuate
///       everybody from the city to the capital, as it is the only other city which is able to accomodate that
///       many newcomers. We need to evacuate everybody as fast as possible, and your task is to find out what is the
///       maximum number of people that can be evacuated each hour given the capacities of all the roads.
///
/// Input: The first line of the input contains integers n and m — the number of cities and the number of roads
///        respectively. Each of the next m lines contains three integers u, v and c describing a particular road —
///        start of the road, end of the road and the number of people that can be transported through this road in
///        one hour. u and v are the 1-based indices of the corresponding cities.
///        The city from which people are evacuating is the city number 1, and the capital city is the city number n.
///        
///        Note that all the roads are given as one-directional, that is, you cannot transport people from v to u
///        using a road that connects u to v. Also note that there can be several roads connecting the same city u to
///        the same city v, there can be both roads from u to v and from v to u, or there can be only roads in one
///        direction, or there can be no roads between a pair of cities. Also note that there can be roads going from
///        a city u to itself in the input.
///
///        When evacuating people, they cannot stop in the middle of the road or in any city other than the capital.
///        The number of people per hour entering any city other than the evacuating city 1 and the capital city n must
///        be equal to the number of people per hour exiting from this city. People who left a city u through some road
///        (u, v, c) are assumed to come immediately after that to the city v. We are interested in the maximum possible
///        number of people per hour leaving the city 1 under the above restrictions.
///
/// Output: Output a single integer — the maximum number of people that can be evacuated from the city number 1 each hour.


// This class implements a bit unusual scheme for storing edges of the graph,
// in order to retrieve the backward edge for a given edge quickly.
class FlowGraph {
public:
  struct Edge {
    int from, to, capacity, flow;
  };

private:
  // List of all - forward and backward - edges
  std::vector<Edge> edges;

  // These adjacency lists store only indices of edges in the edges list
  std::vector<std::vector<size_t> > graph;

public:
  explicit FlowGraph(size_t n, size_t m)
  : graph(n)
  {
    edges.reserve(2 * m);
  }

  void add_edge(int from, int to, int capacity) {
    // Note that we first append a forward edge and then a backward edge,
    // so all forward edges are stored at even indices (starting from 0),
    // whereas backward edges are stored at odd indices in the list edges
    Edge forward_edge = {from, to, capacity, 0};
    Edge backward_edge = {to, from, 0, 0};
    graph[from].push_back(edges.size());
    edges.push_back(forward_edge);
    graph[to].push_back(edges.size());
    edges.push_back(backward_edge);
  }

  size_t size() const {
    return graph.size();
  }

  const std::vector<size_t>& get_ids(int from) const {
    return graph[from];
  }

  const Edge& get_edge(size_t id) const {
    return edges[id];
  }

  void add_flow(size_t id, int flow) {
    // To get a backward edge for a true forward edge (i.e id is even), we should get id + 1
    // due to the described above scheme. On the other hand, when we have to get a "backward"
    // edge for a backward edge (i.e. get a forward edge for backward - id is odd), id - 1
    // should be taken.
    //
    // It turns out that id ^ 1 works for both cases. Think this through!
    edges[id].flow += flow;
    edges[id ^ 1].flow -= flow;
  }
};


FlowGraph read_data() {
  int vertex_count, edge_count;
  std::cin >> vertex_count >> edge_count;

  FlowGraph graph(vertex_count, edge_count);

  for (int i = 0; i < edge_count; ++i) {
    int u, v, capacity;
    std::cin >> u >> v >> capacity;
    graph.add_edge(u - 1, v - 1, capacity);
  }

  return graph;
}


void BFS(const FlowGraph& graph, int s, int t, std::vector<int>& pred) {
  std::queue<int> q;
  q.push(s);

  std::fill(pred.begin(), pred.end(), -1);

  while(!q.empty()) {
    int curr = q.front();
    q.pop();

    for (auto id : graph.get_ids(curr)) {
      const FlowGraph::Edge& e = graph.get_edge(id);

      if (pred[e.to] == -1 && e.capacity > e.flow && e.to != s) {
        pred[e.to] = id;
        q.push(e.to);
      }
    }
  }
}


int max_flow(FlowGraph& graph, int from, int to) {
  int flow = 0;

  // Contains predecessors of a vertex to get the path
  // and calculate minimum flow thereon
  std::vector<int> pred(graph.size());

  do {
    BFS(graph, from, to, pred);

    if (pred[to] != -1) {
      int min_flow = std::numeric_limits<int>::max();

      // Find minimal flow on the path from BFS
      for (int u = pred[to]; u != -1; u = pred[graph.get_edge(u).from]) {
        min_flow = std::min(min_flow, graph.get_edge(u).capacity - graph.get_edge(u).flow);
      }

      // Update flow in original and residual graphs along the path from BFS
      for (int u = pred[to]; u != -1; u = pred[graph.get_edge(u).from]) {
        graph.add_flow(u, min_flow);
      }

      flow += min_flow;
    }
  } while (pred[to] != -1);

  return flow;
}


int main() {
  std::ios_base::sync_with_stdio(false);
  FlowGraph graph = read_data();

  std::cout << max_flow(graph, 0, graph.size() - 1) << "\n";
  return 0;
}
