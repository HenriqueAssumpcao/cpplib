#include <vector>
#include <queue>
#include <limits>

#include "common.hpp"
#include "graph/shortest_path.hpp"


void dijkstra(const wgraph &G, const unsigned s,std::vector<ll> &dist,std::vector<unsigned> &pred){
    // Initializes distance and predecessor vectors
    for(unsigned i = 0; i < dist.size(); i++){
        dist[i] = inf;
        pred[i] = -1;
    }
    dist[s] = 0;

    // Creates a priority queue ordered w.r.t. the weighted distance between vertices
    std::priority_queue<std::pair<ll,unsigned>> pq; // each element of the priority queue is a pair (d,v), where d is the distance from s to v
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