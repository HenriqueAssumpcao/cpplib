#include <map>
#include <tuple>

#include "algebra/binomial.hpp"
#include "common.hpp"

std::map<std::pair<int,int>,ll> binom2val;

ll binom_coeff(int n, int k){
    if(k < 0 || k > n){
        return 0;   
    }
    else if(k == 0){
        return 1;
    }
    else{
        auto temp1 = binom2val.find({n-1,k}), temp2 = binom2val.find({n-1,k-1});
        if(temp1 == binom2val.end()){
            binom2val[{n-1,k}] = binom_coeff(n-1,k);
        }
        if(temp2 == binom2val.end()){
            binom2val[{n-1,k-1}] = binom_coeff(n-1,k-1);
        }
        return binom2val[{n-1,k}] + binom2val[{n-1,k-1}];
    }
}