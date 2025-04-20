#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

#define LLINF LLONG_MAX/2
#define IINF INT_MAX/2

typedef long long ll;
typedef vector<vector<int>> imatrix;

void longest_common_subsequence_dp(string &s1, string &s2, imatrix &dp){
    int n = s1.size(),m = s2.size();
    dp = imatrix(n+1,vector<int>(m+1,0));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
}

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);

    string search,article;

    cin >> search;
    cin >> article;

    imatrix dp;

    longest_common_subsequence_dp(search,article,dp);

    cout << dp[search.size()][article.size()] << endl;

    return 0;
}
