#include <iostream>
#include <vector>

#include "common.h"

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