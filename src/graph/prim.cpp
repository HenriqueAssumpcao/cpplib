#include <vector>
#include <queue>
#include <list>

#include "common.hpp"
#include "graph/mst.hpp"

void prim(const int s,const wgraph &g, std::vector<int> &pred){
    int n = g.size();

    std::vector<ll> keys(n);
    std::vector<bool> visited(n);
    pred.resize(n);
    for(int i = 0; i < n; i++){
        pred[i] = -1;
        keys[i] = LLINF;
        visited[i] = 0;
    }
    keys[s] = 0;

    std::priority_queue<std::pair<ll,int>> pq;
    pq.emplace(0,s);

    while(pq.size()){
        auto [neg_key,u] = pq.top();
        pq.pop();
        visited[u] = 1;
        if(keys[u] >= -neg_key){
            for(auto [v,w] : g[u]){
                if(visited[v] == 0 && w < keys[v]){
                    pred[v] = u;
                    keys[v] = w;
                    pq.emplace(-w,v);
                }
            }
        }
    }
}