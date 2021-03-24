#include <ios>
#include <iostream>
#include <vector>


/// Assign Frequencies to the Cells of a GSM Network
///
/// Intro: In this problem, you will learn to reduce the real-world problem about assigning frequencies to the
///        transmitting towers of the cells in a GSM network to a problem of proper coloring a graph into 3 colors.
///        Then you will design and implement an algorithm to reduce this problem to an instance of SAT.
///
/// Task: GSM network is a type of infrastructure used for communication via mobile phones. It includes transmitting
///       towers scattered around the area which operate in different frequencies. Typically there is one tower in the
///       center of each hexagon called “cell” on the grid above — hence the name “cell phone”.
///       A cell phone looks for towers in the neighborhood and decides which one to use based on strength of signal and
///       other properties. For a phone to distinguish among a few closest towers, the frequencies of the neighboring
///       towers must be different. You are working on a plan of GSM network for mobile, and you have a restriction that
///       you’ve only got 3 different frequencies from the government which you can use in your towers. You know which
///       pairs of the towers are neighbors, and for all such pairs the towers in the pair must use different frequencies.
///       You need to determine whether it is possible to assign frequencies to towers and satisfy these restrictions.
///
///       This is equivalent to a classical graph coloring problem: in other words, you are given a graph, and you need to
///       color its vertices into 3 different colors, so that any two vertices connected by an edge need to be of different
///       colors. Colors correspond to frequencies, vertices correspond to cells, and edges connect neighboring cells. Graph
///       coloring is an NP-complete problem, so we don’t currently know an efficient solution to it, and you need to reduce
///       it to an instance of SAT problem which, although it is NP-complete, can often be solved efficiently in practice
///       using special programs called SAT-solvers.
///
/// Input: The first line of the input contains integers n and m — the number of vertices and edges in the graph. The
///        vertices are numbered from 1 through n. Each of the next m lines contains two integers u and v — the numbers of
///        vertices connected by an edge. It is guaranteed that a vertex cannot be connected to itself by an edge.
///
/// Output: You need to output a boolean formula in the conjunctive normal form (CNF) in a specific format. If it is
///         possible to color the vertices of the input graph in 3 colors such that any two vertices connected by an edge
///         are of different colors, the formula must be satisfiable. Otherwise, the formula must be unsatisfiable. The
///         number of variables in the formula must be at least 1 and at most 3000. The number of clauses must be at least
///         1 and at most 5000.


struct ConvertGSMNetworkProblemToSat {
  static constexpr auto K = 3;

  struct Edge {
    int from;
    int to;
  };

  ConvertGSMNetworkProblemToSat(int n, int m)
    : numVertices(n)
    , edges(m)
  {
  }

  void printEquisatisfiableSatFormula() const noexcept
  {
    const int C = K * edges.size() + numVertices;
    const int V = numVertices * K;

    printf("%d %d\n", C, V);

    for (int i = 0, cnt = 1; i < numVertices; ++i, cnt += K) {
      printf("%d %d %d 0\n", cnt, cnt + 1, cnt + 2);
    }

    for (const Edge& e : edges) {
      printf("%d %d 0\n", -((e.from - 1) * K + 1), -((e.to - 1) * K + 1));
      printf("%d %d 0\n", -((e.from - 1) * K + 2), -((e.to - 1) * K + 2));
      printf("%d %d 0\n", -((e.from - 1) * K + 3), -((e.to - 1) * K + 3));
    }
  }

  int numVertices;
  std::vector<Edge> edges;
};


int main() {
  std::ios::sync_with_stdio(false);

  int n, m;
  std::cin >> n >> m;

  ConvertGSMNetworkProblemToSat converter(n, m);

  for (int i = 0; i < m; ++i) {
    std::cin >> converter.edges[i].from >> converter.edges[i].to;
  }

  converter.printEquisatisfiableSatFormula();

  return 0;
}
