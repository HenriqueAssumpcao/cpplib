#pragma once

#ifndef GRAPH_MST
#define GRAPH_MST

#include "common.hpp"

// Weighted edge struct
struct wedge{
    int u,v;
    ll w;
    bool operator <(wedge const& other){
        return this->w < other.w;
    }
    wedge(int _u, int _v, ll _w):u(_u),v(_v),w(_w){}
};

ll mst_prim(const int s,const int n,const wgraph &g, std::vector<int> &pred);
ll mst_kruskal(const int n,std::vector<wedge> edges, std::vector<wedge> &mst);


#endif // GRAPH_MST