#include "graph/search.hpp"

int dfs_time;

void dfs_visit(const graph &G,const unsigned u,std::vector<ll> &start,std::vector<int> &pred,std::vector<unsigned> &color,std::vector<unsigned> &finish){
    dfs_time++;
    start[u] = dfs_time;
    color[u] = 1;
    for(auto v : G[u]){
        if(color[v] == 0){
            pred[v] = u;
            dfs_visit(G,v,start,pred,color,finish);
        }
    }
    dfs_time++;
    finish[u] = dfs_time;
    color[u] = 2;
}

void dfs(const graph &G,std::vector<ll> &start,std::vector<int> &pred, std::vector<unsigned> &finish){
    std::vector<unsigned> color(G.size());
    for(unsigned i = 0; i < start.size(); i++){
        start[i] = LLINF;
        pred[i] = -1;
        color[i] = 0;
    }

    std::vector<unsigned> times(G.size());
    dfs_time = 0;

    for(unsigned u = 0; u < G.size(); u++){
        if(color[u] == 0){
            dfs_visit(G,u,start,pred,color,finish);
        }
    }
}

void dfs_visit(const wgraph &G,const unsigned u,std::vector<ll> &start,std::vector<int> &pred,std::vector<unsigned> &color,std::vector<unsigned> &finish){
    dfs_time++;
    start[u] = dfs_time;
    color[u] = 1;
    for(auto [v,w] : G[u]){
        if(color[v] == 0){
            pred[v] = u;
            dfs_visit(G,v,start,pred,color,finish);
        }
    }
    dfs_time++;
    finish[u] = dfs_time;
    color[u] = 2;
}

void dfs(const wgraph &G,std::vector<ll> &start,std::vector<int> &pred, std::vector<unsigned> &finish){
    std::vector<unsigned> color(G.size());
    for(unsigned i = 0; i < start.size(); i++){
        start[i] = LLINF;
        pred[i] = -1;
        color[i] = 0;
    }

    std::vector<unsigned> times(G.size());
    dfs_time = 0;

    for(unsigned u = 0; u < G.size(); u++){
        if(color[u] == 0){
            dfs_visit(G,u,start,pred,color,finish);
        }
    }
}