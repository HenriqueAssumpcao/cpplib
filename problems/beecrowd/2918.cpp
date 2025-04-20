#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

#define LLINF LLONG_MAX/2
#define IINF INT_MAX/2

typedef long long ll;

ll digit_sum_dp_rec(int i, int j, int k, string &ub,vector<vector<ll>> &dp){
    if(i == -1){
        return k;
    }
    else if(dp[i][k] != -1 && j != 1){
        return dp[i][k];
    }
    else{
        ll ret = 0;
        if(j == 0){
            for(int d = 0; d <= 9; d++){
                ret += digit_sum_dp_rec(i-1,0,k+d,ub,dp);
            }
            dp[i][k] = ret;
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


int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);

    ll mod = 1e9+7;
    ll l,r;
    vector<vector<ll>> dp;

    while(cin >> l >> r){
        string l_str = to_string(l-1),r_str = to_string(r);
        reverse(l_str.begin(),l_str.end());
        reverse(r_str.begin(),r_str.end());

        dp = vector<vector<ll>>(11,vector<ll>(90,-1));
        ll ret1 = digit_sum_dp_rec(r_str.size()-1,1,0,r_str,dp);

        dp = vector<vector<ll>>(11,vector<ll>(90,-1));
        ll ret2 = digit_sum_dp_rec(l_str.size()-1,1,0,l_str,dp);

        cout << (ret1 - ret2) % mod << endl;
    }

    return 0;
}
