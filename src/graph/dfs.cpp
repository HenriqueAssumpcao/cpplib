#include <vector>
#include <stack>
#include <limits>

#include "common.h"
#include "graph.h"

// DFS with finish time (recursive!)
int dfs_time;

void dfs_visit(std::vector<std::vector<std::pair<int,ll>>> &G,const int u,std::vector<ll> &dist,std::vector<int> &pred,std::vector<int> &color,std::vector<int> &finish){
    dfs_time++;
    dist[u] = dfs_time;
    color[u] = 1;
    for(auto [v,_] : G[u]){
        if(color[v] == 0){
            pred[v] = u;
            dfs_visit(G,v,dist,pred,color,finish);
        }
    }
    dfs_time++;
    finish[u] = dfs_time;
    color[u] = 2;
}

void dfs(std::vector<std::vector<std::pair<int,ll>>> &G,std::vector<ll> &dist,std::vector<int> &pred, std::vector<int> &finish){
    std::vector<int> color(G.size());
    for(unsigned int i = 0; i < dist.size(); i++){
        dist[i] = inf;
        pred[i] = -1;
        color[i] = 0;
    }

    std::vector<int> times(G.size());
    dfs_time = 0;

    for(unsigned int u = 0; u < G.size(); u++){
        if(color[u] == 0){
            dfs_visit(G,u,dist,pred,color,finish);
        }
    }
}

// Iterative DFS
void dfs(std::vector<std::vector<std::pair<int,ll>>> &G, const int s,std::vector<ll> &dist,std::vector<int> &pred){
    std::vector<int> color(G.size());
    for(unsigned int i = 0; i < dist.size(); i++){
        dist[i] = inf;
        pred[i] = -1;
        color[i] = 0;
    }
    dist[s] = 0;
    color[s] = 1;

    std::stack<int> st;

    st.push(s);

    int u;
    while(st.size()){
        u = st.top();
        st.pop();
        for(auto [v,_] : G[u]){
            if(color[v] == 0){
                color[v] = 1;
                pred[v] = u;
                dist[v] = dist[u] + 1;
                st.push(v);
            }
        }
    }
}
