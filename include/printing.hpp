#pragma once

#ifndef PRINTING
#define PRINTING

#include <iostream>
#include <vector>
#include "common.hpp"

/*
O(n^2)
*/
template <typename T>
void print_matrix(const std::vector<std::vector<T>> &M){
    for(unsigned int i = 0; i < M.size(); i++){
        std::cout << "[";
        for(unsigned int j = 0; j < M[0].size()-1; j++){
            std::cout << M[i][j] << ",";
        }
        std::cout << M[i][M[0].size()-1] << "]" << std::endl;
    }
}

/*
O(n)
*/
template <typename T>
void print_matrix(const std::vector<T> &v){
    std::cout << std::endl;
    std::cout << "[";
    for(unsigned int i = 0; i < v.size()-1; i++){
        std::cout << v[i] << ",";
    }
    std::cout << v[v.size()-1] << "]" << std::endl;
    std::cout << std::endl;
}

/*
O(n)
*/
void print_path(const int s, const int v,const std::vector<int> &pred, const bool arrow = false);

void print_graph(const graph &G);


#endif // PRINTING