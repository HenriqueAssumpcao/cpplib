#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

#define LLINF LLONG_MAX/2
#define IINF INT_MAX/2

typedef long long ll;

typedef vector<vector<int>> imatrix;

int sol_dp(int s, int b,vector<int> &cut_roulette,vector<int> &balls){
    imatrix dp(b,vector<int>(s-1,-IINF));
    for(int j = 0; j < s-1; j++){
        dp[0][j] = -balls[0]*(cut_roulette[j]+cut_roulette[j+1]);
    }

    for(int k = 1; k < b; k++){
        vector<int> prev_max(s-1,-IINF);
        for(int j = 2; j < s-1; j++){
            prev_max[j] = max(prev_max[j-1],dp[k-1][j-2]);
        }
        for(int j = 0; j < s-1; j++){
            dp[k][j] = prev_max[j] -balls[k]*(cut_roulette[j]+cut_roulette[j+1]);
        }
    }

    int ret = -IINF;

    for(int j = 0; j < s-1; j++){
        ret = max(ret,dp[b-1][j]);
    }

    return ret;
}


int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);

    int s,b;
    while(cin >> s >> b){
        if(s == 0){
            break;
        }
        vector<int> roulette(s),balls(b-1);
        int b0;

        for(int i = 0; i < s; i++){
            cin >> roulette[i];
        }
        cin >> b0;
        for(int i = 1; i < b; i++){
            cin >> balls[i-1];
        }
        
        int ret = -IINF;
        for(int i = 0; i < s; i++){
            int temp = -b0*(roulette[i]+roulette[(i+1)%s]);
            vector<int> cut_roulette;
            for(int t = (i+2)%s; t != i;t = (t+1)%s){
                cut_roulette.push_back(roulette[t]);
            }
            if(b > 1){
                ret = max(ret,temp + sol_dp(s-2,b-1,cut_roulette,balls));
            }
            else{
                ret = max(ret,temp);
            }
        }
        cout << ret << endl;
    }

    return 0;
}
