#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

#define LLINF LLONG_MAX/2
#define IINF INT_MAX/2

typedef long long ll;

typedef vector<vector<ll>> llmatrix;


llmatrix matmul_mod(llmatrix &A,llmatrix &B,ll mod){
    llmatrix C(A.size(),vector<ll>(B[0].size()));

    for(int i = 0; i < A.size(); i++){
        for(int j = 0; j < B[0].size(); j++){
            C[i][j] = 0;
            for(int k = 0; k < A[0].size();k++){
                C[i][j] += A[i][k]*B[k][j];
            }
            C[i][j] %= mod;
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

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);

    ll n,k,l;
    ll mod = 1e6;

    while(cin >> n >> k >> l){
        llmatrix trans_mat(2,vector<ll>(2));
        trans_mat[0][0] = (k % mod);
        trans_mat[0][1] = (l % mod);
        trans_mat[1][0] = 1;
        trans_mat[1][1] = 0;

        ll t = n/5;
        if(t == 1){
            cout << setfill('0') << setw(6) << trans_mat[0][1] << endl;
        }
        else{
            llmatrix res = fast_matexp_mod(t-1,trans_mat,mod);
            cout << setfill('0') << setw(6) << ((k%mod)*res[0][0] + res[0][1]) % mod << endl;
        }
    }

    return 0;
}
