#pragma once

#ifndef GRAPH_SHORTEST_PATH
#define GRAPH_SHORTEST_PATH

#include <list>
#include <vector>

#include "common.hpp"

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
llmatrix floyd_warshall(const graph &G);
llmatrix floyd_warshall(const wgraph &G);


#endif // GRAPH_SHORTEST_PATH