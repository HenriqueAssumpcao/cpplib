#pragma once

#ifndef FLOWS
#define FLOWS

#include "common.hpp"

/**
 * Represents a directed edge in a flow network with capacity and flow tracking.
 *
 * This structure stores all necessary information for flow network edges,
 * including reverse edges used in max flow algorithms. The default flow
 * initialization to 0 makes it suitable for immediate use in flow algorithms.
 *
 * @var u    Source vertex of the edge (0-based index)
 * @var v    Target vertex of the edge (0-based index)
 * @var cap  Capacity of the edge (must be non-negative)
 * @var flow Current flow through the edge (initialized to 0)
 *
 * @note For max flow algorithms, reverse edges should have cap = 0 initially
 * @note The residual capacity of an edge is given by (cap - flow)
 * @note This is typically used with algorithms like Ford-Fulkerson,
 *       Edmonds-Karp, or Dinic's algorithm
 *
 * Example usage:
 * @code
 *   // Forward edge with capacity 10
 *   flow_edge fe(0, 1, 10);
 *   // Reverse edge with capacity 0
 *   flow_edge rev_fe(1, 0, 0);
 * @endcode
 */
struct flow_edge {
    int u, v;        // Endpoints of directed edge
    ll cap, flow = 0; // Capacity and current flow
    
    /**
     * Constructs a flow edge with specified parameters.
     *
     * @param _u   Source vertex (0-based index)
     * @param _v   Target vertex (0-based index)
     * @param _cap Edge capacity (must be ≥ 0)
     */
    flow_edge(int _u, int _v, ll _cap) : u(_u), v(_v), cap(_cap) {};
};

/**
 * Constructs a flow graph from input data, optionally merging multi-edges.
 *
 * Reads edge data from standard input and builds:
 * 1) A vector of all flow edges (including reverse edges)
 * 2) An adjacency list representation of the graph
 *
 * @param n                 Number of vertices in the graph
 * @param m                 Number of edges in the input
 * @param merge_multi_edges Whether to merge multiple edges between same vertices
 * @param edges             Output vector of flow edges (will be cleared and populated)
 * @param g                 Output adjacency list (will be cleared and populated)
 *
 * @note Input format expected: for each edge, provide "u v c" representing
 *       start vertex, end vertex, and capacity (1-based indices)
 * @note The function converts input to 0-based indexing internally
 * @note When merge_multi_edges is true, capacities of parallel edges are summed
 * @note Reverse edges (with capacity 0) are automatically added for each edge
 * @note The adjacency list stores edge indices, not vertex indices
 *
 * Example usage:
 * @code
 *   vector<flow_edge> edges;
 *   graph g;
 *   build_flow_graph(n, m, true, edges, g);
 * @endcode
 */
void build_flow_graph(const int n,const int m,const bool merge_multi_edges, std::vector<flow_edge> &edges, graph &g);

/**
 * Finds an augmenting path using BFS and returns its bottleneck capacity.
 *
 * Performs a BFS from source to sink while tracking parent pointers and
 * the maximum possible flow along the current path. Only considers edges
 * with residual capacity >= cap_lb.
 *
 * @param s         Source vertex (0-based index)
 * @param t         Sink vertex (0-based index)
 * @param n         Total number of vertices
 * @param g         Adjacency list representation of the graph
 * @param edges     Vector of all flow edges
 * @param parent    Output vector storing parent edge indices (-1 if unreachable)
 * @param cap_lb    Minimum residual capacity to consider
 * @return          Bottleneck capacity of found path (0 if no path exists)
 *
 * @note The parent vector uses edge indices rather than vertex indices to
 *       facilitate flow updates in the main algorithm
 */
ll aug_path_bfs(const int s,const int t,const int n,const graph &g,const std::vector<flow_edge> &edges, std::vector<int> &parent,const ll cap_lb=1);

/**
 * Computes maximum flow using Edmonds-Karp algorithm (BFS-based Ford-Fulkerson).
 *
 * The algorithm repeatedly:
 * 1) Finds shortest augmenting paths via BFS
 * 2) Pushes flow along these paths
 * 3) Updates residual capacities
 * Until no more augmenting paths exist.
 *
 * @param s         Source vertex (0-based index)
 * @param t         Sink vertex (0-based index)
 * @param n         Total number of vertices
 * @param g         Adjacency list representation of the graph
 * @param edges     Vector of flow edges (will be modified with final flows)
 * @param min_cut   Output vector marking reachable vertices (1 if reachable)
 * @param cap_lb    Minimum residual capacity to consider
 * @return          Maximum flow value from s to t
 *
 * @note The min_cut vector represents the source-side of the minimum cut
 * @note Time complexity: O(V*E²) in worst case
 *
 * Example usage:
 * @code
 *   graph g = build_graph();
 *   vector<flow_edge> edges = get_edges();
 *   vector<int> min_cut;
 *   ll flow = edmonds_karp_maxflow(s, t, n, g, edges, min_cut, 1);
 * @endcode
 */
ll edmonds_karp_maxflow(const int s,const int t,const int n,const graph &g, std::vector<flow_edge> &edges,std::vector<int> &min_cut,const ll cap_lb=1);

/**
 * Performs a breadth-first search (BFS) to establish level graph for Dinic's algorithm.
 * 
 * Computes the shortest path distance from source `s` to all reachable vertices 
 * through edges with residual capacity >= `cap_lb`, storing results in `bfs_layer`.
 *
 * @param s         Source vertex (0-based index)
 * @param n         Total number of vertices in graph
 * @param g         Adjacency list where g[u] contains edge indices for vertex u
 * @param edges     Vector of all flow edges
 * @param bfs_layer Output vector storing BFS layers (-1 if unreachable)
 * @param cap_lb    Minimum residual capacity to consider for edge traversal
*/
void bfs(const int s,const int n,const graph &g,const std::vector<flow_edge> &edges, std::vector<int> &bfs_layer,const ll cap_lb=1);

/**
 * Finds augmenting paths in the level graph using depth-first search (DFS).
 *
 * Attempts to push flow from vertex `u` to sink `t` while respecting:
 * 1) BFS layer constraints (only moving to next layer)
 * 2) Minimum residual capacity requirements (`cap_lb`)
 * Uses DFS pointer (`dfs_ptr`) to avoid revisiting edges unnecessarily.
 *
 * @param u         Current vertex being explored
 * @param t         Sink vertex (0-based index)
 * @param flow      Maximum possible flow that can be pushed in current path
 * @param g         Adjacency list representation of graph
 * @param edges     Vector of flow edges (will be modified with new flows)
 * @param bfs_layer BFS layer information from previous BFS
 * @param dfs_ptr   Vector tracking next edge to explore for each vertex
 * @param cap_lb    Minimum residual capacity to consider
 * @return          Actual flow pushed through this path (0 if no augmentation)
 */
ll layer_aug_path_dfs(const int u,const int t,
const ll flow,const graph &g, std::vector<flow_edge> &edges,std::vector<int> &bfs_layer, std::vector<int> &dfs_ptr,const ll cap_lb=1);

/**
 * Computes maximum flow using Dinic's algorithm.
 *
 * The algorithm alternates between:
 * 1) Building level graphs via BFS
 * 2) Finding blocking flows via DFS with current level graph
 * Continues until no augmenting path exists from source to sink.
 *
 * @param s         Source vertex (0-based index)
 * @param t         Sink vertex (0-based index)
 * @param n         Total number of vertices
 * @param g         Adjacency list representation of graph
 * @param edges     Vector of flow edges (will be modified with final flows)
 * @param min_cut   Output vector marking reachable vertices (1 if reachable)
 * @param cap_lb    Minimum residual capacity to consider (for capacity scaling)
 * @return          Maximum flow value from s to t
 *
 * @note The min_cut vector will contain the vertices of the minimum
 *       cut upon completion (vertices with value 0 are on the source side)
 *
 * Example usage:
 * @code
 *   graph g(n);
 *   vector<flow_edge> edges;
 *   vector<int> min_cut;
 *   ll max_flow = dinic_maxflow(s, t, n, g, edges, min_cut, 1);
 * @endcode
 */
ll dinic_maxflow(const int s,const int t,const int n,const graph &g, std::vector<flow_edge> &edges, std::vector<int> &min_cut,const ll cap_lb=1);

/**
 * Computes maximum flow using capacity scaling technique with a provided max flow algorithm.
 *
 * This function implements the capacity scaling optimization for max flow algorithms.
 * It works by:
 * 1) Starting with the highest possible capacity threshold (max edge capacity)
 * 2) Gradually reducing the threshold by factors of 2
 * 3) At each step, running the provided max flow algorithm considering only edges
 *    with residual capacity >= current threshold
 *
 * @param s              Source vertex (0-based index)
 * @param t              Sink vertex (0-based index)
 * @param n              Total number of vertices in the graph
 * @param maxflow_func   Pointer to the max flow algorithm function to use (e.g., dinic_maxflow)
 * @param g              Adjacency list representation of the graph
 * @param edges          Vector of flow edges (will be modified with final flows)
 * @param min_cut        Output vector marking reachable vertices (1 if reachable from source in min cut)
 * @return               Maximum flow value from s to t
 *
 * @note The function requires that the provided maxflow_func accepts the standard parameters:
 *       (s, t, n, g, edges, min_cut, cap_lb) and returns the flow value as ll
 * @note The min_cut vector will contain the final minimum cut information after execution
 *
 * Example usage:
 * @code
 *   graph g = build_graph();
 *   vector<flow_edge> edges = get_edges();
 *   vector<int> min_cut;
 *   ll flow = cap_scaling_maxflow(s, t, n, dinic_maxflow, g, edges, min_cut);
 * @endcode
 */
ll cap_scaling_maxflow(const int s,const  int t,const  int n,
   ll (*maxflow_func)(const int,const int,const int,const graph&,std::vector<flow_edge>&,std::vector<int>&,const ll),
   const graph &g, std::vector<flow_edge> &edges,std::vector<int> &min_cut);
   
#endif // FLOWS

