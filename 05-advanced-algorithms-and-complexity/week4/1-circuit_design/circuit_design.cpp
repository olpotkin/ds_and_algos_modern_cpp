#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <limits>

/// Integrated Circuit Design
///
/// Intro: In this problem, you will determine how to connect the modules of an integrated circuit with wires so that
///        all the wires can be routed on the same layer of the circuit.
///
/// Useful links:
/// https://en.wikipedia.org/wiki/Tarjan's_strongly_connected_components_algorithm
/// https://en.wikipedia.org/wiki/2-satisfiability
///
/// Task: VLSI or Very Large-Scale Integration is a process of creating an integrated circuit by combining thousands of
///       transistors on a single chip. You want to design a single layer of an integrated circuit. You know exactly
///       what modules will be used in this layer, and which of them should be connected by wires. The wires will be
///       all on the same layer, but they cannot intersect with each other. Also, each wire can only be bent once, in
///       one of two directions — to the left or to the right. If you connect two modules with a wire, selecting the
///       direction of bending uniquely defines the position of the wire. Of course, some positions of some pairs of
///       wires lead to intersection of the wires, which is forbidden. You need to determine a position for each wire
///       in such a way that no wires intersect.
///
///       This problem can be reduced to 2-SAT problem — a special case of the SAT problem in which each clause contains
///       exactly 2 variables. For each wire i, denote by x_i a binary variable which takes value 1 if the wire is bent
///       to the right and 0 if the wire is bent to the left. For each i, x_i must be either 0 or 1. Also, some pairs of
///       wires intersect in some positions. For example, it could be so that if wire 1 is bent to the left and wire 2
///       is bent to the right, then they intersect. We want to write down a formula which is satisfied only if no wires
///       intersect. In this case, we will add the clause (x_1 OR x_2) to the formula which ensures that either x_1 (the
///       first wire is bent to the right) is true or x_2 (the second wire is bent to the left) is true, and so the
///       particular crossing when wire 1 is bent to the left AND wire 2 is bent to the right doesn’t happen whenever the
///       formula is satisfied. We will add such a clause for each pair of wires and each pair of their positions if they
///       intersect when put in those positions. Of course, if some pair of wires intersects in any pair of possible
///       positions, we won’t be able to design a circuit. Your task is to determine whether it is possible, and if yes,
///       determine the direction of bending for each of the wires.
///
/// Input / Output requirements:
/// https://github.com/olpotkin/ds_and_algos_modern_cpp/blob/master/05-advanced-algorithms-and-complexity/week4/Programming-Assignment-4.pdf


struct solver_2SAT {
  struct util {
    util()
      : index{ MIN }
      , lowlink{ MIN }
      , id{ -1 }
      , on_stack{ false }
    {
    }

    int index, lowlink, id;
    bool on_stack;
    std::vector<int> edges;
  };

  solver_2SAT(std::unordered_map<int, util> adj_lst_graph, int num_of_vars)
    : n{ num_of_vars }
    , graph{ std::move(adj_lst_graph) }
    , sol{ std::vector<bool>(n, false) }
  {
  }

  void process_vertex(int v) {
    auto& utl = graph[v];

    utl.lowlink = utl.index = t++;
    utl.on_stack = true;
    stk.push(v);

    for (auto w : utl.edges) {
      if (graph[w].index == MIN) {
        process_vertex(w);
        utl.lowlink = std::min(utl.lowlink, graph[w].lowlink);
      }
      else if (graph[w].on_stack) {
        utl.lowlink = std::min(utl.lowlink, graph[w].index);
      }
    }

    if (utl.lowlink == utl.index) {
      do {
        w = stk.top();
        stk.pop();

        if (id == graph[-w].id) {
          sat = false;
          return;
        }

        auto& w_utl = graph[w];
        w_utl.on_stack = false;
        w_utl.id = id;

        sol[abs(w) - 1] = w < 0 ? true : false;

      } while (w != v);
      
      ++id;
    }
  }

  void solve() {
    for (int i = -n; i <= n; ++i) {
      if (graph[i].index == MIN && i != 0) {
        process_vertex(i);
      }
    }
  }

  void print_solution() const noexcept {
    if (!sat) {
      printf("%s\n", "UNSATISFIABLE\0");
      return;
    }

    printf("%s\n", "SATISFIABLE\0");

    for (unsigned int i = 0, s = sol.size(); i < s; ++i) {
      printf("%d ", (sol[i] ? i + 1 : -(i + 1)));
    }

    printf("\n");
  }

  int t{ 0 }, id{ 0 }, w{ 0 }, n{ 0 };

  std::unordered_map<int, util> graph;
  std::vector<bool> sol;
  std::stack<int> stk;

  bool sat{ true };

  static constexpr int MIN = std::numeric_limits<int>::min();
};


int main()
{
  std::ios::sync_with_stdio(false);

  int n, m;
  std::cin >> n >> m;

  std::unordered_map<int, solver_2SAT::util> adj_lst_graph(n * 2);

  for (int i = 0, x, y; i < m; ++i) {
    std::cin >> x >> y;
    adj_lst_graph[-x].edges.emplace_back(y);
    adj_lst_graph[-y].edges.emplace_back(x);
  }

  solver_2SAT solver(std::move(adj_lst_graph), n);
  solver.solve();
  solver.print_solution();
}
