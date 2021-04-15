# Solutions for the [Genome Assembly Programming Challenge](https://www.coursera.org/learn/assembling-genomes?specialization=data-structures-algorithms) course

## Contents

### Section 1: The 2011 European E. coli Outbreak

* [Assembling the phi X174 Genome from Error-Prone Reads Using Overlap Graphs](https://github.com/olpotkin/ds_and_algos_modern_cpp/blob/master/06-assembling-genomes/week1/phi-x174-error-prone-reads.cpp):
   Perform Genome Assembly on a simulated error-prone sequencing dataset.

### Section 2: Assembling Genomes Using de Bruijn Graphs

* [Puzzle Assembly](https://github.com/olpotkin/ds_and_algos_modern_cpp/blob/master/06-assembling-genomes/week2/01-puzzle-assemply.cpp):
   Consider a square puzzle consisting of n-by-n square pieces, where each square piece has a single color on each of its four edges.

* [Finding an Eulerian Cycle in Directed Graph](https://github.com/olpotkin/ds_and_algos_modern_cpp/blob/master/06-assembling-genomes/week2/02-eulerian-cycle.cpp):
   Given a directed graph, find an Eulerian cycle in the graph or report that none exists.

### Section 3: Genome Assembly Faces Real Sequencing Data

* [Finding a Circulation in a Network](https://tbd):
   Given a network with lower bounds and capacities on edges, find a circulation if it exists.

* [Selecting the Optimal k-mer Size](https://github.com/olpotkin/ds_and_algos_modern_cpp/blob/master/06-assembling-genomes/week3/02-optimal-kmer-size.cpp):
   Given a list of error-free reads, return an integer k such that, when a de Bruijn graph is created from the k-length fragments of the reads, the de Bruijn graph has a single possible Eulerian Cycle.

## Build instructions

* clang

```bash
clang++ -std=c++11 -stdlib=libc++ -Weverything file_name.cpp
```

* g++

```bash
g++ -pipe -O2 -std=c ++14 file_name.cpp -lm
```
