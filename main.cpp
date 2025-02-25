#include <iostream>
#include <vector>

#include "common.h"
#include "graph.h"

int main(){

    int n = 5;
    std::vector<std::vector<std::pair<int,ll>>> G(n); // Graph as adjacency list with weights on edges, the u-th entry contains pairs (v,w), with (u,v) \in E, w(u,v) = w
    
    // Bellman-Ford Test
    G[0] = {{1,6},{2,7}};
    G[1] = {{2,8},{3,5},{4,-4}};
    G[2] = {{3,-3},{4,9}};
    G[3] = {{1,-2}};
    G[4] = {{0,2},{3,7}};

    std::vector<ll> dist(G.size());
    std::vector<int> pred(G.size());
    std::vector<int> finish(G.size());

    std::cout << "Bellman-Ford" << std::endl;
    bool res = bellman_ford(G,0,dist,pred);
    std::cout << res << std::endl;
    print_vector<ll>(dist);
    print_vector<int>(pred);
    print_path(0,4,pred);

    // Dijkstra test
    G[0] = {{1,10},{2,5}};
    G[1] = {{2,2},{3,1}};
    G[2] = {{3,9},{1,3},{4,2}};
    G[3] = {{4,4}};
    G[4] = {{0,7},{3,6}}; 
    std::cout << "Djikstra" << std::endl;
    dijkstra(G,0,dist,pred);

    print_vector<ll>(dist);
    print_vector<int>(pred);
    print_path(0,4,pred);


    return 0;
}