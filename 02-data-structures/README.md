
# Solutions for the [Data Structures](https://www.coursera.org/learn/data-structures/) course

## Contents

### Section 1: Basic Data Structures

* [Check brackets in the code](https://github.com/olpotkin/ds_and_algos_modern_cpp/blob/master/02-data-structures/week1/1_brackets_in_code/check_brackets.cpp):
   If the code in S uses brackets correctly, output “Success" (without the quotes). Otherwise, output the 1-based index of the first unmatched closing bracket, and if there are no unmatched closing brackets, output the 1-based index of the first unmatched opening bracket.

* [Compute tree height](https://github.com/olpotkin/ds_and_algos_modern_cpp/blob/master/02-data-structures/week1/2_tree_height/tree-height.cpp):
   Output the height of the tree (optimal solution is required).

* [Network packet processing simulation](https://github.com/olpotkin/ds_and_algos_modern_cpp/tree/master/02-data-structures/week1/3_network_simulation)
   Implement a program to simulate the processing of network packets.

### Section 2: Priority Queues and Disjoint Sets

* [Convert array into heap](https://github.com/olpotkin/ds_and_algos_modern_cpp/blob/master/02-data-structures/week2/1_make_heap/build_heap.cpp)
   Convert an array of integers into a heap.

* [Parallel processing](https://github.com/olpotkin/ds_and_algos_modern_cpp/blob/master/02-data-structures/week2/2_job_queue/job_queue.cpp)
   Determine for each job which thread will process it and when will it start processing.

### Section 3: Hash Tables

* [Phone book](https://github.com/olpotkin/ds_and_algos_modern_cpp/blob/master/02-data-structures/week3/1_phone_book/phone_book.cpp)
   Implement a simple phone book manager using hash tables.

* [Hashing with chains](https://github.com/olpotkin/ds_and_algos_modern_cpp/blob/master/02-data-structures/week3/2_hash_chains/hash_chains.cpp)
   Implement a hash table using the chaining scheme.

### Section 4: Binary Search Trees

* [Binary tree traversals](https://github.com/olpotkin/ds_and_algos_modern_cpp/blob/master/02-data-structures/week4/1_tree_traversals/tree-orders.cpp)
   Implement in-order, pre-order and post-order traversals of a binary tree.

* [Is it a binary search tree?](https://github.com/olpotkin/ds_and_algos_modern_cpp/blob/master/02-data-structures/week4/2_is_bst/is_bst.cpp)
   Test whether a binary search tree data structure from some input was done correctly.

* [Is it a binary search tree? Hard version.](https://github.com/olpotkin/ds_and_algos_modern_cpp/blob/master/02-data-structures/week4/3_is_bst_advanced/is_bst_hard.cpp)
   Test whether a binary search tree data structure from some input was done correctly, but for a more general case, when binary search tree may contain equal keys.

## Build instructions

* clang

```bash
clang++ -std=c++11 -stdlib=libc++ -Weverything file_name.cpp
```

* g++

```bash
g++ -pipe -O2 -std=c ++14 file_name.cpp -lm
```
