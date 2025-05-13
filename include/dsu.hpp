#pragma once

#ifndef DSU
#define DSU

#include "common.hpp"

/**
 * Disjoint Set Union (DSU) data structure with path compression and union by rank.
 *
 * Also known as Union-Find, this data structure efficiently manages and queries
 * disjoint sets, supporting two primary operations:
 * - Find: Determine which set an element belongs to
 * - Union: Merge two sets together
 *
 * @var n       Number of elements in the DSU
 * @var parent  Array storing parent pointers for each element
 * @var rank    Array storing ranks for union by rank optimization
 *
 * @note Implements path compression in find_set for amortized O(α(n)) operations
 * @note Uses union by rank to keep the tree structure flat
 * @note All operations have amortized O(α(n)) time complexity (near-constant)
 * @note α(n) is the inverse Ackermann function (≤ 4 for practical n)
 *
 * Example usage:
 * @code
 *   dsu d(5);                // Create DSU for 5 elements
 *   d.make_set(0);           // Initialize set (typically done in constructor)
 *   d.union_sets(0, 1);      // Merge sets containing 0 and 1
 *   if (d.find_set(0) == d.find_set(1)) {
 *       // Elements are in the same set
 *   }
 * @endcode
 */
struct dsu{
    int n;
    std::vector<int> parent,rank;

    /**
     * Constructs a DSU structure for n elements.
     *
     * @param n Number of elements (0-based)
     */
    dsu(int n){
        this->n = n;
        this->parent = std::vector<int>(n,-1);
        this->rank = std::vector<int>(n,0);
    }

    /**
     * Creates a new set containing element v.
     *
     * @param v Element to create set for (0-based index)
     */
    void make_set(int v){
        parent[v] = v;
        rank[v];
    }

    /**
     * Finds the representative (root) of the set containing v.
     *
     * Implements path compression for future queries.
     *
     * @param v Element to find set for (0-based index)
     * @return The representative element of v's set
     */
    int find_set(int v){
        if(v == parent[v]){
            return v;
        }
        parent[v] = find_set(parent[v]);
        return parent[v];
    }

    /**
     * Merges the sets containing elements a and b.
     *
     * Uses union by rank to keep the tree shallow.
     *
     * @param a First element (0-based index)
     * @param b Second element (0-based index)
     */
    void union_sets(int a, int b){
        a = find_set(a);b = find_set(b);
        if(a != b){
            if(rank[a] < rank[b]){
                std::swap(a,b);
            }
            else if(rank[a] == rank[b]){
                rank[a]++;
            }
            parent[b] = a;
        }
    }
};

#endif // DSU