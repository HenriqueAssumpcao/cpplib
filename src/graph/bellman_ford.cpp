#include <vector>
#include <limits>

#include "common.h"
#include "graph.h"

bool bellman_ford(std::vector<std::vector<std::pair<int,ll>>> &G, int s,std::vector<ll> &dist,std::vector<int> &pred){
    // Initializes distance and predecessor vectors
    for(unsigned int i = 0; i < dist.size(); i++){
        dist[i] = inf;
        pred[i] = -1;
    }
    dist[s] = 0;

    // Performs n-1 relaxations on all edges of the graph
    for(unsigned int i = 0; i < G.size()-1; i++){
        for(unsigned int u = 0; u < G.size(); u++){
            for(auto [v,w] : G[u]){
                if(dist[v] > dist[u] + w){
                    dist[v] = dist[u] + w;
                    pred[v] = u;
                }
            }
        }
    }

    // Checks for negative cycles
    for(unsigned int u = 0; u < G.size(); u++){
        for(auto [v,w] : G[u]){
            if(dist[v] > dist[u] + w){
                return false;
            }
        }
    }
    return true;
}