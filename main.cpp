#include <iostream>
#include <vector>
#include <limits>
#include <cmath>
#include <list>
#include <unordered_map>
#include <numeric>

#include "common.hpp"
#include "graph.hpp"
#include "linalg.hpp"
#include "printing.hpp"


int main(){
    // graph G(4);
    // G[0] = {1,1,1,3};
    // G[1] = {0,0,0,2};
    // G[2] = {1,2,3};
    // G[3] = {0,2,3};

    // graph G_und = equivalent_graph(G);

    // print_graph(G_und);

    // graph G_sqrd = square_graph(G_und);

    // print_graph(G_sqrd);

    // std::vector<unsigned> outd = out_deg(G_und);

    // print_matrix<unsigned>(outd);
    
    // unsigned m = std::accumulate(outd.begin(),outd.end(),0);
    // std::cout << m << std::endl;

    // intmatrix B = incidence_matrix(G_und,m);

    // print_matrix<int>(B);

    // intmatrix B_t = transpose<int>(B);

    // print_matrix<int>(B_t);
    // print_matrix<int>(matmul(B,B_t));

    // print_matrix<bool>(adj_matrix(G_sqrd));


    // graph G(7);
    // G[0] = {1,2};
    // G[1] = {3,4};
    // G[2] = {5,6};
    // G[3] = G[4] = G[5] = G[6] = {};

    // print_graph(G);

    // std::vector<ll> dist(7);
    // std::vector<int> pred(7);

    // bfs(G,0,dist,pred);

    // print_matrix<ll>(dist);






    // int n = 5;
    // wgraph G(n); // Graph as adjacency list with weights on edges, the u-th entry contains pairs (v,w), with (u,v) \in E, w(u,v) = w
    
    // // // Bellman-Ford Test
    // G[0] = {{1,6},{2,7}};
    // G[1] = {{2,8},{3,5},{4,-4}};
    // G[2] = {{3,-3},{4,9}};
    // G[3] = {{1,-2}};
    // G[4] = {{0,2},{3,7}};
    
    // llmatrix D = floyd_warshall(G);

    // print_matrix<ll>(D);

    // std::cout << "Bellman-Ford" << std::endl;
    // std::vector<ll> dist(G.size());
    // std::vector<int> pred(G.size());
    // for(int i = 0; i < 5; i++){
    //     bellman_ford(G,i,dist,pred);
    //     print_matrix<ll>(dist);
    // }

    // // Dijkstra test
    // G[0] = {{1,10},{2,5}};
    // G[1] = {{2,2},{3,1}};
    // G[2] = {{3,9},{1,3},{4,2}};
    // G[3] = {{4,4}};
    // G[4] = {{0,7},{3,6}}; 

    return 0;
}