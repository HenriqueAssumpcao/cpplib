#include "graph/flows.hpp"

void build_flow_graph(const int n,const int m,const bool merge_multi_edges, std::vector<flow_edge> &edges, graph &g){
    g = graph(n);
    int u,v;
    ll c;
    int eid = 0;
    if(merge_multi_edges){
        std::map<std::pair<int,int>,int> pair2edge;
        for(int i = 0; i < m; i++){
            std::cin >> u >> v >> c;
            u--;v--;
            if(pair2edge.find({u,v}) == pair2edge.end()){
                edges.push_back(flow_edge(u,v,c));
                edges.push_back(flow_edge(v,u,0));
                g[u].push_back(eid);
                g[v].push_back(eid+1);
                pair2edge[{u,v}] = eid;
                eid += 2;
            }
            else{
                edges[pair2edge[{u,v}]].cap += c;
            }
        }
    }
    else{
        for(int i = 0; i < m; i++){
            std::cin >> u >> v >> c;
            u--;v--;
            edges.push_back(flow_edge(u,v,c));
            edges.push_back(flow_edge(v,u,0));
            g[u].push_back(eid);
            g[v].push_back(eid+1);
            eid += 2;
        }
    }
}