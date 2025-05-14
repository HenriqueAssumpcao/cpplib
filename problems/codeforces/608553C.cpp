#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

#define LLINF LLONG_MAX/2
#define IINF INT_MAX/2

typedef long long ll;
typedef vector<vector<pair<int,ll>>> wgraph; // weighted graph
typedef vector<vector<int>> graph; // unweighted graph

typedef vector<vector<int>> imatrix;
typedef vector<vector<ll>> llmatrix;

int sol_dp(int a, int b, imatrix &dp){
    if(a == b){
        return 0;
    }
    else if(dp[a][b] != -1){
        return dp[a][b];
    }

    int min_h = IINF;
    for(int i = 1; i < a; i++){
        min_h = min(min_h,sol_dp(i,b,dp) + sol_dp(a-i,b,dp) + 1);
    }

    int min_v = IINF;
    for(int j = 1; j < b; j++){
        min_v = min(min_v,sol_dp(a,j,dp) + sol_dp(a,b-j,dp)+1);
    }

    dp[a][b] = min(min_h,min_v);
    return dp[a][b];
}

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);

    int a,b;

    cin >> a >> b;

    int n = max(a,b);
    imatrix dp(n+1,vector<int>(n+1,-1));

    cout << sol_dp(a,b,dp) << endl;

    return 0;
}
