#include <cmath>
#include <list>
#include <limits>
#include <vector>

#include "common.h"
#include "graph.h"
#include "linalg.h"

llmatrix floyd_warshall(const wgraph &G){
    // Initialize distance matrix as weight matrix
    llmatrix D(G.size(),std::vector<ll>(G.size(),inf));
 
    for(unsigned int u = 0; u < G.size();u++){
        D[u][u] = 0;
        for(auto [v,w] : G[u]){
            D[u][v] = w;
        }
    }

    // Main loop
    for(unsigned int k = 0; k < G.size(); k++){
        for(unsigned int i = 0; i < G.size(); i++){
            for(unsigned int j = 0; j < G.size(); j++){
                if(D[i][k] != inf and D[k][j] != inf){
                    D[i][j] = std::min(D[i][j],D[i][k] + D[k][j]);
                }
            }
        }
    }

    return D;

};