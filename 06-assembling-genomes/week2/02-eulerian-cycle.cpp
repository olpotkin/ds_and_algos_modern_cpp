#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <stack>


/// Finding an Eulerian Cycle in Directed Graph
///
/// Intro: A cycle in a graph is called Eulerian if it traverses each edge of the graph exactly once. Assuming that there
///        are no isolated vertices in a graph, it contains an Eulerian cycle if and only if it is strongly connected and for
///        each vertex, its in-degree is equal to its out-degree. Recall from the lectures that a (circular) genome spells
///        an Eulerian cycles in the de Bruijn graph constructed on all k-mers of the genome.
///
/// Task: Given a directed graph, find an Eulerian cycle in the graph or report that none exists.
///
/// Input: The first line contains integers n and m — the number of vertices and the number of edges, respectively.
///        Each of the following m lines specifies an edge in the format “u v”. (As usual, we assume that the vertices
///        of the graph are {1, 2, ... , n }.) The graph may contain self-loops (that is, edges of the form (v, v)) and
///        parallel edges (that is, several copies of the same edge). It is guaranteed that the graph is strongly connected.
///
/// Output: If the graph has no Eulerian cycle, output 0. Otherwise output 1 in the first line and a sequence
///         v_1, v_2, ... , v_m of vertices in the second line. This sequence should traverse an Eulerian cycle in the graph:
///         (v1, v2), (v2, v3), ... ,(v_m-1, v_m), (v_m, v_1) should all be edges of the graph and each edge of the graph
///         should appear in this sequence exactly once. As usual, the graph may contain many Eulerian cycles (in particular,
///         each Eulerian cycle may be traversed starting from any of its vertices). You may output any one of them.


bool checkDegrees(const std::vector<int>& in,
                   const std::vector<int>& out)
{
  assert(in.size() == out.size());

  for (size_t i = 0; i < in.size(); ++i) {
    if (in[i] != out[i]) {
      return false;
    }
  }

  return true;
}


std::vector<int> makeEulerCycle(std::vector<std::vector<int>> graph)
{
  std::stack<int>  verteces;
  std::vector<int> path;

  verteces.push(0);
  int current = 0;

  while (!verteces.empty()) {
    current = verteces.top();
    if (!graph[current].empty()) {
      verteces.push(graph[current].back());
      graph[current].pop_back();
      continue;
    }

    path.push_back(current);
    verteces.pop();
  }

  std::reverse(path.begin(), path.end());
  path.pop_back();
  return path;
}


int main ()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  int num_verteces;
  int num_edges;

  std::cin >> num_verteces >> num_edges;

  std::vector<std::vector<int>> graph(num_verteces);
  std::vector<int> in(num_verteces), out(num_verteces);

  for (int i = 0; i < num_edges; ++i)  {
    int from;
    int to;

    std::cin >> from >> to;
    graph[--from].push_back(--to);
    ++in[to];
    ++out[from];
  }

  if (!checkDegrees(in, out)) {
    std::cout << 0 << std::endl;
    return 0;
  }

  auto cycle = makeEulerCycle(std::move(graph));

  std::cout << 1 << '\n';
  for (auto v : cycle) {
    std::cout << v+1 << ' ';
  }
  std::cout << std::endl;

  return 0;
}
