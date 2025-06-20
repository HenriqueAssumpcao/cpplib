#include "dp/obst.hpp"
/*
Problem: Given nodes with keys {1,...,n} and acess frequencies {f_1,...,f_n}, find a binary search tree whose expected cost is minimal
Solution: Build a dp table where dp[i][j] is the minimum cost of an optimal binary search tree w.r.t. nodes {i,...,j}
Complexity: O(n^3) if we are naive, O(n^2) if we use Knuth's optimization
*/

void obst_dp_naive(const int &n,const std::vector<int> &f, llmatrix &dp, llmatrix &roots){
    dp = llmatrix(n,std::vector<ll>(n,0)),roots = llmatrix(n,std::vector<ll>(n,0));
    std::vector<int> cumul_f(n+1,0);
    for(int i = 0; i < n; i++){
        dp[i][i] = f[i];
        roots[i][i] = i;
        cumul_f[i+1] = cumul_f[i] + f[i];
    }

    for(int i = n-2; i >= 0; i--){
        for(int j = i+1; j < n; j++){
            int temp = IINF,idx = 0,aux;
            for(int k = i; k <= j; k++){
                aux = (k != 0) ? dp[i][k-1] : 0;
                aux += (k != n-1) ? dp[k+1][j] : 0;
                if(aux < temp){
                    temp = aux;
                    idx = k;
                }
            }
            dp[i][j] = temp + (cumul_f[j+1]-cumul_f[i]);
            roots[i][j] = idx;
        }
    }
}

void obst_dp_knuth(const int &n,const std::vector<int> &f, llmatrix &dp, llmatrix &roots){
    dp = llmatrix(n,std::vector<ll>(n,0)),roots = llmatrix(n,std::vector<ll>(n,0));
    std::vector<int> cumul_f(n+1,0);
    for(int i = 0; i < n; i++){
        dp[i][i] = f[i];
        roots[i][i] = i;
        cumul_f[i+1] = cumul_f[i] + f[i];
    }

    for(int i = n-2; i >= 0; i--){
        for(int j = i+1; j < n; j++){
            int temp = IINF,idx = 0,aux;
            for(int k = roots[i][j-1]; k <= roots[i+1][j]; k++){
                aux = (k != 0) ? dp[i][k-1] : 0;
                aux += (k != n-1) ? dp[k+1][j] : 0;
                if(aux < temp){
                    temp = aux;
                    idx = k;
                }
            }
            dp[i][j] = temp + (cumul_f[j+1]-cumul_f[i]);
            roots[i][j] = idx;
        }
    }
}

void reconstruct_obst(node *curr,int i, int j, const llmatrix &roots){
    curr->key = roots[i][j];
    if(i <= roots[i][j]-1){
        curr->left = new node();
        reconstruct_obst(curr->left,i,roots[i][j]-1,roots);
    }
    if(j >= roots[i][j]+1){
        curr->right = new node();
        reconstruct_obst(curr->right,roots[i][j]+1,j,roots);
    }
}