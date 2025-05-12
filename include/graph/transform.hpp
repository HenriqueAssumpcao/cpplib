#pragma once

#ifndef GRAPH_TRANSFORM
#define GRAPH_TRANSFORM

#include "common.hpp"

// O(E)
graph graph_transpose(const graph &G);

/*
Transforms the input multigraph into a simple loopless graph.

O(V+E)
*/
graph equivalent_graph(const graph &G);

/*
Returns the squared graph of input graph, i.e., the graph in which (u,v) are connected iff there is a path of length at most 2 between u and v in the original graph.acoshf128

O(VE)
*/
graph square_graph(const graph &G);


#endif //GRAPH_TRANSFORM