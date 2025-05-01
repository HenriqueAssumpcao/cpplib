#include "algebra/exp.hpp"
#include "common.hpp"

// Fast exp
int fast_exp(int e,const int &b){
    if(e == 1){
        return b;
    }
    int temp = fast_exp(e/2,b);
    temp *= temp;
    if((e % 2) == 1){
        temp *= b;
    }
    return temp;
}

ll fast_exp(ll e,const ll &b){
    if(e == 1){
        return b;
    }
    ll temp = fast_exp(e/2,b);
    temp *= temp;
    if((e % 2) == 1){
        temp *= b;
    }
    return temp;
}

// Fast exp mod
int fast_exp_mod(int e,const int &b,const int &mod){
    if(e == 1){
        return b % mod;
    }
    int temp = fast_exp_mod(e/2,b,mod);
    temp = (temp*temp)%mod;
    if((e % 2) == 1){
        temp = (temp*b)%mod;
    }
    return temp;
}

ll fast_exp_mod(ll e,const ll &b,const ll &mod){
    if(e == 1){
        return b % mod;
    }
    ll temp = fast_exp_mod(e/2,b,mod);
    temp = (temp*temp)%mod;
    if((e % 2) == 1){
        temp = (temp*b)%mod;
    }
    return temp;
}

