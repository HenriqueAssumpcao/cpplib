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
    for(unsigned i = 0; i < M.size(); i++){
        tr += M[i][i];
    }
    return tr;
}


// transpose

template <typename T>
std::vector<std::vector<T>> transpose(const std::vector<std::vector<T>> &M){
    std::vector<std::vector<T>> M_t(M[0].size(),std::vector<T>(M.size()));

    for(unsigned i = 0; i < M_t.size(); i++){
        for(unsigned j = 0; j < M_t[0].size(); j++){
            M_t[i][j] = M[j][i];
        }
    }

    return M_t;
}

// Diagonal operations
/*
O(n)
*/
template <typename T>
std::vector<std::vector<T>> Diag(const std::vector<T> &v){
    std::vector<std::vector<T>> M(v.size(),std::vector<T>(v.size(),0));
    for(unsigned i = 0; i < v.size(); i++){
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
    for(unsigned i = 0; i < M.size(); i++){
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
    for(unsigned i = 0; i < M1.size(); i++){
        for(unsigned j = 0; j < M2[0].size(); j++){
            for(unsigned k = 0; k < M1[0].size(); k++){
                M[i][j] += M1[i][k] * M2[k][j];
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
    for(unsigned i = 0; i < M1.size(); i++){
        for(unsigned j = 0; j < M1.size(); j++){
            M[i][j] = M1[i][j]*M2[i][j];
        }
    }
    return M;
}


#endif // LINALG