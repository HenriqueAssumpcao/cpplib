#include "graph/shortest_path.hpp"

// Weighted
bool bellman_ford(const wgraph &G, const int s,std::vector<ll> &dist,std::vector<int> &pred){
    // Initializes distance and predecessor vectors
    for(unsigned i = 0; i < dist.size(); i++){
        dist[i] = LLINF;
        pred[i] = -1;
    }
    dist[s] = 0;

    // Performs n-1 relaxations on all edges of the graph
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

    // Checks for negative cycles
    for(unsigned u = 0; u < G.size(); u++){
        for(auto [v,w] : G[u]){
            if(dist[v] > dist[u] + w){
                return true;
            }
        }
    }
    return false;
}