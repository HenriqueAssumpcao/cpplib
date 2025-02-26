#pragma once

#ifndef GRAPH
#define GRAPH

#include <vector>
#include <list>

#include "common.h"
#include "linalg.h"

/*
A graph G = (V,E) with n nodes is represented with a vector of size n, where the entry corresponding to node u is a vector whose size equals the degree of u.
Each entry of the adjacency list of u contains a pair (v,w), where (u,v) \in E, and W(u,v) = w, where W is a weighting function.
*/

#define wgraph std::vector<std::list<std::pair<int,ll>>> // type of a weighted graph

// BFS
/*
O(V+E)
*/
void bfs(const wgraph &G, const int s,std::vector<ll> &dist,std::vector<int> &pred);

// DFS
/// Recurive
/*
O(V+E)
*/
void dfs_visit(const wgraph &G,const int u,std::vector<ll> &dist,std::vector<int> &pred,std::vector<int> &color,std::vector<int> &finish);

/*
O(V+E)
*/
void dfs(const wgraph &G,std::vector<ll> &dist,std::vector<int> &pred, std::vector<int> &finish);

/// Iterative
/*
O(V+E)
*/
void dfs(const wgraph &G, const int s,std::vector<ll> &dist,std::vector<int> &pred);


// Bellman-Ford

/*
O(V(V+E))
*/
bool bellman_ford(const wgraph &G, const int s,std::vector<ll> &dist,std::vector<int> &pred);

// Dijkstra
/*
O(V^2)
*/
void dijkstra(const wgraph &G, const int s,std::vector<ll> &dist,std::vector<int> &pred);

// Floyd-Warshall

/*
O(V^3)
*/
llmatrix floyd_warshall(const wgraph &G);




#endif // GRAPH