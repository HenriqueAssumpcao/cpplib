#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

#define LLINF LLONG_MAX/2
#define IINF INT_MAX/2

typedef long long ll;
typedef vector<vector<int>> imatrix;

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);

    int n;
    while(cin >> n){
        if(n == 0){
            break;
        }

        int N = 2*n;
        vector<bool> nums(N);
        int temp;
        for(int i = 0; i < N; i++){
            cin >> temp;
            nums[i] = (temp % 2 == 0);
        }

        imatrix dp(N,vector<int>(N,0));
        imatrix choice(N,vector<int>(N,0));

        for(int i = 0; i < N-1; i++){
            dp[i][i] = nums[i];
            choice[i][i] = i;
            choice[i][i+1] = (nums[i] == 1) ? i : i+1;
            dp[i][i+1] = nums[choice[i][i+1]];
        }
        dp[N-1][N-1] = nums[N-1];
        choice[N-1][N-1] = N-1;

        for(int d = 2; d < N; d++){
            for(int i = 0; i < N-d; i++){
                int j = i + d;
                int temp_left,temp_right;
                if(choice[i+1][j] == i+1){
                    temp_left = nums[i] + dp[i+2][j];
                }
                else{
                    temp_left = nums[i] + dp[i+1][j-1];
                }
                if(choice[i][j-1] == i){
                    temp_right = nums[j] + dp[i+1][j-1];
                }
                else{
                    temp_right = nums[j] + dp[i][j-2];
                }
                if(temp_left >= temp_right){
                    dp[i][j] = temp_left;
                    choice[i][j] = i;
                }
                else{
                    dp[i][j] = temp_right;
                    choice[i][j] = j;
                }
            }
        }
        cout << dp[0][N-1] << endl;
    }
    return 0;
}
