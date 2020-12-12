#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>


/// Building Roads to Connect Cities
///
/// Intro: In this problem, the goal is to build roads between some pairs of the given cities such that there is a path
///        between any two cities and the total length of the roads is minimized.
/// Task: Given n points on a plane, connect them with segments of minimum total length such that there is a path
///       between any two points.
/// Input: The first line contains the number 𝑛 of points. Each of the following n lines defines a point (x_i, y_i).
/// Output: Output the minimum total length of segments. The absolute value of the difference between the answer of
///         your program and the optimal value should be at most 10^−6. To ensure this, output your answer with at
///         least seven digits after the decimal point (otherwise your answer, while being computed correctly, can turn
///         out to be wrong because of rounding issues).


struct node {
  int parent;
  int rank;
  int x;
  int y;
	
  node(int a, int b, int c = -1, int d = 0) {
    x = a;
    y = b;
    parent = c;
    rank = d;
  }
};

struct edge {
  int u;
  int v;
  double weight;
  
  edge(int a, int b, double c) {
    u = a;
    v = b;
    weight = c;
  }
};


bool cmp(const edge& a, const edge& b) {
  return a.weight < b.weight;
}


void make_set(int i, std::vector<node>& nodes, std::vector<int>& x, std::vector<int>& y) {
  nodes.push_back(node(x[i], y[i], i));
}


double weight(int x1, int y1, int x2, int y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}


int Find(int i, std::vector<node>& nodes) {
  if (i != nodes[i].parent) {
    nodes[i].parent = Find(nodes[i].parent, nodes);
  }
  return nodes[i].parent;
}


void Union(int u, int v, std::vector<node> &nodes) {
  int r1 = Find(u, nodes);
  int r2 = Find(v, nodes);
  if (r1 != r2) {
    if (nodes[r1].rank > nodes[r2].rank) {
      nodes[r2].parent = r1;
    } else {
      nodes[r1].parent = r2;
      if (nodes[r1].rank == nodes[r2].rank) {
        nodes[r2].rank++;
      }
    }
  }
}


double minimum_distance(std::vector<int> x, std::vector<int> y) {
  double result = 0.;

  int n = x.size();
  std::vector<node> nodes;

  for (int i = 0; i < n; i++) {
    make_set(i, nodes, x, y);
  }

  std::vector<edge> edges;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      edges.push_back(edge(i, j, weight(x[i], y[i], x[j], y[j])));
    }
  }

  std::sort(edges.begin(), edges.end(), cmp);

  for (int i = 0; i < edges.size(); i++) {
    edge current_edge = edges[i];
    int u = current_edge.u;
    int v = current_edge.v;

    if (Find(u, nodes) != Find(v, nodes)) {
      result += current_edge.weight;
      Union(u, v, nodes);
    }
  }
  
  return result;
}


int main() {
  size_t n;
  std::cin >> n;

  std::vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }

  std::cout << std::setprecision(10) << minimum_distance(x, y) << std::endl;

  return 0;
}
