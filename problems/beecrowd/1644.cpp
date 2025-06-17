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

string permute(int n,string s, vector<int> &perm){
    string perm_s = s;
    for(int i = 0; i < n; i++){
        perm_s[i] = s[perm[i]];
    }
    return perm_s;
}

vector<int> compose_permutation(int n,vector<int> &perm1, vector<int> &perm2){
    vector<int> prod(n);
    for(int i = 0; i < n; i++){
        prod[i] = perm2[perm1[i]];
    }
    return prod;
}

vector<int> fast_exp_permute(int n, ll e, vector<int> &perm){
    if(e == 1){
        return perm;
    }
    else if(e == 2){
        return compose_permutation(n,perm,perm);
    }
    vector<int> temp = fast_exp_permute(n,e/2,perm);
    temp = compose_permutation(n,temp,temp);
    if((e%2) == 1){
        temp = compose_permutation(n,perm,temp);
    }
    return temp;
}


int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);

    int n;
    ll m;
    while(cin >> n >> m){
        if(n == 0){
            break;
        }
        vector<int> perm(n);
        for(int i = 0; i < n; i++){
            cin >> perm[i];
            perm[i]--;
        }
        cin.ignore();
        string s;
        getline(cin,s);

        vector<int> inv_perm(n);
        for(int i = 0; i < n; i++){
            inv_perm[perm[i]] = i;
        }

        vector<int> exp_perm = fast_exp_permute(n,m,inv_perm);
        permute(n,s,exp_perm);
        cout << s << endl;
    }

    return 0;
}
