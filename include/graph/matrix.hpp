#pragma once

#ifndef GRAPH_MATRIX
#define GRAPH_MATRIX

#include "common.hpp"

graph adj_list(const bmatrix &A);
wgraph adj_list(const llmatrix &A);

bmatrix adj_matrix(const graph &G);
llmatrix wadj_matrix(const wgraph &G);

intmatrix incidence_matrix(const graph &G, const unsigned m);
intmatrix incidence_matrix(const wgraph &G, const unsigned m);


#endif //GRAPH_MATRIX