#include "dp/tsp.hpp"

/*
Problem: TSP
Solution: fix s = n-1, and let dp[v][S] be the length of the shortest path from s to v that passes through each vertex of S.
Complexity: O(n^22^n)

Assumes that dp is initialized as llmatrix dp(n,std::vector<ll>(1 << n,-1))
*/

void tsp_dp(int v, int S, int n,llmatrix &dp, llmatrix &dist_mat){
    if(dp[v][S] == -1){
        if(S == (1 << v)){
            dp[v][S] = dist_mat[n][v];
        }
        else if((S & (1 << v)) == 0){
            dp[v][S] = IINF;
        }
        else{
            ll temp = IINF;
            for(int i = 0; i < n; i++){
                if(i != v && (S & (1 << i))){
                    tsp_dp(i,S & (~(1 << v)),n,dp,dist_mat);
                    temp = std::min(temp,dp[i][S & (~(1 << v))] + dist_mat[v][i]);
                }
            }
            dp[v][S] = temp;
        }
    }
}