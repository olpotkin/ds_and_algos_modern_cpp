
# Solutions for the [Advanced Algorithms and Complexity](https://www.coursera.org/learn/advanced-algorithms-and-complexity) course

## Contents

### Section 1: Flows in Networks

* [Evacuating People](https://github.com/olpotkin/ds_and_algos_modern_cpp/blob/master/05-advanced-algorithms-and-complexity/week1/1-evacuation/evacuation.cpp):
   Apply an algorithm for finding maximum flow in a network to determine how fast people can be evacuated from the given city.

* [Assigning Airline Crews to Flights](https://github.com/olpotkin/ds_and_algos_modern_cpp/blob/master/05-advanced-algorithms-and-complexity/week1/2-airline_crews/airline_crews.cpp):
   Apply an algorithm for finding maximum matching in a bipartite graph to assign airline crews to flights in the most efficient way.

### Section 2: Linear Programming

* [Infer Energy Values of Ingredients](https://github.com/olpotkin/ds_and_algos_modern_cpp/blob/master/05-advanced-algorithms-and-complexity/week2/1-energy_values/energy_values.cpp):
   Apply Gaussian Elimination to infer the energy values of ingredients given a restaurant menu with calorie counts and ingredient lists provided for each item.

* [Optimal Diet Problem](https://tbd):
   Шmplement an algorithm for solving linear programming with only a few inequalities and apply it to determine the optimal diet.

### Section 3: NP-complete Problems

* [TBD](https://tbd):
   tbd

### Section 4: Coping with NP-completeness

## Build instructions

* clang

```bash
clang++ -std=c++11 -stdlib=libc++ -Weverything file_name.cpp
```

* g++

```bash
g++ -pipe -O2 -std=c ++14 file_name.cpp -lm
```
