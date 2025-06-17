#include "algebra/basics.hpp"
#include "common.hpp"

// Fast exp

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

// Finds integers x,y such that x*a + y*b = gcd(a,b) using euclid's extended algorithm
ll gcd_ext(ll a, ll b, ll &x, ll &y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    ll ret = gcd_ext(b,a%b,x,y);
    ll temp = y;
    y = x - (a/b)*temp;
    x = temp;
    return ret;
}

// Inverse of a in Z_n, returns 0 if doesnt exist
ll inv_mod(const ll &a, const ll &n){
    ll x,y,d;
    d = gcd_ext(a,n,x,y);
    if(d == 1){
        if(x < 0){
            x = n - ((-x) % n);
        }
        return x%n;
    }
    else{
        return 0;
    }
}
// Inverse of a modulo p
ll inv_modp(const ll &a, const ll &p){
    if(a == 0){
        return 0;
    }
    return fast_exp_mod(p-2,a,p);
}

// matrix multiplication modulo mod
llmatrix matmul_mod(const llmatrix &A,const llmatrix &B,const ll &mod){
    llmatrix C(A.size(),std::vector<ll>(B[0].size()));

    for(unsigned i = 0; i < A.size(); i++){
        for(unsigned j = 0; j < B[0].size(); j++){
            C[i][j] = 0;
            for(unsigned k = 0; k < A[0].size();k++){
                C[i][j] = (C[i][j] + ((A[i][k]*B[k][j]) % mod)) % mod;
            }
        }
    }

    return C;
}

// fast matrix exponentiation modulo mod
llmatrix fast_matexp_mod(ll e, const llmatrix &M,const ll &mod){
    if(e == 1){
        return M;
    }
    llmatrix N = fast_matexp_mod(e/2,M,mod);
    llmatrix temp = matmul_mod(N,N,mod);
    if((e % 2) == 1){
        temp = matmul_mod(temp,M,mod);
    }
    return temp;
}

// product of two permutations, i.e., first applying perm2 and then perm1
std::vector<int> compose_permutation(int n,std::vector<int> &perm1, std::vector<int> &perm2){
    std::vector<int> prod(n);
    for(int i = 0; i < n; i++){
        prod[i] = perm2[perm1[i]];
    }
    return prod;
}

// fast exponentiation of permutation
std::vector<int> fast_exp_permute(int n, ll e, std::vector<int> &perm){
    if(e == 1){
        return perm;
    }
    else if(e == 2){
        return compose_permutation(n,perm,perm);
    }
    std::vector<int> temp = fast_exp_permute(n,e/2,perm);
    temp = compose_permutation(n,temp,temp);
    if((e%2) == 1){
        temp = compose_permutation(n,perm,temp);
    }
    return temp;
}