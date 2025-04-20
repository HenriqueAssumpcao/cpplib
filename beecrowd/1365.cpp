#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

#define LLINF LLONG_MAX/2
#define IINF INT_MAX/2

typedef long long ll;

typedef vector<vector<bool>> bmatrix;
typedef vector<vector<int>> imatrix;

int sol_dp(int &r, int &c,int &k, bmatrix &available, imatrix &dp){
    dp = imatrix(r,vector<int>(c));
    dp[0][0] = available[0][0];
    for(int i = 1; i < r; i++){
        dp[i][0] = available[i][0] + dp[i-1][0];
    }
    for(int j = 1; j < c; j++){
        dp[0][j] = available[0][j] + dp[0][j-1];
    }

    for(int i = 1; i < r; i++){
        for(int j = 1; j < c; j++){
            dp[i][j] = available[i][j] + dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1];
        }
    }

    int min_area = IINF;

    for(int i = 0; i < r; i++){
        for(int ii = i; ii < r; ii++){
            int j = 0,jj = 0;
            while(jj < c){
                int aux = dp[ii][jj];
                if(i > 0){
                    aux -= dp[i-1][jj];
                }
                if(j > 0){
                    aux -= dp[ii][j-1];
                }
                if(i > 0 && j > 0){
                    aux += dp[i-1][j-1];
                }
                if(aux >= k){
                    min_area = min(min_area,(ii-i+1)*(jj-j+1));
                    j++;
                    if(j > jj){
                        jj = j;
                    }
                }
                else{
                    jj++;
                }

            }
        }
    }

    return min_area;
}

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);

    int r,c,k;
    while(cin >> r >> c >> k){
        if(r == 0){
            break;
        }
        bmatrix available(r,vector<bool>(c));
        for(int i = 0; i < r; i++){
            string temp;
            cin >> temp;
            for(int j = 0; j < c; j++){
                available[i][j] = (temp[j] == '.') ? 1 : 0;
            }
        }
        imatrix dp;
        cout << sol_dp(r,c,k,available,dp) << endl;

    }

    return 0;
}
