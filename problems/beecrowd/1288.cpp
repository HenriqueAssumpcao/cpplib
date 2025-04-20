#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

#define LLINF LLONG_MAX/2
#define IINF INT_MAX/2

typedef long long ll;
typedef vector<vector<int>> imatrix;

void knapsack(int &n,int &c, vector<int> &weights, vector<int> &values, imatrix &dp){
    dp = imatrix(n+1,vector<int>(c+1,0));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= c; j++){
            if(weights[i-1] > j){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-weights[i-1]]+values[i-1]);
            }
        }
    }
}



int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
    
        vector<int> power(n),weights(n);
    
        for(int i = 0; i < n; i++){
            cin >> power[i] >> weights[i];
        }
    
        int k,r;
        cin >> k;
        cin >> r;
    
        imatrix dp;
    
        knapsack(n,k,weights,power,dp);
    
        if(dp[n][k] < r){
            cout << "Falha na missao" << endl;
        }
        else{
            cout << "Missao completada com sucesso" << endl;
        }
    
    }


    return 0;
}
