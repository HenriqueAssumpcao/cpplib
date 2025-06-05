#include "graph/shortest_path.hpp"


llmatrix floyd_warshall(const graph &G){
    llmatrix D(G.size(),std::vector<ll>(G.size(),LLINF));
 
    for(unsigned u = 0; u < G.size();u++){
        D[u][u] = 0;
        for(auto v : G[u]){
            D[u][v] = 1;
        }
    }

    for(unsigned k = 0; k < G.size(); k++){
        for(unsigned i = 0; i < G.size(); i++){
            for(unsigned j = 0; j < G.size(); j++){
                D[i][j] = std::min(D[i][j],D[i][k] + D[k][j]);
            }
        }
    }

    return D;

};



llmatrix floyd_warshall(const wgraph &G){
    llmatrix D(G.size(),std::vector<ll>(G.size(),LLINF));
 
    for(unsigned u = 0; u < G.size();u++){
        D[u][u] = 0;
        for(auto [v,w] : G[u]){
            D[u][v] = w;
        }
    }
    
    for(unsigned k = 0; k < G.size(); k++){
        for(unsigned i = 0; i < G.size(); i++){
            for(unsigned j = 0; j < G.size(); j++){
                D[i][j] = std::min(D[i][j],D[i][k] + D[k][j]);
            }
        }
    }

    return D;

};