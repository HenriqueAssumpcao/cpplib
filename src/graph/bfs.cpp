#include <limits>
#include <vector>
#include <queue>

#include "common.hpp"
#include "graph/search.hpp"

/*
BFS search w.r.t. to a fixed node s on input graph G. dist is a vector of distances (ignoring weights), and pred is a vector of predecessors.
Expects both dist and pred arrays to have size equal to the number of nodes.
*/
void bfs(const graph &G, const unsigned s,std::vector<ll> &dist,std::vector<int> &pred){
    // Initializes the distance,predecessor and color vectors
    std::vector<int> color(G.size());
    for(unsigned i = 0; i < dist.size(); i++){
        dist[i] = inf;
        pred[i] = -1;
        color[i] = 0;
    }
    dist[s] = 0;
    color[s] = 1;
    
    // Queue
    std::queue<unsigned> q;
    q.push(s);

    // Main loop: for each neighbor of current queue front, explore it if its color is 0
    unsigned u;
    while(q.size()){
        u = q.front();
        q.pop();
        for(auto v : G[u]){
            if(color[v] == 0){
                color[v] = 1;
                pred[v] = u;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

/*
BFS search w.r.t. to a fixed node s on input graph G. dist is a vector of distances (ignoring weights), and pred is a vector of predecessors.
Expects both dist and pred arrays to have size equal to the number of nodes.
*/
void bfs(const wgraph &G, const unsigned s,std::vector<ll> &dist,std::vector<int> &pred){
    // Initializes the distance,predecessor and color vectors
    std::vector<unsigned> color(G.size());
    for(unsigned i = 0; i < dist.size(); i++){
        dist[i] = inf;
        pred[i] = -1;
        color[i] = 0;
    }
    dist[s] = 0;
    color[s] = 1;
    
    // Queue
    std::queue<unsigned> q;
    q.push(s);

    // Main loop: for each neighbor of current queue front, explore it if its color is 0
    unsigned u;
    while(q.size()){
        u = q.front();
        q.pop();
        for(auto [v,w] : G[u]){
            if(color[v] == 0){
                color[v] = 1;
                pred[v] = u;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}