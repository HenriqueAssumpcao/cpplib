#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

#define LLINF LLONG_MAX/2
#define IINF INT_MAX/2

typedef long long ll;
typedef vector<list<pair<int,ll>>> wgraph; // weighted graph
typedef vector<list<int>> graph; // unweighted graph

typedef vector<vector<int>> imatrix;
typedef vector<vector<ll>> llmatrix;
typedef vector<vector<vector<vector<int>>>> imatrix4d;

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

// void sol_dp(int &n, int &m, int &x, int &y, imatrix &M, imatrix4d &dp){
//     dp = imatrix4d(n,vector<vector<vector<int>>>(m,imatrix(x,vector<int>(y,IINF))));
//     imatrix4d visited(n,vector<vector<vector<int>>>(m,imatrix(x,vector<int>(y,0))));

//     if(M[0][0] > 0 || (M[0][0] = 0 && x > 0) || (M[0][0] < 0 && y > 0)){
//         dp[0][0][x][y] = M[0][0];
//         visited[0][0][x][y] = 1;
//     }
//     else{
//         return;
//     }

//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < m; j++){
//             if(j > 0){
//                 int left_neigh_cost = 
//             }
//         }
//     }
// }


int main(){
    //std::ios::sync_with_stdio(0);cin.tie(0);

    int n,m,x,y;

    while(cin >> n >> m >> x >> y){
        imatrix M(n,vector<int>(m));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> M[i][j];
            }
        }
        print_matrix<int>(M);

        imatrix dp;

    }

    return 0;
}
