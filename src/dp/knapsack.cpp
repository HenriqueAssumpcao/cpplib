#include <vector>

#include "common.hpp"
#include "dp/knapsack.hpp"

void knapsack(int n, int w, std::vector<int> &values, std::vector<int> &weights, intmatrix &opt, std::vector<int> &sol){
    opt = intmatrix(n+1,std::vector<int>(w+1,0));
    sol = std::vector<int>(n,0);

    for(int i = 0; i < n; i++){
        for(int ww = 0; ww <= w; ww++){
            if(weights[i] > ww || (opt[i][ww] > values[i] + opt[i][ww-weights[i]])){
                opt[i+1][ww] = opt[i][ww];
            }
            else{
                opt[i+1][ww] = values[i] + opt[i][ww-weights[i]];
            }
        }
    }

    int temp = w;
    for(int i = n-1; i >= 0; i--){
        if(opt[i+1][temp] > opt[i][temp]){
            sol[i] = 1;
            temp -= weights[i];
        }
    }
}