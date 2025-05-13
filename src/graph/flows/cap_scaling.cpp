#include "graph/flows.hpp"

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