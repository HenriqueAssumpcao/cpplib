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

template <typename T>
void print_vector(vector<T> &vec){
    for(unsigned i = 0; i < vec.size(); i++){
        cout << vec[i] << " "; 
    }
    cout << endl;
}

int sub1mod3(int x){
    if(x > 0){
        return (x-1) % 3;
    }
    return 2;
}

int sol_dp(int n, vector<int> vec){
    imatrix dp = imatrix(n,vector<int>(3));

    for(int j = 0; j < 3; j++){
        if(j == ((vec[0]+1) % 3)){
            dp[0][j] = -IINF;
        }
        else if(j == vec[0]){
            dp[0][j] = 0;
        }
        else{
            dp[0][j] = 1;
        }
    }

    for(int i = 1; i < n; i++){
        for(int j = 0; j < 3; j++){
            if(j == ((vec[i]+1) % 3)){
                dp[i][j] = -IINF;
            }
            else if(j == vec[i]){
                dp[i][j] = max(dp[i-1][((vec[i]+1) % 3)],dp[i-1][sub1mod3(vec[i])]);
            }
            else{
                dp[i][j] = 1 + max(dp[i-1][((vec[i]+1) % 3)],dp[i-1][vec[i]]);
            }
        }
    }

    int ret = 0;
    for(int j = 0; j < 3; j++){
        ret = max(ret,dp[n-1][j]);
    }
    return ret;
}

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> vec(n,0); // R = 0, S = 1, P = 2
    for(int i = 0; i < n; i++){
        // (vec[i] - 1) % 3 is who he loses against, and (vec[i] + 1) % 3 is who he wins
        if(s[i] == 'S'){
            vec[i] = 1;
        }
        else if(s[i] == 'P'){
            vec[i] = 2;
        }
    }

    cout << sol_dp(n,vec) << endl;



    return 0;
}
