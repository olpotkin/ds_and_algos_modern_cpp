#include <iostream>
#include <vector>
#include <cstdio>


/// Cleaning the Apartment
///
/// Intro: In this problem, you will learn to determine whether it is possible to clean an apartment after a party
///        without leaving any traces of the party. You will learn how to reduce it to the classic Hamiltonian Path
///        problem, and then you will design and implement an efficient algorithm to reduce it to SAT.
///
/// Task: You’ve just had a huge party in your parents’ house, and they are returning tomorrow. You need to not only
///       clean the apartment, but leave no trace of the party. To do that, you need to clean all the rooms in some
///       order. After finishing a thorough cleaning of some room, you cannot return to it anymore: you are afraid
///       you’ll ruin everything accidentally and will have to start over. So, you need to move from room to room,
///       visit each room exactly once and clean it. You can only move from a room to the neighboring rooms. You want
///       to determine whether this is possible at all.
///
///       This can be reduced to a classic Hamiltonian Path problem: given a graph, determine whether there is a route
///       visiting each vertex exactly once. Rooms are vertices of the graph, and neighboring rooms are connected by edges.
///       Hamiltonian Path problem is NP-complete, so we don’t know an efficient algorithm to solve it. You need to reduce
///       it to SAT, so that it can be solved efficiently by a SAT-solver.
///
/// Input: The first line contains two integers n and m — the number of rooms and the number of corridors connecting the
///        rooms respectively. Each of the next m lines contains two integers u and v describing the corridor going from
///        room u to room v. The corridors are two-way, that is, you can go both from u to v and from v to u. No two
///        corridors have a common part, that is, every corridor only allows you to go from one room to one other room.
///        Of course, no corridor connects a room to itself. Note that a corridor from u to v can be listed several times,
///        and there can be listed both a corridor from u to v and a corridor from v to u.
///
/// Output: You need to output a boolean formula in the CNF form in a specific format. If it is possible to go through all
///         the rooms and visit each one exactly once to clean it, the formula must be satisfiable. Otherwise, the formula
///         must be unsatisfiable. The sum of the numbers of variables used in each clause of the formula must not exceed 120 000.


struct HamiltonianPathToSAT {

  HamiltonianPathToSAT(int n, int m)
    : clauses_num(0)
    , vertices_num(n)
    , matrix(n, std::vector<bool>(n, false))
    , data(n, std::vector<int>(n))
  {
    for (int i = 0, cnt = 0; i < vertices_num; ++i) {
      for (int j = 0; j < vertices_num; ++j) {
        data[i][j] = ++cnt;
      }
    }
  }

  void PrintSATFormula(const int max_clauses_num) noexcept
  {
    clauses_stream.reserve(max_clauses_num * 3);

    EachVertexInPath();
    EachVertexInPathOnlyOnce();
    EachPathPositionOccupied();
    VerticesOccupyDiffPositions();
    NonadjacentVerticesNonadjacentInPath();

    printf("%d %d \n%s", clauses_num, vertices_num * vertices_num, clauses_stream.c_str());
  }

  void EachVertexInPath() noexcept
  {
    for (int i = 0; i < vertices_num; ++i, ++clauses_num) {
      for (int j = 0; j < vertices_num; ++j) {
        clauses_stream += std::to_string(data[i][j]) + " ";
      }
      clauses_stream += "0\n";
    }
  }

  void EachVertexInPathOnlyOnce() noexcept
  {
    for (int i = 0; i < vertices_num; ++i) {
      for (int j = 0; j < vertices_num; ++j) {
        for (int k = i + 1; k < vertices_num; ++k, ++clauses_num) {
          clauses_stream += std::to_string(-data[i][j]) + " " + std::to_string(-data[k][j]) + " 0\n";
        }
      }
    }
  }

  void EachPathPositionOccupied() noexcept
  {
    for (int i = 0; i < vertices_num; ++i, ++clauses_num) {
      for (int j = 0; j < vertices_num; ++j) {
        clauses_stream += std::to_string(data[j][i]) + " ";
      }
      clauses_stream += "0\n";
    }
  }

  void VerticesOccupyDiffPositions() noexcept
  {
    for (int i = 0; i < vertices_num; ++i) {
      for (int j = 0; j < vertices_num; ++j) {
        for (int k = j + 1; k < vertices_num; ++k, ++clauses_num) {
          clauses_stream += std::to_string(-data[i][j]) + " " + std::to_string(-data[i][k]) + " 0\n";
        }
      }
    }
  }

  void NonadjacentVerticesNonadjacentInPath() noexcept
  {
    for (int i = 0; i < vertices_num; ++i) {
      for (int j = 0; j < vertices_num; ++j) {
        if (!matrix[i][j] && j != i) {
          for (int k = 0; k < vertices_num - 1; ++k, ++clauses_num) {
            clauses_stream += std::to_string(-data[i][k]) + " " + std::to_string(-data[j][k + 1]) + " 0\n";
          }
        }
      }
    }
  }

  unsigned int                   clauses_num;
  const unsigned int             vertices_num;
  std::vector<std::vector<bool>> matrix;
  std::vector<std::vector<int>>  data;
  std::string                    clauses_stream;
};


int main()
{
  std::ios::sync_with_stdio(false);

  int n, m;
  std::cin >> n >> m;

  HamiltonianPathToSAT converter(n, m);

  for (int k = 0; k < m; ++k) {
    int i, j;
    std::cin >> i >> j;
    converter.matrix[i - 1][j - 1] = true;
    converter.matrix[j - 1][i - 1] = true;
  }

  converter.PrintSATFormula(120000);

  return 0;
}
