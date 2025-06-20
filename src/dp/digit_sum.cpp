#include "dp/digit_sum.hpp"

// digit sum dp

ll digit_sum_dp_rec(int i, int j, int k, std::string &ub,llmatrix3d &dp){
    if(i == -1){
        return k;
    }
    else if(dp[i][j][k] != -1 && j != 1){
        return dp[i][j][k];
    }
    else{
        ll ret = 0;
        if(j == 0){
            for(int d = 0; d <= 9; d++){
                ret += digit_sum_dp_rec(i-1,0,k+d,ub,dp);
            }
            dp[i][0][k] = ret;
        }
        else{
            int aux = ub[i] - '0';
            for(int d = 0; d < aux; d++){
                ret += digit_sum_dp_rec(i-1,0,k+d,ub,dp);
            }
            ret += digit_sum_dp_rec(i-1,1,k+aux,ub,dp);
        }
        return ret;
    }
}