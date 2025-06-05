#include "graph/shortest_path.hpp"

bool bellman_ford(const wgraph &G, const int s,std::vector<ll> &dist,std::vector<int> &pred){
    for(unsigned i = 0; i < dist.size(); i++){
        dist[i] = LLINF;
        pred[i] = -1;
    }
    dist[s] = 0;

    for(unsigned i = 0; i < G.size()-1; i++){
        for(unsigned u = 0; u < G.size(); u++){
            for(auto [v,w] : G[u]){
                if(dist[v] > dist[u] + w){
                    dist[v] = dist[u] + w;
                    pred[v] = u;
                }
            }
        }
    }

    for(unsigned u = 0; u < G.size(); u++){
        for(auto [v,w] : G[u]){
            if(dist[v] > dist[u] + w){
                return true;
            }
        }
    }
    return false;
}