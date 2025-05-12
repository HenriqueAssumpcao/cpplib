#pragma once

#ifndef GRAPH_UTILS
#define GRAPH_UTILS

#include "common.hpp"

// O(V)
std::vector<unsigned> out_deg(const graph &G);

// O(V+E)
std::vector<unsigned> in_deg(const graph &G);



#endif //GRAPH_UTILS