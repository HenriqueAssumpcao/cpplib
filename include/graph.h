#pragma once

#ifndef GRAPH
#define GRAPH

#include <vector>
#include <queue>
#include <stack>

#define ll long long

/*
A graph G = (V,E) with n nodes is represented with a vector of size n, where the entry corresponding to node u is a vector whose size equals the degree of u.
Each entry of the adjacency list of u contains a pair (v,w), where (u,v) \in E, and W(u,v) = w, where W is a weighting function.
*/


// BFS
void bfs(std::vector<std::vector<std::pair<int,ll>>> &G, const int s,std::vector<ll> &dist,std::vector<int> &pred);

// DFS
/// Recurive
void dfs_visit(std::vector<std::vector<std::pair<int,ll>>> &G,const int u,std::vector<ll> &dist,std::vector<int> &pred,std::vector<int> &color,std::vector<int> &finish);
void dfs(std::vector<std::vector<std::pair<int,ll>>> &G,std::vector<ll> &dist,std::vector<int> &pred, std::vector<int> &finish);

/// Iterative
void dfs(std::vector<std::vector<std::pair<int,ll>>> &G, const int s,std::vector<ll> &dist,std::vector<int> &pred);


// Bellman-Ford
bool bellman_ford(std::vector<std::vector<std::pair<int,ll>>> &G, const int s,std::vector<ll> &dist,std::vector<int> &pred);

// Dijkstra
void dijkstra(std::vector<std::vector<std::pair<int,ll>>> &G, const int s,std::vector<ll> &dist,std::vector<int> &pred);

#endif