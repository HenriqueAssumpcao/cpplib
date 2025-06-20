#pragma once

#ifndef OBST
#define OBST

#include "common.hpp"

struct node{
    int key;
    node *left,*right;

    node():key(0),left(nullptr),right(nullptr){};
    node(int key):key(key),left(nullptr),right(nullptr){};
    node(int key, node *left, node *right):key(key),left(left),right(right){};
    
};

void pre_order(node *curr){
    if(curr != nullptr){
        std::cout << curr->key << " ";
        pre_order(curr->left);
        pre_order(curr->right);
    }
}

void in_order(node *curr){
    if(curr != nullptr){
        in_order(curr->left);
        std::cout << curr->key << " ";
        in_order(curr->right);
    }
}

void pos_order(node *curr){
    if(curr != nullptr){
        pos_order(curr->left);
        pos_order(curr->right);
        std::cout << curr->key << " ";
    }
}

void obst_dp_naive(const int &n,const std::vector<int> &f, llmatrix &dp, llmatrix &roots);
void obst_dp_knuth(const int &n,const std::vector<int> &f, llmatrix &dp, llmatrix &roots);
void reconstruct_obst(node *curr,int i, int j, const llmatrix &roots);

#endif //OBST