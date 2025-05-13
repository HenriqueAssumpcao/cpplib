#include <numeric>
#include <vector>
#include "common.hpp"
#include "dp/knapsack.hpp"

/*
Problem: Given n items, with weights w_1,...,w_n, values v_1,...,v_n, find a subset with maximum value with total weight at most C;
Solution: Create a table dp where dp[i][j] is the maximum value subset of {1,...,i} with weight at most j, and return dp[n][C]
Complexity: O(nC)
*/
void knapsack_max(const int &n, const int &C,const std::vector<int> &weights,const std::vector<int> &values, intmatrix &dp, std::vector<int> &sol){
    dp = intmatrix(n+1,std::vector<int>(C+1,0));
    sol = std::vector<int>(n,0);

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= C; j++){
            if(weights[i-1] > j){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = std::max(dp[i-1][j],dp[i-1][j-weights[i-1]] + values[i-1]);
            }
        }
    }

    int aux = C;
    for(int i = n; i > 0; i--){
        if(dp[i-1][aux] < dp[i][aux]){
            sol[i-1] = 1;
            aux -= weights[i-1];
        }
    }
}

/*
Problem: Given n items, with weights w_1,...,w_n, values v_1,...,v_n, find a subset with minimum weight and value at least V;
Solution: Create a table dp where dp[i][j] is the minimum weight of a subset that obtains at least j total value;
Complexity: O(nV)
*/
void knapsack_min(const int &n, const int &V,const std::vector<int> &weights, const std::vector<int> &values, intmatrix &dp, std::vector<int> &sol){
    dp = intmatrix(n+1,std::vector<int>(V+1,0));
    for(int j = 1; j <= V; j++){
        dp[0][j] = IINF;
    }
    sol = std::vector<int>(n,0);

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= V; j++){
            int aux = std::max(0,j-values[i-1]);
            if(dp[i-1][j] == IINF){
                if(dp[i-1][aux] == IINF){
                    dp[i][j] = IINF;
                }
                else{
                    dp[i][j] = dp[i-1][aux] + weights[i-1];
                }
            }
            else{
                if(dp[i-1][aux] == IINF){
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    dp[i][j] = std::min(dp[i-1][j],dp[i-1][aux]+weights[i-1]);
                }
            }
        }
    }

    int aux = V;
    for(int i = n; i > 0; i--){
        if(dp[i][aux] < dp[i-1][aux]){
            sol[i-1] = 1;
            aux -= values[i-1];
        }
    }
}