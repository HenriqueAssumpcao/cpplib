#pragma once

#ifndef LINALG
#define LINALG

#include "common.hpp"

// trace
/*
O(n)
*/
template <typename T>
T trace(const std::vector<std::vector<T>> &M){
    T tr = 0;
    for(unsigned int i = 0; i < M.size(); i++){
        tr += M[i][i];
    }
    return tr;
}


// Diagonal operations
/*
O(n)
*/
template <typename T>
std::vector<std::vector<T>> Diag(const std::vector<T> &v){
    std::vector<std::vector<T>> M(v.size(),std::vector<T>(v.size(),0));
    for(unsigned int i = 0; i < v.size(); i++){
        M[i][i] = v[i];
    }
    return M;
}

/*
O(n)
*/
template <typename T>
std::vector<T> diag(const std::vector<std::vector<T>> &M){
    std::vector<T> v(M.size());
    for(unsigned int i = 0; i < M.size(); i++){
        v[i] = M[i][i];
    }
    return v;
}

// Products
/*
O(n^3)
*/
template <typename T>
std::vector<std::vector<T>> matmul(const std::vector<std::vector<T>> &M1,const std::vector<std::vector<T>> &M2){
    std::vector<std::vector<T>> M(M1.size(),std::vector<T>(M1.size()));
    for(unsigned int i = 0; i < M1.size(); i++){
        for(unsigned int j = 0; j < M1.size(); j++){
            for(unsigned int k = 0; k < M1.size(); k++){
                M[i][j] += M1[i][k]*M2[k][j];
            }
        }
    }
    return M;
}

/*
O(n^2)
*/
template <typename T>
std::vector<std::vector<T>> schur(const std::vector<std::vector<T>> &M1,const std::vector<std::vector<T>> &M2){
    std::vector<std::vector<T>> M(M1.size(),std::vector<T>(M1.size()));
    for(unsigned int i = 0; i < M1.size(); i++){
        for(unsigned int j = 0; j < M1.size(); j++){
            M[i][j] = M1[i][j]*M2[i][j];
        }
    }
    return M;
}


#endif // LINALG