#include <limits>
#include <stack>
#include <vector>


#include "common.hpp"
#include "graph/search.hpp"

// DFS with finish time (recursive!)
int dfs_time;

void dfs_visit(const graph &G,const unsigned u,std::vector<ll> &dist,std::vector<int> &pred,std::vector<unsigned> &color,std::vector<unsigned> &finish){
    dfs_time++;
    dist[u] = dfs_time;
    color[u] = 1;
    for(auto v : G[u]){
        if(color[v] == 0){
            pred[v] = u;
            dfs_visit(G,v,dist,pred,color,finish);
        }
    }
    dfs_time++;
    finish[u] = dfs_time;
    color[u] = 2;
}

void dfs(const graph &G,std::vector<ll> &dist,std::vector<int> &pred, std::vector<unsigned> &finish){
    std::vector<unsigned> color(G.size());
    for(unsigned i = 0; i < dist.size(); i++){
        dist[i] = inf;
        pred[i] = -1;
        color[i] = 0;
    }

    std::vector<unsigned> times(G.size());
    dfs_time = 0;

    for(unsigned u = 0; u < G.size(); u++){
        if(color[u] == 0){
            dfs_visit(G,u,dist,pred,color,finish);
        }
    }
}

void dfs_visit(const wgraph &G,const unsigned u,std::vector<ll> &dist,std::vector<int> &pred,std::vector<unsigned> &color,std::vector<unsigned> &finish){
    dfs_time++;
    dist[u] = dfs_time;
    color[u] = 1;
    for(auto [v,w] : G[u]){
        if(color[v] == 0){
            pred[v] = u;
            dfs_visit(G,v,dist,pred,color,finish);
        }
    }
    dfs_time++;
    finish[u] = dfs_time;
    color[u] = 2;
}

void dfs(const wgraph &G,std::vector<ll> &dist,std::vector<int> &pred, std::vector<unsigned> &finish){
    std::vector<unsigned> color(G.size());
    for(unsigned i = 0; i < dist.size(); i++){
        dist[i] = inf;
        pred[i] = -1;
        color[i] = 0;
    }

    std::vector<unsigned> times(G.size());
    dfs_time = 0;

    for(unsigned u = 0; u < G.size(); u++){
        if(color[u] == 0){
            dfs_visit(G,u,dist,pred,color,finish);
        }
    }
}

// Iterative DFS
void dfs(const graph &G, const unsigned s,std::vector<ll> &dist,std::vector<int> &pred){
    std::vector<unsigned> color(G.size());
    for(unsigned i = 0; i < dist.size(); i++){
        dist[i] = inf;
        pred[i] = -1;
        color[i] = 0;
    }
    dist[s] = 0;
    color[s] = 1;

    std::stack<unsigned> st;

    st.push(s);

    unsigned u;
    while(st.size()){
        u = st.top();
        st.pop();
        for(auto v : G[u]){
            if(color[v] == 0){
                color[v] = 1;
                pred[v] = u;
                dist[v] = dist[u] + 1;
                st.push(v);
            }
        }
    }
}

void dfs(const wgraph &G, const unsigned s,std::vector<ll> &dist,std::vector<int> &pred){
    std::vector<unsigned> color(G.size());
    for(unsigned i = 0; i < dist.size(); i++){
        dist[i] = inf;
        pred[i] = -1;
        color[i] = 0;
    }
    dist[s] = 0;
    color[s] = 1;

    std::stack<unsigned> st;

    st.push(s);

    unsigned u;
    while(st.size()){
        u = st.top();
        st.pop();
        for(auto [v,w] : G[u]){
            if(color[v] == 0){
                color[v] = 1;
                pred[v] = u;
                dist[v] = dist[u] + 1;
                st.push(v);
            }
        }
    }
}

