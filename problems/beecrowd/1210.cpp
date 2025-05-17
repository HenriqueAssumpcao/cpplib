#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

#define LLINF LLONG_MAX/2
#define IINF INT_MAX/2

typedef long long ll;
typedef vector<vector<int>> imatrix;
typedef vector<vector<ll>> llmatrix;

template <typename T>
void print_vector(vector<T> &vec){
    for(unsigned i = 0; i < vec.size()-1; i++){
        cout << vec[i] << " "; 
    }
    cout << vec[vec.size()-1] << endl;
}

int sol_dp(int n, int I, int m, int p, vector<int> &cost, vector<int> &price, vector<int> &res){
    imatrix dp(n,vector<int>(m));
    imatrix choice(n,vector<int>(m,0));

    vector<int> switch_cost(m);
    for(int j = 0; j < m; j++){
        switch_cost[j] = p - price[j] + cost[0];
    }

    dp[n-1][m-1] = switch_cost[m-1];
    for(int j = 0; j < m-1; j++){
        if(switch_cost[j] <= cost[j+1]){
            dp[n-1][j] = switch_cost[j];
            choice[n-1][j] = 1;
        }
        else{
            dp[n-1][j] = cost[j+1];
        }
    }

    for(int i = n-2; i >= 0; i--){
        dp[i][m-1] = switch_cost[m-1] + dp[i+1][0];
        choice[i][m-1] = 1;
        for(int j = m-2; j >= 0; j--){
            if((switch_cost[j] + dp[i+1][0]) <= (cost[j+1] + dp[i+1][j+1])){
                dp[i][j] = switch_cost[j] + dp[i+1][0];
                choice[i][j] = 1;
            }
            else{
                dp[i][j] = cost[j+1] + dp[i+1][j+1];
            }
        }
    }
    int j = I-1;
    for(int i = 0; i < n; i++){
        if(choice[i][j] == 1){
            res.push_back(i+1);
            j = 0;
        }
        else{
            j++;
        }
    }

    return dp[0][I-1];

}

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);

    int n,i,m,p;
    while(cin >> n >> i >> m >> p){
        vector<int> cost(m);
        for(int i = 0;i < m; i++){
            cin >> cost[i];
        }
        vector<int> price(m);
        for(int i = 0;i < m; i++){
            cin >> price[i];
        }

        vector<int> res;

        cout << sol_dp(n,i,m,p,cost,price,res) << endl;

        if(res.size() == 0){
            cout << 0 << endl;
        }
        else{
            print_vector<int>(res);
        }
    }

    return 0;
}
