
# Solutions for the [Algorithms on Strings](https://www.coursera.org/learn/algorithms-on-strings/) course

## Contents

### Section 1: Suffix Trees

* [Construct a Trie from a Collection of Patterns](https://github.com/olpotkin/ds_and_algos_modern_cpp/blob/master/04-algorithms-on-strings/week1/1-trie/trie.cpp):
   Find all occurrences of a collection of patterns in a text.

* [Implement TrieMatching](https://github.com/olpotkin/ds_and_algos_modern_cpp/blob/master/04-algorithms-on-strings/week1/2-trie_matching/trie_matching.cpp):
   Implement TrieMatching algorithm.

* [Extend TrieMatching](https://github.com/olpotkin/ds_and_algos_modern_cpp/blob/master/04-algorithms-on-strings/week1/3-trie_matching_extended/trie_matching_extended.cpp):
   Extend TrieMatching algorithm so that it handles correctly cases when one of the patterns is a prefix of another one.

### Section 2: Burrows-Wheeler Transform and Suffix Arrays

* [Construct the Burrows–Wheeler Transform of a String](https://github.com/olpotkin/ds_and_algos_modern_cpp/blob/master/04-algorithms-on-strings/week2/1-bwt/bwt.cpp):
   Construct the Burrows–Wheeler Transform of a String.

* [Reconstruct a String from its Burrows–Wheeler Transform](https://github.com/olpotkin/ds_and_algos_modern_cpp/blob/master/04-algorithms-on-strings/week2/2-bwtinverse/bwtinverse.cpp):
   Reconstruct a String from its Burrows–Wheeler Transform.

* [Implement BetterBWMatching](https://github.com/olpotkin/ds_and_algos_modern_cpp/blob/master/04-algorithms-on-strings/week2/3-bwmatching/bwmatching.cpp):
   Implement BetterBWMatching algorithm.

### Section 3: Constructing Suffix Arrays and Suffix Trees

* [Find All Occurrences of a Pattern in a String](https://github.com/olpotkin/ds_and_algos_modern_cpp/blob/master/04-algorithms-on-strings/week3/1-kmp/kmp.cpp):
   How many times one string occurs as a substring of another?

* [Construct the Suffix Array of a Long String](TBD):
   The goal in this problem is to construct the suffix array of a given string again, but this time for a longer string. This will require you to implement an efficient algorithm.

## Build instructions

* clang

```bash
clang++ -std=c++11 -stdlib=libc++ -Weverything file_name.cpp
```

* g++

```bash
g++ -pipe -O2 -std=c ++14 file_name.cpp -lm
```
