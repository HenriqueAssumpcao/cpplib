#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

#define LLINF LLONG_MAX/2
#define IINF INT_MAX/2

typedef long long ll;

typedef vector<vector<ll>> llmatrix;

void cis_dp(int &n, int &k,vector<ll> &a, llmatrix &dp){
    dp = llmatrix(n+1,vector<ll>(k+1,0));

    for(int i = 1; i <= n; i++){
        dp[i][1] = 1;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 2; j <= k; j++){
            for(int l = 1; l <= i-1; l++){
                if(a[l-1] < a[i-1]){
                    dp[i][j] += dp[l][j-1];
                }
            }
        }
    }
}

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);

    int n,k;

    while(cin >> n >> k){
        if(n == 0){
            break;
        }
        vector<ll> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        llmatrix dp;

        cis_dp(n,k,a,dp);

        ll ret = 0;
        for(int i = 1; i <= n; i++){
            ret += dp[i][k];
        }

        cout << ret << endl;
    }

    return 0;
}
