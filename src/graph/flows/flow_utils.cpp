#include "graph/flows.hpp"

void add_edge(int u, int v, ll c,int &eid, std::vector<flow_edge> &edges, graph &g){
    edges.push_back(flow_edge(u,v,c));
    edges.push_back(flow_edge(v,u,0));
    g[u].push_back(eid);
    g[v].push_back(eid+1);
    eid+=2;
}

void build_flow_graph(const int n,const int m, std::vector<flow_edge> &edges, graph &g,const bool merge_multi_edges,const bool undirected){
    g = graph(n);
    int u,v;
    ll c;
    int eid = 0;
    if(merge_multi_edges){
        std::map<std::pair<int,int>,int> pair2edge;
        for(int i = 0; i < m; i++){
            std::cin >> u >> v >> c;
            u--;v--;
            if(u == v){
                continue;
            }
            if(pair2edge.find({u,v}) == pair2edge.end()){
                pair2edge[{u,v}] = eid;
                add_edge(u,v,c,eid,edges,g);
                if(undirected){
                    pair2edge[{v,u}] = eid;
                    add_edge(v,u,c,eid,edges,g);
                }
            }
            else{
                edges[pair2edge[{u,v}]].cap += c;
                if(undirected){
                    edges[pair2edge[{v,u}]].cap += c;
                }
            }
        }
    }
    else{
        for(int i = 0; i < m; i++){
            std::cin >> u >> v >> c;
            u--;v--;
            if(u == v){
                continue;
            }
            add_edge(u,v,c,eid,edges,g);
            if(undirected){
                add_edge(v,u,c,eid,edges,g);
            }
        }
    }
}