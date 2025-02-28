#include <cmath>
#include <list>
#include <limits>
#include <vector>

#include "common.hpp"
#include "graph/shortest_path.hpp"


llmatrix floyd_warshall(const graph &G){
    // Initialize distance matrix as weight matrix
    llmatrix D(G.size(),std::vector<ll>(G.size(),inf));
 
    for(unsigned u = 0; u < G.size();u++){
        D[u][u] = 0;
        for(auto v : G[u]){
            D[u][v] = 1;
        }
    }

    // Main loop
    for(unsigned k = 0; k < G.size(); k++){
        for(unsigned i = 0; i < G.size(); i++){
            for(unsigned j = 0; j < G.size(); j++){
                if(D[i][k] != inf and D[k][j] != inf){
                    D[i][j] = std::min(D[i][j],D[i][k] + D[k][j]);
                }
            }
        }
    }

    return D;

};



llmatrix floyd_warshall(const wgraph &G){
    // Initialize distance matrix as weight matrix
    llmatrix D(G.size(),std::vector<ll>(G.size(),inf));
 
    for(unsigned u = 0; u < G.size();u++){
        D[u][u] = 0;
        for(auto [v,w] : G[u]){
            D[u][v] = w;
        }
    }

    // Main loop
    for(unsigned k = 0; k < G.size(); k++){
        for(unsigned i = 0; i < G.size(); i++){
            for(unsigned j = 0; j < G.size(); j++){
                if(D[i][k] != inf and D[k][j] != inf){
                    D[i][j] = std::min(D[i][j],D[i][k] + D[k][j]);
                }
            }
        }
    }

    return D;

};