#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

#define LLINF LLONG_MAX/2
#define IINF INT_MAX/2

typedef long long ll;
typedef vector<vector<int>> imatrix;

template <typename T>
void print_vector(vector<T> &vec){
    for(unsigned i = 0; i < vec.size(); i++){
        cout << vec[i] << " "; 
    }
    cout << endl;
}

template <typename T>
void print_matrix(vector<vector<T>> &M){
    for(unsigned i = 0; i < M.size(); i++){
        print_vector<T>(M[i]);
    }
}


int main(){
    //std::ios::sync_with_stdio(0);cin.tie(0);

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

        print_vector<bool>(nums);
        cout << endl;

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


        print_matrix<int>(dp);
        cout << endl;
        print_matrix<int>(choice);

        for(int d = 2; d < N; d++){
            cout << "diagonal = " << d << endl;
            for(int i = 0; i < N-d; i++){
                int j = i + d;
                cout << "i = " << i << ";j = " << j << endl;
                if(dp[i+1][j] < dp[i][j-1]){
                    choice[i][j] = i;
                    dp[i][j] = nums[i];
                    dp[i][j] += (choice[i+1][j] == j) ? (dp[i+1][j-1]) : (dp[i+2][j]);
                }
                else if(dp[i+1][j] > dp[i][j-1]){
                    choice[i][j] = j;
                    dp[i][j] = nums[j];
                    dp[i][j] += (choice[i][j-1] == i) ? (dp[i+1][j-1]) : (dp[i][j-2]);
                }
                else{
                    int temp1 = (choice[i][j-1] == i) ? (dp[i+1][j-1]) : (dp[i][j-2]);
                    int temp2 = (choice[i+1][j] == j) ? (dp[i+1][j-1]) : (dp[i+2][j]);
                    dp[i][j] = max(nums[i] + temp1,nums[j] + temp2);
                }

            }
        }

        print_matrix<int>(dp);

        cout << dp[0][N-1] << endl;


    }


    return 0;
}
