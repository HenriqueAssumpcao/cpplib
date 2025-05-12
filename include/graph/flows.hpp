#pragma once

#ifndef FLOWS
#define FLOWS

#include "common.hpp"


// Edge struct

struct flow_edge{
    int u,v; // Endpoits of directed edge
    ll cap,flow = 0;
    flow_edge(int _u,int _v, ll _cap):u(_u),v(_v),cap(_cap){};

};

/*
Build flow graph
The adjacency list g is such that g[u][i] is an edge id for the i-th arc in u's adjacency list. 
For each arc received as input, creates the parallel arc with id equal to one plus the original arc id.
Can chose whether to merge multiple arcs into single one.
*/
void build_flow_graph(const int n,const int m,const bool merge_multi_edges, std::vector<flow_edge> &edges, graph &g);

/*
Edmonds-Karp algorithm for finding the maximum flow. 
Overview: at each iteration finds an augmenting path via a BFS, and increments the flow as much as possible, until there are no more augmenting paths.
O(nm^2), where n is the number of nodes and m is the number of arcs.
Expects graph coming from create_flow_graph.
*/
ll aug_path_bfs(const int s,const int t,const int n,const graph &g,const std::vector<flow_edge> &edges, std::vector<int> &parent,const ll cap_lb=1);
ll edmonds_karp_maxflow(const int s,const int t,const int n,const graph &g, std::vector<flow_edge> &edges,std::vector<int> &min_cut,const ll cap_lb=1);

/*
Dinic's algorithm for finding the maximum flow.
Overview: at each iteration, first perform a bfs in order to get the bfs layers, and then push flow using a dfs only looking at edges between layers.
O(n^2m) in general, O(m*min(m^1/2,n^2/3)) if all capacities are equal to one. 
Expects graph coming from create_flow_graph.
*/
void bfs(const int s,const int n,const graph &g,const std::vector<flow_edge> &edges, std::vector<int> &bfs_layer,const ll cap_lb=1);
ll layer_aug_path_dfs(const int u,const int t,
const ll flow,const graph &g, std::vector<flow_edge> &edges,std::vector<int> &bfs_layer, std::vector<int> &dfs_ptr,const ll cap_lb=1);

/*
Returns the maxflow, and also stores the partition of vertices that yield the minimum cut in the min_cut std::vector, where min_cut[u] = 0 if u belongs to the block
containing s, and 1 if it belongs to the block containing t.
*/
ll dinic_maxflow(const int s,const int t,const int n,const graph &g, std::vector<flow_edge> &edges, std::vector<int> &min_cut,const ll cap_lb=1);

/*
Capacity scaling for findinf the maximum flow. 
Overview: at each iteration, pushes the maximum flow by only considering edges with capacity at least cap_lb, and then divides cap_lb by 2. 
Can use any flow algorithm at each step. 
O(E^2logC) in general, and O(VElogC) with dinic, where C is the maximum capacity. 
flow_func_lb is the max_flow algorithm of choice, with signature maxflow_func(int s, int t, int n, graph &g, vector<flow_edge> &edges,vector<int> &min_cut,ll cap_lb),
where cap_lb is the lower bound on the capacity, i.e., only arcs with capacity at least cap_lb will be considered
*/
ll cap_scaling_maxflow(const int s,const  int t,const  int n,
   ll (*maxflow_func)(const int,const int,const int,const graph&,std::vector<flow_edge>&,std::vector<int>&,const ll),
   const graph &g, std::vector<flow_edge> &edges,std::vector<int> &min_cut);
   
#endif // FLOWS

