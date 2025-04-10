#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

#define LLINF LLONG_MAX/2
#define IINF INT_MAX/2

typedef long long ll;
typedef vector<vector<int>> imatrix;

void knapsack_min(const int &n, const int &V,const vector<int> &weights, const vector<int> &values, imatrix &dp){
    dp = imatrix(n+1,vector<int>(V+1,0));
    for(int j = 1; j <= V; j++){
        dp[0][j] = IINF;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= V; j++){
            int aux = max(0,j-values[i-1]);
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
                    dp[i][j] = min(dp[i-1][j],dp[i-1][aux]+weights[i-1]);
                }
            }
        }
    }
}


int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);
    int n,p;
    while(cin >> n >> p){
        vector<int> damage(n),mana(n);

        for(int i = 0; i < n; i++){
            cin >> damage[i] >> mana[i];
        }

        imatrix dp;

        knapsack_min(n,p,mana,damage,dp);

        int ret = (dp[n][p] == IINF) ? -1 : dp[n][p];

        cout << ret << endl;
    }


    return 0;
}
