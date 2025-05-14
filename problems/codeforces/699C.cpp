#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

#define LLINF LLONG_MAX/2
#define IINF INT_MAX/2

typedef long long ll;

int sol(int i, vector<int> &dp, const vector<int> &a, const int &n){
    if(i == (n+1)){
        int num_zeros = 0;
        for(int j = 1; j <= n; j++){
            if(dp[j] == 0){
                num_zeros++;
            }
        }
        return num_zeros;
    }
    else{
        if(a[i] == 0){
            dp[i] = 0;
            return sol(i+1,dp,a,n);
        }
        else if(a[i] == 1 || a[i] == 2){
            dp[i] = (dp[i-1] == a[i]) ? 0 : a[i];
            return sol(i+1,dp,a,n);
        }
        else{
            if(dp[i-1] == 1){
                dp[i] = 2;
                return sol(i+1,dp,a,n);
            }
            else if(dp[i-1] == 2){
                dp[i] = 1;
                return sol(i+1,dp,a,n);
            }
            else{
                if(i == n || a[i+1] == 0 || a[i+1] == 2){
                    dp[i] = 1;
                    return sol(i+1,dp,a,n);
                }
                else if(a[i+1] == 1){
                    dp[i] = 2;
                    return sol(i+1,dp,a,n);
                }
                else{
                    int temp1,temp2;
                    dp[i] = 1;
                    temp1 = sol(i+1,dp,a,n);
                    dp[i] = 2;
                    temp2 = sol(i+1,dp,a,n);
                    return min(temp1,temp2);
                }
            }
        }
    }
}


int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);


    int n;
    cin >> n;

    vector<int> a(n+1);
    a[0] = 0;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    vector<int> dp(n+1,0);

    cout << sol(1,dp,a,n) << endl;

    return 0;
}
