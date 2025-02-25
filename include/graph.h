#pragma once

#ifndef GRAPH
#define GRAPH

#include <vector>
#include <queue>
#include <stack>

#define ll long long

// BFS
void bfs(std::vector<std::vector<std::pair<int,ll>>> &G, int s,std::vector<ll> &dist,std::vector<int> &pred);

// DFS
/// Recurive
void dfs_visit(std::vector<std::vector<std::pair<int,ll>>> &G,int u,std::vector<ll> &dist,std::vector<int> &pred,std::vector<int> &color,std::vector<int> &finish);
void dfs(std::vector<std::vector<std::pair<int,ll>>> &G,std::vector<ll> &dist,std::vector<int> &pred, std::vector<int> &finish);

/// Iterative
void dfs(std::vector<std::vector<std::pair<int,ll>>> &G, int s,std::vector<ll> &dist,std::vector<int> &pred);


// Bellman-Ford
bool bellman_ford(std::vector<std::vector<std::pair<int,ll>>> &G, int s,std::vector<ll> &dist,std::vector<int> &pred);

// Dijkstra
void dijkstra(std::vector<std::vector<std::pair<int,ll>>> &G, const int s,std::vector<ll> &dist,std::vector<int> &pred);

#endif