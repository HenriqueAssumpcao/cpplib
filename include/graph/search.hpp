#pragma once

#ifndef GRAPH_SEARCH
#define GRAPH_SEARCH

#include "common.hpp"

void bfs(const graph &G, const unsigned s,std::vector<ll> &dist,std::vector<int> &pred);
void bfs(const wgraph &G, const unsigned s,std::vector<ll> &dist,std::vector<int> &pred);

void dfs_visit(const graph &G,const unsigned u,std::vector<ll> &start,std::vector<int> &pred,std::vector<unsigned> &color,std::vector<unsigned> &finish);
void dfs(const graph &G,std::vector<ll> &start,std::vector<int> &pred, std::vector<unsigned> &finish);

void dfs_visit(const wgraph &G,const unsigned u,std::vector<ll> &start,std::vector<int> &pred,std::vector<unsigned> &color,std::vector<unsigned> &finish);
void dfs(const wgraph &G,std::vector<ll> &start,std::vector<int> &pred, std::vector<unsigned> &finish);



#endif // GRAPH_SEARCH