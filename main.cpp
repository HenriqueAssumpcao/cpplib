#include <iostream>
#include <vector>
#include <limits>
#include <cmath>
#include <list>

#include "common.h"
#include "graph.h"
#include "linalg.h"

int main(){

    int n = 5;
    wgraph G(n); // Graph as adjacency list with weights on edges, the u-th entry contains pairs (v,w), with (u,v) \in E, w(u,v) = w
    
    // // Bellman-Ford Test
    G[0] = {{1,6},{2,7}};
    G[1] = {{2,8},{3,5},{4,-4}};
    G[2] = {{3,-3},{4,9}};
    G[3] = {{1,-2}};
    G[4] = {{0,2},{3,7}};
    
    llmatrix D = floyd_warshall(G);

    print_matrix<ll>(D);

    std::cout << "Bellman-Ford" << std::endl;
    std::vector<ll> dist(G.size());
    std::vector<int> pred(G.size());
    for(int i = 0; i < 5; i++){
        bellman_ford(G,i,dist,pred);
        print_matrix<ll>(dist);
    }

    // // Dijkstra test
    // G[0] = {{1,10},{2,5}};
    // G[1] = {{2,2},{3,1}};
    // G[2] = {{3,9},{1,3},{4,2}};
    // G[3] = {{4,4}};
    // G[4] = {{0,7},{3,6}}; 

    return 0;
}