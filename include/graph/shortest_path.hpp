#pragma once

#ifndef GRAPH_SHORTEST_PATH
#define GRAPH_SHORTEST_PATH

#include "common.hpp"

/**
 * Implements the Bellman-Ford algorithm for single-source shortest paths with negative edge weights.
 *
 * Computes shortest paths from source node `s` to all other nodes in a weighted graph,
 * and detects whether the graph contains any negative-weight cycles reachable from `s`.
 *
 * @param G     Weighted graph represented as an adjacency list where G[u] contains
 *              pairs of (v, w) indicating an edge from u to v with weight w
 * @param s     Source vertex index (0-based)
 * @param dist  Output vector that will store the shortest distance from s to each vertex
 *              (initial contents will be overwritten)
 * @param pred  Output vector that will store predecessors in the shortest path tree
 *              (-1 indicates no predecessor/vertex unreachable)
 * @return      true if a negative-weight cycle is detected, false otherwise
 *
 * @note The algorithm performs V-1 relaxations of all edges, followed by one additional
 *       pass to detect negative cycles
 * @note Time complexity: O(V*E), where V is number of vertices and E is number of edges
 * @note Space complexity: O(V) for distance and predecessor storage
 *
 * Example usage:
 * @code
 *   wgraph G = {{{1, 4}, {2, 1}}, {{3, 1}}, {{1, 2}, {3, 5}}, {}};
 *   vector<ll> dist(4);
 *   vector<int> pred(4);
 *   bool has_negative_cycle = bellman_ford(G, 0, dist, pred);
 *   if (!has_negative_cycle) {
 *       // dist now contains shortest paths from node 0
 *   }
 * @endcode
 */
bool bellman_ford(const wgraph &G, const int s,std::vector<ll> &dist,std::vector<int> &pred);

/**
 * Computes single-source shortest paths using Dijkstra's algorithm.
 *
 * Finds the shortest paths from a source vertex `s` to all other vertices in
 * a weighted graph with non-negative edge weights. Uses a priority queue for
 * efficient extraction of the next vertex to process.
 *
 * @param G     Weighted graph represented as an adjacency list, where G[u] contains
 *              pairs of (v, w) indicating an edge from u to v with weight w
 * @param s     Source vertex index (0-based)
 * @param dist  Output vector that will be resized and filled with shortest distances
 *              from s to each vertex (LLINF for unreachable vertices)
 * @param pred  Output vector that will be resized and filled with predecessors in
 *              the shortest path tree (-1 indicates no predecessor)
 *
 * @note The graph must not contain negative edge weights
 * @note Uses a max-heap priority queue with negative distances for min-heap behavior
 * @note Time complexity: O((V + E) log V) with binary heap
 * @note Space complexity: O(V) for distance and predecessor storage
 *
 * Example usage:
 * @code
 *   wgraph G = {{{1, 4}, {2, 1}}, {{3, 1}}, {{1, 2}, {3, 5}}, {}};
 *   vector<ll> dist;
 *   vector<int> pred;
 *   dijkstra(G, 0, dist, pred);
 *   // dist now contains shortest distances from node 0
 * @endcode
 */
void dijkstra(const wgraph &G, const int s,std::vector<ll> &dist,std::vector<int> &pred);

// Floyd-Warshall

/*
O(V^3)
*/
/**
 * Computes all-pairs shortest paths using the Floyd-Warshall algorithm (unweighted version).
 * 
 * For an unweighted graph, computes the shortest path distances between all pairs of vertices
 * where each edge has implicit weight 1. Handles both connected and disconnected graphs.
 *
 * @param G Input graph represented as an adjacency list (G[u] contains neighbors of u)
 * @return  Distance matrix D where D[i][j] = shortest distance from i to j (LLINF if unreachable)
 *
 * @note Time complexity: O(V³) where V is number of vertices
 * @note Space complexity: O(V²) for the distance matrix
 * @note Suitable for dense graphs where V is not too large
 * @note Automatically handles self-loops (D[i][i] = 0)
 *
 * Example usage:
 * @code
 *   graph G = {{1, 2}, {0, 2}, {0, 1}};  // Triangle graph
 *   auto distances = floyd_warshall(G);
 *   // distances[0][1] == 1 (direct edge)
 * @endcode
 */
llmatrix floyd_warshall(const graph &G);

/**
 * Computes all-pairs shortest paths using the Floyd-Warshall algorithm (weighted version).
 *
 * For a weighted graph, computes the shortest path distances between all pairs of vertices,
 * including handling of negative edge weights (but no negative cycles).
 *
 * @param G Input weighted graph represented as an adjacency list (G[u] contains pairs of (v, weight))
 * @return  Distance matrix D where D[i][j] = shortest distance from i to j (LLINF if unreachable)
 *
 * @note Detects negative cycles if any diagonal entry D[i][i] becomes negative
 * @note Time complexity: O(V³) where V is number of vertices
 * @note Space complexity: O(V²) for the distance matrix
 * @note For graphs with negative cycles, results are not valid
 *
 * Example usage:
 * @code
 *   wgraph G = {{{1, 4}, {2, 2}}, {{0, 1}}, {{1, -3}}};
 *   auto distances = floyd_warshall(G);
 *   // distances[0][1] == -1 (path 0->2->1)
 * @endcode
 */
llmatrix floyd_warshall(const wgraph &G);


#endif // GRAPH_SHORTEST_PATH