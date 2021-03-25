
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

* [Optimal Diet Problem](https://github.com/olpotkin/ds_and_algos_modern_cpp/blob/master/05-advanced-algorithms-and-complexity/week2/2-diet/diet.cpp):
   Шmplement an algorithm for solving linear programming with only a few inequalities and apply it to determine the optimal diet.

### Section 3: NP-complete Problems

* [Assign Frequencies to the Cells of a GSM Network](https://github.com/olpotkin/ds_and_algos_modern_cpp/blob/master/05-advanced-algorithms-and-complexity/week3/1-gsm_network/gsm_network.cpp):
   Learn to reduce the real-world problem about assigning frequencies to the transmitting towers of the cells in a GSM network to a problem of proper coloring a graph into 3 colors. Then design and implement an algorithm to reduce this problem to an instance of SAT.

* [Cleaning the Apartment](https://github.com/olpotkin/ds_and_algos_modern_cpp/blob/master/05-advanced-algorithms-and-complexity/week3/2-cleaning_apartment/cleaning_apartment.cpp):
   Learn to determine whether it is possible to clean an apartment after a party without leaving any traces of the party. Learn how to reduce it to the classic Hamiltonian Path problem, and then design and implement an efficient algorithm to reduce it to SAT.

### Section 4: Coping with NP-completeness

* [Integrated Circuit Design](https://github.com/olpotkin/ds_and_algos_modern_cpp/blob/master/05-advanced-algorithms-and-complexity/week4/1-circuit_design/circuit_design.cpp):
   Determine how to connect the modules of an integrated circuit with wires so that all the wires can be routed on the same layer of the circuit.

* [Plan a Fun Party](https://github.com/olpotkin/ds_and_algos_modern_cpp/blob/master/05-advanced-algorithms-and-complexity/week4/2-plan_party/plan_party.cpp):
   Design and implement an efficient algorithm to plan invite the coolest people from the company to a party in such a way that everybody is relaxed, because the direct boss of any invited person is not invited.

## Build instructions

* clang

```bash
clang++ -std=c++11 -stdlib=libc++ -Weverything file_name.cpp
```

* g++

```bash
g++ -pipe -O2 -std=c ++14 file_name.cpp -lm
```
