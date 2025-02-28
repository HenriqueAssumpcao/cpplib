#include <list>
#include <vector>

#include "common.hpp"
#include "graph/utils.hpp"



// O(V)
std::vector<unsigned> out_deg(const graph &G){
    std::vector<unsigned> out(G.size(),0);
    for(unsigned u = 0; u < G.size(); u++){
        out[u] += G[u].size();
    }

    return out;
}

// O(V+E)
std::vector<unsigned> in_deg(const graph &G){
    std::vector<unsigned> in(G.size(),0);
    for(unsigned u = 0; u < G.size(); u++){
        for(unsigned v : G[u]){
            in[v]++;
        }
    }
    return in;
}
