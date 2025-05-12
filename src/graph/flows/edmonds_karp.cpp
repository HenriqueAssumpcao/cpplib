#include "graph/flows.hpp"

/*
Edmonds-Karp algorithm for finding the maximum flow. 
Overview: at each iteration finds an augmenting path via a BFS, and increments the flow as much as possible, until there are no more augmenting paths.
O(nm^2), where n is the number of nodes and m is the number of arcs.
Expects graph coming from create_flow_graph.
Preserves the capacities in the input edges, i.e., doesn't explicitly use the residual graph.
*/

ll aug_path_bfs(const int s,const int t,const int n,const graph &g,const std::vector<flow_edge> &edges, std::vector<int> &parent,const ll cap_lb){
    parent = std::vector<int>(n,-1);
    std::vector<bool> visited(n,0);
    visited[s] = 1;

    std::queue<std::pair<int,ll>> q;
    q.push({s,LLINF});

    while(q.size()){
        auto [u,flow] = q.front();
        q.pop();

        for(int eid : g[u]){
            if(visited[edges[eid].v] == 0 && ((edges[eid].cap - edges[eid].flow) >= cap_lb)){
                visited[edges[eid].v] = 1;
                parent[edges[eid].v] = eid;
                flow = std::min(flow,edges[eid].cap-edges[eid].flow);
                if(edges[eid].v == t){
                    return flow;
                }
                q.push({edges[eid].v,flow});
            }
        }
    }
    return 0;
}

/*
Returns the maxflow, and also stores the partition of vertices that yield the minimum cut in the min_cut vector, where min_cut[u] = 0 if u belongs to the block
containing s, and 1 if it belongs to the block containing t.
*/
ll edmonds_karp_maxflow(const int s,const int t,const int n,const graph &g, std::vector<flow_edge> &edges,std::vector<int> &min_cut,const ll cap_lb){
    ll max_flow = 0;
    std::vector<int> parent;

    ll curr_flow;
    while((curr_flow = aug_path_bfs(s,t,n,g,edges,parent,cap_lb))){
        max_flow += curr_flow;
        int temp = t;
        while(temp != s){
            int prev = edges[parent[temp]].u;
            int op_edge_id = parent[temp] ^ 1;

            edges[parent[temp]].flow += curr_flow;
            edges[op_edge_id].flow -= curr_flow;
            temp = prev;
        }
    }
    
    min_cut = std::vector<int>(n,0);
    for(int u = 0; u < n; u++){
        if(u != s && parent[u] == -1){
            min_cut[u] = 1;
        }
    }

    return max_flow;
}