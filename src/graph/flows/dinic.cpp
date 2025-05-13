#include "graph/flows.hpp"

void bfs(const int s,const int n,const graph &g,const std::vector<flow_edge> &edges, std::vector<int> &bfs_layer,const ll cap_lb){
    bfs_layer = std::vector<int>(n,-1);
    std::queue<int> q;
    q.push(s);
    bfs_layer[s] = 0;

    while(q.size()){
        int u = q.front();
        q.pop();
        for(int eid : g[u]){
            if(bfs_layer[edges[eid].v] == -1 && ((edges[eid].cap - edges[eid].flow) >= cap_lb)){
                bfs_layer[edges[eid].v] = bfs_layer[edges[eid].u] + 1;
                q.push(edges[eid].v);
            }
        }
    }
}

ll layer_aug_path_dfs(const int u,const int t,
const ll flow,const graph &g, std::vector<flow_edge> &edges,std::vector<int> &bfs_layer, std::vector<int> &dfs_ptr,const ll cap_lb){
    if((flow == 0) || (u == t)){
        return flow;
    }
    for(int &i = dfs_ptr[u]; i < (int)g[u].size(); i++){
        int eid = g[u][i];
        if((bfs_layer[edges[eid].v] == bfs_layer[u] + 1) && (edges[eid].cap - edges[eid].flow) >= cap_lb){
            ll down_flow = layer_aug_path_dfs(edges[eid].v,t,std::min(flow,edges[eid].cap - edges[eid].flow),g,edges,bfs_layer,dfs_ptr,cap_lb);
            if(down_flow >= cap_lb){
                edges[eid].flow += down_flow;
                edges[eid ^ 1].flow -= down_flow;
                return down_flow;
            }
        }
    }

    return 0;

}

ll dinic_maxflow(const int s,const int t,const int n,const graph &g, std::vector<flow_edge> &edges, std::vector<int> &min_cut,const ll cap_lb){
    std::vector<int> bfs_layer,dfs_ptr;
    ll max_flow = 0,curr_flow;
    while(true){
        bfs(s,n,g,edges,bfs_layer,cap_lb);
        if(bfs_layer[t] == -1){
            break;
        }
        dfs_ptr = std::vector<int>(n,0);
        while((curr_flow = layer_aug_path_dfs(s,t,LLONG_MAX,g,edges,bfs_layer,dfs_ptr,cap_lb))){
            max_flow += curr_flow;
        }
    }
    min_cut = std::vector<int>(n,0);
    for(int u = 0; u < n; u++){
        if(bfs_layer[u] == -1){
            min_cut[u] = 1;
        }
    }

    return max_flow;
}