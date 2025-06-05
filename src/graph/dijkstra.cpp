#include "graph/shortest_path.hpp"


void dijkstra(const wgraph &G, const int s,std::vector<ll> &dist,std::vector<int> &pred){
    dist.resize(G.size());pred.resize(G.size());
    for(unsigned i = 0; i < dist.size(); i++){
        dist[i] = LLINF;
        pred[i] = -1;
    }
    dist[s] = 0;

    std::priority_queue<std::pair<ll,unsigned>> pq;
    pq.emplace(0,s);

    while(pq.size()){
        auto [curr_dist,u] = pq.top();
        pq.pop();
        if(dist[u] >= -curr_dist){
            for(auto [v,w]:G[u]){
                if(dist[v] > dist[u] + w){
                    dist[v] = dist[u] + w;
                    pred[v] = u;
                    pq.emplace(-dist[v],v);
                }
            }

        }
    }
}