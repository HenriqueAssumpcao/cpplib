#include "graph/ccs.hpp"
#include "graph/transform.hpp"
#include "graph/search.hpp"


void kosaraju_visit(int u,const int &n,const graph &gt, std::vector<int> &color, std::vector<int> &scc){
    color[u] = 1;
    for(int v : gt[u]){
        if(color[v] == 0){
            scc.push_back(v);
            kosaraju_visit(v,n,gt,color,scc);
        }
    }
}

std::vector<std::vector<int>> kosaraju_sccs(const int &n,const  graph &g){
    std::vector<ll> dist;
    std::vector<unsigned> finish;
    std::vector<int> pred;
    dfs(g,dist,pred,finish);

    std::vector<std::pair<int,unsigned>> nodefinish(n);
    for(int u = 0; u < n; u++){
        nodefinish[u] = {u,finish[u]};
    }
    std::sort(nodefinish.begin(), nodefinish.end(), [](auto &left, auto &right) {
        return left.second > right.second;});

    graph gt = graph_transpose(g);
    std::vector<int> color(n,0);
    std::vector<std::vector<int>> sccs;

    for(int i = 0; i < n; i++){
        int u = nodefinish[i].first;
        if(color[u] == 0){
            std::vector<int> scc;
            scc.push_back(u);
            kosaraju_visit(u,n,gt,color,scc);
            sccs.push_back(scc);
        }
    }

    return sccs;
}