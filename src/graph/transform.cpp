#include <list>
#include <vector>

#include "common.hpp"
#include "graph/transform.hpp"

// O(E)
graph graph_transpose(const graph &G){
    graph G_t(G.size());
    for(unsigned u = 0; u < G.size(); u++){
        for(unsigned v: G[u]){
            G_t[v].push_back(u);
        }
    }
    return G_t;
}

/*
Transforms the input multigraph into a simple loopless graph.

O(V+E)
*/
graph equivalent_graph(const graph &G){
    graph G_und(G.size());
    std::vector<unsigned> aux(G.size(),G.size()+1);

    for(unsigned u = 0; u < G.size(); u++){
        for(unsigned v: G[u]){
            if(u != v && aux[v] != u){
                G_und[u].push_back(v);
                aux[v] = u;
            }
        }
    }

    return G_und;
}

/*
Returns the squared graph of input graph, i.e., the graph in which (u,v) are connected iff there is a path of length at most 2 between u and v in the original graph.acoshf128

O(VE)
*/
graph square_graph(const graph &G){
    graph G_sqrd = G;
    for(unsigned u = 0; u < G.size(); u++){
        for(unsigned v : G[u]){
            for(unsigned z : G[v]){
                if(u != z){
                    G_sqrd[u].push_back(z);
                }
            }
        }
    }

    return equivalent_graph(G_sqrd);
}