#include <vector>
#include <queue>
#include <limits>

#include "common.hpp"
#include "graph/shortest_path.hpp"


void dijkstra(const wgraph &G, const int s,std::vector<ll> &dist,std::vector<int> &pred){
    // Initializes distance and predecessor vectors
    for(unsigned int i = 0; i < dist.size(); i++){
        dist[i] = inf;
        pred[i] = -1;
    }
    dist[s] = 0;

    // Creates a priority queue ordered w.r.t. the weighted distance between vertices
    std::priority_queue<std::pair<ll,int>> pq;
    pq.emplace(0,s);

    while(pq.size()){
        auto [curr_dist,u] = pq.top();
        pq.pop();
        for(auto [v,w]:G[u]){
            if(dist[u] != inf and dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pred[v] = u;
                pq.emplace(-dist[v],v);
            }
        }
    }
}