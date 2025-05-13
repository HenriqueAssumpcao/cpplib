#pragma once

#ifndef DSU
#define DSU

#include "common.hpp"

// Disjoint-set union
struct dsu{
    int n;
    std::vector<int> parent,rank;
    dsu(int n){
        this->n = n;
        this->parent = std::vector<int>(n,-1);
        this->rank = std::vector<int>(n,0);
    }

    void make_set(int v){
        parent[v] = v;
        rank[v];
    }

    int find_set(int v){
        if(v == parent[v]){
            return v;
        }
        parent[v] = find_set(parent[v]);
        return parent[v];
    }

    void union_sets(int a, int b){
        a = find_set(a);b = find_set(b);
        if(a != b){
            if(rank[a] < rank[b]){
                std::swap(a,b);
            }
            else if(rank[a] == rank[b]){
                rank[a]++;
            }
            parent[b] = a;
        }
    }
};

#endif // DSU