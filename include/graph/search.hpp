#pragma once

#ifndef GRAPH_SEARCH
#define GRAPH_SEARCH

#include "common.hpp"

// BFS
/*
O(V+E)
*/
void bfs(const graph &G, const unsigned s,std::vector<ll> &dist,std::vector<int> &pred);
void bfs(const wgraph &G, const unsigned s,std::vector<ll> &dist,std::vector<int> &pred);

// DFS
/// Recurive
/*
O(V+E)
*/
void dfs_visit(const graph &G,const unsigned u,std::vector<ll> &dist,std::vector<int> &pred,std::vector<unsigned> &color,std::vector<unsigned> &finish);
void dfs_visit(const wgraph &G,const unsigned u,std::vector<ll> &dist,std::vector<int> &pred,std::vector<unsigned> &color,std::vector<unsigned> &finish);

/*
O(V+E)
*/
void dfs(const graph &G,std::vector<ll> &dist,std::vector<int> &pred, std::vector<unsigned> &finish);
void dfs(const wgraph &G,std::vector<ll> &dist,std::vector<int> &pred, std::vector<unsigned> &finish);

/// Iterative
/*
O(V+E)
*/
void dfs(const graph &G, const unsigned s,std::vector<ll> &dist,std::vector<unsigned> &pred);
void dfs(const wgraph &G, const unsigned s,std::vector<ll> &dist,std::vector<unsigned> &pred);



#endif // GRAPH_SEARCH