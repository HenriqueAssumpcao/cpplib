#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

#define LLINF LLONG_MAX/2
#define IINF INT_MAX/2

typedef long long ll;

typedef vector<vector<int>> imatrix;

void sol_dp(int &n, int &c, vector<int> &p, imatrix &dp){
    int M = 2*c+1;
    dp = imatrix(n,vector<int>(M,0));

    for(int j = 0; j < M; j++){
        if(p[0] == abs(j-c)){
            dp[0][j] = 1;
        }
    }

    for(int i = 1; i < n; i++){
        for(int j = 0; j < M; j++){
            if(j-p[i] >= 0 && dp[i-1][j-p[i]] == 1){
                dp[i][j] = 1;
            }
            else if(j+p[i] < M && dp[i-1][j+p[i]] == 1){
                dp[i][j] = 1;
            }
            else{
                dp[i][j] = 0;
            }
        }
    }
}

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);

    int t;
    cin >> t;

    int c = 5;
    
    while(t--){
        int n;
        cin >> n;

        vector<int> p(n);

        for(int i = 0; i < n; i++){
            cin >> p[i];
        }

        imatrix dp;

        sol_dp(n,c,p,dp);

        bool check_row;
        for(int i = 0; i < n; i++){
            check_row = false;
            for(int j = 0; j < 2*c+1; j++){
                if(dp[i][j] == 1){
                    check_row = true;
                    break;
                }
            }
            if(!check_row){
                cout << "Ho Ho Ho!" << endl;
                break;
            }
        }
        if(check_row){
            cout << "Feliz Natal!" << endl;
        }
    }

    return 0;
}
