#pragma once

#ifndef FLOWS
#define FLOWS

#include <vector>
#include <list>

#include "common.hpp"

struct flow_edge{
    int u,v; // Endpoits of directed edge
    ll cap,flow = 0;
    flow_edge(int _u,int _v, ll _cap):u(_u),v(_v),cap(_cap){};

};

ll find_aug_path_lb(const int s,const int t, int n,const ll cap_lb,const graph &g,const std::vector<flow_edge> &edges, std::vector<int> &parent);
ll edmonds_karp_maxflow_lb(const int s,const int t,const int n,const ll cap_lb,const graph &g, std::vector<flow_edge> &edges);
ll cap_scaling_maxflow(const int s,const int t,const int n,const graph &g, std::vector<flow_edge> &edges);
ll edmonds_karp_maxflow(const int s,const int t,const int n,const graph &g, std::vector<flow_edge> &edges);
void min_cut(const int s,const int n,const graph &g,const std::vector<flow_edge> &edges, std::vector<int> &is_in_cut);



#endif // FLOWS

