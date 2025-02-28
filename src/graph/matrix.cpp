#include <list>
#include <vector>

#include "common.hpp"
#include "graph/matrix.hpp"

graph adj_list(const bmatrix &A){
    graph G(A.size());

    for(unsigned u = 0; u < A.size(); u++){
        for(unsigned v = 0; v < A.size(); v++){
            if(A[u][v] == 1){
                G[u].push_back(v);
            }
        }
    }

    return G;
}

wgraph adj_list(const llmatrix &A){
    wgraph G(A.size());

    for(unsigned u = 0; u < A.size(); u++){
        for(unsigned v = 0; v < A.size(); v++){
            if(A[u][v] > 0){
                G[u].push_back({v,A[u][v]});
            }
        }
    }

    return G;
}

bmatrix adj_matrix(const graph &G){
    bmatrix adj(G.size(),std::vector<bool>(G.size(),0));

    for(unsigned u = 0; u < G.size(); u++){
        for(unsigned v : G[u]){
            adj[u][v] = 1;
        }
    }
    return adj;
}

llmatrix wadj_matrix(const wgraph &G){
    llmatrix adj(G.size(),std::vector<ll>(G.size(),0));

    for(unsigned u = 0; u < G.size(); u++){
        for(auto [v,w] : G[u]){
            adj[u][v] = w;
        }
    }
    return adj;
}

intmatrix incidence_matrix(const graph &G, const unsigned m){
    intmatrix incidence(G.size(),std::vector<int>(m,0));

    unsigned edge_counter = 0;
    for(unsigned u = 0; u < G.size(); u++){
        for(unsigned v : G[u]){
            incidence[u][edge_counter] = -1;
            incidence[v][edge_counter] = 1;
            edge_counter++;
        }
    }

    return incidence;
}

intmatrix incidence_matrix(const wgraph &G, const unsigned m){
    intmatrix incidence(G.size(),std::vector<int>(m,0));

    unsigned edge_counter = 0;
    for(unsigned u = 0; u < G.size(); u++){
        for(auto [v,w] : G[u]){
            incidence[u][edge_counter] = -1;
            incidence[v][edge_counter] = 1;
            edge_counter++;
        }
    }

    return incidence;
}
