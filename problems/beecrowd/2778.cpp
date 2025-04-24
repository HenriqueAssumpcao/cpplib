#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

#define LLINF LLONG_MAX/2
#define IINF INT_MAX/2

typedef long long ll;

typedef vector<vector<int>> imatrix;
typedef vector<vector<ll>> llmatrix;
typedef vector<vector<vector<vector<int>>>> imatrix4d;
typedef vector<vector<vector<vector<pair<int,int>>>>> pmatrix4d;


void sol_dp(int n, int m, int x, int y, imatrix &M, imatrix4d &dp){
    dp = imatrix4d(n,vector<imatrix>(m,imatrix(x+1,vector<int>(y+1,IINF))));
    pmatrix4d parent(n,vector<vector<vector<pair<int,int>>>>(m,vector<vector<pair<int,int>>>(x+1,vector<pair<int,int>>(y+1,{-1,-1}))));

    for(int xx = 0; xx <= x; xx++){
        for(int yy = 0; yy <= y; yy++){
            if(M[0][0] > 0 || (M[0][0] == 0 && xx > 0) || (M[0][0] < 0 && yy > 0)){
                dp[0][0][xx][yy] = M[0][0];
            }
        }
    }

    for(int xx = 0;xx <= x; xx++){
        for(int yy = 0;yy <= y; yy++){
            for(int j = 1; j < m; j++){
                if(M[0][j] > 0 && dp[0][j-1][xx][yy] != IINF){
                    dp[0][j][xx][yy] = M[0][j] + dp[0][j-1][xx][yy];
                    parent[0][j][xx][yy] = {0,j-1};
                }
                else if(M[0][j] == 0 && xx > 0 && dp[0][j-1][xx-1][yy] != IINF){
                    dp[0][j][xx][yy] = M[0][j] + dp[0][j-1][xx-1][yy];
                    parent[0][j][xx][yy] = {0,j-1};   
                }
                else if(M[0][j] < 0 && yy > 0 && dp[0][j-1][xx][yy-1] != IINF){
                    dp[0][j][xx][yy] = M[0][j] + dp[0][j-1][xx][yy-1];
                    parent[0][j][xx][yy] = {0,j-1}; 
                }
            }
        }
    }

    for(int i = 1; i < n; i++){
        for(int xx = 0; xx <= x; xx++){
            for(int yy = 0; yy <= y; yy++){
                // compute first using left and up neighbors
                for(int j = 0; j < m; j++){
                    if(M[i][j] > 0){
                        if(dp[i-1][j][xx][yy] != IINF){
                            dp[i][j][xx][yy] = dp[i-1][j][xx][yy] + M[i][j];
                            parent[i][j][xx][yy] = {i-1,j};
                        }
                        if((j > 0) && (dp[i][j-1][xx][yy] != IINF)){
                            if(M[i][j] + dp[i][j-1][xx][yy] < dp[i][j][xx][yy]){
                                dp[i][j][xx][yy] = M[i][j] + dp[i][j-1][xx][yy];
                                parent[i][j][xx][yy] = {i,j-1};
                            }
                        }
                    }
                    else if(M[i][j] == 0 && xx > 0){
                        if(dp[i-1][j][xx-1][yy] != IINF){
                            dp[i][j][xx][yy] = dp[i-1][j][xx-1][yy] + M[i][j];
                            parent[i][j][xx][yy] = {i-1,j};
                        }
                        if((j > 0) && (dp[i][j-1][xx-1][yy] != IINF) && (parent[i][j-1][xx-1][yy].first != i || parent[i][j-1][xx-1][yy].second != j)){
                            if(M[i][j] + dp[i][j-1][xx-1][yy] < dp[i][j][xx][yy]){
                                dp[i][j][xx][yy] = M[i][j] + dp[i][j-1][xx-1][yy];
                                parent[i][j][xx][yy] = {i,j-1};
                            }
                        }
                    }
                    else{
                        if(yy > 0){
                            if(dp[i-1][j][xx][yy-1] != IINF){
                                dp[i][j][xx][yy] = dp[i-1][j][xx][yy-1] + M[i][j];
                                parent[i][j][xx][yy] = {i-1,j};
                            }
                            if((j > 0) && (dp[i][j-1][xx][yy-1] != IINF) && (parent[i][j-1][xx][yy-1].first != i || parent[i][j-1][xx][yy-1].second != j)){
                                if(M[i][j] + dp[i][j-1][xx][yy-1] < dp[i][j][xx][yy]){
                                    dp[i][j][xx][yy] = M[i][j] + dp[i][j-1][xx][yy-1];
                                    parent[i][j][xx][yy] = {i,j-1};
                                }
                            }
                        }
                        else{
                            dp[i][j][xx][yy] = IINF;
                        }
                    }
                }
                // compare with possible right paths
                for(int j = m-2; j >= 0; j--){
                    if(M[i][j] > 0){
                        if((dp[i][j+1][xx][yy] != IINF) && (parent[i][j+1][xx][yy].first != i || parent[i][j+1][xx][yy].second != j)){
                            if(M[i][j] + dp[i][j+1][xx][yy] < dp[i][j][xx][yy]){
                                dp[i][j][xx][yy] = M[i][j] + dp[i][j+1][xx][yy];
                                parent[i][j][xx][yy] = {i,j+1};
                            }
                        }
                    }
                    else if(M[i][j] == 0 && xx > 0){
                        if((dp[i][j+1][xx-1][yy] != IINF) && (parent[i][j+1][xx-1][yy].first != i || parent[i][j+1][xx-1][yy].second != j)){
                            if(M[i][j] + dp[i][j+1][xx-1][yy] < dp[i][j][xx][yy]){
                                dp[i][j][xx][yy] = M[i][j] + dp[i][j+1][xx-1][yy];
                                parent[i][j][xx][yy] = {i,j+1};
                            }
                        }
                    }
                    else if(M[i][j] < 0 && yy > 0){
                        if((dp[i][j+1][xx][yy-1] != IINF) && (parent[i][j+1][xx][yy-1].first != i || parent[i][j+1][xx][yy-1].second != j)){
                            if(M[i][j] + dp[i][j+1][xx][yy-1] < dp[i][j][xx][yy]){
                                dp[i][j][xx][yy] = M[i][j] + dp[i][j+1][xx][yy-1];
                                parent[i][j][xx][yy] = {i,j+1};
                            }
                        }
                    }
                }
            }
        }
    }
}

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);

    int n,m,x,y;

    while(cin >> n >> m >> x >> y){
        imatrix M(n,vector<int>(m));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> M[i][j];
            }
        }

        imatrix4d dp;

        sol_dp(n,m,x,y,M,dp);
        if(dp[n-1][m-1][x][y] == IINF){
            cout << "Impossivel" << endl;
        }
        else{
            cout << dp[n-1][m-1][x][y] << endl;
        }

    }

    return 0;
}
