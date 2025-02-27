#pragma once

#ifndef GRAPH_SEARCH
#define GRAPH_SEARCH

#include <list>
#include <vector>

#include "common.hpp"

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



#endif // GRAPH_SEARCH