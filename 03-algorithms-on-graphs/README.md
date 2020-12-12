
# Solutions for the [Algorithms on Graphs](https://www.coursera.org/learn/algorithms-on-graphs/) course

## Contents

### Section 1: Decomposition of Graphs I

* [Finding an Exit from a Maze](https://github.com/olpotkin/ds_and_algos_modern_cpp/blob/master/03-algorithms-on-graphs/week1/1_finding_exit_from_maze/reachability.cpp):
   Given an undirected graph and two distinct vertices _u_ and _v_, check if there is a path between _u_ and _v_.

* [Adding Exits to a Maze](https://github.com/olpotkin/ds_and_algos_modern_cpp/blob/master/03-algorithms-on-graphs/week1/2_adding_exits_to_maze/connected_components.cpp):
   Given an undirected graph with n vertices and m edges, compute the number of connected components in it.

### Section 2: Decomposition of Graphs II

* [Checking Consistency of CS Curriculum](https://github.com/olpotkin/ds_and_algos_modern_cpp/blob/master/03-algorithms-on-graphs/week2/1_cs_curriculum/acyclicity.cpp):
   Check whether a given directed graph with n vertices and m edges contains a cycle.

* [Determining an Order of Courses](https://github.com/olpotkin/ds_and_algos_modern_cpp/blob/master/03-algorithms-on-graphs/week2/2_order_of_courses/toposort.cpp):
   Compute a topological ordering of a given directed acyclic graph (DAG) with n vertices and m edges.

### Section 3: Paths in Graphs I

* [Breadth first search (minimum number of flight segments)](https://github.com/olpotkin/ds_and_algos_modern_cpp/blob/master/03-algorithms-on-graphs/week3/1_flight_segments/bfs.cpp):
   Given an undirected graph with _n_ vertices and _m_ edges and two vertices _u_ and _v_, compute the length of a shortest path between _u_ and _v_ (that is, the minimum number of edges in a path from _u_ to _v_).

### Section 4: Paths in Graphs II

* [Computing the Minimum Cost of a Flight](https://github.com/olpotkin/ds_and_algos_modern_cpp/blob/master/03-algorithms-on-graphs/week4/1_minimum_flight_cost/dijkstra.cpp):
   Given an directed graph with positive edge weights and with _n_ vertices and _m_ edges as well as two vertices _u_ and _v_, compute the weight of a shortest path between _u_ and _v_ (that is, the minimum total weight of a path from _u_ to _v_).

* [Exchanging Money Optimally](https://github.com/olpotkin/ds_and_algos_modern_cpp/blob/master/03-algorithms-on-graphs/week4/3_exchanging_money/shortest_paths.cpp):
   Given an directed graph with possibly negative edge weights and with _n_ vertices and _m_ edges as well as its vertex _s_, compute the length of shortest paths from _s_ to all other vertices of the graph.

### Section 5: Minimum Spanning Trees

* [Building Roads to Connect Cities](TBD):
   The goal is to build roads between some pairs of the given cities such that there is a path between any two cities and the total length of the roads is minimized.

## Build instructions

* clang

```bash
clang++ -std=c++11 -stdlib=libc++ -Weverything file_name.cpp
```

* g++

```bash
g++ -pipe -O2 -std=c ++14 file_name.cpp -lm
```
