#include "graph/search.hpp"

void bfs(const graph &G, const unsigned s,std::vector<ll> &dist,std::vector<int> &pred){
    std::vector<int> color(G.size());
    for(unsigned i = 0; i < dist.size(); i++){
        dist[i] = LLINF;
        pred[i] = -1;
        color[i] = 0;
    }
    dist[s] = 0;
    color[s] = 1;
    
    std::queue<unsigned> q;
    q.push(s);

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


void bfs(const wgraph &G, const unsigned s,std::vector<ll> &dist,std::vector<int> &pred){
    std::vector<unsigned> color(G.size());
    for(unsigned i = 0; i < dist.size(); i++){
        dist[i] = LLINF;
        pred[i] = -1;
        color[i] = 0;
    }
    dist[s] = 0;
    color[s] = 1;
    
    std::queue<unsigned> q;
    q.push(s);

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