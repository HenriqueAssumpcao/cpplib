#include "graph/flows.hpp"

/*
Capacity scaling for findinf the maximum flow. 
Overview: at each iteration, pushes the maximum flow by only considering edges with capacity at least cap_lb, and then divides cap_lb by 2. 
Can use any flow algorithm at each step. 
O(E^2logC) in general, and O(VElogC) with dinic, where C is the maximum capacity. 
flow_func_lb is the max_flow algorithm of choice, with signature maxflow_func(int s, int t, int n, graph &g, vector<flow_edge> &edges,vector<int> &min_cut,ll cap_lb),
where cap_lb is the lower bound on the capacity, i.e., only arcs with capacity at least cap_lb will be considered
*/
ll cap_scaling_maxflow(const int s,const  int t,const  int n,
   ll (*maxflow_func)(const int,const int,const int,const graph&,std::vector<flow_edge>&,std::vector<int>&,const ll),
   const graph &g, std::vector<flow_edge> &edges,std::vector<int> &min_cut){

    ll cap_lb = 0;
    for(flow_edge e:edges){
        cap_lb = std::max(cap_lb,e.cap);
    }
    ll max_flow = 0;
    while(cap_lb >= 1){
        max_flow += maxflow_func(s,t,n,g,edges,min_cut,cap_lb);
        cap_lb >>= 1;
    }

    return max_flow;
}