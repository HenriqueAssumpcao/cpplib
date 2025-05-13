#include "graph/mst.hpp"
#include "dsu.hpp"

ll mst_kruskal(const int n,std::vector<wedge> edges, std::vector<wedge> &mst){
    std::sort(edges.begin(),edges.end());
    dsu nodes(n);

    for(int u = 0; u < n; u++){
        nodes.make_set(u);
    }  

    ll mst_cost = 0;
    for(wedge e : edges){
        if(nodes.find_set(e.u) != nodes.find_set(e.v)){
            mst.push_back(e);
            mst_cost += e.w;
            nodes.union_sets(e.u,e.v);
        }
    }
    return mst_cost;
}