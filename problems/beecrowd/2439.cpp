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


llmatrix matmul_mod(llmatrix &A,llmatrix &B,ll mod){
    llmatrix C(A.size(),vector<ll>(B[0].size()));

    for(int i = 0; i < A.size(); i++){
        for(int j = 0; j < B[0].size(); j++){
            C[i][j] = 0;
            for(int k = 0; k < A[0].size();k++){
                C[i][j] = (C[i][j] + ((A[i][k]*B[k][j]) % mod)) % mod;
            }
        }
    }

    return C;
}

llmatrix fast_matexp_mod(ll e, llmatrix &M,ll &mod){
    if(e == 1){
        return M;
    }
    llmatrix N = fast_matexp_mod(e/2,M,mod);
    llmatrix temp = matmul_mod(N,N,mod);
    if((e % 2) == 1){
        temp = matmul_mod(temp,M,mod);
    }
    return temp;

}

int can_be_adj(vector<int> &c1, vector<int> &c2){
    return (c1[0] != c2[0] && c1[1] != c2[1] && c1[2] != c2[2]);
}


int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);
    ll mod = 1e9 + 7;
    imatrix valid_cols = {{0,1,0},{0,1,2},{0,2,0},{0,2,1},{1,0,1},{1,0,2},{1,2,0},{1,2,1},{2,0,1},{2,0,2},{2,1,0},{2,1,2}};
    llmatrix trans_matrix(12,vector<ll>(12));
    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 12; j++){
            trans_matrix[i][j] = can_be_adj(valid_cols[i],valid_cols[j]);
        }
    }
    ll n;
    cin >> n;
    if(n == 1){
        cout << 12 << endl;
    }
    else{
        llmatrix temp = fast_matexp_mod(n-1,trans_matrix,mod);
        ll ret = 0;
        for(int i = 0; i < 12; i++){
            for(int j = 0; j < 12; j++){
                ret = (ret + temp[i][j]) % mod;
            }
        }
        cout << ret << endl;
    }

    return 0;
}
