#include <iostream>
#include <vector>
#include <list>

#include "common.hpp"

void print_path(const int s,const int v,const std::vector<int> &pred, const bool arrow){
    if(s == v){
        std::cout << s << " --> ";
    }
    else if(pred[v] == -1){
        std::cout << "No path from " << s << " to " << v << std::endl;
    }
    else{
        print_path(s,pred[v],pred,true);
        std::cout << v;
        if(arrow){
            std::cout << " --> ";
        }
        else{
            std::cout << std::endl;
        }
    }
}


// O(V+E)
void print_graph(const graph &G){
    for(unsigned u = 0; u < G.size(); u++){
        std::cout << "Node: " << u << ";Neighbors: [";
        for(auto it = G[u].begin(); it != G[u].end(); it++){
            std::cout << (*it);
            if(next(it) != G[u].end()){
                std::cout << ",";
            }
        }
        std::cout << "]" << std::endl;

    }
}