#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

#define LLINF LLONG_MAX/2
#define IINF INT_MAX/2

typedef long long ll;

typedef vector<vector<int>> imatrix;
typedef vector<vector<ll>> llmatrix;

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

    int n,c;
    int h = 1;

    while(cin >> n >> c){
        if(n == 0){
            break;
        }
        vector<int> values(n),weights(n);
        for(int i = 0; i < n; i++){
            cin >> weights[i] >> values[i];
        }

        imatrix dp;
        knapsack(n,c,weights,values,dp);

        cout << "Caso " << h << ": " << dp[n][c] << endl;
        h++;


    }
    return 0;
}
