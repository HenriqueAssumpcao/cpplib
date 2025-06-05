#include "graph/mst.hpp"

ll mst_prim(const int n,const wgraph &g, std::vector<int> &pred){
    std::vector<ll> key(n,LLINF);
    std::vector<bool> visited(n,0);
    pred = std::vector<int>(n,-1);
    key[0] = 0;

    std::priority_queue<std::pair<ll,int>> pq;
    pq.emplace(0,0);

    while(pq.size()){
        auto [neg_key,u] = pq.top();
        pq.pop();
        visited[u] = 1;
        for(auto [v,w] : g[u]){
            if(visited[v] == 0 && w < key[v]){
                pred[v] = u;
                key[v] = w;
                pq.emplace(-w,v);
            }
        }
    }

    ll mst_cost = 0;
    for(int u = 0; u < n; u++){
        if(key[u] != LLINF){
            mst_cost += key[u];
        }
    }

    return mst_cost;
}