#pragma once

#ifndef GRAPH_MST
#define GRAPH_MST

#include <list>
#include <vector>

#include "common.hpp"

// Prim
void prim(const int s,const wgraph &g, std::vector<int> &pred);


#endif // GRAPH_MST