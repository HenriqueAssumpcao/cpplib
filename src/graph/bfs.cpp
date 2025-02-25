
#include <vector>
#include <queue>
#include <limits>

#include "common.h"
#include "graph.h"

void bfs(std::vector<std::vector<std::pair<int,ll>>> &G, const int s,std::vector<ll> &dist,std::vector<int> &pred){
    /*
    BFS search w.r.t. to a fixed node s on input graph G. dist is a vector of distances (ignoring weights), and pred is a vector of predecessors.
    */
    // Initializes the distance,predecessor and color vectors
    std::vector<int> color(G.size());
    for(unsigned int i = 0; i < dist.size(); i++){
        dist[i] = inf;
        pred[i] = -1;
        color[i] = 0;
    }
    dist[s] = 0;
    color[s] = 1;
    
    // Queue
    std::queue<int> q;
    q.push(s);

    // Main loop: for each neighbor of current queue front, explore it if its color is 0
    int u;
    while(q.size()){
        u = q.front();
        q.pop();
        for(auto [v,_] : G[u]){
            if(color[v] == 0){
                color[v] = 1;
                pred[v] = u;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}