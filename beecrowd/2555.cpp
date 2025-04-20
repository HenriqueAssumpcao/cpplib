#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

#define LLINF LLONG_MAX/2
#define IINF INT_MAX/2

typedef long long ll;
typedef vector<vector<double>> dmatrix;


void sol_dp(int &n, int &k, vector<int> &p, vector<double> &c, dmatrix &dp){
    dp = dmatrix(n,vector<double>(k+1,0));

    for(int j = 1; j <= k; j++){
        dp[n-1][j] = p[n-1];
    }

    for(int i = 0; i < n; i++){
        double temp = c[i];
        dp[i][0] = temp*p[i];
        for(int l = i+1; l < n; l++){
            temp *= c[l];
            dp[i][0] += temp*p[l];
        }
    }

    for(int i = n-2; i >= 0; i--){
        for(int j = k; j > 0; j--){
            dp[i][j] = max(p[i] + dp[i+1][j-1],c[i]*(p[i]+dp[i+1][j]));
        }
    }
}


int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);

    cout << fixed;
    cout << setprecision(2);

    int n,k;

    while(cin >> n >> k){
        vector<int> p(n);
        vector<double> c(n);

        for(int i = 0; i < n; i++){
            cin >> p[i];
        }

        int temp;
        for(int i = 0; i < n; i++){
            cin >> temp;
            c[i] = temp/(100.0);
        }

        dmatrix dp;

        sol_dp(n,k,p,c,dp);

        cout << dp[0][k] << endl;

    }

    return 0;
}
