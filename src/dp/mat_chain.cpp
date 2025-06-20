#include "dp/mat_chain.hpp"

/*
Problem: Given matrices A_0,...,A_{n-1}, A_i with size a_i x a_{i+1}, find the minimum number of scalar operations needed to compute the product A_0*...*A_{n-1}
Solution: Build a dp table where dp[i][j] is the minimum cost of the product A_i*...*A_{n-1}, thus we wish to compute dp[0][n-1].
Complexity: O(n^3)
*/

void mat_chain_order_dp(const int &n,const std::vector<int> &a, llmatrix &dp, llmatrix &recover){
    dp = llmatrix(n,std::vector<ll>(n,0)),recover = llmatrix(n,std::vector<ll>(n,0));

    for(int i = n-2; i >= 0; i--){
        for(int j = i+1; j < n; j++){
            int aux,idx = 0,temp = IINF;
            for(int k = i; k < j; k++){
                aux = dp[i][k]+dp[k+1][j]+a[i]*a[k+1]*a[j+1];
                if(temp > aux){
                    temp = aux;
                    idx = k;
                }
            }
            dp[i][j] = temp;
            recover[i][j] = idx;
        }
    }
}

std::string recover_product(int l, int r,llmatrix &recover){
    if(l == r){
        return "A_" + std::to_string(l);
    }
    else{
        std::string temp1 = recover_product(l,recover[l][r],recover);
        std::string temp2 = recover_product(recover[l][r]+1,r,recover);
        return "(" + temp1 + temp2 + ")";
    }
}