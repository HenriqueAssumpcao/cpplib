#pragma once

#ifndef COMMON
#define COMMON

#define inf std::numeric_limits<ll>::max()

#include <iostream>
#include <vector>

template <typename T>
void print_vector(std::vector<T> &vec){
    for(unsigned int i =0; i < vec.size(); i++){
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

void print_path(int s, int v,std::vector<int> &pred, bool arrow = false);

#endif 