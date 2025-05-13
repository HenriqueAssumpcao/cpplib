#pragma once

#ifndef GRAPH_MST
#define GRAPH_MST

#include "common.hpp"

/**
 * Represents a weighted undirected edge in a graph for Minimum Spanning Tree (MST) algorithms.
 *
 * This structure stores edge information including its endpoints and weight,
 * and provides comparison functionality for sorting edges by weight.
 *
 * @var u  Source vertex of the edge (0-based index)
 * @var v  Target vertex of the edge (0-based index)
 * @var w  Weight/cost of the edge 
 *
 * @note Designed for use with Kruskal's algorithm and other MST algorithms
 * @note The operator< is defined for sorting edges by weight in non-decreasing order
 *
 * Example usage:
 * @code
 *   vector<wedge> edges;
 *   edges.emplace_back(0, 1, 4);  // Edge between 0 and 1 with weight 4
 *   edges.emplace_back(1, 2, 2);  // Edge between 1 and 2 with weight 2
 *   sort(edges.begin(), edges.end());  // Sorts edges by weight
 * @endcode
 */
struct wedge {
    int u, v;  // Edge endpoints
    ll w;      // Edge weight

    /**
     * Comparison operator for sorting edges by weight.
     *
     * @param other Another wedge to compare against
     * @return true if this edge's weight is less than the other's weight
     */
    bool operator<(wedge const& other) {
        return this->w < other.w;
    }

    /**
     * Constructs a new weighted edge.
     *
     * @param _u Source vertex (0-based index)
     * @param _v Target vertex (0-based index)
     * @param _w Edge weight (should be non-negative for MST algorithms)
     */
    wedge(int _u, int _v, ll _w) : u(_u), v(_v), w(_w) {}
};

/**
 * Computes the Minimum Spanning Tree (MST) of a graph using Prim's algorithm.
 *
 * This implementation uses a priority queue to efficiently select the next edge
 * with minimum weight to add to the growing MST. The graph is represented as
 * an adjacency list.
 *
 * @param s     Starting vertex for the MST (0-based index)
 * @param n     Total number of vertices in the graph
 * @param g     Weighted graph represented as an adjacency list where g[u] contains
 *              pairs of (v, w) indicating an edge from u to v with weight w
 * @param pred  Output vector that will store the predecessor of each vertex in the MST
 *              (-1 indicates no predecessor/vertex unreachable)
 * @return      The total weight/cost of the MST
 *
 * @note The graph must be undirected and connected (for complete MST)
 * @note Time complexity: O(E log V) with binary heap priority queue
 * @note Space complexity: O(V) for key, pred, and visited storage
 * @note Uses a max-heap priority queue with negative weights for min-heap behavior
 * @note LLINF should be defined as a large constant (e.g., numeric_limits<ll>::max())
 *
 * Example usage:
 * @code
 *   wgraph g = {{{1, 4}, {2, 3}}, {{0, 4}, {2, 1}}, {{0, 3}, {1, 1}}};
 *   vector<int> pred;
 *   ll total_weight = mst_prim(0, 3, g, pred);
 *   // pred will contain MST parent pointers
 *   // total_weight will be 4 (0-2 and 1-2)
 * @endcode
 */
ll mst_prim(const int s,const int n,const wgraph &g, std::vector<int> &pred);

/**
 * Computes the Minimum Spanning Tree (MST) of a graph using Kruskal's algorithm.
 *
 * This implementation uses a Disjoint Set Union (DSU) data structure for efficient
 * cycle detection. The graph is represented as a list of weighted edges.
 *
 * @param n     Number of vertices in the graph (0 to n-1)
 * @param edges Vector of all weighted edges in the graph (will be sorted)
 * @param mst   Output vector that will contain the edges of the MST
 * @return      The total weight/cost of the MST
 *
 * @note The graph must be undirected (each edge should appear once)
 * @note Time complexity: O(E log E) for sorting + O(E α(V)) for DSU operations
 * @note Space complexity: O(V) for DSU storage + O(E) for MST storage
 * @note Requires wedge type with {u, v, w} members and operator< defined for sorting
 * @note Requires dsu class with make_set, find_set, and union_sets methods
 *
 * Example usage:
 * @code
 *   vector<wedge> edges = {{0, 1, 4}, {1, 2, 2}, {0, 2, 3}};
 *   vector<wedge> mst_edges;
 *   ll total_weight = mst_kruskal(3, edges, mst_edges);
 *   // mst_edges will contain the MST edges
 *   // total_weight will be 5 (1-2 and 0-2)
 * @endcode
 */
ll mst_kruskal(const int n,std::vector<wedge> edges, std::vector<wedge> &mst);


#endif // GRAPH_MST