#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

#define LLINF LLONG_MAX/2
#define IINF INT_MAX/2

typedef long long ll;
typedef vector<list<pair<int,ll>>> wgraph; // weighted graph
typedef vector<list<int>> graph; // unweighted graph

typedef vector<vector<int>> imatrix;
typedef vector<vector<double>> dmatrix;
typedef vector<vector<ll>> llmatrix;

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

void knapsack(int &n,int &c, vector<int> &weights, vector<int> &values, dmatrix &dp){
    dp = dmatrix(n+1,vector<int>(c+1,0));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= c; j++){
            if(weights[i-1] > j){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-weights[i-1]]+values[i-1]);
            }
        }
    }
}

int main(){
    //std::ios::sync_with_stdio(0);cin.tie(0);

    cout << fixed;
    cout << setprecision(2);

    int n,k;

    while(cin >> n >> k){
        vector<int> prizes(n);
        vector<double> probs(n);

        for(int i = 0; i < n; i++){
            cin >> prizes[i];
        }

        int temp;
        vector<double> cumul(n+1);
        cumul[0] = 1;
        for(int i = 0; i < n; i++){
            cin >> temp;
            probs[i] = temp/(100.0);
            cumul[i+1] = cumul[i] * probs[i];
        }

        print_vector<double>(cumul);

        vector<int> weights(n,1);
        vector<double> values(n);

        for(int i = 0; i < n;i++){
            values[i] = prizes[i] * (cumul[i]-cumul[i+1]);
        }

        print_vector<double>(values);
        print_vector<int>(weights);

        

        dmatrix dp;
        knapsack(n,k,weights,values,dp);

        double ret = -1;

        for(int i = 0; i < n+1; i++){
            for(int j = 0; j < k+1; j++){
                ret = max(ret,dp[i][j]);
            }
        }

        for(int i = 0; i < n; i++){
            ret += cumul[i+1]*prizes[i];
        }

        cout << ret << endl;


    }

    return 0;
}
