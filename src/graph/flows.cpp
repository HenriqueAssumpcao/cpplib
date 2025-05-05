#include <queue>
#include <vector>
#include <list>
#include "graph/flows.hpp"

// Capacity Scaling

ll find_aug_path_lb(const int s,const int t,const int n,const ll cap_lb,const graph &g,const std::vector<flow_edge> &edges, std::vector<int> &parent){
    parent = std::vector<int>(n,-1);
    std::vector<bool> visited(n,0);
    visited[s] = 1;

    std::queue<std::pair<int,ll>> q;
    q.push({s,LLINF});

    while(q.size()){
        auto [u,flow] = q.front();
        q.pop();

        for(int i : g[u]){
            if(visited[edges[i].v] == 0 && edges[i].cap >= cap_lb){
                visited[edges[i].v] = 1;
                parent[edges[i].v] = i;
                flow = std::min(flow,edges[i].cap);
                if(edges[i].v == t){
                    return flow;
                }
                q.push({edges[i].v,flow});
            }
        }
    }
    return 0;
}

ll edmonds_karp_maxflow_lb(const int s,const int t,const int n,const ll cap_lb,const graph &g, std::vector<flow_edge> &edges){
    ll max_flow = 0;
    std::vector<int> parent;

    ll curr_flow;
    while((curr_flow = find_aug_path_lb(s,t,n,cap_lb,g,edges,parent))){
        max_flow += curr_flow;
        int temp = t;
        while(temp != s){
            int prev = edges[parent[temp]].u;
            int op_edge_id = parent[temp] ^ 1;

            edges[parent[temp]].flow += curr_flow;
            edges[parent[temp]].cap -= curr_flow;
            edges[op_edge_id].flow -= curr_flow;
            edges[op_edge_id].cap += curr_flow;
            temp = prev;
        }
    }

    return max_flow;
}

ll cap_scaling_maxflow(const int s,const int t,const int n,const graph &g, std::vector<flow_edge> &edges){
    ll max_cap = 0;;
    std::vector<flow_edge> res_edges;
    for(flow_edge e:edges){
        max_cap = std::max(max_cap,e.cap);
        res_edges.push_back(e);
    }
    ll max_flow = 0;
    while(max_cap >= 1){
        max_flow += edmonds_karp_maxflow_lb(s,t,n,max_cap,g,res_edges);
        max_cap /= 2;
    }

    for(unsigned i = 0; i < edges.size(); i++){
        edges[i].flow = res_edges[i].flow;
    }

    return max_flow;
}

// Edmonds-Karp
ll edmonds_karp_maxflow(const int s,const int t,const int n,const graph &g, std::vector<flow_edge> &edges){
    std::vector<flow_edge> res_edges = edges;
    ll max_flow = edmonds_karp_maxflow_lb(s,t,n,1,g,res_edges);
    for(unsigned i = 0; i < edges.size(); i++){
        edges[i].flow = res_edges[i].flow;
    }
    return max_flow;
}



// Finding the std::min cut (assumes it receives the non-residual edges)
void min_cut(const int s,const int n,const graph &g,const std::vector<flow_edge> &edges, std::vector<int> &is_in_cut){
    is_in_cut = std::vector<int>(n,0);
    is_in_cut[s] = 1;

    std::queue<int> q;
    q.push(s);

    while(q.size()){
        int u = q.front();
        q.pop();
        for(int i : g[u]){
            if(is_in_cut[edges[i].v] == 0 && edges[i].cap-edges[i].flow > 0){
                is_in_cut[edges[i].v] = 1;
                q.push(edges[i].v);
            }
        }
    }
}